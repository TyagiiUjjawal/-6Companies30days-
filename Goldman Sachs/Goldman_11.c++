class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        vector<string>name;
        vector<int>time;
        vector<int>amount;
        vector<string>city;
        vector<string>res;
        int f=0;
        
        for(auto str:transactions){
            stringstream ss(str);
            string st;
            
            while(getline(ss,st,',')){
                if(f==0){
                    name.emplace_back(st);
                    f=1;
                }
                else if(f==1){
                    time.emplace_back(stoi(st));
                    f=2;
                }
                else if(f==2){
                    amount.emplace_back(stoi(st));
                    f=3;                    
                }
                else if(f==3){
                    city.emplace_back(st);
                    f=0;                    
                }
            }                    
        }
        
		
        int j=0;
        for(auto it:amount){
            if(it>1000){
                res.emplace_back(transactions[j]);                
            }
            j++;
        }
        
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.size();j++){
                if(name[i]==name[j] && city[i]!=city[j]){
                    if(abs(time[i]-time[j])<=60){
                        if(amount[i]<=1000){
                            res.emplace_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
		
        return res;
    }
};


