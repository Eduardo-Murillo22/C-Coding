
/* 
 * File:   USERFunctions.h
 * Author: HP Omen
 *
 * Created on April 29, 2023, 1:33 AM
 */

#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ostream>

using namespace std;

#include "USER.h"

void USER::StoreUser(User U) {

    ofstream outFile("UserInfo.bin", ios::out | ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: Could not open file." << endl;
    }

    outFile.write((char*) &U, sizeof (U));
}

void USER::AnswerASurvey(char* FileName) {
    ifstream readFile(FileName, ios::binary);
    if (!readFile) {
        cerr << "Error: Unable to open file '" << FileName << "'" << endl;
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





    char extAns[4] = "Ans";
    strcat(FileName, extAns);
    ifstream read(FileName, ios::binary);

        int sizeOfQuestions=0, sizeOfAnswers=0;
    if(read.is_open()){

        read.read(reinterpret_cast<char*> (&sizeOfAnswers), sizeof (int));
        read.read(reinterpret_cast<char*> (&sizeOfQuestions), sizeof (int));

    }
        int* arr = new int[sizeOfAnswers];
        read.read(reinterpret_cast<char*> (arr), sizeOfAnswers * sizeof (int));
    


    int ANSOp;
    int ANSIndexwrite = 0;
    int* UserAns = new int[sizeA];
    for (int i = 0; i < sizeQ; i++) {
        cout << "Question #" << i + 1 << ": " << ArrayOfQuestions[i] << endl;
        for (int y = 0; y < Qsize; y++) {
            cout << "Option #" << y + 1 << ": " << ArrayOfAnswers[i * Qsize + y] << endl;
        }
p:
        cout << "What  number is you answer?" << endl;
        cin >> ANSOp;
        if (ANSOp < 0 || ANSOp > Qsize) {
            cerr << "This is not a valid answer." << endl;
            goto p;
        }

        for (int o = 0; o < Qsize; o++) {
            if (o == ANSOp - 1) {
                UserAns[ANSIndexwrite] = 1;
                if (read.is_open()) {
                    UserAns[ANSIndexwrite] = arr[ANSIndexwrite] + UserAns[ANSIndexwrite];
                }
            } else {
                UserAns[ANSIndexwrite] = 0;
                if (read.is_open()) {
                    UserAns[ANSIndexwrite] = arr[ANSIndexwrite] + UserAns[ANSIndexwrite];
                }
            }
            ANSIndexwrite++;
        }
    }

    // Free memory for the arrays
    delete[] ArrayOfQuestions;
    delete[] ArrayOfAnswers;

    for(int p = 0; p < sizeOfAnswers;p++){
        cout << UserAns[p] << endl;
    }

    ofstream ANS(FileName, ios::binary);


    ANS.write(reinterpret_cast<char*> (&sizeA), sizeof (int));
    ANS.write(reinterpret_cast<char*> (&sizeQ), sizeof (int));

    ANS.write(reinterpret_cast<char*> (UserAns), sizeA * sizeof (int));

    ANS.close();


}

void USER::SurveyList() {

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
    cout << "What Number Survey Do You Want To Answer?" << endl;
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

    AnswerASurvey(found);


}


#endif /* USERFUNCTIONS_H */

