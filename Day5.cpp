#include <iostream>
using namespace std;


void primeSieve(int n){
    int prime[100]={0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i]==0)
        {
            for (int j = i*i; j <= n; j+=i)
            {
                prime[j]=1;
            }
            
        }
        
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i]==0)
        {
            cout<<i<<" ";
        }
        
    }
    cout<<endl;
    
    
}
void primeFactor(int n){
    int arr[n]={};
    for (int i = 1; i <= n; i++)
    {
        arr[i]=-1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i]==-1)
        {
            for (int j = i; j <= n; j+=i)
            {
                arr[j]=i;
            }
            
        }
        
    }
    while (n!=1)
    {
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }
    
    
    
    
    
}
int rem=1;
int gcd(int x, int y){
    while (rem!=0)
    {
        rem=x%y;
        x=y;
        y=rem;
    }
    return x;
    
    
}
int main()
{
    int n;
    cin>>n;
    
    primeSieve(n);
    primeFactor(42);
    cout<<gcd(42,24);
    return 0;
}
