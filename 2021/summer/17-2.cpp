class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s = cost[0];
        int f = cost[1];
        if (cost.size() == 2)
            return std::min(s, f);
        for (int i = 2; i < cost.size(); i++)
        {
            int k = std::min(s+cost[i], f+cost[i]);
            s = f;
            f = k;
        }
        return std::min(f, s);
    }
};
