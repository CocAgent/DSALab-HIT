// ============================================================
//  Chapter5_Graph.cpp
//  Do thi: Bieu dien, BFS, DFS, Dijkstra, Kruskal (MST)
//  DSALab — CD Cong Thuong TP.HCM · 2025
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

// ============================================================
//  PHAN 1: BIEU DIEN DO THI
// ============================================================

// 1.1 Ma tran ke (Adjacency Matrix)
struct GraphMatrix {
    int V;
    vector<vector<int>> adj;

    GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v, int w = 1) {
        adj[u][v] = w;
        adj[v][u] = w;  // vo huong
    }

    void addEdgeDirected(int u, int v, int w = 1) {
        adj[u][v] = w;
    }

    void print() {
        cout << "  Ma tran ke:\n     ";
        for (int i = 0; i < V; i++) cout << setw(3) << i;
        cout << "\n  " << string(4 + 3*V, '-') << "\n";
        for (int i = 0; i < V; i++) {
            cout << "  " << setw(2) << i << " |";
            for (int j = 0; j < V; j++)
                cout << setw(3) << adj[i][j];
            cout << "\n";
        }
    }
};

// 1.2 Danh sach ke (Adjacency List) - hieu qua hon cho do thi thua
struct Edge {
    int to, weight;
};

struct Graph {
    int V;
    vector<vector<Edge>> adj;
    bool directed;

    Graph(int v, bool dir = false) : V(v), adj(v), directed(dir) {}

    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        if (!directed) adj[v].push_back({u, w});
    }

    void print() {
        cout << "  Danh sach ke:\n";
        for (int u = 0; u < V; u++) {
            cout << "  " << u << " -> ";
            for (auto &e : adj[u])
                cout << e.to << "(" << e.weight << ") ";
            cout << "\n";
        }
    }
};

// ============================================================
//  PHAN 2: BFS — Breadth-First Search
// ============================================================
/*
 * Y tuong: Duyet theo tung MUC, dung Queue
 * Do phuc tap: O(V + E)
 * Ung dung: Duong ngan nhat (khong trong so), kiem tra lien thong
 */
vector<int> BFS(const Graph &g, int start) {
    vector<bool> visited(g.V, false);
    vector<int> order;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (auto &e : g.adj[u]) {
            if (!visited[e.to]) {
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }
    return order;
}

// BFS tim khoang cach (khong trong so)
vector<int> BFS_Distance(const Graph &g, int start) {
    vector<int> dist(g.V, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &e : g.adj[u]) {
            if (dist[e.to] == -1) {
                dist[e.to] = dist[u] + 1;
                q.push(e.to);
            }
        }
    }
    return dist;
}

// ============================================================
//  PHAN 3: DFS — Depth-First Search
// ============================================================
/*
 * Y tuong: Di sau nhat co the, dung Stack (hoac de quy)
 * Do phuc tap: O(V + E)
 * Ung dung: Phat hien chu trinh, sap xep topo, thanh phan lien thong
 */

// DFS de quy
void DFS_Recursive(const Graph &g, int u, vector<bool> &visited, vector<int> &order) {
    visited[u] = true;
    order.push_back(u);
    for (auto &e : g.adj[u]) {
        if (!visited[e.to])
            DFS_Recursive(g, e.to, visited, order);
    }
}

vector<int> DFS(const Graph &g, int start) {
    vector<bool> visited(g.V, false);
    vector<int> order;
    DFS_Recursive(g, start, visited, order);
    return order;
}

// DFS dung Stack tuong minh
vector<int> DFS_Iterative(const Graph &g, int start) {
    vector<bool> visited(g.V, false);
    vector<int> order;
    stack<int> stk;

    stk.push(start);
    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
        if (visited[u]) continue;
        visited[u] = true;
        order.push_back(u);
        for (int i = (int)g.adj[u].size()-1; i >= 0; i--)
            if (!visited[g.adj[u][i].to])
                stk.push(g.adj[u][i].to);
    }
    return order;
}

// Kiem tra do thi lien thong
bool IsConnected(const Graph &g) {
    auto order = BFS(g, 0);
    return (int)order.size() == g.V;
}

// Phat hien chu trinh (do thi vo huong)
bool HasCycle_DFS(const Graph &g, int u, int parent, vector<bool> &visited) {
    visited[u] = true;
    for (auto &e : g.adj[u]) {
        if (!visited[e.to]) {
            if (HasCycle_DFS(g, e.to, u, visited)) return true;
        } else if (e.to != parent) {
            return true;  // tim thay canh ngược — co chu trinh
        }
    }
    return false;
}

