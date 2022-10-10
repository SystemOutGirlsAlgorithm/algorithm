class Solution {
public: 
    int startcolor;
    int newcolor;
    
    void dfs(vector<vector<int>>& image, int sr, int sc) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size())
            return;
        
        if (image[sr][sc] == startcolor) {
            image[sr][sc] = newcolor;
            dfs(image, sr-1, sc);
            dfs(image, sr+1, sc);
            dfs(image, sr, sc-1);
            dfs(image, sr, sc+1);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        startcolor = image[sr][sc];
        newcolor = color;
        
        if (startcolor == newcolor) return image;
        
        dfs(image, sr, sc);
        return image;
    }
};