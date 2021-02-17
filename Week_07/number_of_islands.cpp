#include <iostream>
using namespace std;

int main() {

    cout << "岛屿数量" << endl;

    return 0;
}

//解法一：深度优先遍历(DFS)
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        for (int r = 0; r < nr; ++r)
            for (int c = 0; c < nc; ++c)
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
        return num_islands;
    }
};

//解法二：广度优先遍历(BFS)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        for (int r = 0; r < nr; ++r)
            for (int c = 0; c < nc; ++c)
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row + 1][col] == '1') {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col + 1] == '1') {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
        return num_islands;
    }
};

//解法三：并查集
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * nc + j);
                    ++count;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (parent[rootx] != parent[rooty]) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rootx] = rooty;
            if (rank[rootx] == rank[rooty]) {
                rank[rootx] += 1;
            }
            --count;
        }
    }

    int getcount() {
        return count;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        for (int r = 0; r < nr; ++r)
            for (int c = 0; c < nc; ++c)
                if (grid[r][c] == '1') {
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * nc + c, (r - 1) * nc + c);
                    if (r + 1 < nr && grid[r + 1][c] == '1') uf.unite(r * nc + c, (r + 1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c + 1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
        return uf.getcount();
    }
};