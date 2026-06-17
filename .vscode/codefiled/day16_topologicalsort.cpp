//拓扑排序207 329
#include<bits/stdc++.h>
using namespace std;
/*
//深度优先搜索
class Solution {
private:
    vector<vector<int>> edge;
    vector<int> visited;//0未访问，1正在访问，2访问完成
    bool valid = true;
    void dfs(int i){
        visited[i] = 1;
        for(auto& node:edge[i]){
            if(visited[node] == 0){
                dfs(node);
            }else if(visited[node] == 1){
                valid = false;
                return;
            }
        }
        visited[i] = 2;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visited.resize(numCourses);
        for(auto& pre:prerequisites){
            edge[pre[1]].push_back(pre[0]);//课程pre[1]是课程pre[0]的先修课程
        }
        for(int i = 0;i < numCourses;i++){
            if(visited[i] == 0){
                dfs(i);
            }
        }
        return valid;
    }
};
//广度优先搜索 队列
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建邻接表和入度数组
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(const auto& pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        // 使用队列进行拓扑排序
        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(int nextCourse : graph[course]){
                inDegree[nextCourse]--;
                if(inDegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }
        return count == numCourses;
    }
};
*/
//最长递增路径
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        queue<pair<int,int>> neighbors;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> outdegree(rows,vector<int>(cols));
        //出度数组，记录每个节点的出度
        //如果一个节点的出度为0，说明它没有比它更大的邻居，可以作为拓扑排序的起点
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(i - 1 >= 0 && matrix[i-1][j] > matrix[i][j]){
                    outdegree[i][j]++;
                }
                if(i + 1 < rows && matrix[i+1][j] > matrix[i][j]){
                    outdegree[i][j]++;
                }
                if(j - 1 >= 0 && matrix[i][j-1] > matrix[i][j]){
                    outdegree[i][j]++;
                }
                if(j + 1 < cols && matrix[i][j+1] > matrix[i][j]){
                    outdegree[i][j]++;
                }
                if(outdegree[i][j] == 0){
                    neighbors.push({i,j});
                }
            }
        }
        int length = 0;
        //递减路径的出度为0，递增路径的入度为0
        //可以反向从出度为0,最大的节点开始拓扑排序
        while(!neighbors.empty()){
            length++;
            int size = neighbors.size();
            for(int i = 0;i < size;i++){
                auto point = neighbors.front();
                neighbors.pop();
                int row = point.first;
                int col = point.second;
                if(row - 1 >= 0 && matrix[row-1][col] < matrix[row][col]){
                    outdegree[row-1][col]--;
                    if(outdegree[row-1][col] == 0){
                        neighbors.push({row-1,col});
                    }
                }
                if(row + 1 < rows && matrix[row+1][col] < matrix[row][col]){
                    outdegree[row+1][col]--;
                    if(outdegree[row+1][col] == 0){
                        neighbors.push({row+1,col});
                    }
                }
                if(col - 1 >= 0 && matrix[row][col-1] < matrix[row][col]){
                    outdegree[row][col-1]--;
                    if(outdegree[row][col-1] == 0){
                        neighbors.push({row,col-1});
                    }
                }
                if(col + 1 < cols && matrix[row][col+1] < matrix[row][col]){
                    outdegree[row][col+1]--;
                    if(outdegree[row][col+1] == 0){
                        neighbors.push({row,col+1});
                    }
                }
            }
        }
        return length;
    }
};