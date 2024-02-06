/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/


#include <iostream>
#include <string>
#include <iomanip>
#include "GeneralHashFunctions.h"
using namespace std;

int main(int argc, char* argv[])
{
//   string key = "abcdefghijklmnopqrstuvwxyz1234567890";//1
//   string key = "Enter your code";//5
//   string key = "LWLJBTDFYLEFKKLDATOP";//0
//   string key = "ML";//6

   cout << "General Purpose Hash Function Algorithms Test" <<endl;
   cout << "By Arash Partow - 2002        " <<endl;
   cout << "Key:     " <<key<<endl;
   cout << " 1. RS-Hash Function Value:   " <<setw(15)<< RSHash(key)   <<endl;
   cout << " 2. JS-Hash Function Value:   " <<setw(15)<< JSHash(key)   <<endl;
   cout << " 3. PJW-Hash Function Value:  " <<setw(15)<< PJWHash(key)  <<endl;
   cout << " 4. ELF-Hash Function Value:  " <<setw(15)<< ELFHash(key)  <<endl;
   cout << " 5. BKDR-Hash Function Value: " <<setw(15)<< BKDRHash(key) <<endl;
   cout << " 6. SDBM-Hash Function Value: " <<setw(15)<< SDBMHash(key) <<endl;
   cout << " 7. DJB-Hash Function Value:  " <<setw(15)<< DJBHash(key)  <<endl;
   cout << " 8. DEK-Hash Function Value:  " <<setw(15)<< DEKHash(key)  <<endl;
   cout << " 9. FNV-Hash Function Value:  " <<setw(15)<< FNVHash(key)  <<endl;
   cout << "10. BP-Hash Function Value:   " <<setw(15)<< BPHash(key)   <<endl;
   cout << "11. AP-Hash Function Value:   " <<setw(15)<< APHash(key)   <<endl;

   return 0;
}
