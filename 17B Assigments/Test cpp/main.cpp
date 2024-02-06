//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    ofstream outfile("binaryfile.bin", ios::binary);
//    if (!outfile)
//    {
//        cout << "Error opening file!" << endl;
//        return 1;
//    }
//
//    outfile.write(reinterpret_cast<char*>(arr), n * sizeof(int));
//    outfile.close();
//
//    return 0;
//}


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int arr[5];

    ifstream infile("binaryfile.bin", ios::binary);
    if (!infile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    infile.read(reinterpret_cast<char*>(arr), 5 * sizeof(int));
    infile.close();

    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
