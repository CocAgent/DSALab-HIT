// ============================================================
// ch5_graph.cpp  —  Chapter 5: BFS + DFS + Dijkstra
// Compile: g++ -std=c++17 ch5_graph.cpp -o ch5 && ./ch5
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

// ════════════════════════════════════════════════════════════
// Graph (adjacency list)
// ════════════════════════════════════════════════════════════
struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;   // {neighbor, weight}

    explicit Graph(int v): V(v), adj(v) {}

    void add_edge(int u, int v, int w=1, bool directed=false){
        adj[u].push_back({v,w});
        if(!directed) adj[v].push_back({u,w});
    }

    // ── BFS — Breadth First Search O(V+E) ────────────────────
    vector<int> bfs(int src, bool verbose=true){
        vector<bool> vis(V,false);
        vector<int>  dist(V,-1), order;
        queue<int>   q;
        vis[src]=true; dist[src]=0; q.push(src);

        if(verbose) cout << "\nBFS tu " << src << ":\n";
        while(!q.empty()){
            int u=q.front(); q.pop();
            order.push_back(u);
            if(verbose) cout << "  Visit " << u << "  (level=" << dist[u] << ")\n";
            for(auto[v,w] : adj[u]){
                if(!vis[v]){
                    vis[v]=true; dist[v]=dist[u]+1; q.push(v);
                    if(verbose) cout << "    enqueue " << v << "\n";
                }
            }
        }
        return order;
    }

    // ── DFS — Depth First Search O(V+E) ──────────────────────
    void dfs_rec(int u, vector<bool>& vis, vector<int>& order, int depth=0){
        vis[u]=true; order.push_back(u);
        cout << string(depth*2,' ') << "\033[33m[" << u << "]\033[0m\n";
        for(auto[v,w] : adj[u]){
            if(!vis[v]){
                cout << string(depth*2+1,' ') << "-> " << v << "\n";
                dfs_rec(v, vis, order, depth+1);
            }
        }
        cout << string(depth*2,' ') << "<< backtrack\n";
    }
    vector<int> dfs(int src){
        vector<bool> vis(V,false); vector<int> order;
        cout << "\nDFS tu " << src << " (call stack):\n";
        dfs_rec(src, vis, order);
        return order;
    }

    // ── Dijkstra — Shortest Path O((V+E) log V) ──────────────
    struct DijkRes { vector<int> dist, prev; };
    DijkRes dijkstra(int src){
        vector<int> dist(V,INT_MAX), prev(V,-1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src]=0; pq.push({0,src});

        while(!pq.empty()){
            auto[d,u]=pq.top(); pq.pop();
            if(d>dist[u]) continue;
            for(auto[v,w] : adj[u])
                if(dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w; prev[v]=u;
                    pq.push({dist[v],v});
                }
        }
        return {dist, prev};
    }

    vector<int> shortest_path(DijkRes& r, int src, int dst){
        vector<int> path;
        for(int at=dst; at!=-1; at=r.prev[at]) path.push_back(at);
        reverse(path.begin(), path.end());
        return (path.empty()||path[0]!=src) ? vector<int>{} : path;
    }

    // ── Cycle detection (undirected) ──────────────────────────
    bool has_cycle_dfs(int u, int parent, vector<bool>& vis){
        vis[u]=true;
        for(auto[v,w] : adj[u]){
            if(!vis[v]){ if(has_cycle_dfs(v,u,vis)) return true; }
            else if(v!=parent){ cout << "  Back edge: " << u << "->" << v << "\n"; return true; }
        }
        return false;
    }
    bool has_cycle(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++) if(!vis[i] && has_cycle_dfs(i,-1,vis)) return true;
        return false;
    }

    // ── Topological Sort (DAG) ────────────────────────────────
    void topo_dfs(int u, vector<bool>& vis, stack<int>& stk){
        vis[u]=true;
        for(auto[v,w] : adj[u]) if(!vis[v]) topo_dfs(v,vis,stk);
        stk.push(u);
    }
    vector<int> topological_sort(){
        vector<bool> vis(V,false); stack<int> stk;
        for(int i=0;i<V;i++) if(!vis[i]) topo_dfs(i,vis,stk);
        vector<int> order;
        while(!stk.empty()){ order.push_back(stk.top()); stk.pop(); }
        return order;
    }
};

void pv(vector<int> v, string lbl){
    cout << lbl << ": ";
    for(int x:v) cout<<x<<" "; cout<<"\n";
}