bool HasCycle(const Graph &g) {
    vector<bool> visited(g.V, false);
    for (int u = 0; u < g.V; u++)
        if (!visited[u])
            if (HasCycle_DFS(g, u, -1, visited)) return true;
    return false;
}

// ============================================================
//  PHAN 4: DIJKSTRA — Duong di ngan nhat
// ============================================================
/*
 * Y tuong: Gom luon dinh co dist nho nhat chua tham
 * Yeu cau: Trong so KHONG AM
 * Do phuc tap: O((V+E) log V) voi priority_queue
 */
vector<int> Dijkstra(const Graph &g, int src) {
    vector<int> dist(g.V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;  // da co duong tot hon

        for (auto &e : g.adj[u]) {
            int newDist = dist[u] + e.weight;
            if (newDist < dist[e.to]) {
                dist[e.to] = newDist;
                pq.push({newDist, e.to});
            }
        }
    }
    return dist;
}

// Dijkstra tim ca duong di (parent array)
pair<vector<int>,vector<int>> DijkstraPath(const Graph &g, int src) {
    vector<int> dist(g.V, INT_MAX);
    vector<int> parent(g.V, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : g.adj[u]) {
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return {dist, parent};
}

vector<int> GetPath(const vector<int> &parent, int dst) {
    vector<int> path;
    for (int v = dst; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

// ============================================================
//  PHAN 5: KRUSKAL — Cay khung nho nhat (MST)
// ============================================================
/*
 * Y tuong: Sap xep cac canh tang dan, them canh nho nhat
 *          neu khong tao chu trinh (dung Union-Find)
 * Do phuc tap: O(E log E)
 */
struct EdgeKruskal {
    int u, v, w;
    bool operator<(const EdgeKruskal &o) const { return w < o.w; }
};

// Union-Find (Disjoint Set Union - DSU)
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;  // cung thanh phan — tao chu trinh
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

struct MSTResult {
    vector<EdgeKruskal> edges;
    int totalWeight;
};

MSTResult Kruskal(int V, vector<EdgeKruskal> &edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    MSTResult result = {{}, 0};

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            result.edges.push_back(e);
            result.totalWeight += e.w;
            if ((int)result.edges.size() == V - 1) break;
        }
    }
    return result;
}

// ============================================================
//  PHAN 6: SAP XEP TOPO (Topological Sort - DAG)
// ============================================================
/*
 * Chi ap dung voi DAG (Do thi co huong khong chu trinh)
 * Y tuong (Kahn's Algorithm): Dung BFS + in-degree
 */
vector<int> TopologicalSort(const Graph &g) {
    vector<int> inDegree(g.V, 0);
    for (int u = 0; u < g.V; u++)
        for (auto &e : g.adj[u])
            inDegree[e.to]++;

    queue<int> q;
    for (int u = 0; u < g.V; u++)
        if (inDegree[u] == 0) q.push(u);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto &e : g.adj[u]) {
            inDegree[e.to]--;
            if (inDegree[e.to] == 0) q.push(e.to);
        }
    }
    return order;  // rong neu co chu trinh
}

