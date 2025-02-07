class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5  = 0;
        int count_10 = 0;
        int count_20 = 0;
        
        bool result = true;
        
        for(int i=0 ; i<bills.size() ; i++){
            if(bills[i] == 5) count_5++;
            
            else if(bills[i] == 10){
                if(count_5 > 0){
                    count_5--;
                    count_10++;
                }
                else{
                    result = false;
                    break;
                }
            }
            
            else{
                // 10을 먼저 없애야 나중에 5를 활용 가능함
                if(count_10 > 0 && count_5 > 0){
                    count_10--;
                    count_5--;
                }
                // 어쩔 수 없이 5 3개 사용
                else if(count_5 >= 3){
                    count_5 -= 3;
                }
                else{
                    result = false;
                    break;
                }
            }
            
        }
        
        return result;
    }
};