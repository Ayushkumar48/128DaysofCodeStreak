#include <iostream>
using namespace std;

int sum(int n){
    if (n==0)
    {
        return 0;
    }
    
    int preSum=sum(n-1);
    return n+preSum;
}


int power(int n, int p){
    if (p==0)
    {
        return 1;
    }
    
    int prePow=power(n, (p-1));
    return n*prePow;
}



int fact(int n){
    if (n==0)
    {
        return 1;
    }
    
    int prefact=fact(n-1);
    return n*prefact;
}

int permutation(int n, int r){
    return fact(n)/fact(n-r);
}

int combi(int n, int r){
    return fact(n)/(fact(r)*fact(n-r));
}



int fib(int n){
    if (n==0||n==1)
    {
        return n;
    }
    

    return fib(n-1)+fib(n-2);
}

bool sorted(int arr[], int n){
    if (n==1)
    {
        return true;
    }
    
    bool restArray=sorted(arr+1,n-1);
    return (arr[0]<arr[1]&&restArray);
    
}
int main()
{
    int n;
    cin>>n;
    int r;
    cin>>r;
    int p;
    cin>>p;
    cout<<sum(n);
    cout<<power(n,p);
    cout<<combi(n,r);
    cout<<fib(n);
    int arr[]={1,2,3,4,5};
    cout<<sorted(arr,5);
    
    return 0;
}