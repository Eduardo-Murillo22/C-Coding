#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ostream>

using namespace std;

struct User {
    char Email[30], Username[30], Password[30];
};

void LoginUser();

void writeSurvey();
void ViewSurveyAnswers();
void AnswerASurvey(char*);
void SurveyList();
void ReadSurveyAns();

void StoreUser(User);
void ReadUser();

int main() {
    LoginUser();
}

void LoginUser() {
    User Info;
    char AdminEmail[20] = "ADMIN123", AdminPass[20] = "Password1234";
    int choice;


    cout << "Enter Email" << endl; 
    cin >> Info.Email;

    cout << "Enter username" << endl;
    cin >> Info.Username;

    cout << "Enter Password" << endl;
    cin >> Info.Password;


    if ((strcmp(Info.Email, AdminEmail) == 0) && ((strcmp(Info.Username, "Eduardo") == 0) || (strcmp(Info.Username, "Mark") == 0)) && (strcmp(Info.Password, AdminPass) == 0)) {

X:
        cout << "Enter what you would like to do" << endl;
        cout << "(1) Create questions" << endl;
        cout << "(2) View Users Information" << endl;
        cout << "(3) View answers" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                writeSurvey();
                break;
            case 2:
                ReadUser();
            case 3:
                ReadSurveyAns();
                break;
            default:
                cout << "This is not a valid input" << endl;
                goto X;
                break;
        }


        
    } 

    else {
        StoreUser(Info);
        SurveyList();
    }

}

void StoreUser(User U) {

    ofstream outFile("UserInfo.bin", ios::out | ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: Could not open file." << endl;
    }

    outFile.write((char*) &U, sizeof (U));
}

void ReadUser() {
    // Open the binary file for reading
    ifstream inFile("UserInfo.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file. UserInfo.bin" << endl;

    }

    int count = 0;
    // Read data from the file into a Data struct
    User UserInfo;
    while (inFile.read((char*) &UserInfo, sizeof (UserInfo))) {
        count++;
        cout << "User #" << count << endl;
        cout << "Email: " << UserInfo.Email << endl;
        cout << "Username: " << UserInfo.Username << endl;
        cout << "Password: " << UserInfo.Password << endl << endl;

    }

    // Close the file
    inFile.close();
}

void writeSurvey() {
    char FileName[20];
    cout << "Enter the name of your survey: ";
    cin >> FileName;
    
    ofstream StoreName("SurveyNames.bin",ios::binary | ios::app);
    StoreName.write(reinterpret_cast<char*>(&FileName),sizeof(FileName));
    StoreName.close();

    int QuestionSize, AnswersSize, Qsize;
    cout << "How many questions do you want to input? ";
    cin >> QuestionSize;
    cout << "How many options will each question have? ";
    cin >> Qsize;

    AnswersSize = Qsize * QuestionSize;
    string* ArrayOfQuestions = new string[QuestionSize];
    string* ArrayOfAnswers = new string[AnswersSize];

    ofstream writeFile(FileName, ios::binary);

    cin.ignore();
    for (int i = 0; i < QuestionSize; i++) {
        cout << "Enter Question #" << i + 1 << ": ";
        getline(cin, ArrayOfQuestions[i]);
        for (int y = 0; y < Qsize; y++) {
            cout << "Enter option #" << y + 1 << ": ";
            getline(cin, ArrayOfAnswers[i * Qsize + y]);
        }
    }

    writeFile.write(reinterpret_cast<char*>(&QuestionSize), sizeof(int));
    writeFile.write(reinterpret_cast<char*>(&AnswersSize), sizeof(int));
    for (int i = 0; i < QuestionSize; i++) {
        writeFile.write(ArrayOfQuestions[i].c_str(), ArrayOfQuestions[i].size() + 1);
        for (int y = 0; y < Qsize; y++) {
            writeFile.write(ArrayOfAnswers[i * Qsize + y].c_str(), ArrayOfAnswers[i * Qsize + y].size() + 1);
        }
    }

    writeFile.close();
    delete[] ArrayOfQuestions;
    delete[] ArrayOfAnswers;
    cout << "Survey saved to file " << FileName << endl;


    ifstream readFile(FileName, ios::binary);
    if (!readFile) {
        cerr << "Error: Unable to open file '" << FileName << "'" << endl;
        return;
    }

    // Read the size of the arrays
    int sizeQR, sizeAR;
    readFile.read(reinterpret_cast<char*> (&sizeQR), sizeof (int));
    readFile.read(reinterpret_cast<char*> (&sizeAR), sizeof (int));
    int QsizeR = sizeAR / sizeQR;

    // Allocate memory for the arrays
    string* ArrayOfQuestionsR = new string[sizeQR];
    string* ArrayOfAnswersR = new string[sizeAR];

    // Read the arrays from the file
    for (int i = 0; i < sizeQR; i++) {
        char buffer[100];
        readFile.getline(buffer, 100, '\0');
        ArrayOfQuestionsR[i] = buffer;
        for (int y = 0; y < QsizeR; y++) {
            char buffer[100];
            readFile.getline(buffer, 100, '\0');
            ArrayOfAnswersR[i * QsizeR + y] = buffer;
        }
    }

    // Close the file
    readFile.close();

    // Print the arrays
    for (int i = 0; i < sizeQR; i++) {
        cout << "Question #" << i + 1 << ": " << ArrayOfQuestions[i] << endl;
        for (int y = 0; y < QsizeR; y++) {
            cout << "Option #" << y + 1 << ": " << ArrayOfAnswers[i * Qsize + y] << endl;
        }
    }

    // Free memory for the arrays

    delete[] ArrayOfQuestions;
    delete[] ArrayOfAnswers;
    
}