int main(){
    cout << "╔══════════════════════════════════════╗\n"
         << "║  Chapter 5: BFS + DFS + Dijkstra     ║\n"
         << "╚══════════════════════════════════════╝\n";

    // ── BFS ───────────────────────────────────────────────────
    cout << "\nGraph: 0-1-2-3-4-5 (undirected)\n";
    Graph g(6);
    g.add_edge(0,1); g.add_edge(0,2);
    g.add_edge(1,3); g.add_edge(1,4);
    g.add_edge(2,4); g.add_edge(3,5); g.add_edge(4,5);

    pv(g.bfs(0,false), "BFS order");

    // ── DFS ───────────────────────────────────────────────────
    pv(g.dfs(0), "\nDFS order");

    // ── Cycle detection ───────────────────────────────────────
    cout << "\n=== Cycle Detection ===\n";
    Graph g_tree(4);
    g_tree.add_edge(0,1); g_tree.add_edge(1,2); g_tree.add_edge(2,3);
    cout << "0-1-2-3 (no cycle): " << (g_tree.has_cycle()?"YES":"NO") << "\n";
    Graph g_cycle(4);
    g_cycle.add_edge(0,1); g_cycle.add_edge(1,2); g_cycle.add_edge(2,3); g_cycle.add_edge(3,0);
    cout << "0-1-2-3-0 (cycle):  " << (g_cycle.has_cycle()?"YES":"NO") << "\n";

    // ── Dijkstra ──────────────────────────────────────────────
    cout << "\n=== Dijkstra Shortest Path ===\n";
    Graph wg(6);
    wg.add_edge(0,1,7); wg.add_edge(0,2,9); wg.add_edge(0,5,14);
    wg.add_edge(1,2,10);wg.add_edge(1,3,15);
    wg.add_edge(2,3,11);wg.add_edge(2,5,2);
    wg.add_edge(3,4,6); wg.add_edge(4,5,9);

    auto res = wg.dijkstra(0);
    cout << "Khoang cach ngan nhat tu node 0:\n";
    for(int i=0;i<6;i++){
        auto path = wg.shortest_path(res, 0, i);
        cout << "  -> " << i << ": dist=" << setw(3) << res.dist[i] << "  path: ";
        for(int j=0;j<(int)path.size();j++){ cout<<path[j]; if(j+1<(int)path.size()) cout<<"->"; }
        cout << "\n";
    }

    // ── Topological Sort ──────────────────────────────────────
    cout << "\n=== Topological Sort (DAG) ===\n";
    cout << "Tasks: 0(compile) -> 2(link), 1(assets) -> 2, 2 -> 4(test), 0 -> 3(docs)\n";
    Graph dag(5);
    dag.add_edge(0,2,1,true); dag.add_edge(1,2,1,true);
    dag.add_edge(2,4,1,true); dag.add_edge(0,3,1,true);
    pv(dag.topological_sort(), "Build order");

    // ── BFS Maze solver ──────────────────────────────────────
    cout << "\n=== BFS Maze Solver ===\n";
    vector<string> maze = {"S..#..","#.#.#.","....#.","##.##.","...#.E"};
    int R=maze.size(), C=maze[0].size();
    pair<int,int> start={0,0}, end_={R-1,C-1};
    vector<vector<bool>> vis(R,vector<bool>(C,false));
    vector<vector<pair<int,int>>> prev(R,vector<pair<int,int>>(C,{-1,-1}));
    queue<pair<int,int>> mq; mq.push(start); vis[0][0]=true;
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    while(!mq.empty()){
        auto[r,c]=mq.front(); mq.pop();
        if(r==end_.first&&c==end_.second) break;
        for(int d=0;d<4;d++){
            int nr=r+dx[d],nc=c+dy[d];
            if(nr>=0&&nr<R&&nc>=0&&nc<C&&!vis[nr][nc]&&maze[nr][nc]!='#'){
                vis[nr][nc]=true; prev[nr][nc]={r,c}; mq.push({nr,nc});
            }
        }
    }
    auto [er,ec]=end_;
    for(auto [r,c]=end_; prev[r][c].first!=-1; tie(r,c)=prev[r][c])
        if(maze[r][c]!='E') maze[r][c]='*';
    for(auto& row:maze){ cout<<"  "; for(char ch:row) cout<<(ch=='*'?"\033[32m*\033[0m":string(1,ch)); cout<<"\n"; }

    cout << "\n=== Bài tập ===\n"
         << "Easy  : BFS dem so connected components\n"
         << "Medium: Kiem tra graph co biet partite (2-colorable)\n"
         << "Medium: Bellman-Ford (xu ly negative weights)\n"
         << "Hard  : Minimum Spanning Tree (Prim hoac Kruskal)\n";
    return 0;
}
