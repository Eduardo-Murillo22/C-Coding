#include<iostream>
#include<fstream>
#include <string>
using namespace std;

struct Name {
    string name="";
    int num=0;
};
int main() {
    int SIZE;
    cout << "size" << endl;
    cin >> SIZE;

    //    name past;
    //    ifstream NW("TEST.txt", ios::in | ios::binary);
    //    for(int i=0;i < SIZE;i++){
    //        NW.read(reinterpret_cast<char*>(&past[i]), sizeof(Name));
    //    }
    //
//      Name* NM = new Name[SIZE];
//        for(int i = 0 ; i < SIZE ; i++){
//            NM[i].name = "Eduardo" + to_string(i);
//            NM[i].num = i*i;
//        }
//        
//        ofstream file("TEST.txt", ios:: out | ios::binary);
//        for(int i=0;i < SIZE;i++){
//            file.write(reinterpret_cast<char*>(&NM[i]), sizeof(Name));
//        }
//        file.close();


    Name* NEW = new Name[SIZE];

    ifstream NW("TEST.txt", ios::in | ios::binary);
    for (int i = 0; i < SIZE; i++) {
        NW.read(reinterpret_cast<char*>(&NEW[i]), sizeof(Name));
    }
    for (int i = 0; i < SIZE; i++) {
        cout << NEW[i].name << endl;
        cout << NEW[i].num << endl;
    }



    return 0;
}