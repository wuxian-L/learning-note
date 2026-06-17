//广度优先搜索 200 695 994
/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(!rows) return 0;
        int cols = grid[0].size();
        int num_islands = 0;
        for(int r = 0;r < rows;r++){
            for(int c = 0;c < cols;++c){
                if(grid[r][c] == '1'){
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int,int>> neighbors;
                    neighbors.push({r,c});
                    while(!neighbor.empty()){
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first;
                        int col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < rows && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < cols && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};
*/
/*
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>> neighbors;
        int maxland = 0;
        int rows = grid.size();
        if(rows == 0)return 0;
        int cols = grid[0].size();
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                int countland = 0;
                if(grid[i][j] == 1){
                    ++countland;
                    grid[i][j] = 0;
                    neighbors.push({i,j});
                }
                while(!neighbors.empty()){
                    auto point = neighbors.front();
                    neighbors.pop();
                    int row = point.first;
                    int col = point.second;
                    if(row - 1 >= 0 && grid[row-1][col] == 1){
                        neighbors.push({row-1,col});
                        grid[row-1][col] = 0;
                        ++countland;
                    }
                    if(row + 1 < rows && grid[row+1][col] == 1){
                        neighbors.push({row+1,col});
                        grid[row+1][col] = 0;
                        ++countland;
                    }
                    if(col-1 >= 0 && grid[row][col-1] == 1){
                        neighbors.push({row,col-1});
                        grid[row][col-1] = 0;
                        ++countland;
                    }
                    if(col+1 < cols && grid[row][col+1] == 1){
                        neighbors.push({row,col+1});
                        grid[row][col+1] = 0;
                        ++countland;
                    }
                }
                maxland = max(countland,maxland);
            }
        }
        return maxland;
    }
};
*/
/*
class Solution {
private:
    struct PairHash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> badoranges;
        unordered_set<pair<int,int>,PairHash> goodoranges;
        int rows = grid.size();
        if(rows == 0)return -1;
        int cols = grid[0].size();
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(grid[i][j] == 2){
                    badoranges.push({i,j});
                }
                if(grid[i][j] == 1){
                    goodoranges.insert({i,j});
                }
            }
        }
        if(badoranges.empty() && goodoranges.empty()){
            return 0;
        }
        if(badoranges.empty() && !goodoranges.empty()){
            return -1;
        }
        int time = -1;
        while(!badoranges.empty())
        {   
            time++;
            int size = badoranges.size();
            for(int i = 0;i < size;i++){
                auto badorange = badoranges.front();
                badoranges.pop();
                int row = badorange.first;
                int col = badorange.second;
                if(row - 1 >= 0 && goodoranges.find({row-1,col}) != goodoranges.end()){
                    badoranges.push({row-1,col});
                    goodoranges.erase({row-1,col});
                    grid[row-1][col] = 2;
                }
                if(row + 1 < rows && goodoranges.find({row+1,col}) != goodoranges.end()){
                    badoranges.push({row+1,col});
                    goodoranges.erase({row+1,col});
                    grid[row+1][col] = 2;
                }
                if(col-1 >= 0 && goodoranges.find({row,col-1}) != goodoranges.end()){
                    badoranges.push({row,col-1});
                    goodoranges.erase({row,col-1});
                    grid[row][col-1] = 2;
                }
                if(col+1 < cols && goodoranges.find({row,col+1}) != goodoranges.end()){
                    badoranges.push({row,col+1});
                    goodoranges.erase({row,col+1});
                    grid[row][col+1] = 2;
                }
            }
        }
        return goodoranges.empty()?time : -1;
    }
};
*/
