#include <iostream>
#include <array>
using namespace std;

int ceiling(int arr[],int n,int t){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    while(s<=e)
    {
        if (t>arr[n-1])
        {
            return -1;
        }
        if (t==arr[m])
        {
            return arr[m];
        }
        else if(t<arr[m])
        {
            e=m-1;
            m=s+(e-s)/2;
        }
        else if (t>arr[m])
        {
            s=m+1;
            m=s+(e-s)/2;
        }
    }
    return arr[s];
    
}
int floor(int arr[],int n,int t){
    if (t<arr[0])
    {
        return -1;
    }
    
    
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    while(s<=e)
    {
        if (t==arr[m])
        {
            return arr[m];
        }
        else if(t<arr[m])
        {
            e=m-1;
            m=s+(e-s)/2;
        }
        else if (t>arr[m])
        {
            s=m+1;
            m=s+(e-s)/2;
        }
    }
    return arr[e];
    
}
int main()
{
    int n;
    cout<<"Enter the array size: "<<endl;
    cin>>n;
    cout<<"Enter each element of array: "<<endl;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int t=15;
    cout<<"Ceiling of the given target in the array is: "<<ceiling(arr,n,t)<<endl;
    cout<<"Floor of the given target in the array is: "<<floor(arr,n,t)<<endl;

    
    
    return 0;
}
