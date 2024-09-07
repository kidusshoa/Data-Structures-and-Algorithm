#include <iostream>-
using namespace std;
int buble_sort(int arr[], int size){
for(int i=0; i<size; i++){
            for(int j=0; j<size-1; j++){
                if(arr[j]>arr[j+1]){
                      swap(arr[j], arr[j+1]);
                }  
            }
           
        }
}
int main(){
      int size = 5;
    int array[size];
    cout<<"Enter array elements : \n";
    for(int i=0; i<size; i++){
        cin>>array[i];}
        cout<<"\n before sort array elements : \n";
        for(int i=0; i<size; i++){
            cout<<array[i]<<"\t";
        }
        buble_sort(array, size);
        cout<<"\n after sort array elements : \n";
        for(int i=0; i<size; i++){
            cout<<array[i]<<"\t";
        }
}