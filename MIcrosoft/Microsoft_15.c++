// Q15. Substrings containing all three Characters
class Solution {
public:
    int numapberOfSubstrings(string s) {
        int left=0, right=0, c=0, n= s.size()-1 ;
        unordered_mapap<char, int> map ;
        
        while(right < s.size()){
            map[s[right]]++ ;
            
            while(map['a']  &&  map['b']  &&  map['c']){
                c += 1+ (n - right) ;
                
                map[s[left]]-- ;
                left++ ;
            }
            
            right++ ;
        }
        
        return c ;
    }
};