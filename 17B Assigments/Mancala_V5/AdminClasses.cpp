#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include<iomanip>
#include <cstring>
#include <fstream>
#include"ADMIN.h"
#include"USERInfo.h"

const int SIZE=12;

void ADMIN::ViewPlayers() {

    ifstream inFile("UserInfo.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file. UserInfo.bin" << endl;

    }

    int count = 0;
    // Read data from the file into a Data struct
    user UserInfo;
    while (inFile.read((char*) &UserInfo, sizeof (UserInfo))) {
        count++;
        cout << "User #" << count << endl;
        cout << "Email: " << UserInfo.Email << endl;
        cout << "Username: " << UserInfo.Username << endl;
        cout << "Password: " << UserInfo.Password << endl;
        cout << "Score: " << UserInfo.score << endl << endl;

    }

    // Close the file
    inFile.close();


}

void ADMIN::AdminLogin() {
    user Info;
    int choice1;
    char AdminEmail[20] = "ADMIN123", AdminPass[20] = "Password1234";

    cout << "** Email:ADMIN123\nUsername:Eduardo or Mark\nPassword:Password1234\n**" << endl;
    cout << "Enter Email" << endl; //need to be in html format <label></label>
    cin >> Info.Email;

    cout << "Enter username" << endl;
    cin >> Info.Username;

    cout << "Enter Password" << endl;
    cin >> Info.Password;
    if ((strcmp(Info.Email, AdminEmail) == 0) && ((strcmp(Info.Username, "Eduardo") == 0) || (strcmp(Info.Username, "Mark") == 0)) && (strcmp(Info.Password, AdminPass) == 0)) {

X:
        cout << "Enter what you would like to do" << endl;
        cout << "(1) View Players" << endl;
        cout << "(2) Modify Username" << endl;
        cout << "(3) Edit Score" << endl;
        cin >> choice1;

        switch (choice1) {
            case 1:
                ViewPlayers();
                break;
            case 2:
                ViewPlayers();
                ModifyInfo();
                break;
            case 3:
                ViewPlayers();
                ModifyScore();
            default:
                cout << "Invalid option" << endl;
                goto X;
        }
    } else {
        cerr << "Error Not correct Admin Login" << endl;
        goto X;
    }


}

void ADMIN::ModifyInfo() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("UserInfo.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (user);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    user FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Name: " << FindOrder.Username << endl;
    cout << "Score: " << FindOrder.score << endl;


    char NewStatus[30];
    cout << "What is the new Username?" << endl;
    cin >> NewStatus;

    strcpy(FindOrder.Username, NewStatus);

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

void ADMIN::ModifyScore() {

    int ModNum;
    cout << "What order Number would you like to modify?" << endl;
    cin >> ModNum;

    fstream file("UserInfo.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Determine the size of each structure
    const size_t structSize = sizeof (user);

    // Determine the index of the structure to read
    const size_t structIndex = ModNum - 1;

    // Set the position of the file pointer to the start of the structure you want to read
    file.seekg(structIndex * structSize, ios::beg);

    // Read data from the file into a Data struct
    user FindOrder;
    file.read(reinterpret_cast<char*> (&FindOrder), structSize);

    cout << "Order #" << ModNum << endl;
    cout << "Name: " << FindOrder.Username << endl;
    cout << "Score: " << FindOrder.score << endl;


    int NewStatus;
    cout << "What is the new Username?" << endl;
    cin >> NewStatus;

    FindOrder.score = NewStatus;

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

