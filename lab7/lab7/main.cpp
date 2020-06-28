//
//  main.cpp
//  lab7
//
//  Created by Vincent on 12/17/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void wordCount(char *);
void lineCount(char *);
int main(int argc, const char * argv[]) {
    // insert code here...
   
    string line,str;
    ifstream myfile("/Users/Chin/Desktop/computer programming/picasso.txt");
    string content( (istreambuf_iterator<char>(myfile) ),
                   (istreambuf_iterator<char>()    ) );
    int n = content.length();
    char char_array[n + 1];
    strcpy(char_array, content.c_str());
    
    //for (int i = 0; i < n; i++)
        //cout << char_array[i];

    cout << "The number of words in the entered string is:  ";
    wordCount(char_array);
    cout<<endl<<"The number of lines: ";
    lineCount(char_array);
    /*if(myfile.is_open()){
       while(getline(myfile,line)){
           str = line;
        }
        cout<< str;
        myfile.close();
    }
    else
        cout<<"noooooo";*/
    
    return 0;
}
void wordCount(char *string)
{
    int numWords = 0;
    while(*string != '\0')
    {
        if(*string == ' ')
            numWords++;
        string++;
    }
    cout << numWords;

}
void lineCount(char *string)
{
    int numLines = 0;
    while(*string != '\0')
    {
        if(*string == '\n')
            numLines++;
        string++;
    }
    cout << numLines-1;
    
}
