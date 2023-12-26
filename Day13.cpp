// LeetCode
// 744. Find Smallest Letter Greater Than Target
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s=0;
        int e=letters.size()-1;
        int m;
        while(s<=e){
            m=s+(e-s)/2;
            if(letters[m]>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return letters[s % letters.size()];
    }
};

// 852. Peak Index in a Mountain Array
class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int m;
        while(s < e){
           m = s + (e - s)/2;
           if(arr[m] > arr[m+1]){
                e=m;
           }
           else{
               s = m + 1;
           }
        }
        return s;
    }
};