/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Login.h
 * Author: HP Omen
 *
 * Created on April 29, 2023, 1:24 AM
 */

#ifndef LOGIN_H
#define LOGIN_H

#include "UserInfo.h"

#include <iostream>
#include <cstring>
using namespace std;

#include "ADMIN.h"
#include "USER.h"

void LoginUser() {
    User Info;
    USER USER; //call the classes with the functions
    ADMIN ADMIN; //call the classes with the functions
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
                ADMIN.writeSurvey();
                break;
            case 2:
                ADMIN.ReadUser();
            case 3:
                ADMIN.ReadSurveyAns();
                break;
            default:
                cout << "This is not a valid input" << endl;
                goto X;
                break;
        }



    }

    else {
        USER.StoreUser(Info);
        USER.SurveyList();
    }

}


#endif /* LOGIN_H */

