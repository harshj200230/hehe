#include<iostream>
using namespace std;

int main(){
    int * arr = new int[5];
    cin>>*arr;
    cout<<*arr;
    arr++;
    cin>>*arr;
    cout<<*arr;
    return 0;
}