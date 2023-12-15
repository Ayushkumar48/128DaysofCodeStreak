#include<iostream>
#include<algorithm>
using namespace std;
int linear(int arr[],int key){
    for (int i = 0; i < 6; i++)
    {
        if (arr[i]==key)
        {
            return i;
        }
        
        
    }
    return -1;
}

int binary(int arr[], int key, int len){
    int start=0;
    int end=len-1;
    int mid=(start+end)/2;
    for (int i = 0; i < len; i++)
    {
        
        if (key==arr[mid])
        {
            return mid;
        }
        
        else if (key<arr[mid])
        {
            end=mid-1;
            mid=(start+end)/2;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
            mid=(start+end)/2;
        }
        
    }
    return -1;
    
    
    
}

void selectionSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            
            if (arr[j]<arr[i])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
            
        }
        
    }
    
}
void bubbleSort(int arr[],int n){
    int counter=1;
    while (counter<n)
    {
        for (int i = 0; i < n-counter; i++)
        {
            if (arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            
        }
        counter++;
        
    }
    
}
int main(){
    int arr[6]={12,18,20,42,8,10};
    int len=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+len);
    cout<<binary(arr,42,len);
    cout<<linear(arr,19);
    int arr[]={12,18,20,42,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    bubbleSort(arr,n);
    for (int i = 0; i < n-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}