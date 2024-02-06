#include <iostream>
#include <string>
#include <fstream>

using namespace std;




struct itmdis{
    string name, img;
    int $price;
};
struct user{
    string Email;
    string Username;
    string Password;
};

void start(user&);
void items();
void readUsers();

int main() {
    int SIZE=0;
    string ADINUSER = "ADMIN123", ADMINPASS = "Password1234";
    
    user us;


    start(us);


    if (us.Email == ADINUSER && ADMINPASS == us.Password && us.Username == "Eduardo" || us.Username == "Mark") {

        cout << "Enter what you would like to do" << endl;
        cout << "(1) View Records" << endl;
        cout << "(2) View Orders" << endl;
        cout << "(3) Add items to store" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "DISPLAY REC" << endl; break;//display user.bin
        case 2:
            cout << "ViewOrders" << endl; break;
        case 3:

            ofstream file("StoreInventory.bin", ios::binary | ios::app);
                if (!file) {
                    cerr << "Error opening file" << endl;
                    return 1;
                }
            

            itmdis NewItem;
            
            cout << "Add Items to store" << endl;
            cout << "<input type='file'>Enter Image of the item</input>" << endl;
            cin.ignore();
            getline(cin,NewItem.img);
            cout << "<input type='text' placeholder='Name'>Enter the Name of the item</input>" << endl;
            cin.ignore();
            getline(cin, NewItem.name);
            cout << "<input type='number' min='0' placeholder='Price'>Enter the price</input>" << endl;
            cin >> NewItem.$price;

            file.write((char*)&NewItem, sizeof(itmdis));
            file.close();

            items();

            break;

        }
    }
    else {

        items();
        readUsers();
    }
    

}

void start(user &U) {

    
    cout << "Enter Email" << endl; //need to be in html format <label></label>
    getline(cin, U.Email); //Store into cookies
    cout << "Enter username" << endl;
    getline(cin, U.Username); //Store into cookies 
    cout << "Enter Password" << endl;
    getline(cin, U.Password); //Store into cookies
    
    while (U.Email == ""){;
        cout << "You need to enter a email." << endl;
        getline(cin, U.Email); 
    }
    while (U.Username == "") {
        cout << "You need to enter a username." <<  endl;
        getline(cin, U.Username);
    }
    while (U.Password == "") {
        cout << "You need to enter a password." << endl;
        getline(cin, U.Password);
    }

    ofstream myFile("userInfo.dat", ios::out | ios::binary);


    myFile.write(reinterpret_cast<char*> (&U), sizeof (user));
    myFile.close();
    
}
void items() {

    ifstream file("StoreInventory.bin", ios::binary);

    // Check if file is open
    if (!file) {
        cerr << "Error opening file" << endl;
    }

    // Read each inventory item from the file
    itmdis item;
    while (file.read((char*) &item, sizeof (item))) {
        // Do something with the item
        cout << "ID: " << item.img << endl;
        cout << "Name: " << item.name << endl;
        cout << "Price: " << item.$price << endl;
    }

    // Close the file
    file.close();

}


void readUsers() {
        user US;

    ifstream rf("userInfo.dat", ios::in | ios::binary);
    

    rf.read(reinterpret_cast<char*> (&US), sizeof (user));
    rf.close();

        cout << "readUservoid" << endl << US.Email << endl << US.Username << endl << US.Password << endl << "END" << endl;

    
}
