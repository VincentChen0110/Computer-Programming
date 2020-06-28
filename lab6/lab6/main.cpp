//
//  main.cpp
//  lab6
//
//  Created by Vincent on 11/29/19.
//  Copyright © 2019 Vincent. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class complex_number {
private:
    double real, imaginary;
public:
   // double re, img;
    complex_number(double re = 0.0, double im =0.0){
        real = re;
        imaginary = im; }
    int size = 7;
    void show_array(string a[], int size){
        for (int i = 0;i < size;i++){
            cout<<a[i]<<" ";
        }
        cout<< endl;
};
    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    };
    void bubbleSort(int m[], int size)
    {
        for (int i = 0; i < size-1; i++){
            
            for (int j = 0; j < size-i-1; j++){
                if (m[j] > m[j+1])
                    swap(&m[j], &m[j+1]);
            }
        }
    };
    void input_array(string a[]){
        for (int i = 0;i<size;i++)
            cin>>a[i];
    };
    void magnitude(string a[],int m[]){
        for(int i = 0;i<size;i++){

            m[i]=pow(a[i][0]-48,2)+pow(a[i][3]-48,2);
        }
    };
    void point_answer(string a[],int size,int m[]){
        for(int i = 0;i<size;i++)
            if(pow(a[i][0]-48,2)+pow(a[i][3]-48,2)==m[3])
                cout<<"Median: "<<a[i];
    }
};
int main(int argc, const char * argv[]) {
    complex_number num;
    const int size = 7;
    string a[size];
    int m[size];
    num.input_array(a);
    num.magnitude(a,m);
    cout<<"Original Array: "<<endl;
    num.show_array(a,size);
    num.bubbleSort(m,size);
    num.point_answer(a,size,m);
    //cout << "Hello, World!\n";
    //2+j7 4+j0 9+j4 8+j8 2+j4 5+j5 3+j2cout<<" "<<a[1][0]<<" "<<a[2][0]<<endl<<m[3]<<endl;
    return 0;
}
