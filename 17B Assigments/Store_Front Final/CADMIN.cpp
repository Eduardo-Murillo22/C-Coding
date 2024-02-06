
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#include "ADMIN.h"
#include "User.h"
#include "ItemDiscription.h"
#include "OrderInfo.h"


void ADMIN::creatItem(){
    Items I;
    p:
    cout << "Input the Image" << endl;
    cin >> I.image;
    cout << "Input the Name" << endl;
    cin>> I.Name;
    cout << "Input the price" << endl;
    cin  >> I.price;

    ofstream outFile("Items.bin",ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: Could not open file." << endl;
    }
            
    outFile.write(reinterpret_cast<char*>(&I), sizeof(I));

    outFile.close();
    
    char yew;
    cout<< "Would  you like put another item? Enter Y if yes"<< endl;
    cin >> yew;
    yew  = toupper(yew);
    
    if(yew == 'Y'){
        goto p;
    }
    
}

void USER::readItems(){
    // Open the binary file for reading
    ifstream inFile("Items.bin", ios::in | ios::binary);
    
    if (!inFile) {
        cout << "Error: Could not open file." << endl;

    }
    
    // Read data from the file into a Data struct
    Items myData;
    int NumberofItems=0;
    while(inFile.read(reinterpret_cast<char*>(&myData), sizeof(myData))){
        cout << "Item #" << NumberofItems+1<< endl;
        cout << "IMG: " << myData.image << endl;
        cout << "Name: " << myData.Name << endl; 
        cout << "Price: " << myData.price << endl << endl;
        NumberofItems++;
    }
    
    
    // Close the file
    inFile.close();
    
}

void USER::StoreUser(User U){

    ofstream outFile("UserInfo.bin", ios::out | ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: Could not open file." << endl;
    }

    outFile.write((char*) &U, sizeof (U));
}

