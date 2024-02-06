/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream> //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std;  //Libraries compiled under std


#include "CMovie.h"
#include "MovieInfoSturc.h"
#include<fstream>
#include <string>


CMovie::~CMovie(){
    //Clean Up the Dynamic Stuff
    delete [] movies->mveInfo;//Now the array of Structures
    delete movies;//Now deallocate the final Movie Structure
}

//Just copy, cut, and paste into a function.  Code already checked out in main.
void CMovie::display(){
    
    
    fstream txtFile("TESTTEX.txt");
    
        for(int mvees=0;mvees<movies->nMovies;mvees++){
        //I copied the output from Code-E then applied formatting
        txtFile<<setw(11)<<"Title:"<<movies->mveInfo[mvees].movName<< endl;
        txtFile<<setw(11)<<"Director:"<<movies->mveInfo[mvees].dirName<< endl;
        txtFile<<setw(11)<<"Year:"<<movies->mveInfo[mvees].yrRlsd<<endl;
        txtFile<<setw(11)<<"Length:"<<movies->mveInfo[mvees].runTime<<endl;
    }
    int find=0;
    cout << "Enter the position information you would like to see\n" ;
    cin >> find;
    while(find > movies->nMovies || find < 0)
    {
        cout << "This number is to large to fins in the file\n";
        cin >> find;
    }
    ifstream rf("BinaryFileForMovies.bin",ios :: in | ios::binary);
    
    int XM=12,XD=17;
    
       MovieInfo newstruct[movies->nMovies];
   for(int i = 0; i < movies->nMovies; i++)
   {
       if(i == 10 || i == 100 || i== 1000 || i == 10000)
       {
           XM += 1;
           XD += 1;
       }
        rf.read(reinterpret_cast<char*> (&newstruct[i].movName), XM);
        rf.read(reinterpret_cast<char*> (&newstruct[i].dirName), XD);
        rf.read(reinterpret_cast<char*> (&newstruct[i].yrRlsd), sizeof(unsigned short));
        rf.read(reinterpret_cast<char*> (&newstruct[i].runTime), sizeof(unsigned short));
      
   }
   rf.close();
   

        cout << newstruct[find].movName << endl;
        cout << newstruct[find].dirName << endl;
        cout << newstruct[find].yrRlsd << endl;
        cout << newstruct[find].runTime << endl;

       //Now you can loop on the data as many times as it takes!
//    for(int mvees=0;mvees<movies->nMovies;mvees++){
//        //I copied the output from Code-E then applied formatting
//        cout<<left<<endl;
//        cout<<setw(11)<<"Title:"<<movies->mveInfo[mvees].movName<<endl;
//        cout<<setw(11)<<"Director:"<<movies->mveInfo[mvees].dirName<<endl;
//        cout<<setw(11)<<"Year:"<<movies->mveInfo[mvees].yrRlsd<<endl;
//        cout<<setw(11)<<"Length:"<<movies->mveInfo[mvees].runTime<<endl;
//    }


    
    


}

CMovie CMovie::operator=(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;            
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        movies->mveInfo[mvees].movName=obj.movies->mveInfo[mvees].movName;
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        movies->mveInfo[mvees].dirName=obj.movies->mveInfo[mvees].dirName;
        movies->mveInfo[mvees].yrRlsd=obj.movies->mveInfo[mvees].yrRlsd;
        movies->mveInfo[mvees].runTime=obj.movies->mveInfo[mvees].runTime;
    }   
    
    return *this;
}

CMovie::CMovie(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;            
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        movies->mveInfo[mvees].movName=obj.movies->mveInfo[mvees].movName;
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        movies->mveInfo[mvees].dirName=obj.movies->mveInfo[mvees].dirName;
        movies->mveInfo[mvees].yrRlsd=obj.movies->mveInfo[mvees].yrRlsd;
        movies->mveInfo[mvees].runTime=obj.movies->mveInfo[mvees].runTime;
    }    
}

//This implementation of this function was thoroughly tested out already
//in main.
CMovie::CMovie(){
    
    ofstream binfile, txtFile;
    
    binfile.open("BinaryFileForMovies.bin",ios :: binary);
    txtFile.open("TESTTEX.txt");
    if(!binfile || !txtFile)
    {
        cout << "FAIL TO OPEN THE FILES" << endl;
    }
    
    //Declare the Structure array
    movies=new Movies;
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>movies->nMovies;                //Integer Read
    
//    Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies]; 


    for(int mvees=0;mvees<movies->nMovies;mvees++){
        
        
        movies->mveInfo[mvees].movName = "Test Movie " + to_string(mvees);
        movies->mveInfo[mvees].dirName = "Eduardo Murillo " + to_string(mvees);
        movies->mveInfo[mvees].yrRlsd = 1890+mvees;
        movies->mveInfo[mvees].runTime = 10+mvees;   
        }
        
    for(int i = 0 ; i  < movies->nMovies ; i ++)
    {
        int sizeMov=0,sizeDir=0;
        sizeMov = movies->mveInfo[i].movName.size();
        sizeDir = movies->mveInfo[i].dirName.size();
                
        binfile.write(reinterpret_cast<char*>(&movies->mveInfo[i].movName),  sizeMov);
        binfile.write(reinterpret_cast<char*>(&movies->mveInfo[i].dirName),  sizeDir);
        binfile.write(reinterpret_cast<char*>(&movies->mveInfo[i].yrRlsd), sizeof(unsigned short));
        binfile.write(reinterpret_cast<char*>(&movies->mveInfo[i].runTime),  sizeof(unsigned short));   
    }
    cout << movies->nMovies <<" were stored in binary and text files." << endl;
    binfile.close();
    txtFile.close();
}