void AnswerASurvey(char* FileName) {
    ifstream readFile(FileName, ios::binary);
    if (!readFile) {
        cerr << "Error: Unable to open file '" << FileName << "'" << endl;
        return;
    }

    // Read the size of the arrays
    int sizeQ, sizeA;
    readFile.read(reinterpret_cast<char*>(&sizeQ), sizeof(int));
    readFile.read(reinterpret_cast<char*>(&sizeA), sizeof(int));
    int Qsize = sizeA / sizeQ;

    // Allocate memory for the arrays
    string* ArrayOfQuestions = new string[sizeQ];
    string* ArrayOfAnswers = new string[sizeA];

    // Read the arrays from the file
    for (int i = 0; i < sizeQ; i++) {
        char buffer[100];
        readFile.getline(buffer, 100, '\0');
        ArrayOfQuestions[i] = buffer;
        for (int y = 0; y < Qsize; y++) {
            char buffer[100];
            readFile.getline(buffer, 100, '\0');
            ArrayOfAnswers[i * Qsize + y] = buffer;
        }
    }

    // Close the file
    readFile.close();

//    // Print the arrays ** TEST **
//    for (int i = 0; i < sizeQ; i++) {
//        cout << "Question #" << i + 1 << ": " << ArrayOfQuestions[i] << endl;
//        for (int y = 0; y < Qsize; y++) {
//            cout << "Option #" << y + 1 << ": " << ArrayOfAnswers[i * Qsize + y] << endl;
//        }
//    }


    
    char extAns[4] = "Ans";
    strcat(FileName, extAns);
    ifstream read(FileName,ios::binary);



    int sizeOfQuestions, sizeOfAnswers;
    read.read(reinterpret_cast<char*> (&sizeOfAnswers), sizeof (int));
    read.read(reinterpret_cast<char*> (&sizeOfQuestions), sizeof (int));
    int* arr = new int[sizeOfAnswers];
    read.read(reinterpret_cast<char*> (arr), sizeOfAnswers * sizeof (int));

    for (int i = 0; i < sizeOfAnswers; i++) {
        cout << arr[i] << endl;
    }

    int ANSOp;
    int ANSIndexwrite=0;
    int* UserAns = new int[sizeA];
    for (int i = 0; i < sizeQ; i++) {
        cout << "Question #" << i + 1 << ": " << ArrayOfQuestions[i] << endl;
        for (int y = 0; y < Qsize; y++) {
            cout << "Option #" << y + 1 << ": " << ArrayOfAnswers[i * Qsize + y] << endl;
        }
        p:
        cout << "What  number is you answer?" << endl;
        cin >> ANSOp;
        if(ANSOp < 0 || ANSOp > Qsize){
            cerr << "This is not a valid answer." << endl;
            goto p;
        }
        
        for(int o = 0; o < Qsize; o++){
        if(o == ANSOp-1){
                UserAns[ANSIndexwrite] = 1;
                if(read.is_open()){
                    UserAns[ANSIndexwrite] = arr[ANSIndexwrite] + UserAns[ANSIndexwrite];
                }
            }
            else{
                UserAns[ANSIndexwrite] = 0;
                if(read.is_open()){
                    UserAns[ANSIndexwrite] = arr[ANSIndexwrite] + UserAns[ANSIndexwrite];
                }
            }
            ANSIndexwrite++;
        }
    }
    
    // Free memory for the arrays
    delete[] ArrayOfQuestions;
    delete[] ArrayOfAnswers;
    

    ofstream ANS(FileName, ios::binary);


    ANS.write(reinterpret_cast<char*>(&sizeA),sizeof(int));
    ANS.write(reinterpret_cast<char*> (&sizeQ),sizeof(int));

    ANS.write(reinterpret_cast<char*> (UserAns), sizeA * sizeof(int));
    
    ANS.close();

    
}

