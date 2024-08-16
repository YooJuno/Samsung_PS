class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        int A=0;
        int B=0;
        int flag = 0;
        int len = costs.size();
        int max_idx;
        
        for(int j=0 ; j<len ; j++){
            cout<<endl<<"costs.size : "<<costs.size()<<endl;
            for(int i=0 ; i<costs.size() ; i++) cout<<costs[i][0]<<' '<<costs[i][1]<<"   ";
            cout<<endl;
            int max=0;
            for(int i=0 ; i<costs.size() ; i++){
                int temp = abs(costs[i][0]-costs[i][1]);
                if(max<temp){
                    max = temp;
                    max_idx = i;
                    
                    cout<<'M'<<max<<'('<<i<<") ";
                }
            }
            cout<<endl;
            
            if(costs[max_idx][0]>costs[max_idx][1]){
                sum += costs[max_idx][1];
                B++;
                costs.erase(costs.begin()+max_idx);
                if(B==(len/2)){
                    for(int k=0 ; k<costs.size() ; k++) sum += costs[k][0];
                    flag = 1;     
                }
            }
            else{
                sum += costs[max_idx][0];
                A++;
                costs.erase(costs.begin()+max_idx);
                if(A==(len/2)){
                    for(int k=0 ; k<costs.size() ; k++) sum += costs[k][1];
                    flag = 1;
                }
            }
            cout<<"sum : "<<sum<<endl;
            if(flag == 1) break;
        }
        return sum;   
    }
};

/*
        int sum=0;
        int zero=0;
        int one =0;
        int len = costs.size();
        int half = len/2;
        int flag=0;
        for(int i=0 ; i<len ; i++){
            cout<<endl<<"costs.size : "<<costs.size()<<endl;
            vector <int> juno;
            for(int j=0 ; j<costs.size() ; j++){
                juno.push_back(costs[j][0]);
                juno.push_back(costs[j][1]);
            }
            sort(juno.begin(), juno.end());
            
            int min = juno[0];
            
            sum += min;
            cout<<"sum : "<<sum<<endl;
            
            for(int j=0 ; j<costs.size() ; j++){
                if(costs[j][0]==min){
                    costs.erase(costs.begin()+j);
                    zero++;
                    if(zero==half){
                        for(int k=0 ; k<costs.size() ; k++){
                            sum += costs[k][1];
                            flag = 1;
                        }
                    }
                    break;
                }
                else if(costs[j][1]==min){
                    costs.erase(costs.begin()+j);
                    one++;
                    if(one==half){
                        for(int k=0 ; k<costs.size() ; k++){
                            sum += costs[k][0];
                            flag = 1;
                        }
                    }
                    break;
                }
            }
            if(flag==1) break;
        }
        return sum; 
        */