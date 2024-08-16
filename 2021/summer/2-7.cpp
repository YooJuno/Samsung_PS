class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //s 부터 정리
        for(int i=0 ; s[i] != NULL ; i++){
            if(s[i]=='#'){
                // 처음에 #이 나온거라면 샾만 지우고 순서는 -1
                if(i==0){
                    s.erase(s.begin());
                    i--;
                }
                // 처음이 아니라면 두 개를 지워야하니 순서 -2
                else {
                    s.erase(s.begin()-1+i,s.begin()+1+i);
                    i -=2;
                }
            }
        }
        
        for(int i=0 ; t[i] != NULL ; i++){
            if(t[i]=='#'){
                if(i==0){
                    t.erase(t.begin());
                    i--;
                }
                else {
                    t.erase(t.begin()-1+i,t.begin()+1+i);
                    i -=2;
                }
            }
        }
        if(!s.compare(t)) return true;
        else return false;
    }
};