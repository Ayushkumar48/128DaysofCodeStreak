#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Find if array is sorted using recursion.
bool isSorted(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans =isSorted(arr+1,n-1); 
        return ans;
    }
}



// Linear Search using recursion

int linearSearch(int arr[], int n, int key){
    if(n==0){
        return -1;
    }
    if(arr[n-1]==key){
        return n-1;
    }
    else{
        return linearSearch(arr,n-1,key);
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    cout<<linearSearch(arr,n,3);
    cout<<isSorted(arr,n);
    return 0;
}
