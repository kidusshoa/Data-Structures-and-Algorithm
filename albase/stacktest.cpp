#include <iostream>
using namespace std;
int array[10];
int Top = -1;
 
void display(){
    if(Top == -1){
        cout <<"stack is underflow \n";
    }else{
        for(int i=Top;i>-1;i--){
            cout <<array[i] <<endl;
    }
}}

void push(){
    if(Top >= 9){
        cout <<"stack is overflow \n";
    }else{
        int element;
        Top++;
        cout<< "enter an element u want to add \n";
        cin >> element;
        array[Top]=element;
        
    }
}

void Pop(){
    if(Top == -1){
        cout <<"stack is underflow \n";
    }else{
        Top--;
    }
}

int main(){
   while(1){
    int a;
    cout<<"choose an operation \n";
    cin>>a;
    if(a ==1){
        display();
    }else if(a ==2){
        push();
    }else{
        Pop();
    }
   }
}