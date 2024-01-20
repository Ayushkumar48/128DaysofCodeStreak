//LeetCode

//349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> intersection;
        for (int num : set1) {
            if (set2.count(num)) {
                intersection.push_back(num);
            }
        }

        return intersection;
    }
};



//350. Intersection of Two Arrays II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> a1(nums1.begin(),nums1.end());
        int n2=nums2.size();
        vector<int> ans;
        for(int i=0;i<n2;i++){
            auto num=a1.find(nums2[i]);
            if(num!=a1.end()){
                ans.push_back(nums2[i]);
                a1.erase(a1.find(nums2[i]));
            }
        }
        return ans;
    }
};