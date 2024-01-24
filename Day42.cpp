//LeetCode


//633. Sum of Square Numbers
class Solution {
public:
    bool judgeSquareSum(int c) {
        long s = 0;
        long e = sqrt(c);

        while (s <= e) {

            if (s * s + e * e == (long)c) {
                return true;
            }
            if (s * s + e * e > (long)c) {
                e--;
            }
            else if (s * s + e * e < (long)c) {
                s++;
            }
        }
        return false;
    }
};

//1011. Capacity To Ship Packages Within D Days
class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap){
        int ships=1;
        int currCap=0;
        for(int i=0;i<weights.size();i++){
            if(currCap+weights[i]<=cap){
                currCap+=weights[i];
            }
            else{
                ships++;
                if(ships>days || weights[i]>cap){
                    return false;
                }
                currCap=weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxi=weights[0];
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(weights[i]>maxi){
                maxi=weights[i];
            }
        }
        int s=maxi;
        int e=sum;
        int res=e;
        while(s<=e){
            int cap=(s+e)>>1;
            if(canShip(weights, days, cap)){
                res=min(res,cap);
                e=cap-1;
            }
            else{
                s=cap+1;
            }
        }
        return res;
    }
};