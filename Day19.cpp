#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int power(int n){
    if(n==0){
        return 1;
    }
    int s=power(n-1);
    int b=2*s;
    return b;
}

vector<int> nos;
vector<int> printNos(int n){
    
    if(n==0){
        return nos;
    }
    nos.push_back(n);
    printNos(n-1);
    
    return nos;
}
int main()
{
    int n;
    cin>>n;
    vector<int> y=printNos(n);
    for (int i = 0; i < y.size(); i++)
    {
        cout<<y[i]<<" ";
    }
    
    
    int ans=power(n);
    cout<<ans;
    return 0;
}
