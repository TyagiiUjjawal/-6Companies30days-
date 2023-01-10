class Solution {
public:
    int ans = 0;
    int n = 0;
    
    bool istrue(string& str, vector<vector<int>>& statements){
        
        for(int i=0; i<n; i++){
            if(str[i] == '1'){ 
                for(int j=0; j<n; j++){
                    if(statements[i][j] != 2 && statements[i][j] != str[j] - '0') return false;
                }
            }
        }
        
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        string str = "";
        dfs(statements, str, 0, 0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& statements, string& str, int x, int goodPersonCount){
        if(x == n){
            if(istrue(str, statements)) ans = max(goodPersonCount, ans);
            return;
        }
        
        str.push_back('1');
        dfs(statements, str, x+1, goodPersonCount+1);
        
        str.back() = '0';
        dfs(statements, str, x+1, goodPersonCount);
        
        str.pop_back();
    }
    
};