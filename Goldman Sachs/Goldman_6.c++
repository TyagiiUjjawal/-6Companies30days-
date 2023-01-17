//Minimum Consecutive card to Pick Up
class Solution {
public:
    int minimumCardPickup(vector<int>& card) {
        map<int, vector<int>>m;
        int anss=1e9;
        for(int i=0; i<card.size(); i++){
            m[card[i]].push_back(i);
        }
        for(auto it: m){
          
            if(it.second.size()>1){
                int cnt=1e9;
                for(int j=0; j<it.second.size()-1; j++){
                    cnt=min(cnt, it.second[j+1]-it.second[j]+1);
                }
                anss=min(anss, cnt);
            }
        }
        if(anss==1e9){return -1;}
        return anss;
    }
};