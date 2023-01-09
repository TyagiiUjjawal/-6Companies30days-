class Solution {
public:
    int delay,forget;
    vector<long> dp;
    long dp(int n) {
        if(!n)
            return 0;
        if(dp[n]!=-1)  
            return dp[n];
        long result=1;
        for(int i=delay;i<forget;i++)       
            if(n-i>=0)
                result=(result+dp(n-i))%1e9+7;
        return dp[n]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->delay=delay;
        this->forget=forget;
        dp.resize(n+1,-1);
        return (dp(n)-dp(n-forget)+1e9+7)%1e9+7;   
    }
};