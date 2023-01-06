// Q15. Substrings containing all three Characters
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0, right=0, c=0, n= s.size()-1 ;
        unordered_map<char, int> m ;
        
        while(right < s.size()){
            m[s[right]]++ ;
            
            while(m['a']  &&  m['b']  &&  m['c']){
                c += 1+ (n - right) ;
                
                m[s[left]]-- ;
                left++ ;
            }
            
            right++ ;
        }
        
        return c ;
    }
};