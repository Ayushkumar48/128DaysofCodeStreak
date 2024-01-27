//LeetCode

//2824. Count Pairs Whose Sum is Less than Target
class Solution {
public:
    int binarySearch(vector<int>& nums, int num1, int s, int e){
        int m;
        while(s<=e){
            m=(s+e)>>1;
            if(num1>nums[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return e;
    }
    int countPairs(vector<int>& nums, int target) {
        //nums[j]<target-nums[i];
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int num=nums[i];
            int ans=binarySearch(nums, target-num, i+1, n-1);
            if(ans!=-1){
                count+=ans-i;
            }
        }
        return count;
    }
};


// 2089. Find Target Indices After Sorting Array
class Solution {
public:
    vector<int> ans;
    int partition(vector<int>& arr, int s, int e) {
        int p = arr[e];
        int i = s - 1;
        for (int j = s; j < e; j++) {
            if (arr[j] < p) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[e]);
        return (i + 1);
    }
    void quickSort(vector<int>& arr, int s, int e) {
        if (s < e) {
            int pa = partition(arr, s, e);
            quickSort(arr, s, pa - 1);
            quickSort(arr, pa + 1, e);
        }
    }
    void binarySearch(vector<int>& nums, int s, int e, int target) {
        if (s > e) {
            return;
        }
        int m = s + (e - s) / 2;
        if (nums[m] == target) {
            binarySearch(nums, s, m - 1, target);
            ans.push_back(m);
            binarySearch(nums, m + 1, e, target);
        } else if (nums[m] > target) {
            binarySearch(nums, s, m - 1, target);
        } else {
            binarySearch(nums, m + 1, e, target);
        }
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        // sort(nums.begin(), nums.end());
        binarySearch(nums, 0, n - 1, target);
        return ans;
    }
};