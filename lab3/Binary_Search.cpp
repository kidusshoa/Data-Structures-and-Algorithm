#include <iostream>
using namespace std;
int binarysearch(string ar[], int n, string sk){
    int mid, li=0, upi = n -1;
    while(li<=upi){
        mid = (li+upi)/2;
        if (sk == ar[mid]){
            return mid;
        }
        else if(sk<ar[mid]){
            upi = mid-1;
        }
        else{
            li=mid+1;
        }
        
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
        int res = binarysearch(array,size,searchkey);
        if (res != -1){
            cout<<"element is found at array["<<res<<"]\n";
        }
        else {
            cout<<"element is not found in the array list \n";
        }
    }
}