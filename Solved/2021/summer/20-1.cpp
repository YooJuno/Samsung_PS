class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0};//A total of 256 ascii code
        int m2[256] = {0};
      
        
        for(int i = 0; i < s.size(); i++){
            if(m1[s[i]] != m2[t[i]]) return false; // different values ​​corresponding position, does not meet the
            
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
        
    
};