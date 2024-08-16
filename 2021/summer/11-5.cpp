class Solution {
    public:
        int calPoints(vector<string>& ops) {
            int res = 0; // must be initialized to 0
            stack<int> s;
            for(auto x: ops){
                if(x == "C" && !s.empty()) s.pop();
                else if(x == "D" && !s.empty())
                    s.push(s.top() * 2);
                else if(x == "+" && !s.empty()){
                    int tmp1 = s.top();
                    s.pop();
                    int tmp2 = tmp1;
                    if(!s.empty()){
                        tmp2 += s.top();
                    }
                    s.push(tmp1);
                    s.push(tmp2);
                }
                            Else s.push(stoi(x)); //need to convert string to int
            }
            
                    //Next, access the elements in the stack one by one to get the total score
            while(!s.empty()){
                res += s.top();
                s.pop();
            }
            return res;
        }
};