class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector <int> v(digits);
        vector <int>::iterator it;
        it = v.begin();
        v[v.size()-1]++;
        for(int i = 0 ; i<v.size() ; i++){
            if(v[v.size()-i-1]==10){
                if(i== v.size()-1){
                    v[v.size()-i-1] -= 10;
                    v.insert(it,1);
                }
                else{
                    v[v.size()-i-1] -= 10;
                    v[v.size()-i-2]++;
                }
            }
        }
        
        
        return v; 
    }
};