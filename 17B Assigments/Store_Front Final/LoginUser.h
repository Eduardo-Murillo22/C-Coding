/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   LoginUser.h
 * Author: HP Omen
 *
 * Created on April 21, 2023, 9:45 PM
 */

#ifndef LOGINUSER_H
#define LOGINUSER_H


#include "ADMIN.h"
#include "User.h"

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void LoginUser() {
    User Info;
    USER USER;//call the classes with the functions
    ADMIN ADMIN;//call the classes with the functions
    char AdminEmail[20] = "ADMIN123", AdminPass[20] = "Password1234";
    int choice;

    cout << "ADMIN LOGIN IS: Admin123, Eduardo or Mark, Password1234" << endl;


    cout << "Enter Email" << endl; //need to be in html format <label></label>
    cin >> Info.Email;

    cout << "Enter username" << endl;
    cin >> Info.Username;

    cout << "Enter Password" << endl;
    cin >> Info.Password;


    if ((strcmp(Info.Email, AdminEmail) == 0) && ((strcmp(Info.Username, "Eduardo") == 0) || (strcmp(Info.Username, "Mark") == 0)) && (strcmp(Info.Password, AdminPass) == 0)) {

X:
        cout << "Enter what you would like to do" << endl;
        cout << "(1) View User Records" << endl;
        cout << "(2) View Orders" << endl;
        cout << "(3) Add items to store" << endl;
        cin >> choice;

        if (choice < 0 || choice > 4) {
            cout << "NOT VALID INPUT" << endl;
            goto X;
        }
        switch (choice) {
            case 1:
                ADMIN.ReadUser();
                break;
            case 2:
                ADMIN.readOrders();
                break;
            case 3:
                ADMIN.creatItem();
                break;

        }
    } else {
        USER.StoreUser(Info);
        USER.readItems();

        char PlaceOrder;

B:
        cout << "Would you like to place a order Y or N?" << endl;
        cin >> PlaceOrder;
        PlaceOrder = toupper(PlaceOrder);

        if (PlaceOrder == 'Y') {
            USER.orders(Info.Username); //users name
        } else if (PlaceOrder == 'N') {
            cout << "Thank You for visiting the store :)" << endl;
        } else {
            cout << "You need to input 'Y' for yes or 'N' for No\nTry Again" << endl;
            goto B;
        }

    }

}



#endif /* LOGINUSER_H */

