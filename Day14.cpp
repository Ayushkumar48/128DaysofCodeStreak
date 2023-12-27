// LeetCode
// 1095. Find in Mountain Array
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(int target, MountainArray &mountainArr) {
        int s = 0;
        int e = mountainArr.length() - 1;
        int m;
        while (s < e) {
            m = s + (e - s) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1)) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
    int front(int target, MountainArray &mountainArr){
        int e=getIndex(target, mountainArr);
        int s=0;
        int m;
        while(s<=e){
            m=s+(e-s)/2;
            int u=mountainArr.get(m);
            if(u==target){
                return m;
            }
            else if(u>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return -1;
    }
    int back(int target, MountainArray &mountainArr){
            int s=getIndex(target, mountainArr);
            int e=mountainArr.length()-1;
            int m;
            
            while(s<=e){
                m=s+(e-s)/2;
                int u=mountainArr.get(m);
                if(u==target){
                    return m;
                }
                else if(u>target){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
                
            }
            return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int q=front(target,mountainArr);
        if(q!=-1){
            return q;
        }
        else{
            int w=back(target,mountainArr);
            return w;
        }
    }
};