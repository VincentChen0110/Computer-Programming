//
//  main.cpp
//  class1
//
//  Created by Vincent on 9/12/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
void show_string(HANDLE&, int, int, string);
void clear_screen(HANDLE&, int, int);
void sleep(int);
class complex { private:
    double real;
    double imaginary; public:
    complex(double re = 0.0, double im =0.0){
        real = re;
        imaginary = im; }
    void set_a_complex(double re, double im){
        real = re;
        imaginary = im; }
    double get_real(){ return(real);}
    double get_imaginary(){ return(imaginary);}
    complex operator+(complex x){
        complex sum;
        double final_real = this->get_real() + x.get_real(); double final_imaginary = this->get_imaginary() +
        x.get_imaginary();
        sum.set_a_complex(final_real, final_imaginary);
        return(sum); }
    int operator==(complex& b){
        bool if_eq = (this->get_real()==b.get_real() && this->get_imaginary()==b.get_imaginary());
        return(if_eq); }
    // overload << as a regular function
    // Function Prototype + Function Definition
    ostream& operator<<(ostream& os, complex &x){
        os << "complex number: " << x.get_real() << " + j " <<
        x.get_imaginary() << endl;
        return(os);
        int main()
        complex a(1, 2), b(10, 20) ; a.set_a_complex(1, 2); b.set_a_complex(1, 2);
        cout << "Checking if a is equal to b: " << (a==b) << endl;
        complex sum = a + b;
        cout << a << b << sum;
        /*----------- Display character in a particular position on the screen
         --------*/
        HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
        clear_screen(screen, 20, 100);
        for(int k=0; k<11; k++){ show_string(screen, k, k, "x");
        }
        1 2
