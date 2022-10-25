#include <iostream>
#include <vector>
using namespace std;
int main(){
    string sntnc , word="";
    vector<string> newSntnc;
    cout<<"enter the sentence"<<endl;
    getline(cin, sntnc);
    for (int i=0 ; i<sntnc.length(); i++)
    {
        
        word = word+sntnc[i];
        if (sntnc[i+1]==' ' or i==sntnc.length()-1){
            newSntnc.push_back(word);
            if(word=="he")
            newSntnc.push_back("or she");
            else if (word=="He")
            newSntnc.push_back("or She");
            else if (word=="him")
            newSntnc.push_back("or her");
            else if (word=="Him")
            newSntnc.push_back("or Her");
            else if (word=="him.")
            newSntnc.push_back("or her.");
            else if (word=="Him.")
            newSntnc.push_back("or Her.");
            i++;
            word="";
        }

    }
    for(int i =0; i<newSntnc.size();i++)
    {

        cout<<newSntnc[i]<<" ";
    }


}