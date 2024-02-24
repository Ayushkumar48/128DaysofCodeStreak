//LeetCode

// 172. Factorial Trailing Zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        
        return (n/5)+(n/25)+(n/125)+(n/625)+(n/3125);
    }
};

// 929. Unique Email Addresses
class Solution {
public:
    string actualEmail(string email){
        string ans="";
        int i=0;
        while (i < email.size() && email[i] != '@') {
            if (email[i] == '+') {
                while (i < email.size() && email[i] != '@') {
                    i++;
                }
                break;
            }
            else if (email[i] != '.') {
                ans += email[i];
            }
            i++;
        }
        while(i<email.size()){
            ans+=email[i];
            i++;
        }
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(auto it:emails){
            s.insert(actualEmail(it));   
        }
        return s.size();
    }
};
