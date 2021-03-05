//Video explenation here - 
//https://youtu.be/bI27Vnwakxc

class Solution {
    int rows, cols;
    vector<vector<int>> cache;
    int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    
    bool valid(int i, int j){
        return i<rows && i>=0 && j<cols && j>=0;
    }
    
    int longestIncPath(vector<vector<int>>& matrix, int i, int j){
        if(cache[i][j]) return cache[i][j];
        
        int max_dir_path = 0;
        for(auto dir : dirs){
            int dir_i = i + dir[0];
            int dir_j = j + dir[1];
            
            if(valid(dir_i, dir_j) && matrix[i][j] < matrix[dir_i][dir_j]){
                max_dir_path = max(max_dir_path, longestIncPath(matrix, dir_i, dir_j));
            }
        }
        cache[i][j] = max_dir_path + 1;
        return cache[i][j];
    }
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(!rows) return 0;
        cols = matrix[0].size();
        
        cache = vector<vector<int>>(rows, vector<int>(cols));
        int max_path = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                max_path = max(max_path, longestIncPath(matrix, i, j));
            }
        }
        return max_path;
    }
};
