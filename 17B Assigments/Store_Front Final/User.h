/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: HP Omen
 *
 * Created on April 21, 2023, 7:35 PM
 */

#ifndef USER_H
#define USER_H
#include "OrderInfo.h"
#include "UserInfo.h"


class USER{
 
public:
    void orders(char *); //admin
    void writeOrder(placeOrder); //user
    void StoreUser(User); //user
    void readItems();//both

};


#endif /* USER_H */

