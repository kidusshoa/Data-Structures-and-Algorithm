#include <iostream>
using namespace std;
int array[5];
int top= -1;

void display(){
    cout<<"======================\n";
    if(top==-1){
        cout<<" Stack is empty"<<endl;
    }
    else{
        cout<<" Top->  ";
        for(int i=top; i>=0; i--){
            cout<<"|"<< array[i]<<"|"<<endl<<"\t";
        }
    }
}

void push(){
    int element;
    cout<<"Enter value you want to push on the stack = ";
    cin >> element;
    if(top<4){
        top++;
        array[top]= element;
        cout<<" ";
        display();
    }else{
        cout<<" stack overflow"<<endl;

    }
}

void pop(){
    if(top == -1){
        cout<<" Stack is underflow\n";
    }else{
        cout<<array[top]<<"removed from the top of the stack\n";
        top--;
        display();
    }
}
bool isfull(){
    if(top ==4){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
}
bool isempty(){
    if(top ==-1){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
}

int main(){
    while(1){
        cout <<"Stack operation menu driven \n";
        cout <<"Press 1 to push element to the top of the stack\n"; 
        cout <<"Press 2 to to diplay the elemets of the stack\n"; 
        cout <<"Press 3 to pop element from the top of the stack\n";
        cout <<"Press 4 is the stack full\n";
        cout <<"Press 5 is the stack empty\n";
        int ch;
        cout <<"Enter your choice now = ";
        cin>>ch;
        switch(ch){
            case 1: push(); break;
            case 2: display(); break;
            case 3: pop(); break;
            case 4: isfull(); break;
            case 5: isempty(); break;
        }
    }
}