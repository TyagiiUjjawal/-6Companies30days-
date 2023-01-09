class Solution {
public:

    vector<int> finalVector;
    int maxfinal = 0;

    void solve(vector<int>& aliceArrows, vector<int> &bobArrows, int maxx, int numArrows, int ind){
            
        if(numArrows == 0 || ind < 0){
            if(maxfinal<maxx){
                maxfinal = maxx;
                finalVector = bobArrows;
            }
            return;
        }
        if(ind == 0){
            bobArrows[ind] = numArrows;
            solve(aliceArrows, bobArrows, maxx+ind, 0, ind-1);
            bobArrows[ind] = 0;
            return;
        }
        else if(numArrows>= (aliceArrows[ind]+1)){
            bobArrows[ind] = aliceArrows[ind]+1;
            solve(aliceArrows, bobArrows, maxx+ind,numArrows-(aliceArrows[ind]+1),ind-1);
            bobArrows[ind] = 0;
        }
        solve(aliceArrows, bobArrows, maxx, numArrows, ind-1);

    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bobArrows;
        for(int i=0;i<12;i++)
            bobArrows.push_back(0);
        solve(aliceArrows, bobArrows, 0, numArrows, 11);
        return finalVector;
    }
};