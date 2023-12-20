#include <iostream>
using namespace std;
void decr(int n){
    if (n==0)
    {
        return;
    }
    cout<<n<<" ";
    decr(n-1);
}


void incr(int n){
    if (n==0)
    {
        return;
    }
    incr(n-1);
    cout<<n<<" ";
    
}


int firstOcc(int arr[], int n, int i, int key){
    if (i==n)
    {
        return -1;
    }
    
    if (arr[i]==key)
    {
        return i;
    }
    return firstOcc(arr, n, i+1, key);
}
int lastOcc(int arr[], int n, int i, int key){
    if (i==n)
    {
        return -1;
    }
    int restArray=lastOcc(arr,n,i+1,key);
    if (restArray!=-1)
    {
        return restArray;
    }
    if (arr[i]==key)
    {
        return i;
    }
    return -1;
}

void reverse(string s){
    if (s.length()==0)
    {
        return;
    }
    string ros=s.substr(1);
    reverse(ros);
    cout<<s[0];
    
}


void callpi(string s){
    if (s.length()==0){
        return;
    }
    if (s[0]=='p'&&s[1]=='i')
    {
        cout<<"3.14";
        callpi(s.substr(2));
    }
    else
    {
        cout<<s[0];
        callpi(s.substr(1));
    }
      
}
int main()
{
    int n;
    cin>>n;
    int r;
    cin>>r;
    int p;
    cin>>p;
    decr(5);
    incr(5);
    int arr[]={4,2,1,2,5,2,7};
    cout<<firstOcc(arr,7,0,2)<<endl;
    cout<<lastOcc(arr,7,0,2)<<endl;
    reverse("doomsday");
    callpi("pixxpippxppxpi");
    return 0;
}
