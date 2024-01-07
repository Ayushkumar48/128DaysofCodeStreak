// LeetCode

//11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int multiply;
        int maxMultiply=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            multiply=(j-i)*min(height[i],height[j]);
            maxMultiply=max(maxMultiply,multiply);
            if(height[i]<=height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxMultiply;
    }
};


//26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i=1;
	    int j=1;
	    int key=a[0];
	    while(i<a.size()){
		    if(key!=a[i]){
			    key=a[i];
		    	a[j]=key;
		    	    j++;
		    	i++;
		    }
		    else{
			    i++;
		    }
	    }
	    a.erase(a.begin()+j, a.end());
	    return a.size();
    }
};