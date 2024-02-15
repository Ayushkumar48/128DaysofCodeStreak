//LeetCode

//1512. Number of Good Pairs
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

//1108. Defanging an IP Address
class Solution {
public:
    string defangIPaddr(string address) {
        string s="";
        for(int i=0;i<address.size();i++){
            if(address[i]!='.'){
                s+=address[i];
            }
            else{
                s+="[.]";
            }
        }
        return s;
    }
};