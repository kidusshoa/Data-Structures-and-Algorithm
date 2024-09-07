#include <iostream>
using namespace std;
int selection_sort(int arr[], int size){
for(int i=0; i<size; i++){
            int smallest = i;
            for(int j=i+1; j<size; j++){
                if(arr[j]<arr[smallest]){
                    smallest=j;
                }  
            }
             swap(arr[i], arr[smallest]);
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
        selection_sort(array, size);
        cout<<"\n after sort array elements : \n";
        for(int i=0; i<size; i++){
            cout<<array[i]<<"\t";
        }
}