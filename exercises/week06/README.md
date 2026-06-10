# Tuần 6: Danh Sách Liên Kết Đơn — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt Singly Linked List, thành thạo con trỏ, thêm/xóa/duyệt.

---

### Bài 1: Cài đặt Linked List ⭐⭐
Cài đặt đầy đủ: thêm đầu, thêm cuối, xóa đầu, xóa cuối, xóa theo giá trị, tìm kiếm, in danh sách.

### Bài 2: Đảo ngược danh sách ⭐⭐
Đảo ngược Linked List bằng 2 cách: iterative (3 con trỏ) và recursive. So sánh.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void push_back(int val) {
        if (!head) { head = new Node(val); return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = new Node(val);
    }

    // Đảo ngược Iterative (3 con trỏ)
    void reverse_iterative() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Đảo ngược Recursive
    Node* reverse_recursive(Node* node) {
        if (!node || !node->next) return node;
        Node* newHead = reverse_recursive(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }
};

### Bài 3: Phát hiện vòng lặp ⭐⭐⭐
Cài đặt Floyd's Cycle Detection (slow/fast pointer). Tìm điểm bắt đầu vòng lặp.
Node* detectStartOfLoop(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            Node* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // Điểm bắt đầu vòng lặp
        }
    }
    return nullptr;
}

### Bài 4: 🔥 Dự Án Mini — Lịch Sử Trình Duyệt ⭐⭐⭐
> **Cảm hứng:** BaiTapTongHop — Lịch sử trình duyệt (DSALab)

Mô phỏng lịch sử duyệt web bằng Singly Linked List:
```
=== TRÌNH DUYỆT WEB (Linked List) ===
> visit google.com
> visit facebook.com  
> visit youtube.com
> back
← Quay lại: facebook.com
> back
← Quay lại: google.com
> forward
→ Tiến tới: facebook.com
> history
📋 Lịch sử: google.com → facebook.com → youtube.com
                                ↑ (đang ở đây)
```
#include <vector>
#include <string>

class BrowserHistory {
private:
    vector<string> history;
    int curr_idx = -1;

public:
    void visit(string url) {
        // Xóa các trang sau curr_idx
        history.erase(history.begin() + curr_idx + 1, history.end());
        history.push_back(url);
        if (history.size() > 50) history.erase(history.begin());
        else curr_idx++;
    }

    string back() {
        if (curr_idx > 0) return history[--curr_idx];
        return "N/A";
    }

    string forward() {
        if (curr_idx < history.size() - 1) return history[++curr_idx];
        return "N/A";
    }
};
**Yêu cầu:** hỗ trợ visit, back, forward, history, clear, tối đa 50 trang trong lịch sử.

---
📁 Tham khảo: `Chuong3_DanhSachLienKet/Chuong3_DanhSachLienKet.cpp`
