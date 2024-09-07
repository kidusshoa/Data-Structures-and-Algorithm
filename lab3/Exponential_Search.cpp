#include <iostream>
using namespace std;
int binarysearch(int ar[], int li, int upi, int sk){
    
    while(li<=upi){
        int mid = (li+upi)/2;
        if (sk == ar[mid]){
            return mid;
        }
        else if(sk<ar[mid]){
            return binarysearch(ar,li, mid-1, sk);
        }
        else{
            return binarysearch(ar, mid+1, upi, sk);
        }
        
    }
    return -1;
}

int exponentialsearch(int array[], int size, int sk){
  if (sk == array[0]){
    return 0;
  }
  int i =1;
  while(i< size &&array[i]<=sk ){
    i=i*2;
  }
  return binarysearch(array,i/2,min(i,size-1),sk);
}
int main(){
int size = 5;
    int array[size];
    cout<<"Enter array elements : \n";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    while(1){
        int searchkey;
        cout<<"Enter an element u going to be search = ";
        cin>>searchkey;
        int res = exponentialsearch(array,size,searchkey);
        if (res != -1){
            cout<<"element is found at array["<<res<<"]\n";
        }
        else {
            cout<<"element is not found in the array list \n";
        }
    }
}