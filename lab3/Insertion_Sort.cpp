#include <iostream>
using namespace std;
int insertion_sort(int arr[], int size){
for(int i=0; i<size; i++){
            int temp = arr[i];
            for(int j=i; j>0 && temp <arr[j-1]; j--){
                swap(arr[j], arr[j-1]);
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
        insertion_sort(array, size);
        cout<<"\n after sort array elements : \n";
        for(int i=0; i<size; i++){
            cout<<array[i]<<"\t";
        }

}