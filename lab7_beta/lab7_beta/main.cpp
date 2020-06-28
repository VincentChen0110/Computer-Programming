//
//  main.cpp
//  lab7_beta
//
//  Created by Vincent on 12/19/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

//#define VERBOSE 0
using namespace std;

class name_freq_pair{
public:
    string name;
    int freq;
};

void process_a_line(string ,map<string,int>&);
void print_word_array(vector<name_freq_pair>& , int);
int myfunction(name_freq_pair &p1, name_freq_pair &p2){
    return (p1.freq>p2.freq);
}

int main(int argc,  char * argv[])
{
    if (argc<2){
        cout << "Too few arguments" << endl; return(-1);
        //printf("Usage: %s <filename>\n", argv[0]);
    }
    //ifstream in_fp(argv[1], ios::in);
    //if(! in_fp) {
       // cout << "Input file " << argv[1] << " is not valid\n" <<endl; return(0);
        
    //}
    //printf("%s %s\n", argv[0], argv[1]);
    ifstream in_fp("/Users/Chin/Desktop/computer programming/picasso.txt");
    string cpp_line;
    int line_count = 0;
    map<string,int> book;
    map<string,int>::iterator it;
    getline(in_fp,cpp_line);
    //if(VERBOSE>0){ cout << cpp_line << endl; }
    while(!cpp_line.empty()){
        process_a_line(cpp_line, book);
        line_count++;
        getline(in_fp, cpp_line);
        
        }
    
        cout << "Total no. of lines: " << line_count-1 << endl;
    //vector
    vector<name_freq_pair> A;
    name_freq_pair p;
    for(it=book.begin(); it!=book.end(); it++){
        // word and its count
        //if(VERBOSE>0){ cout << it->first << " " << it->second << endl; }
        p.name = it->first;
        p.freq = it->second;
        A.push_back(p);
    }
    printf("The total number of words : %lu\n", A.size()-1);
    sort(A.begin(), A.end(),myfunction);
    print_word_array(A, 10);
          return 0;
}
void process_a_line(string cpp_line,map<string,int>& book){
    char c_line[100000], *word;
    string cpp_word;
    map<string,int>::iterator it;
    strcpy(c_line,cpp_line.c_str());
    word = strtok(c_line, "\"-,:;.() ");
    while(word != 0){
        cpp_word = word;
        it = book.find(cpp_word);
        if(it != book.end()){
        // An existing word
        it->second = (it->second)+1;
        }
        else {// A new word
            book[cpp_word]=1;
        }
        word = strtok(NULL, "\"-,:;.() ");
        
    }
                  
}
void print_word_array(vector<name_freq_pair>& A, int top){
    int i;
    for(i=0; i<top && i<(int) A.size(); i++){
        printf("The %d-th frequent word is (%s) with no. of appearances(%d)\n", i, A[i].name.c_str(), A[i].freq); }
}

