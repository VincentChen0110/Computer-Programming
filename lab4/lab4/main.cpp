//
//  main.cpp
//  lab4
//
//  Created by Vincent on 10/21/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int i,n;
    int sum = 0;
    cin >> i >> n;
    while(sum<n){
        sum += i;
        i++;
        }
    cout<<i-1;
    return 0;
}
