 class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            if(image.empty()) return image;
            int n = image.size();
            int m = image[0].size();
            vector<vector<bool>> check(n, vector<bool>(m, false));
            int initial = image[sr][sc];
            dfs(image, check, sr, sc, newColor, n, m, initial);
            return image;
        }

        void dfs(vector<vector<int>>& image, vector<vector<bool>>& check, int i, int j, int newColor, int n, int m, int initial){
            if(check[i][j] || image[i][j] != initial) return;
            image[i][j] = newColor;
            check[i][j] = true;
            if(i+1 < n){dfs(image, check, i+1, j, newColor, n, m, initial);}
            if(i-1 >= 0){dfs(image, check, i-1, j, newColor, n, m, initial);}
            if(j+1 < m){dfs(image, check, i, j+1, newColor, n, m, initial);}
            if(j-1 >= 0){dfs(image, check, i, j-1, newColor, n, m, initial);}
        }
};