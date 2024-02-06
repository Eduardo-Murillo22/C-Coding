/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   OrderInfo.h
 * Author: HP Omen
 *
 * Created on April 21, 2023, 4:08 PM
 */

#ifndef ORDERINFO_H
#define ORDERINFO_H

struct placeOrder {
    char Custumer[30];
    char nameOfItem[20];
    float total = 0;
    char street[30];
    int Hnumber = 0;
    int numOfItems;
    char status[20];
};

#endif /* ORDERINFO_H */

