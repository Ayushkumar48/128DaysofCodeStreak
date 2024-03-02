// LeetCode

// 20. Valid Parentheses
// Could have mad this code look better with the help of arrays but I am little bit lazy to think that little optimization. :(
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) {
            return false;
        }
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' && st.empty() == false) {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (ch == '}' && st.empty() == false) {
                if (st.top() == '{') {
                    st.pop();
                }
                else{
                    return false;
                }
            } else if (ch == ']' && st.empty() == false) {
                if (st.top() == '[') {
                    st.pop();
                }
                else{
                    return false;
                }
            } else {
                return false;
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

// 1047. Remove All Adjacent Duplicates In String
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else if(!st.empty() && ch==st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};