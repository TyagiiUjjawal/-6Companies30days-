//Q5. split array into subsequences
public:
    bool isPossible(vector<int>& nums) {
        vector<int> c (2001, 0);
        for (int& n : nums) c[n + 1000]++;
        
        for (int i = 0; i <= 1998; i++) {
            if (c[i] == 0) continue;
            while (c[i]) {
                int c = 0;
                while (c[i+c] <= c[i+c+1]) {
                    c[i+c]--;
                    c++;
                }
            
                c[i+c]--;
                c++;
                if (c < 3) return false;
            }
        }
        if (c[1999] or c[2000]) return false;
        
        return true;
    }
};
