#include <iostream>
using namespace std;
int linear_search(string arr[], int n, string sk){
    for(int i=0; i<n; i++){
        if(sk == arr[i])
        return i;
    }
    return -1;
}
int main(){
    int size = 5;
    string array[size];
    cout<<"Enter array elements : \n";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    while(1){
        string searchkey;
        cout<<"Enter an element u going to be search = ";
        cin>>searchkey;
        int res = linear_search(array,size,searchkey);
        if (res != -1){
            cout<<"element is found at array["<<res<<"]\n";
        }
        else {
            cout<<"element is not found in the array list \n";
        }
    }
}