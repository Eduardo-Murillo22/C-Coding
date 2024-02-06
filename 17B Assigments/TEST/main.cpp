#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


typedef struct student
{
    char name[10];
    int age;
    vector<int> grades;
}student_t;

int main()
{
    student_t apprentice[3];  
    strcpy(apprentice[0].name, "john");
    apprentice[0].age = 21;
    apprentice[0].grades.push_back(1);
    apprentice[0].grades.push_back(3);
    apprentice[0].grades.push_back(5);    

    strcpy(apprentice[1].name, "jerry");
    apprentice[1].age = 22;
    apprentice[1].grades.push_back(2);
    apprentice[1].grades.push_back(4);
    apprentice[1].grades.push_back(6);

    strcpy(apprentice[2].name, "jimmy");
    apprentice[2].age = 23;
    apprentice[2].grades.push_back(8);
    apprentice[2].grades.push_back(9);
    apprentice[2].grades.push_back(10);

    // Serializing struct to student.data
    ofstream output_file("students.data", ios::binary);
    ofstream tf("students.txt");
    tf.write((char*)&apprentice, sizeof(apprentice));
    output_file.write((char*)&apprentice, sizeof(apprentice));
    output_file.close();
    tf.close();

    // Reading from it
    ifstream input_file("students.data", ios::binary);
    student_t master[3];
    input_file.read((char*)&master, sizeof(master));         

    for (size_t idx = 0; idx < 3; idx++)
    {
        // If you wanted to search for specific records, 
        // you should do it here! if (idx == 2) ...

        cout << "Record #" << idx << endl;
        cout << "Name: " << master[idx].name << endl;
        cout << "Age: " << master[idx].age << endl;
        cout << "Grades: " << endl;
        for (size_t i = 0; i < master[idx].grades.size(); i++)
           cout << master[idx].grades[i] << " ";
        cout << endl << endl;
    }

    return 0;
}