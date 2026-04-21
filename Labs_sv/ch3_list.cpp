// ============================================================
// ch3_list.cpp  —  Chapter 3: Linked List + Stack + Queue
// Compile: g++ -std=c++17 ch3_list.cpp -o ch3 && ./ch3
// ============================================================
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <vector>
#include <functional>
using namespace std;

struct Node { int data; Node* next; explicit Node(int v): data(v), next(nullptr){} };

// ════════════════════════════════════════════════════════════
// Linked List (Singly)
// ════════════════════════════════════════════════════════════
struct LinkedList {
    Node* head = nullptr;
    int   size  = 0;

    void push_front(int v){ Node* n=new Node(v); n->next=head; head=n; ++size; }
    void push_back(int v){
        Node* n=new Node(v); ++size;
        if(!head){ head=n; return; }
        Node* c=head; while(c->next) c=c->next; c->next=n;
    }
    bool remove(int v){
        if(!head) return false;
        if(head->data==v){ Node* t=head; head=head->next; delete t; --size; return true; }
        for(Node* c=head; c->next; c=c->next)
            if(c->next->data==v){ Node* t=c->next; c->next=t->next; delete t; --size; return true; }
        return false;
    }
    bool search(int v){ for(Node* c=head;c;c=c->next) if(c->data==v) return true; return false; }

    // Đảo ngược in-place — O(n), 3 con trỏ
    void reverse(){
        Node *prev=nullptr, *curr=head, *nxt;
        while(curr){ nxt=curr->next; curr->next=prev; prev=curr; curr=nxt; }
        head=prev;
    }

    // Floyd's cycle detection — O(n), O(1) space
    bool has_cycle(){
        Node *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next; fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }

    // Tìm node giữa — slow/fast pointer
    Node* find_middle(){
        Node *slow=head, *fast=head;
        while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }
        return slow;
    }

    void print(string lbl=""){
        if(!lbl.empty()) cout << lbl << ": ";
        for(Node* c=head; c; c=c->next) cout << c->data << (c->next?" -> ":"");
        cout << " -> NULL  (size=" << size << ")\n";
    }

    ~LinkedList(){ while(head){ Node* t=head; head=head->next; delete t; } }
};

// ════════════════════════════════════════════════════════════
// Stack (LIFO) — push/pop tại head = O(1)
// ════════════════════════════════════════════════════════════
struct Stack {
    Node* top = nullptr;
    int   sz  = 0;

    void push(int v, bool silent=false){
        Node* n=new Node(v); n->next=top; top=n; ++sz;
        cout << "  push(" << v << ")  stack size=" << sz << "\n";
    }
    int pop(){
        if(!top) throw runtime_error("Stack underflow!");
        int v=top->data; Node* t=top; top=top->next; delete t; --sz; return v;
    }
    int peek(){ return top ? top->data : -1; }
    bool empty(){ return !top; }
    ~Stack(){ while(top){ Node* t=top; top=top->next; delete t; } }
};

// ════════════════════════════════════════════════════════════
// Queue (FIFO) — enqueue tại back, dequeue tại front = O(1)
// ════════════════════════════════════════════════════════════
struct Queue {
    Node *front=nullptr, *back=nullptr;
    int   sz=0;

    void enqueue(int v){
        Node* n=new Node(v); ++sz;
        if(!back){ front=back=n; return; }
        back->next=n; back=n;
        cout << "  enqueue(" << v << ")  queue size=" << sz << "\n";
    }
    int dequeue(){
        if(!front) throw runtime_error("Queue underflow!");
        int v=front->data; Node* t=front;
        front=front->next; if(!front) back=nullptr;
        delete t; --sz; return v;
    }
    bool empty(){ return !front; }
    ~Queue(){ while(front){ Node* t=front; front=front->next; delete t; } }
};

