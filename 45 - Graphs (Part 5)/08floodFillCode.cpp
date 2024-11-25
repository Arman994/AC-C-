#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
void dsf(int row, int col, int n, int m, vector<vector<int>>& image, vector<vector<bool>>& vis, int newColor, int oldColor) {
    vis[row][col] = true;
    image[row][col] = newColor;

    //up
    if(row-1 >=0 && !vis[row-1][col] && image[row-1][col] == oldColor) {
        dsf(row-1, col, n, m, image, vis, newColor, oldColor);
    }

    //down
   if(row+1 < n && !vis[row+1][col] && image[row+1][col] == oldColor) {
        dsf(row+1, col, n, m, image, vis, newColor, oldColor);
    }

    //left
    if(col-1 >=0 && !vis[row][col-1] && image[row][col-1] == oldColor) {
        dsf(row, col-1, n, m, image, vis, newColor, oldColor);
    }

    //right
    if(col+1 < m && !vis[row][col+1] && image[row][col+1] == oldColor) {
        dsf(row, col+1, n, m, image, vis, newColor, oldColor);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dsf(sr, sc, n, m, image, vis, color, image[sr][sr]);
        return image;
    }
};