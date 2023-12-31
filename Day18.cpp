#include <iostream>

using namespace std;

void swap(int *a, int *b, int arr[]){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int x=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[x])
            {
                x=j;
            }
        }
        swap(&arr[x], &arr[i], arr);
    }
}


void bubbleSort(int arr[]){
    bool swapped;
    
    for (int i = 0; i < 5; i++)
    {
        swapped=false;
        for (int j = 0; j < 5-i; j++)
        {
            if (arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                swapped=true;
            }
            
        }
        if (swapped==false)
        {
            break;
        }
        
        
    }
    
}
int main()
{
    int arr[]={3,1,5,4,2};
    int n=5;
    bubbleSort(arr);
    selectionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    
    return 0;
}
