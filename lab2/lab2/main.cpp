//
//  main.cpp
//  lab2
//
//  Created by Vincent on 9/12/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    double a,b,c;
    cout << "Please enter three types of wavelength";
    cin >>a >> b >>c ;
    if (a < 1e-11){
        cout <<"The first is Gamma Rays "<<a<<"\n";}
    else if (1e-11 <=a && a <1e-8){
        cout <<"The first is X Rays "<<a<<"\n";}
    else if (1e-8 <=a && a <4e-7){
        cout <<"The first is Ultraviolet "<<a<<"\n";}
    else if (4e-7 <=a && a <7e-7){
        cout <<"The first is Visible light "<<a<<"\n";}
    else if (7e-7 <=a && a <1e-3){
        cout <<"The first is Infared "<<a<<"\n";}
    else if (1e-3 <=a && a <1e-2){
        cout <<"The first is Microwaves "<<a<<"\n";}
    else if (1e-2 <=a ){
        cout <<"The first is Radiowaves "<<a<<"\n";}
    
    if (b < 1e-11){
        cout <<"The second is Gamma Rays "<<b<<"\n";}
    else if (1e-11 <=b && b <1e-8){
        cout <<"The second is X Rays "<<b<<"\n";}
    else if (1e-8 <=b && b <4e-7){
        cout <<"The second is Ultraviolet "<<b<<"\n";}
    else if (4e-7 <=b && b <7e-7){
        cout <<"The second is Visible light "<<b<<"\n";}
    else if (7e-7 <=b && b <1e-3){
        cout <<"The second is Infared "<<b<<"\n";}
    else if (1e-3 <=b && b <1e-2){
        cout <<"The second is Microwaves "<<b<<"\n";}
    else if (1e-2 <=b ){
        cout <<"The second is Radiowaves "<<b<<"\n";}

    if (c < 1e-11){
        cout <<"The Third is Gamma Rays "<<c<<"\n";}
    else if (1e-11 <=c && c <1e-8){
        cout <<"The Third is X Rays "<<c<<"\n";}
    else if (1e-8 <=c && c <4e-7){
        cout <<"The Third is Ultraviolet "<<c<<"\n";}
    else if (4e-7 <=c && c <7e-7){
        cout <<"The Third is Visible light "<<c<<"\n";}
    else if (7e-7 <=c && c <1e-3){
        cout <<"The Third is Infared "<<c<<"\n";}
    else if (1e-3 <=c && c <1e-2){
        cout <<"The Third is Microwaves "<<c<<"\n";}
    else if (1e-2 <=c ){
        cout <<"The Third is Radiowaves "<<c<<"\n";}

    return 0;
}