// ============================================================
//  IN KET QUA
// ============================================================
void printVector(const vector<int> &v, const string &name = "") {
    if (!name.empty()) cout << "  " << name << ": ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// ============================================================
//  BAI TAP UNG DUNG
// ============================================================

// BT1: Tim so thanh phan lien thong
int CountComponents(const Graph &g) {
    vector<bool> visited(g.V, false);
    int count = 0;
    for (int u = 0; u < g.V; u++) {
        if (!visited[u]) {
            count++;
            vector<int> tmp;
            DFS_Recursive(g, u, visited, tmp);
        }
    }
    return count;
}

// BT2: Kiem tra do thi 2 phia (Bipartite)
bool IsBipartite(const Graph &g) {
    vector<int> color(g.V, -1);
    for (int start = 0; start < g.V; start++) {
        if (color[start] != -1) continue;
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g.adj[u]) {
                if (color[e.to] == -1) {
                    color[e.to] = 1 - color[u];
                    q.push(e.to);
                } else if (color[e.to] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// ============================================================
//  DEMO
// ============================================================
void DemoGraph() {
    cout << "\n=== DEMO DO THI CO SO ===\n";

    // Tao do thi:  0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5
    Graph g(6);
    g.addEdge(0, 1); g.addEdge(0, 2);
    g.addEdge(1, 3); g.addEdge(1, 4);
    g.addEdge(2, 4); g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.print();
    cout << "\n  Lien thong? " << (IsConnected(g) ? "Co" : "Khong") << "\n";
    cout << "  Co chu trinh? " << (HasCycle(g) ? "Co" : "Khong") << "\n";
    cout << "  So thanh phan lien thong: " << CountComponents(g) << "\n";
    cout << "  Do thi 2 phia (bipartite)? " << (IsBipartite(g) ? "Co" : "Khong") << "\n";

    printVector(BFS(g, 0),           "\n  BFS tu dinh 0");
    printVector(DFS(g, 0),           "  DFS (de quy) tu dinh 0");
    printVector(DFS_Iterative(g, 0), "  DFS (stack) tu dinh 0");

    auto dist = BFS_Distance(g, 0);
    cout << "  Khoang cach BFS tu dinh 0:\n";
    for (int i = 0; i < g.V; i++)
        cout << "    -> " << i << ": " << dist[i] << " buoc\n";
}

void DemoDijkstra() {
    cout << "\n=== DEMO DIJKSTRA ===\n";
    Graph g(5, false);
    // Cac canh co trong so
    g.addEdge(0, 1, 10); g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);  g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);  g.addEdge(2, 3, 8); g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 5);  g.addEdge(4, 3, 1);

    g.print();

    auto [dist, parent] = DijkstraPath(g, 0);
    cout << "\n  Duong di ngan nhat tu dinh 0:\n";
    for (int i = 0; i < g.V; i++) {
        cout << "    -> " << i << ": ";
        if (dist[i] == INT_MAX) { cout << "Khong the den\n"; continue; }
        cout << "khoang cach = " << dist[i] << " | duong di: ";
        auto path = GetPath(parent, i);
        for (int j = 0; j < (int)path.size(); j++) {
            if (j) cout << " -> ";
            cout << path[j];
        }
        cout << "\n";
    }
}

void DemoKruskal() {
    cout << "\n=== DEMO KRUSKAL (MST) ===\n";
    int V = 6;
    vector<EdgeKruskal> edges = {
        {0,1,4}, {0,2,3}, {1,2,1}, {1,3,2},
        {2,3,4}, {3,4,2}, {4,5,6}, {3,5,5}
    };

    cout << "  Tat ca cac canh:\n";
    for (auto &e : edges)
        cout << "    " << e.u << " -- " << e.v << " : " << e.w << "\n";

    auto mst = Kruskal(V, edges);
    cout << "\n  Cay khung nho nhat (MST):\n";
    for (auto &e : mst.edges)
        cout << "    " << e.u << " -- " << e.v << " : " << e.w << "\n";
    cout << "  Tong trong so MST: " << mst.totalWeight << "\n";
}

void DemoTopoSort() {
    cout << "\n=== DEMO SAP XEP TOPO (Bieu do mon hoc) ===\n";
    // DAG: Mon hoc phu thuoc
    // 0=Toan co so, 1=CTDL, 2=Giai tich, 3=GT, 4=CSDL, 5=AI
    // 0->1, 0->2, 1->3, 2->3, 3->4, 3->5
    Graph dag(6, true);
    dag.addEdge(0,1); dag.addEdge(0,2);
    dag.addEdge(1,3); dag.addEdge(2,3);
    dag.addEdge(3,4); dag.addEdge(3,5);

    string names[] = {"Toan-CB", "CTDL", "Giai-Tich", "GT", "CSDL", "AI"};
    auto order = TopologicalSort(dag);
    cout << "  Thu tu hoc mon (Topo Sort):\n  ";
    for (int i = 0; i < (int)order.size(); i++) {
        if (i) cout << " -> ";
        cout << names[order[i]];
    }
    cout << "\n";
}

void DemoBaiTap() {
    cout << "\n=== BAI TAP CHUONG 5 ===\n";

    // Do thi khong lien thong
    Graph g(7);
    g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,0);
    g.addEdge(3,4);
    // 5, 6 bi cach li

    cout << "  Do thi 7 dinh (khong lien thong):\n";
    g.print();
    cout << "  So thanh phan lien thong: " << CountComponents(g) << "\n";
    cout << "  Do thi 2 phia? " << (IsBipartite(g) ? "Co" : "Khong") << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  CHUONG 5: DO THI CO BAN (GRAPH)\n";
    cout << "  Bieu dien | BFS | DFS | Dijkstra | Kruskal | Topo Sort\n";
    cout << "============================================================\n";

    DemoGraph();
    DemoDijkstra();
    DemoKruskal();
    DemoTopoSort();
    DemoBaiTap();

    cout << "\n============================================================\n";
    return 0;
}
