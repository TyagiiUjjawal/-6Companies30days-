// Q1.You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();

                    int y=b+a;
                    s.push(y);
            }
            else if(tokens[i]=="*"){
                int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();

                    int y=a*b;
                    s.push(y);
            }
            else if(tokens[i]=="/"){
                int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();

                    int y=b/a;
                    s.push(y);
            }
           else if(tokens[i]=="-"){
                int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();

                    int y=b-a;
                    s.push(y);
            }
            else {
                int x=stoi(tokens[i]);
                s.push(x);
            }
        }
        int ans=s.top();
        return ans;
    }
};