#include <iostream>
using namespace std;
int mani(){
    char base[8] = {(char)'A',(char) 'B',(char) 'C',(char) 'D',(char) 'D',(char) 'D',(char) 'E',(char) 'F'};
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