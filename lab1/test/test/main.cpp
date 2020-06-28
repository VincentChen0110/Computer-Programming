//
//  main.cpp
//  test
//
//  Created by Vincent on 10/3/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){

int largest = pow(2, 15)-1;
cout << "Assigning NUM = largest + 1" << endl;
printf("Largest integer in 16 bits (in INT) is: %d\n", largest);
int NUM = (largest + 1);
cout << "Display NUM in SHORT INT: " << (short) NUM << endl; //

cout << "Display NUM in INT: " << NUM << endl;

cout << right << setw(30);
cout << setprecision(8);
cout << float(NUM) << endl;
}