void ADMIN::ReadUser() {
    // Open the binary file for reading
    ifstream inFile("UserInfo.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file. UserInfo.bin" << endl;

    }

    int count=0;
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

void USER::orders(char *info){
    int orderChoice=0;
    
    T:
    cout << "Please enter the number of the order you want" << endl;
    cin >> orderChoice;
    
    
      // Open the binary file for reading
    ifstream inFile("Items.bin", ios::in | ios::binary);
    
    if (!inFile) {
        cout << "Error: Could not open file." << endl;
    }
    
    // Determine the size of each structure
    const size_t structSize = sizeof (Items);

    // Determine the index of the structure to read
    const size_t structIndex = orderChoice-1; // read the third structure (zero-based index)

    // Set the position of the file pointer to the start of the structure you want to read
    inFile.seekg(structIndex * structSize, ios::beg);
    
    // Read data from the file into a Data struct
    Items myData;
    int NumberofItems= structIndex;
    inFile.read(reinterpret_cast<char*>(&myData), structSize);
    if(myData.price!=0){
        
        cout << "Item #" << NumberofItems+1<< endl;
        cout << "IMG: " << myData.image << endl;
        cout << "Name: " << myData.Name << endl;
        cout << "Price: " << myData.price << endl << endl;
        
        A:
        placeOrder O;
        strcpy(O.Custumer, info);
        strcpy(O.nameOfItem, myData.Name);
        cout << "How Many " << myData.Name << " would you like?!" << endl;
        cin >> O.numOfItems;
        O.total = O.numOfItems * myData.price;
        cout << "Your total is: " << O.total << endl;
        cout << "Input your street name" << endl;
        cin >> O.street;
        cout << "Input your house number" << endl;
        cin >> O.Hnumber;
        strcpy(O.status, "Pending");
        
        B:
        char correct;
        cout << "Is Your information correct?? (Y for Yes and N for No)" << endl;
        cin >> correct;
        correct = toupper(correct);
        
        if(correct == 'Y'){
            writeOrder(O);

        }
        else if(correct == 'N'){
            goto A;
        }
        else{
            cout << "Please input 'Y' or 'N'" << endl;
            goto B;
        }
    }
    else{
        cout << "There is no item in that position \n" << endl;
        goto T;
    }
    
    // Close the file
    inFile.close();
}

void USER::writeOrder(placeOrder O){
    
    cout << "OK your order will be sent to " << O.Hnumber << " " << O.street << endl;
    cout << "Thank you for doing business with us" << endl;
    
    ofstream outFile("Orders.bin", ios::out | ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: Could not open file." << endl;
    }

    outFile.write((char*) &O, sizeof (O));
    outFile.close();
    
}

void ADMIN::readOrders(){

    ifstream inFile("Orders.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file." << endl;
    }

    cout << "This is the orders: " << endl;
    int count = 0;
    // Read data from the file into a Data struct
    placeOrder Orders;
    while (inFile.read((char*) &Orders, sizeof (Orders))) {
        count++;
        cout << "Order #" << count << endl;
        cout << "Costumers Name: " << Orders.Custumer << endl;
        cout << "Item: " << Orders.nameOfItem << endl;
        cout << "Amount of items: " << Orders.numOfItems << endl;
        cout << "Total: $" << Orders.total << endl ;
        cout << "Street: " << Orders.street << endl;
        cout << "House Number: " << Orders.Hnumber << endl;
        cout << "STATUS: " << Orders.status << endl << endl << endl;
    }
    inFile.close();
    
    char MOD;
    int UserChoice;
    cout << "Would you like to modify something from the orders ? Y or N" << endl;
    cin >> MOD;
    MOD = toupper(MOD);
    


    
    if(MOD == 'Y'){

        cout << "(1) Change Status of order " << endl;
        cout << "(2) Change Costumer Name of order " << endl;
        cout << "(3) Change Items of order " << endl;
        cout << "(4) Change Amount of items of order " << endl;
        cout << "(5) Change Total of order " << endl;
        cout << "(6) Change Street of order " << endl;
        cout << "(7) Change House Number of order " << endl;
        cout << "(8) Delete Order " << endl;
        cout << "(9) Quit" << endl;
        cin >> UserChoice;
        
        switch (UserChoice) {
            case 1:
                ChangeSatus();
                break;
            case 2:
                ChangeName();
                break;
            case 3:
                ChangeItemName();
                break;
            case 4:
                ChangeItemNumber();
                break;
            case 5:
                ChangeTotal();
                break;
            case 6:
                ChangeStreetName();
                break;
            case 7:
                ChangeHouseNumber();
                break;
            case 8:
                OrderDel(count);
                break;
            case 9:
                break;
            default:
                cout << "This is not a valid option" << endl;
                break;    
        }
    }
}

void ADMIN::ChangeSatus() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof(placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*>(&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    char NewStatus[30];
    cout << "What is the new status?" << endl;
    cin >> NewStatus;

    strcpy(FindOrder.status, NewStatus);

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*>(&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::ChangeName() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    char Name[30];
    cout << "What is the new Name of the costumer for the order?" << endl;
    cin >> Name;

    strcpy(FindOrder.Custumer, Name);

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::ChangeItemName() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    char NewStatus[30];
    cout << "What is the new Item Name?" << endl;
    cin >> NewStatus;

    strcpy(FindOrder.nameOfItem, NewStatus);

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::ChangeItemNumber() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    int NewStatus;
    cout << "What is the new Number of items?" << endl;
    cin >> NewStatus;

    FindOrder.numOfItems = NewStatus;

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::ChangeTotal() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    int NewStatus;
    cout << "What is the new Total for " << FindOrder.Custumer << " order?" << endl;
    cin >> NewStatus;

    FindOrder.total = NewStatus;

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::ChangeStreetName(){

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    char NewStatus[30];
    cout << "What is the new Street name?" << endl;
    cin >> NewStatus;

    strcpy(FindOrder.street, NewStatus);

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::ChangeHouseNumber() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;

    int NewStatus;
    cout << "What is the new house number?" << endl;
    cin >> NewStatus;

    FindOrder.Hnumber = NewStatus;

    // Seek back to the beginning of the structure in the file before writing the modified data
    file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}

void ADMIN::OrderDel(int size) {
    int ModNum;
    cout << "What order Number would you like to DELETE?" << endl;
    cin >> ModNum;

    fstream file("Orders.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (placeOrder);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    placeOrder FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Costumer's Name: " << FindOrder.Custumer << endl;
    cout << "Item: " << FindOrder.nameOfItem << endl;
    cout << "Amount of items: " << FindOrder.numOfItems << endl;
    cout << "Total: $" << FindOrder.total << endl;
    cout << "Street: " << FindOrder.street << endl;
    cout << "House Number: " << FindOrder.Hnumber << endl;
    cout << "STATUS: " << FindOrder.status << endl << endl << endl;
    
    
   strcpy (FindOrder.Custumer, "NULL");
   strcpy(FindOrder.nameOfItem, "NULL");
   FindOrder.numOfItems = 0;
   FindOrder.total = 0;
   strcpy (FindOrder.street, "NULL");
   FindOrder.Hnumber = 0;
   strcpy (FindOrder.status, "NULL");
   
   file.seekp(structIndex * structSize, ios::beg);

    // Write the modified data to the file
    file.write(reinterpret_cast<const char*> (&FindOrder), structSize);

    // Check if the read and write operations were successful
    if (file.fail() || file.bad()) {
        cerr << "Error reading or writing to file." << endl;
        return;
    }

    cout << "Status updated successfully." << endl;

    file.close();
}