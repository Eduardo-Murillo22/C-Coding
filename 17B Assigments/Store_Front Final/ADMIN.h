/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ADMIN.h
 * Author: HP Omen
 *
 * Created on April 21, 2023, 7:30 PM
 */

#ifndef ADMIN_H
#define ADMIN_H


class ADMIN{

public:
    void readOrders(); //ADMIN
    void ChangeSatus(); //ADMIN
    void OrderDel(int); //ADMIN
    void ReadUser(); //ADMIN
    
 // commands the the admin can do to operate on the orders
    void creatItem(); //admin
    void ChangeName();
    void ChangeItemName();
    void ChangeItemNumber();
    void ChangeTotal();
    void ChangeStreetName();
    void ChangeHouseNumber();

    
};


#endif /* ADMIN_H */

