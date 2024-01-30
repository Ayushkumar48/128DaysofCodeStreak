//LeetCode

//1207. Unique Number of Occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hmap;
        for(auto it:arr){
            hmap[it]++;
        }
        unordered_set<int> uset;
        for(auto it:hmap){
            uset.insert(it.second);
        }
        return hmap.size()==uset.size();
    }
};