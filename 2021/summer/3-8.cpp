class Solution {
public:
    string countAndSay(int n) {
        vector <string> v;
        
        for(int i=0 ; i<n ; i++){
            string s;
            char num;
            int count = 1;
            
            if(i==0) s.push_back('1');
            else{
                num = v[i-1][0];
                for(int j=1 ; j<v[i-1].size() ; j++){
                    if(num == v[i-1][j]) count++;
                    else{
                        s.push_back(count+48);
                        s.push_back(num);
                        
                        count = 1;
                        num = v[i-1][j];
                    }
                }
                
                
                s.push_back(count+48);
                s.push_back(num);
            }
            cout<<s<<endl;
            v.push_back(s);
        }
        string result = v[n-1];
        return result;
    }
};