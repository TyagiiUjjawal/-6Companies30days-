//Q4. You are given an integer array nums of length n. Return maximum length of Rotation Function.
//Sliding Window Approach i have used.

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0; 
        int maxs=0;
         
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maxs+=(i*nums[i]);
        }
        int x=0;
        x=maxs;
        for(int i=nums.size()-1; i>=0; i--){
            maxs+=sum-(nums[i]*nums.size());
            x=max(x, maxs);
        }
        return x;
    }
};