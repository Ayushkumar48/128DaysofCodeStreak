#include<iostream>
#include<cmath>
using namespace std;

void fibonacci(int n){
    int t1=0;
    int t2=1;
    int nextTerm;
    for (int i = 1; i <= n; i++)
    {
        cout<<t1<<endl;
        nextTerm=t1+t2;
        t1=t2;
        
        t2=nextTerm;
    }
    return;
    
}

int fact(int n){
    int fact=1;
    for (int i = 2; i <= n; i++)
    {
        fact=fact*i;
    }
    return fact;
}
int main(){
    int n,r;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the 2nd number: ";
    cin>>r;
    cout<<"The value of "<<n<<"C"<<r<<" is "<<fact(n)/(fact(r)*fact(n-r));






    int n;
    cout<<"Enter the number: ";
    cin>>n;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j;
            
        }
        cout<<endl;
        
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((j+i)%2==0)
            {
                cout<<1;
            }
            else{
                cout<<0;
            }
            
            
        }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (size_t k = 1; k <= n; k++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
        
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int l = i; l >=1; l--)
        {
            cout<<l;
        }
        for (int k = 2; k <= i; k++)
        {
            cout<<k;
        }
        cout<<endl;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int l = 1; l <= (2*i-1); l++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for (int x = n; x >= 1; x--)
    {
        for (int j = 1; j <= n-x; j++)
        {
            cout<<" ";
        }
        for (int k = (2*x-1); k >= 1; k--)
        {
            cout<<"*";
        }
        cout<<endl;
    }


    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i+j)%4==0) || (i==2 && j%4==0))
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
            
        }
        
        cout<<endl;
        
    }
    
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n+1-i; j++)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
    bool flag=0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n%i==0)
        {
            flag=1;
            break;
        }
        
    }
    if (flag==0)
    {
        cout<<"Prime";
    }
    else
    {
        cout<<"Not Prime";
    }
    
    
    
    int newNum=0;
    int rem=0;
    for (int i = 0; n>0; i++)
    {
        rem=n%10;
        n=n/10;
        newNum=newNum*10+rem;
    }
    cout<<newNum;
     
    
    int rem,arm=0;
    int orin=n;
    for (int i = 0; n>0; i++)
    {
        rem=n%10;
        arm=arm+rem*rem*rem;
        n=n/10;
    }
    if (orin==arm)
    {
        cout<<"Armstrong";
    }
    else
    {
        cout<<"Not Armstrong";
    }
    
    fibonacci(n);
    
    
    return 0;
}



