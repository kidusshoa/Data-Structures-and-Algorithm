#include <iostream>
using namespace std;

void ref(int &x, int &y){
    x = x + y;
    y = x - y;
    x = x - y;
}
int def(int x, int y, int z=10){
    return x + y + z;
}

string name (string bekele){
   return bekele;
}
int main(){
  //int x, y;
  //int f=20;
  //cout << "Enter two numbers\n";
  //cin >> x;
  //cin >> y;
  //ref(x, y);
  //cout << x << " " << y << endl;
  //cout<< def(x,y,f)<<endl;
  //cout<< def(x,y)<<endl;
  //string Name;
   //cout<<"name = ";
   //cin>>Name;
   //cout<<name(Name)<<endl;



    char base[8] = {(char)'A',(char) 'B',(char) 'C',(char) 'E',(char) 'E',(char) 'D',(char) 'E',(char) 'F'};
    char longest[8];
    for (int x =0; x< 8; x++){
        if(base[x]== base[x+1]){
    longest[x] = base[x];
    longest[x+1] = base[x+1];
        }
        cout<<longest[4]<<endl;
    }
    return 0;
}   
