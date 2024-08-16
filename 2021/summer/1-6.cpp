class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> v;
        
        for(int i=0 ; i<numRows ; i++){
            vector <int> juno;
            if(i!=0) juno.push_back(1);
            
            for(int j=1 ; j<=i-1 ; j++){
                juno.push_back(v[i-1][j-1] + v[i-1][j]);
            }
            
            juno.push_back(1);
            
            v.push_back(juno);
        }
        
        return v;
    }
};