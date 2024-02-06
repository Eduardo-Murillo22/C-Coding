/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}
int read(char input_array[][COLMAX], int& rows)
{
	int cols = 0;
	for (int i = 0; i < rows; i++)
	{
		cin >> input_array[i];

		if (strlen(input_array[i]) > cols)
		{

			cols = strlen(input_array[i]);
		}
	}
	return cols;

}

void sort(char array_to_sort[][COLMAX], int rows, int cols, const char replace[], const char with[])
{

	char* temp = new char[cols];
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = i + 1; j < rows; j++){
			if (strcmp(array_to_sort[i], array_to_sort[j], replace, with) > 0)
			{
				strcpy(temp, array_to_sort[i]);
				strcpy(array_to_sort[i], array_to_sort[j]);
				strcpy(array_to_sort[j], temp);
			}

		}

	}

}



void print(const char array_to_print[][COLMAX], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		cout << array_to_print[i] << endl;

	}

}

int strcmp(char string1[], char string2[], const char replace[], const char with[])
{
	char* copystring1;
	char* copystring2;
	copystring1 = new char[strlen(string1) + 1];
	copystring2 = new char[strlen(string2) + 1];
	for (int i = 0; i < strlen(string1); i++)
	{
		copystring1[i] = string1[i];
	}
	copystring1[strlen(string1)] = '\0';
	for (int i = 0; i < strlen(string2); i++)
	{
		copystring2[i] = string2[i];
	}
	copystring2[strlen(string2)] = '\0';

	for (int j = 0; j < strlen(replace); j++)
	{
		for (int i = 0; i < strlen(string1); i++)
		{
			if (string1[i] == replace[j])
			{
				copystring1[i] = with[j];
			}
		}

		for (int i = 0; i < strlen(string2); i++)
		{
			if (string2[i] == replace[j])
			{
				copystring2[i] = with[j];
			}
		}
	}
	return strcmp(copystring1, copystring2);

}