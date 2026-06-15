#include "structures.h"
#include <queue>
#include <stack>
#include <climits>
#include <iomanip>
#include <algorithm>
#define _HAS_STD_BYTE 0
#include <windows.h>


BSTNode::BSTNode(Location loc) : data(loc), left(nullptr), right(nullptr) {}


CampusMap::CampusMap(int n) : root(nullptr), numLocations(n) {
    adjList.resize(n);
}


CampusMap::~CampusMap() {
    destroyBST(root);
}


BSTNode* CampusMap::insertBST(BSTNode* node, Location loc) {
    if (!node) return new BSTNode(loc);
    if (loc.id < node->data.id)
        node->left  = insertBST(node->left,  loc);
    else if (loc.id > node->data.id)
        node->right = insertBST(node->right, loc);
    else
        cout << "[!] ID " << loc.id << " da ton tai, bo qua.\n";
    return node;
}

BSTNode* CampusMap::searchBST(BSTNode* node, int id) const {
    if (!node || node->data.id == id) return node;
    return (id < node->data.id)
        ? searchBST(node->left,  id)
        : searchBST(node->right, id);
}

BSTNode* CampusMap::minNode(BSTNode* node) {
    while (node->left) node = node->left;
    return node;
}

BSTNode* CampusMap::deleteBST(BSTNode* node, int id) {
    if (!node) return nullptr;
    if (id < node->data.id) {
        node->left  = deleteBST(node->left,  id);
    } else if (id > node->data.id) {
        node->right = deleteBST(node->right, id);
    } else {

        if (!node->left) {
            BSTNode* tmp = node->right;
            delete node;
            return tmp;
        }
        if (!node->right) {
            BSTNode* tmp = node->left;
            delete node;
            return tmp;
        }

        BSTNode* successor = minNode(node->right);
        node->data  = successor->data;
        node->right = deleteBST(node->right, successor->data.id);
    }
    return node;
}

void CampusMap::inOrder(BSTNode* node) const {
    if (!node) return;
    inOrder(node->left);
    cout << "  [" << setw(2) << node->data.id << "] "
         << left << setw(20) << node->data.name
         << " | " << node->data.description << "\n";
    inOrder(node->right);
}

void CampusMap::destroyBST(BSTNode* node) {
    if (!node) return;
    destroyBST(node->left);
    destroyBST(node->right);
    delete node;
}


bool CampusMap::dijkstra(int start, int target,
                  vector<int>& dist, vector<int>& parent) const {
    dist.assign(numLocations, INT_MAX);
    parent.assign(numLocations, -1);
    dist[start] = 0;

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        if (u == target) return true;
        for (const Edge& e : adjList[u]) {
            int nd = dist[u] + e.weight;
            if (nd < dist[e.to]) {
                dist[e.to]   = nd;
                parent[e.to] = u;
                pq.push({nd, e.to});
            }
        }
    }
    return dist[target] != INT_MAX;
}


bool CampusMap::bfsConnected(int s) const {
    vector<bool> visited(numLocations, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    int count = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const Edge& e : adjList[u]) {
            if (!visited[e.to]) {
                visited[e.to] = true;
                ++count;
                q.push(e.to);
            }
        }
    }
    return count == numLocations;
}


void CampusMap::addLocation(int id, const string& name, const string& desc) {
    if (id < 0 || id >= numLocations) {
        cout << "[!] ID phai trong khoang [0, " << numLocations - 1 << "]\n";
        return;
    }
    Location loc = {id, name, desc};
    root = insertBST(root, loc);
}

void CampusMap::removeLocation(int id) {
    if (!searchBST(root, id)) {
        cout << "[-] Khong tim thay dia diem ID " << id << "\n";
        return;
    }

    for (int u = 0; u < numLocations; ++u) {
        auto& edges = adjList[u];
        edges.erase(remove_if(edges.begin(), edges.end(),
                    [id](const Edge& e){ return e.to == id; }),
                    edges.end());
    }
    adjList[id].clear();
    root = deleteBST(root, id);
    cout << "[+] Da xoa dia diem ID " << id << " va cac duong di lien quan.\n";
}

