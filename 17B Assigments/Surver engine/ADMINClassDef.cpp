
/* 
 * File:   ADMINFuntions.h
 * Author: HP Omen
 *
 * Created on April 29, 2023, 1:30 AM
 */

#ifndef ADMINFUNTIONS_H
#define ADMINFUNTIONS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ostream>

using namespace std;

#include "ADMIN.h"
#include "UserInfo.h"

void ADMIN::ReadUser() {
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

void ADMIN::writeSurvey() {
    char FileName[20];
    cout << "Enter the name of your survey: ";
    cin >> FileName;

    ofstream StoreName("SurveyNames.bin", ios::binary | ios::app);
    StoreName.write(reinterpret_cast<char*> (&FileName), sizeof (FileName));
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

    writeFile.write(reinterpret_cast<char*> (&QuestionSize), sizeof (int));
    writeFile.write(reinterpret_cast<char*> (&AnswersSize), sizeof (int));
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

void ADMIN::ReadSurveyAns() {


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

    ifstream readFile(find, ios::binary);

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
    int sizeOfQuestions, sizeOfAnswers;

    read.read(reinterpret_cast<char*> (&sizeOfAnswers), sizeof (int));
    read.read(reinterpret_cast<char*> (&sizeOfQuestions), sizeof (int));



    int* arr = new int[sizeOfAnswers];
    read.read(reinterpret_cast<char*> (arr), sizeOfAnswers * sizeof (int));


    int INDX = 0;
    int SizeOfQ = sizeOfAnswers / sizeOfQuestions;
    
    for(int k=0;k<sizeOfAnswers;k++){
        cout << arr[k] << endl;
    }
    
    for (int y = 0; y < sizeOfQuestions; y++) {
        cout << "Question #" << y + 1 << ": " << ArrayOfQuestions[y] << endl;
        for (int i = 0; i < SizeOfQ; i++) {

            if (arr[i] > 0) {
                cout << ArrayOfAnswers[INDX];
                for (int o = 0; o < arr[INDX]; o++) {
                    cout << "* ";
                }
            } else {
                cout << ArrayOfAnswers[INDX];
            }
            INDX++;
            cout << endl;
        }
    }


}



#endif /* ADMINFUNTIONS_H */