void ReadSurveyAns() {


    ifstream inFile("SurveyNames.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file." << endl;

    }

    // Read data from the file into a Data struct
    char myData[20];
    int NumberofItems = 0;
    while (inFile.read(reinterpret_cast<char*> (&myData), sizeof (myData))) {
        cout << "Survey #" << NumberofItems << endl;
        cout << myData << endl << endl;
        NumberofItems++;
    }
    inFile.close();

    int index;
    cout << "What Number Survey would you like to see the answers?" << endl;
    cin >> index;

    ifstream Find("SurveyNames.bin", ios::in | ios::binary);
    char find[20], found[20];
    int X = 0;
    while (Find.read(reinterpret_cast<char*> (&find), sizeof (find))) {
        if (index == X) {
            strcpy(found, find);
        }
        X++;
    }
    
    
    
    char extAns[4] = "Ans";
    strcat(found, extAns);

    ifstream readFile(find,ios::binary);

    if (!readFile) {
        cerr << "Error: Unable to open file '" << find << "'" << endl;
        return;
    }

    // Read the size of the arrays
    int sizeQ, sizeA;
    readFile.read(reinterpret_cast<char*> (&sizeQ), sizeof (int));
    readFile.read(reinterpret_cast<char*> (&sizeA), sizeof (int));
    int Qsize = sizeA / sizeQ;

    // Allocate memory for the arrays
    string* ArrayOfQuestions = new string[sizeQ];
    string* ArrayOfAnswers = new string[sizeA];

    // Read the arrays from the file
    for (int i = 0; i < sizeQ; i++) {
        char buffer[100];
        readFile.getline(buffer, 100, '\0');
        ArrayOfQuestions[i] = buffer;
        for (int y = 0; y < Qsize; y++) {
            char buffer[100];
            readFile.getline(buffer, 100, '\0');
            ArrayOfAnswers[i * Qsize + y] = buffer;
        }
    }

    // Close the file
    readFile.close();

    //    // Print the arrays ** TEST **
    //    for (int i = 0; i < sizeQ; i++) {
    //        cout << "Question #" << i + 1 << ": " << ArrayOfQuestions[i] << endl;
    //        for (int y = 0; y < Qsize; y++) {
    //            cout << "Option #" << y + 1 << ": " << ArrayOfAnswers[i * Qsize + y] << endl;
    //        }
    //    }

    ifstream read(found, ios::binary);
    int sizeOfQuestions,sizeOfAnswers;
    
    read.read(reinterpret_cast<char*> (&sizeOfAnswers), sizeof (int));
    read.read(reinterpret_cast<char*>(&sizeOfQuestions),sizeof(int));
    
    
    
    int* arr = new int[sizeOfAnswers];
    read.read(reinterpret_cast<char*>(arr), sizeOfAnswers * sizeof(int));
    
    
    int INDX=0;
    int SizeOfQ=sizeOfAnswers/sizeOfQuestions;
    for(int y = 0 ; y < sizeOfQuestions; y++){
        cout << "Question #" << y + 1 << ": " << ArrayOfQuestions[y] << endl;
        for(int i=0;i < SizeOfQ;i++){

        if(arr[i] > 0){
            cout << ArrayOfAnswers[INDX];
            for (int o = 0; o < arr[i]; o++) {
                cout << "* ";

            }
        }
        else{
            cout << ArrayOfAnswers[INDX];
        }
        INDX++;
            cout << endl;
        }
    }
    
    
}

void SurveyList(){
    
        ifstream inFile("SurveyNames.bin", ios::in | ios::binary);

        if (!inFile) {
            cout << "Error: Could not open file." << endl;

        }

        // Read data from the file into a Data struct
        char myData[20];
        int NumberofItems = 0;
        while (inFile.read(reinterpret_cast<char*> (&myData),sizeof (myData))) {
            cout << "Survey #" << NumberofItems << endl;
            cout << myData << endl << endl;
            NumberofItems++;
        }
        inFile.close();
        
        int index;
        cout << "What Number Survey Do You Want To Answer?" << endl;
        cin >> index;
        
        ifstream Find("SurveyNames.bin", ios::in | ios::binary);
        char find[20], found[20];
        int X=0;
        while (Find.read(reinterpret_cast<char*> (&find),sizeof (find))) {
            if(index == X){
                strcpy(found, find);
            }
            X++;
        }
        
        AnswerASurvey(found);        
        
    
}