void CampusMap::searchAndPrint(int id) const {
    BSTNode* result = searchBST(root, id);
    if (result) {
        cout << "\n[+] Thong tin dia diem:\n";
        cout << "  - ID  : " << result->data.id   << "\n";
        cout << "  - Ten : " << result->data.name << "\n";
        cout << "  - Mo ta: " << result->data.description << "\n";
    } else {
        cout << "\n[-] Khong tim thay dia diem co ID: " << id << "\n";
    }
}

void CampusMap::printAllLocations() const {
    cout << "\n===== DANH SACH DIA DIEM =====\n";
    cout << left << setw(6)  << "  ID"
         << setw(22) << "Ten"
         << "Mo ta\n";
    cout << string(60, '-') << "\n";
    inOrder(root);
}

void CampusMap::addPath(int u, int v, int weight) {
    if (u < 0 || v < 0 || u >= numLocations || v >= numLocations) {
        cout << "[!] ID khong hop le!\n"; return;
    }

    for (const Edge& e : adjList[u])
        if (e.to == v) { cout << "[!] Duong di da ton tai.\n"; return; }

    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});
    cout << "[+] Da them duong di: "
         << searchBST(root, u)->data.name << " <-> "
         << searchBST(root, v)->data.name
         << " (" << weight << "m)\n";
}

void CampusMap::removePath(int u, int v) {
    bool removed = false;
    auto erase = [&](int from, int to) {
        auto& edges = adjList[from];
        auto it = remove_if(edges.begin(), edges.end(),
                            [to](const Edge& e){ return e.to == to; });
        if (it != edges.end()) { edges.erase(it, edges.end()); removed = true; }
    };
    erase(u, v); erase(v, u);
    if (removed) cout << "[+] Da xoa duong di giua " << u << " va " << v << ".\n";
    else         cout << "[-] Khong tim thay duong di giua " << u << " va " << v << ".\n";
}

void CampusMap::showNeighbors(int id) const {
    BSTNode* node = searchBST(root, id);
    if (!node) { cout << "[-] Khong tim thay ID " << id << "\n"; return; }
    cout << "\n[+] Cac dia diem ke " << node->data.name << ":\n";
    if (adjList[id].empty()) { cout << "  (Khong co duong di nao)\n"; return; }
    for (const Edge& e : adjList[id]) {
        BSTNode* nb = searchBST(root, e.to);
        cout << "  -> [" << e.to << "] "
             << (nb ? nb->data.name : "???")
             << " (" << e.weight << "m)\n";
    }
}

void CampusMap::findShortestPath(int start, int target) const {
    BSTNode* sNode = searchBST(root, start);
    BSTNode* tNode = searchBST(root, target);
    if (!sNode || !tNode) { cout << "[-] ID khong hop le!\n"; return; }
    if (start == target)  { cout << "[!] Diem dau va cuoi trung nhau.\n"; return; }

    vector<int> dist, parent;
    bool found = dijkstra(start, target, dist, parent);

    if (!found) {
        cout << "\n[-] Khong co duong di tu \""
             << sNode->data.name << "\" den \""
             << tNode->data.name << "\"\n";
        return;
    }

    stack<int> path;
    for (int cur = target; cur != -1; cur = parent[cur])
        path.push(cur);

    cout << "\n[+] Duong di ngan nhat:\n";
    cout << "    Tu: " << sNode->data.name << "\n";
    cout << "    Den: " << tNode->data.name << "\n";
    cout << "    Tong khoang cach: " << dist[target] << "m\n\n";
    cout << "    Lo trinh: ";
    while (!path.empty()) {
        int locId = path.top(); path.pop();
        BSTNode* n = searchBST(root, locId);
        cout << (n ? n->data.name : "???");
        if (!path.empty()) cout << " => ";
    }
    cout << "\n";
}

void CampusMap::checkConnectivity() const {
    BSTNode* any = root;
    if (!any) { cout << "[!] Ban do trong.\n"; return; }
    while (any->left) any = any->left;

    bool connected = bfsConnected(any->data.id);
    if (connected)
        cout << "\n[+] Ban do LIEN THONG: Moi dia diem deu co the den duoc.\n";
    else
        cout << "\n[!] Ban do KHONG lien thong: Co dia diem bi co lap.\n";
}