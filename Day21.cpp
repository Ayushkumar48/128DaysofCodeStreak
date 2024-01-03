// LeetCode

// 860. Lemonade Change
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5=0;
        int bill10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                bill5+=5;
            }
            else if(bills[i]==10){
                bill10+=10;
                if(bill5>=5){
                    bill5-=5;
                }
                else{
                    return false;
                }
            }
            else if(bills[i]==20){
                if(bill5==0){
                    return false;
                }
                else if(bill5>=5){
                    if(bill10>=10){
                        bill5-=5;
                        bill10-=10;
                    }
                    else if(bill10==0 && bill5>=15){
                        bill5-=15;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// 704. Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int m;
        while(s<=e){
            m=s+(e-s)/2;
            if(nums[m]==target){
                return m;
            }
            else if(target>nums[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return -1;
    }
};