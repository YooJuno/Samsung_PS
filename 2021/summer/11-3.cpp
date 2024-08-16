class NumArray {
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        sum = new int*[len];
        for (int i = 0; i < len; i ++) {
            sum[i] = new int[len];
        }
        for (int i = 0; i < len; i ++) {
            int k = 0;
            for (int j = i; j < len; j ++) {
                k += nums[j];
                sum[i][j] = k;
            }
        }
    }
 
    int sumRange(int i, int j) {
        return sum[i][j];
    }
private:
    int **sum;   
};