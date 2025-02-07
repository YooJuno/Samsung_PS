#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int abc[26] = {0,};
    int answer = 0;
    for(int i=0 ; i<skill.length() ; i++) abc[skill[i]-65] = i+1;
    
    for(int i=0 ; i<skill_trees.size() ; i++){
        int j;
        int max=1;
        for(j=0 ; j<skill_trees[i].length() ; j++){
            if(max == abc[skill_trees[i][j]-65]) max++;    
            else if(abc[skill_trees[i][j]-65]==0) continue; 
            else break;
        }
        if(j==skill_trees[i].length()) answer++;
    }
    return answer;
}