//
//  main.cpp
//  lab8
//
//  Created by Vincent on 12/26/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if (x % y == 0) //base case
        return y;
    else if (y % x ==0)
        return (x);
    if(x>y)
        return(gcd(y, x%y)); // x is larger
    else
        return(gcd(x, y%x)); // y is larger
}

int find_gcd(int A[],int n)
{
    int result = A[0];
    for (int i = 0; i<n; i++){
        result = gcd(A[i],result);
        if (result == 1)
            return 1;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[5] ;//= {102, 340, 153, 187, 425};
    for(int i = 0; i<5; i++ ){
        cin>> A[i];
    }
    int n = 5;
    cout << "The final gcd of {";
    for(int i = 0;i<5;i++)
        cout<<A[i]<<",";
    cout <<"} is: "<< find_gcd(A,n)<<endl;
    //for(int i = 0;i<5;i++)
        //cout<<A[i]<<" ";
    return 0;
}

