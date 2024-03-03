// LeetCode

// 380. Insert Delete GetRandom O(1)
class RandomizedSet {
    unordered_map<int, int> ump;
    vector<int> nums;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(ump.find(val)==ump.end()){
            nums.push_back(val);
            ump[val]=nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it=ump.find(val);
        if(it!=ump.end()){
            int index=it->second;
            nums[index]=nums[nums.size()-1];
            ump[nums[index]]=index;
            nums.pop_back();
            ump.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index=rand()%nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */



// 1051. Height Checker
class Solution {
public:
    int heightChecker(vector<int>& nums) {
        vector<int> last(nums.begin(),nums.end());
        sort(nums.begin(), nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=last[i]){
                count++;
            }
        }
        return count;
    }
};