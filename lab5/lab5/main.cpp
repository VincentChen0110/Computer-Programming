//
//  main.cpp
//  lab5
//
//  Created by Vincent on 11/18/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    char word[] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
        'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
    char c;
    while (cin.get(c)){
        c = tolower(c);
        if (c == ' ')
            cout<< c;
        else if (c =='\n')
            cout<<endl;
        else if (c =='`')
            cout<<'-';
        else if (c =='1')
            cout<<'=';
        else if (c =='q')
            cout<<']';
        else if (c =='w')
            cout<<'\\';
        else if (c =='s')
            cout<<';';
        else if (c =='a')
            cout<<';';
        else if (c =='z')
            cout<<'.';
        else if (c =='x')
                cout<<'/';
        else if (c =='<')
            cout<<'n';
        else if (c =='>')
            cout<<'m';
        else if (c ==':')
            cout<<'k';
        else if (c =='"')
            cout<<'l';
        else if (c =='{')
            cout<<'o';
        else if (c =='}')
            cout<<'p';

        else{
            for (int i = 0; i < 47; i++){
                if (word[i] == c){
                    cout<<word[i-2];
                }
            }
            }
    }
    return 0;
}

