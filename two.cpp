#include <iostream>
using namespace std;

int def(int x, int &y){
     
    return x+y;
}  

int main(){
    int x, y;
    x = 10;
    y = x+10;
     def(x, y);
    if(y=100){
        cout<<y<<endl;
    }else{
        def(x, y);
        cout<<y<<endl;
    }
    
    return 0;  
}