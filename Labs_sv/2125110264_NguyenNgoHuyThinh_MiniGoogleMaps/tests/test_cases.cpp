#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int nodeCount = 0;
vector<string> names;
vector<vector<pair<int,int>>> adj;

void reset() {
    nodeCount = 0;
    names.clear();
    adj.clear();
}

int findNode(const string& name) {
    for (int i = 0; i < (int)names.size(); i++)
        if (names[i] == name) return i;
    return -1;
}

void addNode(const string& name) {
    names.push_back(name);
    adj.push_back(vector<pair<int,int>>());
    nodeCount++;
}

void addEdge(const string& a, const string& b, int w) {
    int u = findNode(a), v = findNode(b);
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

vector<int> dijkstra(int src) {
    vector<int> dist(nodeCount, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first, w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

vector<int> bfs(int src) {
    vector<int> visited(nodeCount, -1);
    queue<int> q;
    visited[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (visited[v] == -1) {
                visited[v] = visited[u] + 1;
                q.push(v);
            }
        }
    }
    return visited;
}

int passCount = 0, failCount = 0;

void check(const string& testName, bool result) {
    if (result) {
        cout << "[PASS] " << testName << "\n";
        passCount++;
    } else {
        cout << "[FAIL] " << testName << "\n";
        failCount++;
    }
}

void test1_findNode() {
    reset();
    addNode("HaNoi");
    addNode("HCM");
    addNode("DaNang");
    check("findNode - tim dung node co san",    findNode("HaNoi")  == 0);
    check("findNode - tim dung node thu 2",     findNode("HCM")    == 1);
    check("findNode - tra -1 khi khong co",     findNode("CanTho") == -1);
}

void test2_dijkstra_co_duong() {
    reset();
    addNode("A"); addNode("B"); addNode("C");
    addEdge("A", "B", 4);
    addEdge("B", "C", 3);
    addEdge("A", "C", 10);
    vector<int> dist = dijkstra(findNode("A"));
    check("Dijkstra - duong ngan nhat A->C qua B (7 < 10)", dist[findNode("C")] == 7);
    check("Dijkstra - khoang cach A->B chinh xac",          dist[findNode("B")] == 4);
    check("Dijkstra - khoang cach A->A la 0",               dist[findNode("A")] == 0);
}

void test3_dijkstra_khong_co_duong() {
    reset();
    addNode("X"); addNode("Y"); addNode("Z");
    addEdge("X", "Y", 5);
    vector<int> dist = dijkstra(findNode("X"));
    check("Dijkstra - INF khi khong co duong di den Z", dist[findNode("Z")] == INF);
}

void test4_bfs_so_buoc() {
    reset();
    addNode("A"); addNode("B"); addNode("C"); addNode("D");
    addEdge("A", "B", 1);
    addEdge("B", "C", 1);
    addEdge("C", "D", 1);
    addEdge("A", "D", 100);
    vector<int> steps = bfs(findNode("A"));
    check("BFS - so buoc A->D ngan nhat la 1 (di thang)", steps[findNode("D")] == 1);
    check("BFS - so buoc A->C la 2",                      steps[findNode("C")] == 2);
    check("BFS - so buoc A->B la 1",                      steps[findNode("B")] == 1);
}

void test5_do_thi_nhieu_nut() {
    reset();
    addNode("HaNoi"); addNode("Vinh"); addNode("Hue");
    addNode("DaNang"); addNode("HCM");
    addEdge("HaNoi",  "Vinh",   300);
    addEdge("Vinh",   "Hue",    200);
    addEdge("Hue",    "DaNang", 100);
    addEdge("DaNang", "HCM",    900);
    addEdge("HaNoi",  "HCM",   1700);
    vector<int> dist = dijkstra(findNode("HaNoi"));
    check("Dijkstra - HaNoi->HCM qua cac thanh pho (1500 < 1700)", dist[findNode("HCM")] == 1500);
    check("Dijkstra - HaNoi->DaNang = 600",  dist[findNode("DaNang")] == 600);
    check("Dijkstra - HaNoi->Hue = 500",     dist[findNode("Hue")]    == 500);
}

int main() {
    cout << "========== CHAY TEST CASES ==========\n\n";

    cout << "--- Test 1: findNode ---\n";
    test1_findNode();

    cout << "\n--- Test 2: Dijkstra co duong di ---\n";
    test2_dijkstra_co_duong();

    cout << "\n--- Test 3: Dijkstra khong co duong di ---\n";
    test3_dijkstra_khong_co_duong();

    cout << "\n--- Test 4: BFS dem so buoc ---\n";
    test4_bfs_so_buoc();

    cout << "\n--- Test 5: Do thi nhieu nut ---\n";
    test5_do_thi_nhieu_nut();

    cout << "\n======================================\n";
    cout << "KET QUA: " << passCount << " PASS / " << failCount << " FAIL\n";
    return 0;
}
