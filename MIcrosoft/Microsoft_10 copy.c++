// Q10. Shortest Unsorted Continuous Subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> left(n , 0) , right(n , 0);
        
        left[0]=nums[0];  
        right[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1] , nums[i]);
        }
        
        for(int  i=n-2;i>=0;i--)
        {
            right[i]=min(right[i+1] , nums[i]); 
        }
        
        int pos1=-1 , pos2=-1;
        
        bool f=false;
        
        for(int i=0;i<n;i++)
        {
            if(left[i]!=right[i] && f==false)
            {
                pos1=i;
                f=true;
            }
            
            if(left[i]!=right[i])
            {
                pos2=i;
            }
        }
        
        if(pos1 !=-1 && pos2!=-1)
        {
            return pos2-pos1+1;
        }
        
        return 0;
    }
};