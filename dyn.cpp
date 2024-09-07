#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14;


int main(){
    int b = 96;
    cout << b << "\t"<<&b<<endl;
    int *a = new int(5);
    cout<<*a<<"\t"<<a;
    delete a;
}