#include <iostream>
using namespace std;

struct funmember {
    int a;
    double b;
    double function (int c, int d){
        cout<<c+d;
    }

};

int main(){
    funmember s, d;
    s.a=45;
    s.b=6.5;
    d.a=20;
    d.b=3.5;
    s.function(s.a,s.b);
    d.function(d.a,d.b);

}