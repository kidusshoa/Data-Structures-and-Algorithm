#include <iostream>
#include <string>
using namespace std;


struct Shape {
    double length;
    double width;
    double radius;

    double calculateRectangleArea() {
        return length * width;
    }

    
    double calculateCircleArea() {
        return 3.14 * radius * radius;
    }
};

void print (){
 //char* name = "kidus";
 string st = "Hello class this sring literall";
 char ch[]= "hello class this is string arr of cha";
 char *p = "Hello class this is string usig pointer";
    //cout<< name <<endl;
    cout << st << "\n" << ch<<endl;
}

void base11() {
    int arr[5] = {1, 2, 3, 4, 5};  

    int* ptr = arr;  

    cout << *(ptr + 2) << endl; 
 
}

void base12() {
    char matrix[3][4] = {"kid", "bid", "naf"};  

    char* ptr = &matrix[0][0];  

    cout << *(ptr + 4) << endl; 
    for (int i =0; i <=2; i++){
        cout<<*(ptr + i) ;
    }
}

void base2(){
    int* ptr = nullptr;
    /*
    A null pointer is a pointer which points nothing.
    Some uses of the null pointer are: 
    a) To initialize a pointer variable when that pointer
    variable isn't assigned any valid memory address yet. 
    b) To pass a null pointer to a function argument when 
    we don't want to pass any valid memory address.
    */
}

void base3() {
    // Dynamic Array
    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;

    int* dynamicArray = new int[size];  // Creating dynamic array

    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i + 1;  // Assigning values to the dynamic array
    }

    cout << "Dynamic Array: ";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << " ";  // Printing dynamic array elements
    }
    cout << endl;

    delete[] dynamicArray;  // Deallocating dynamic array memory

    // Static Array
    const int staticSize = 5;
    int staticArray[staticSize] = {1, 2, 3, 4, 5};  // Creating static array

    cout << "Static Array: ";
    for (int i = 0; i < staticSize; i++) {
        cout << staticArray[i] << " ";  // Printing static array elements
    }
    cout << endl;

    // Dynamic Variable
    int* dynamicVariable = new int;  // Creating dynamic variable

    *dynamicVariable = 10;  // Assigning a value to the dynamic variable

    cout << "Dynamic Variable: " << *dynamicVariable << endl;  // Printing dynamic variable value

    delete dynamicVariable;  // Deallocating dynamic variable memory
}

void base4() {
    Shape rectangle;
    rectangle.length = 5.0;
    rectangle.width = 3.0;

    Shape circle;
    circle.radius = 2.5;

    cout << "Rectangle Area: " << rectangle.calculateRectangleArea() << endl;
    cout << "Circle Area: " << circle.calculateCircleArea() << endl;
}
int main(){
     cout <<"hello world" << endl;
     base4();
    return 0;
}