// ════════════════════════════════════════════════════════════
// Min-Heap (Priority Queue) — đơn giản nhất
// ════════════════════════════════════════════════════════════
struct MinHeap {
    vector<int> data;
    int parent(int i){ return (i-1)/2; }
    int left(int i)  { return 2*i+1;   }
    int right(int i) { return 2*i+2;   }

    void push(int v, bool silent=false){
        data.push_back(v);
        int i=data.size()-1;
        while(i>0 && data[parent(i)]>data[i]){ swap(data[i],data[parent(i)]); i=parent(i); }
    }
    int top(){ return data[0]; }
    void pop(){
        data[0]=data.back(); data.pop_back();
        int i=0, n=data.size();
        while(true){
            int s=i, l=left(i), r=right(i);
            if(l<n && data[l]<data[s]) s=l;
            if(r<n && data[r]<data[s]) s=r;
            if(s==i) break; swap(data[i],data[s]); i=s;
        }
    }
    bool empty(){ return data.empty(); }
};

int main(){
    cout << "╔══════════════════════════════════════╗\n"
         << "║  Chapter 3: Linked List + Stack + Q  ║\n"
         << "╚══════════════════════════════════════╝\n\n";

    // ── Linked List ───────────────────────────────────────────
    cout << "=== Linked List ===\n";
    LinkedList lst;
    for(int x : {10,20,30,40,50}) lst.push_back(x);
    lst.print("Original   ");
    lst.reverse();
    lst.print("Reversed   ");

    Node* mid = lst.find_middle();
    cout << "Middle node: " << (mid ? to_string(mid->data) : "null") << "\n";

    lst.remove(30);
    lst.print("After rm 30");
    cout << "Search 20: " << (lst.search(20)?"FOUND":"NOT FOUND") << "\n";
    cout << "Has cycle:  " << (lst.has_cycle()?"YES":"NO") << "\n\n";

    // ── Stack ─────────────────────────────────────────────────
    cout << "=== Stack (LIFO) ===\n";
    Stack stk;
    stk.push(1); stk.push(2); stk.push(3);
    cout << "Peek: " << stk.peek() << "\n";
    while(!stk.empty()) cout << "  pop -> " << stk.pop() << "\n";

    // Stack ứng dụng: kiểm tra ngoặc hợp lệ
    cout << "\nKiem tra ngoac:\n";
    auto check_brackets = [](string s){
        Stack st;
        for(char c : s){
            if(c=='('||c=='['||c=='{') st.push(c,true);
            else if(c==')'||c==']'||c=='}'){
                if(st.empty()) return false;
                int top=st.pop();
                if((c==')'&&top!='(')||(c==']'&&top!='[')||(c=='}'&&top!='{')) return false;
            }
        }
        return st.empty();
    };
    for(string s : {"(()[]{})", "((())", "{[()]}"})
        cout << "  \"" << s << "\" -> " << (check_brackets(s)?"VALID":"INVALID") << "\n";

    // ── Queue ─────────────────────────────────────────────────
    cout << "\n=== Queue (FIFO) ===\n";
    Queue q;
    q.enqueue(100); q.enqueue(200); q.enqueue(300);
    cout << "  dequeue -> " << q.dequeue() << "\n";
    cout << "  dequeue -> " << q.dequeue() << "\n";

    // ── Min-Heap (Priority Queue) ─────────────────────────────
    cout << "\n=== Min-Heap (Priority Queue) ===\n";
    MinHeap heap;
    for(int v : {5,3,8,1,4,2,7}) heap.push(v);
    cout << "Extract-min sequence: ";
    while(!heap.empty()){ cout << heap.top() << " "; heap.pop(); }
    cout << "(sorted!)\n";

    cout << "\n=== Bài tập ===\n"
         << "Easy  : Implement Doubly Linked List\n"
         << "Medium: Merge 2 sorted linked lists\n"
         << "Medium: Implement LRU Cache (HashMap + Doubly List)\n"
         << "Hard  : Clone linked list co random pointer\n";
    return 0;
}
