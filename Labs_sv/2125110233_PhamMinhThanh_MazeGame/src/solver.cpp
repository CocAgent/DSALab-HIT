#include "solver.h"
#include <queue>
#include <stack>
#include <algorithm>

vector<pair<int, int>> Solver::BFS(Maze& maze, int sx, int sy) {
    queue<pair<int, int>> q;
    bool visited[HEIGHT][WIDTH] = { false };
    pair<int, int> parent[HEIGHT][WIDTH];

    q.push({ sx, sy });
    visited[sy][sx] = true;

    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (maze.grid[y][x] == 'E') {
            vector<pair<int, int>> path;
            while (!(x == sx && y == sy)) {
                path.push_back({ x,y });
                auto p = parent[y][x];
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                if (!visited[ny][nx] && maze.grid[ny][nx] != '#') {
                    visited[ny][nx] = true;
                    parent[ny][nx] = { x,y };
                    q.push({ nx,ny });
                }
            }
        }
    }
    return {};
}

vector<pair<int, int>> Solver::DFS(Maze& maze, int sx, int sy) {
    stack<pair<int, int>> st;
    bool visited[HEIGHT][WIDTH] = { false };
    pair<int, int> parent[HEIGHT][WIDTH];

    st.push({ sx,sy });

    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };

    while (!st.empty()) {
        auto [x, y] = st.top(); st.pop();

        if (visited[y][x]) continue;
        visited[y][x] = true;

        if (maze.grid[y][x] == 'E') {
            vector<pair<int, int>> path;
            while (!(x == sx && y == sy)) {
                path.push_back({ x,y });
                auto p = parent[y][x];
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                if (!visited[ny][nx] && maze.grid[ny][nx] != '#') {
                    parent[ny][nx] = { x,y };
                    st.push({ nx,ny });
                }
            }
        }
    }
    return {};
}