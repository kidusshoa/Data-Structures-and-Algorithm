#include <iostream>
using namespace std;
int array[5];
int front= -1;
int rear= -1;

void display(){
    cout<<"======================\n";
    if(front==-1||front>rear){
        cout<<" queue is empty"<<endl;
    }
    else{
        cout<<" front->  ";
        for(int i=front; i<=rear; i++){
            cout<<"|"<< array[i]<<"|"<<endl<<"\t";
        }
        cout<<"<- rear\n";
    }
}

void enqueue(){
    int element;
    cout<<"Enter value you want to push on the queue = ";
    cin >> element;
    if(rear<4){
        if(front==-1){
            front++;
        }
        rear++;
        array[rear]= element;
        cout<<" Elemet is insereted to the queue successfully"<<endl;
        display();
    }else{
        cout<<" stack overflow"<<endl;

    }
}

void dequeue(){
    if(front == -1 || front > rear){
        cout<<" Queue is underflow\n";
    }else{
        cout<<array[front]<<"removed from the top of the queue\n";
        front++;
        display();
    }
}
bool isfull(){
    if(rear ==4){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
}
bool isempty(){
    if(front ==-1){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
}

int main(){
    while(1){
        cout <<"Queue operation menu driven \n";
        cout <<"Press 1 to enqueue element to the top of the stack\n"; 
        cout <<"Press 2 to to diplay the elemets of the stack\n"; 
        cout <<"Press 3 to dequeue element from the top of the stack\n";
        cout <<"Press 4 is the queue full\n";
        cout <<"Press 5 is the queue empty\n";
        int ch;
        cout <<"Enter your choice now = ";
        cin>>ch;
        switch(ch){
            case 1: enqueue(); break;
            case 2: display(); break;
            case 3: dequeue(); break;
            case 4: isfull(); break;
            case 5: isempty(); break;
        }
    }
}