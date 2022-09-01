#include<iostream>
using namespace std;


int main()
{
    int basic = 5;
    int *basicptr = &basic;
    
    cout << "basicptr = " << basicptr<<endl;
    cout << "*basicptr = " << *basicptr<<endl;
    basic = basic + *basicptr;
    cout << "basic = " << basic<<endl;
    cout << "*basicptr = " << *basicptr<<endl;
    return 0;
}