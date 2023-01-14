class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum=0,negatives=0;
        int minele=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                minele=min(minele,abs(matrix[i][j]));
                if(matrix[i][j]<0) negatives++;
            }
        }
        if(negatives%2!=0){
            sum-=(2*minele);
        }
        return sum;
    }
};