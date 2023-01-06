// Q14. Deletions to make an array divisible.
  int minOperations(vector<int>& nums, vector<int>& numsD) {
        int n = nums.size();
        int ans = -1;
       sort(nums.begin() , nums.end());
        int x = *max_element(numsD.begin() , numsD.end());
        for(auto i:numsD)
        {
            x = __gcd(x , i);
        }
        
        cout<<x<<"\n";
        
        for(int i=0;i<n;++i)
        {
            if(x%nums[i] == 0)
            {
               ans = i;
                break;
            } 
        }
        return ans;
    }