
#include <fstream>
#include <iostream>
#include<string>
using namespace std;

void test1();
int testInt();


int main(int argc, char** argv) {

    ifstream readFile("test.bin", ios::binary);
    string testread;
    //    readFile.read(reinterpret_cast<char*>(&testread),17);

    getline(readFile, testread);

    cout << "test read" << testread << endl;
    readFile.close();
}
