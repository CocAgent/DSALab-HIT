#include "structures.h"

int nodeCount = 0;
vector<string> names;
vector<vector<pair<int,int>>> adj;

int findNode(const string& name) {
    for (int i = 0; i < (int)names.size(); i++)
        if (names[i] == name) return i;
    return -1;
}

void addLocation() {
    string name;
    cout << "Nhap ten dia diem: ";
    cin >> name;
    if (findNode(name) != -1) {
        cout << "Dia diem da ton tai!\n";
        return;
    }
    names.push_back(name);
    adj.push_back(vector<pair<int,int>>());
    nodeCount++;
    cout << "Da them: " << name << "\n";
}

void addRoad() {
    string a, b;
    int w;
    cout << "Tu: ";         cin >> a;
    cout << "Den: ";        cin >> b;
    cout << "Khoang cach: "; cin >> w;
    int u = findNode(a), v = findNode(b);
    if (u == -1 || v == -1) {
        cout << "Dia diem khong ton tai!\n";
        return;
    }
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    cout << "Da them duong: " << a << " <-> " << b << " (" << w << "km)\n";
}

void showMap() {
    if (nodeCount == 0) { cout << "Ban do trong!\n"; return; }
    cout << "\n===== BAN DO =====\n";
    for (int i = 0; i < nodeCount; i++) {
        cout << "[" << names[i] << "] -> ";
        for (int j = 0; j < (int)adj[i].size(); j++)
            cout << names[adj[i][j].first] << "(" << adj[i][j].second << ") ";
        cout << "\n";
    }
}

void printPath(vector<int>& parent, int src, int dest) {
    stack<int> path;
    int cur = dest;
    while (cur != -1) {
        path.push(cur);
        cur = parent[cur];
    }
    bool first = true;
    while (!path.empty()) {
        if (!first) cout << " -> ";
        cout << names[path.top()];
        path.pop();
        first = false;
    }
    cout << "\n";
}

void dijkstra() {
    string a, b;
    cout << "Nguon: "; cin >> a;
    cout << "Dich: ";  cin >> b;
    int src = findNode(a), dest = findNode(b);
    if (src == -1 || dest == -1) { cout << "Dia diem khong ton tai!\n"; return; }

    vector<int> dist(nodeCount, INF);
    vector<int> parent(nodeCount, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[dest] == INF) { cout << "Khong co duong di!\n"; return; }
    cout << "Khoang cach ngan nhat: " << dist[dest] << " km\n";
    cout << "Duong di: ";
    printPath(parent, src, dest);
}

void bfsPath() {
    string a, b;
    cout << "Nguon: "; cin >> a;
    cout << "Dich: ";  cin >> b;
    int src = findNode(a), dest = findNode(b);
    if (src == -1 || dest == -1) { cout << "Dia diem khong ton tai!\n"; return; }

    vector<bool> visited(nodeCount, false);
    vector<int> parent(nodeCount, -1);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == dest) break;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[dest]) { cout << "Khong co duong di!\n"; return; }
    cout << "Duong di it diem nhat: ";
    printPath(parent, src, dest);
}

void dfsHelper(int u, vector<bool>& visited) {
    visited[u] = true;
    cout << names[u] << " ";
    for (int i = 0; i < (int)adj[u].size(); i++)
        if (!visited[adj[u][i].first]) dfsHelper(adj[u][i].first, visited);
}

void dfsTraversal() {
    string a;
    cout << "Bat dau tu: "; cin >> a;
    int src = findNode(a);
    if (src == -1) { cout << "Dia diem khong ton tai!\n"; return; }

    vector<bool> visited(nodeCount, false);
    cout << "Cac dia diem co the den: ";
    dfsHelper(src, visited);
    cout << "\n";
}
