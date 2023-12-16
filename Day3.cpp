#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        int current=arr[i];
        int j=i-1;
        while (arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    int mx=INT_MIN;
    int arr[5]={25,44,12,56,32};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        mx=max(mx,arr[i]);
    }
    cout<<mx;
    int curr=0;
    for (int i = 0; i < n; i++)
    {
        curr=0;
        for (int j = i; j < n; j++)
        {
            curr=curr+arr[j];
            cout<<curr<<endl;
        }
        
    }
    int ans=2;
    int pd=arr[1]-arr[0];
    int j=2;
    int curr=2;
    while (j<n)
    {
        if (pd==arr[j]-arr[j-1])
        {
            curr++;
        }
        else
        {
            pd=arr[j]-arr[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        
        j++;
    }
    
    cout<<ans<<endl;
    
    

    int arr[]={1,2,3,4,5};
    
    int current=arr[0]+arr[1]+arr[2];
    int total=current;
    for (int i = 1; i < 5; i++)
    {
        arr[-1]=0;
        current=current+arr[i+3]-arr[i-1];
        total=total+current;
    }
    cout<<total;
    int a=10;
    int* b=&a;
    cout<<*b<<endl;
    cout<<b<<endl;
    *b=199;
    cout<<a;
    int arr[]={10,20,30};
    cout<<arr<<endl;
    cout<<*arr<<endl;
    int* ptr=arr;
    for (int i = 0; i < 3; i++)
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<*(arr+i)<<endl;
    }
    
    
    return 0;
}