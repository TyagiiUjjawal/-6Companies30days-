//You are playing the Bulls and Cows game with your friend.
//You write down a secret number and ask your friend to guess what the number is.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char,int > s;
        unordered_map<char,int> g;
        int n=secret.size();
        int c1=0;
        for(int i=0;i<n;i++){
                if(secret[i]==guess[i]){
                    c1++;
                }
                else{
                    s[secret[i]]++;
                    g[guess[i]]++;
                }
        }
        int c2=0;
        for(auto i: g){
            if(s.find(i.first)!=s.end()){
                c2+=s[i.first]>=i.second?i.second:s[i.first];
               
            }
        }
        string ans="";
        ans+=to_string(c1);
        ans+="A";
        ans+=to_string(c2);
        ans+="B";
        return ans;
    }
};