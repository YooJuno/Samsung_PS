class Solution {
public:
    /*
    단어들의 앞 글자들이 몇 개가 일치하는지 알아내는 문제
    포문 돌려가면서 인덱스마다 연속으로 일치하는지 알아내면 됨
    */
    string longestCommonPrefix(vector<string>& strs) {

        string juno;
        int min = 200; // 단어 중 제일 작은 길이를 알아내기 위해
        int flag = 0; // 탈출조건 만족시

        // 제일 작은 길이 min에 넣기
        for(int i=0 ; i<strs.size() ; i++)
            if(min>strs[i].length()) 
                min = strs[i].length();
        
        // 단어별 탐색
        for(int i=0 ; i<min ; i++){
            
            // 한글자 씩 탐색
            for(int j=0 ; j<strs.size() ; j++){
                // 일단 넣고
                if(j==0) juno.push_back(strs[j][i]);
                else{
                    if(strs[j][i]!=juno[i]){
                        flag = 1; // 나가자
                        juno.erase(juno.begin()+i);// 아니면 빼
                        break;
                    }
                }
            }
            if(flag==1) break;
        }
        
        return juno;
    }
};