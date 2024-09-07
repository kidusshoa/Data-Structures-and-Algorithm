#include <iostream>
using namespace std;
 string array[]={"kidus", "yasub", "yasub", "yosef", "beza"};
 
void ret(){
  for (int i = 7; i >=0 ; i--)
      
      {
        if(array[i] == array[i-1]){
            cout<<array[i]<<" "<<array[i-1]<<endl;
        }
      }
      
}
int main(){
 ret();    
       
}