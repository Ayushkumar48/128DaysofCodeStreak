//LeetCode

// 448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i])-1] > 0) {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

//680. Valid Palindrome II
class Solution {
public:
    bool isPal(string x, int st, int ed) {
        while (st < ed) {
            if (x[st] != x[ed]) {
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
    bool validPalindrome(string str) {
        int s = 0;
        int e = str.size() - 1;
        while (s < e) {
            if (str[s] != str[e]) {
                bool s1 = isPal(str, s + 1, e);
                bool s2 = isPal(str, s, e - 1);
                return s1 || s2;
            }
            s++;
            e--;
        }
        return true;
    }
};