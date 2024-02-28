// LeetCode

// 215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
// Another approach but T.L.E. ---- Quick Sort like approach
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, index, 0, nums.size() - 1);
    }
private:
    int quickSelect(vector<int>& nums, int k, int l, int r){
        int pivot = nums[r];
        int p_pos = l;
        for (int i = l; i < r; ++i){
            if (nums[i] <= pivot){
                swap(nums[i], nums[p_pos]);
                ++p_pos;
            }
        }
        swap(nums[p_pos], nums[r]);
        if (k < p_pos)
            return quickSelect(nums, k, l, p_pos - 1);
        if (k > p_pos)
            return quickSelect(nums, k, p_pos + 1, r);
        return nums[p_pos];
    }
};

// 3039. Apply Operations to Make String Empty
class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> charCount(26, 0);
        
        int maxCount = 0;
        for(int i=0; i<s.size(); i++) {
            charCount[s[i] - 'a']++;
            maxCount = max(maxCount, charCount[s[i] - 'a']);
        }
        
        string result = "";
        
        for(int i=s.size()-1; i>=0; i--) {
            if(charCount[s[i] - 'a']-- == maxCount) {
                result += s[i];
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};