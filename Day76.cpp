//LeetCode

// 500. Keyboard Row
class Solution {
public:
    bool finding(unordered_set<char> row, string s){
        for(auto ch:s){
            if(row.find(ch)==row.end()){
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> firstRow={'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> secondRow={'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> thirdRow={'z','x','c','v','b','n','m'};
        vector<string> ans;
        for(auto it:words){
            string str=it;
            transform(it.begin(), it.end(), it.begin(), ::tolower); 
            if(firstRow.find(it[0])!=firstRow.end()){
                if(finding(firstRow, it)){
                    ans.push_back(str);
                }
            }
            else if(secondRow.find(it[0])!=secondRow.end()){
                if(finding(secondRow, it)){
                    ans.push_back(str);
                }
            }
            else{
                if(finding(thirdRow, it)){
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};

// 747. Largest Number At Least Twice of Others
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest=INT_MIN;
        int index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                largest=nums[i];
                index=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=largest){
                if(nums[i]*2>largest){
                    return -1;
                }
            }
        }
        return index;
    }
};