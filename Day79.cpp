#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Stack{
    public:
        int *arr;
        int size;
        int top;
        Stack(int size){
            arr=new int[size];
            this->size=size;
            top=-1;
        }
        void push(int data){
            if(top == size-1){
                cout<<"Stack overflow.";
                return;
            }
            else{
                top++;
                arr[top]=data;
            }
        }
        void pop(){
            if(top==-1){
                cout<<"Stack underflow.";
                return;
            }
            else{
                top--;
            }
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        int getTop(){
            if(top == -1){
                cout<<"Stack is empty.";
                return -1;
            }
            else{
                return arr[top];
            }
        }
        int getSize(){
            return top+1;
        }
};

void solve(stack<int> &st, int& pos, int &ans){
    if(pos==1){
        ans= st.top();
        return;
    }
    pos--;
    int temp=st.top();
    st.pop();
    solve(st, pos, ans);
    st.push(temp);
}

int getMiddle(stack<int> &st){
    int size=st.size();
    if(st.empty()){
        return -1;
    }
    else{
        int pos=0;
        if(size & 1){
            pos=(size/2)+1;
        }
        else{
            pos=size/2;
        }
        int ans=-1;
        solve(st, pos, ans);
        return ans;
    }
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.pop();
    cout<<s.top();
    Stack s(9);
    s.push(2);
    s.push(3);
    s.pop();
    cout<<s.isEmpty()<<endl;
    cout<<s.getTop()<<endl;
    cout<<s.getSize()<<endl;
    string str = "beattheworld";
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch=str[i];
        st.push(ch);
    }
    string ans = "";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout << str << endl;
    cout << ans << endl;

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int mid=getMiddle(st);
    cout<<mid<<endl;
    return 0;
}
