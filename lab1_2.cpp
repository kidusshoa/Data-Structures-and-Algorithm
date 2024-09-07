//overloading volume of sphere, cylinder and cone
// vsph = v= 4/3 pi r3,  vcy = c=pir2*h,  vco = 1/3 pir2 *h

#include <iostream>
using namespace std;

void volume(double PI, double r, double base){
    double vsph = base * PI * r * r * r;
    cout<< vsph<<endl;
}

void volume(double PI, double r, double h, double base){
    double vcy = base * PI * r * r * h;
    cout<< vcy<<endl;
}

void volume(double PI, double r, double h, float base2){
    double vco = base2 * PI * r * r * h;
    cout<< vco<<endl;
}
int main(){
    double r, h;
    double PI = 3.14159;
    double base = (4.0/3.0);
    float base2 = (1.0/3.0);
    cout<<"enter radius"<<endl;
    cin >>r;
    cout<<"enter height"<<endl;
    cin >>h;
    cout<<"volume of sphere is ";volume(PI, r, base);
    cout<<"volume of cylinder is ";volume(PI, r, h, base);
    cout<<"volume of cone is ";volume(PI, r, h, base2);
    

    return 0;
}
