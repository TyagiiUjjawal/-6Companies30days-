class Solution {
public:
    int rev(int n){
        int rem=0;
        int ans=0;
        while(n!=0){
        rem=n%10;
        ans=ans*10+rem;
        n=n/10;

        }
        return ans;
        
    }
    int countNicePairs(vector<int>& nms) {
        unordered_map<int,int> m;     
        int res=0;
        for(int i=0;i<nms.size();i++)
        {
            int temp=nms[i]-rev(nms[i]);        
            m[temp]++;
            res=(res+m[temp]-1)%1000000007;   
        }
        return res%1000000007;
    }
};