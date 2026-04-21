// ============================================================
// ch4_tree.cpp  —  Chapter 4: BST + Traversals
// Compile: g++ -std=c++17 ch4_tree.cpp -o ch4 && ./ch4
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

struct Node { int v; Node *l, *r; explicit Node(int x): v(x),l(nullptr),r(nullptr){} };

// ════════════════════════════════════════════════════════════
// Binary Search Tree
// ════════════════════════════════════════════════════════════
struct BST {
    Node* root = nullptr;

    // Insert — O(h)
    Node* insert(Node* n, int v){
        if(!n) return new Node(v);
        if(v < n->v) n->l = insert(n->l, v);
        else if(v > n->v) n->r = insert(n->r, v);
        return n;                          // duplicate ignored
    }
    void insert(int v){ root = insert(root, v); }

    // Search — O(h)
    bool search(Node* n, int v){
        if(!n) return false;
        if(v == n->v) return true;
        return v < n->v ? search(n->l,v) : search(n->r,v);
    }
    bool search(int v){ return search(root, v); }

    // Delete — O(h)
    Node* find_min(Node* n){ while(n->l) n=n->l; return n; }
    Node* remove(Node* n, int v){
        if(!n) return nullptr;
        if(v < n->v) n->l = remove(n->l, v);
        else if(v > n->v) n->r = remove(n->r, v);
        else {
            if(!n->l && !n->r){ delete n; return nullptr; }
            if(!n->l){ Node* t=n->r; delete n; return t; }
            if(!n->r){ Node* t=n->l; delete n; return t; }
            Node* s = find_min(n->r);
            n->v = s->v;
            n->r = remove(n->r, s->v);
        }
        return n;
    }
    void remove(int v){ root = remove(root, v); }

    // ── Traversals ───────────────────────────────────────────
    void inorder  (Node* n, vector<int>& r){ if(!n)return; inorder(n->l,r); r.push_back(n->v); inorder(n->r,r); }
    void preorder (Node* n, vector<int>& r){ if(!n)return; r.push_back(n->v); preorder(n->l,r); preorder(n->r,r); }
    void postorder(Node* n, vector<int>& r){ if(!n)return; postorder(n->l,r); postorder(n->r,r); r.push_back(n->v); }

    vector<int> inorder()  { vector<int> r; inorder(root,r);   return r; }
    vector<int> preorder() { vector<int> r; preorder(root,r);  return r; }
    vector<int> postorder(){ vector<int> r; postorder(root,r); return r; }

    // BFS — level order
    vector<vector<int>> level_order(){
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            int sz=q.size(); vector<int> lvl;
            for(int i=0;i<sz;i++){
                Node* n=q.front(); q.pop();
                lvl.push_back(n->v);
                if(n->l) q.push(n->l);
                if(n->r) q.push(n->r);
            }
            res.push_back(lvl);
        }
        return res;
    }

    // Height
    int height(Node* n){ if(!n)return 0; return 1+max(height(n->l),height(n->r)); }
    int height(){ return height(root); }

    // Valid BST check
    bool is_valid(Node* n, int mn=INT_MIN, int mx=INT_MAX){
        if(!n) return true;
        if(n->v<=mn || n->v>=mx) return false;
        return is_valid(n->l,mn,n->v) && is_valid(n->r,n->v,mx);
    }
    bool is_valid(){ return is_valid(root); }

    // ── ASCII Print ───────────────────────────────────────────
    void print(Node* n, int indent=0, bool isR=false, string pfx=""){
        if(!n) return;
        print(n->r, indent+1, true, pfx + (indent?"    ":""));
        cout << pfx;
        if(indent) cout << (isR ? "  /-" : "  \\-");
        cout << "\033[33m[" << n->v << "]\033[0m\n";
        print(n->l, indent+1, false, pfx + (indent?"    ":""));
    }
    void print(){ print(root,0,false,""); }

    void free(Node* n){ if(!n)return; free(n->l); free(n->r); delete n; }
    ~BST(){ free(root); }
};

// ── Print vector ─────────────────────────────────────────────
void pv(vector<int> v, string lbl){
    cout << lbl << ": [";
    for(int i=0;i<(int)v.size();i++){ cout<<v[i]; if(i+1<(int)v.size()) cout<<","; }
    cout << "]\n";
}

int main(){
    cout << "╔══════════════════════════════════════╗\n"
         << "║  Chapter 4: BST + Traversals          ║\n"
         << "╚══════════════════════════════════════╝\n\n";

    BST bst;
    vector<int> vals = {50,30,70,20,40,60,80,10,25,35,45};
    cout << "Inserting: ";
    for(int v : vals){ cout << v << " "; bst.insert(v); }
    cout << "\n\n";

    // ASCII tree
    cout << "=== ASCII Tree ===\n";
    bst.print();
    cout << "\nHeight: " << bst.height() << "  |  Valid BST: "
         << (bst.is_valid()?"YES":"NO") << "\n\n";

    // Traversals
    cout << "=== Traversals ===\n";
    pv(bst.inorder(),   "Inorder   (sorted!)");
    pv(bst.preorder(),  "Preorder  (root 1st)");
    pv(bst.postorder(), "Postorder (root last)");

    cout << "\nLevel-order (BFS):\n";
    for(auto& lvl : bst.level_order()){
        cout << "  Level: ";
        for(int x : lvl) cout << x << " ";
        cout << "\n";
    }

    // Search
    cout << "\n=== Search ===\n";
    for(int t : {40, 55, 10, 100})
        cout << "search(" << t << "): "
             << (bst.search(t)?"\033[32mFOUND\033[0m":"\033[31mNOT FOUND\033[0m") << "\n";

    // Delete
    cout << "\n=== Delete ===\n";
    cout << "Delete 20 (has 2 children — replace with inorder successor):\n";
    bst.remove(20);
    bst.print();
    pv(bst.inorder(), "Inorder after delete");

    // Balanced vs degenerate
    cout << "\n=== Balanced vs Degenerate ===\n";
    BST bal, deg;
    for(int v : {4,2,6,1,3,5,7}) bal.insert(v);
    for(int v : {1,2,3,4,5,6,7}) deg.insert(v);
    cout << "Balanced (height=" << bal.height() << "):\n"; bal.print();
    cout << "\nDegenerate/sorted input (height=" << deg.height() << ") — nhu linked list!\n";
    deg.print();

    cout << "\n=== Bài tập ===\n"
         << "Easy  : Dem so node trong BST\n"
         << "Medium: Kiem tra BST co balanced khong (|h_left - h_right| <= 1)\n"
         << "Medium: Serialize/Deserialize BST thanh string\n"
         << "Hard  : Implement AVL Tree (tu can bang)\n";
    return 0;
}
