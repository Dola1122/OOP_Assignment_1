#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;
int main(){
    int numberOfLine=0,x=0, chose;
    fstream File1 , File2;
    string line1 , line2, ch1, ch2;
    char FileName1[80], FileName2[80];
    cout<<"enter the name of the first file"<<endl;
    cin.getline(FileName1 , 80);
    strcat(FileName1 , ".txt");
    cout<<"enter the name of the Second file"<<endl;
    cin.getline(FileName2 , 80);
    strcat(FileName2 , ".txt");
    File1.open(FileName1, ios::in | ios::out);
    File2.open(FileName2, ios::in | ios::out);
    cout<<"chosse from the following the type of copmarison"<<endl;
    cout<<"1- by character"<<endl;
    cout<<"2- by word"<<endl;
    cin>>chose;

    if(chose==1){
 
     while(!File1.eof() and !File2.eof()){
        getline(File1 , line1);
        getline(File2 , line2);
        numberOfLine++;
        for (int i =0 ; i<line1.length(); i++){
            if(line1[i]!=line2[i]){
                cout<<"The content of the first different line is "<<line1<<endl;
                cout<<"the number of the line is "<<numberOfLine<<endl;
                x=1;
                break;
            }
        }
        if(x==1)
        break;
        
    }
    if(x==0)
    cout<<"the files is identical"<<endl;


    }


    else if (chose=2){
       
      while(!File1.eof() or !File2.eof()){
        getline(File1 , line1);
        getline(File2 , line2);
        stringstream s1(line1) ;
        stringstream s2(line2);
        while(s1 and s2){
            s1>>ch1;
            s2>>ch2;
            
             if(ch1!=ch2){
                cout<<"the first different word is "<<ch1<<endl;
                cout<<"the content of the line that contains the first diffrenet word is "<<line1<<endl;
                x=1;
                break;
            }
            if(x==1)
            break;
        }
        if(x==1)
        break;
    }
    if(x==0){
        cout<<"the files are identical"<<endl;
    }
    
    }
    

}