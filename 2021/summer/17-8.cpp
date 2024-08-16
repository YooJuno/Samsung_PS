class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>> heap;
        vector<int> result;
        
        for(int num:nums) {
            hash[num]++;
        }
        
        for(auto item:hash) {
            heap.push(make_pair(item.second, item.first));
        }
        
        for(int i=0; i<k; i++) {
            result.push_back(heap.top().second);
            heap.pop();      
        }
        return result;
    }
};