// ============================================================
// Ten file: ClinicManagement.cpp
// Mo ta: Ung dung quan ly phong kham ket hop DSLK, Stack, Queue
// ============================================================
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Cấu trúc dữ liệu Bệnh nhân
struct BenhNhan {
    int id;
    string ten;
    BenhNhan *next;
};

// ============================================================
//  1. QUEUE: QUẢN LÝ HÀNG ĐỢI KHÁM (FIFO)
// ============================================================
struct Queue {
    BenhNhan *front, *rear;
};

void initQueue(Queue &q) { q.front = q.rear = nullptr; }

void enqueue(Queue &q, int id, string ten) {
    BenhNhan *p = new BenhNhan{id, ten, nullptr};
    if (q.front == nullptr) q.front = q.rear = p;
    else { q.rear->next = p; q.rear = p; }
}

BenhNhan* dequeue(Queue &q) {
    if (q.front == nullptr) return nullptr;
    BenhNhan *p = q.front;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    return p;
}

// ============================================================
//  2. STACK: LỊCH SỬ KHÁM GẦN ĐÂY (LIFO)
// ============================================================
struct Stack {
    BenhNhan *top;
};

void initStack(Stack &s) { s.top = nullptr; }

void push(Stack &s, int id, string ten) {
    BenhNhan *p = new BenhNhan{id, ten, s.top};
    s.top = p;
}

// ============================================================
//  3. DSLK: DANH SÁCH TẤT CẢ BỆNH NHÂN (QUẢN LÝ CHUNG)
// ============================================================
struct List {
    BenhNhan *head;
};

void initList(List &l) { l.head = nullptr; }

void addToList(List &l, int id, string ten) {
    BenhNhan *p = new BenhNhan{id, ten, l.head};
    l.head = p;
}

// Tìm kiếm bệnh nhân trong DSLK
void timBenhNhan(List l, int id) {
    BenhNhan *cur = l.head;
    while (cur) {
        if (cur->id == id) {
            cout << "Found: [" << cur->id << "] " << cur->ten << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Khong tim thay benh nhan ID: " << id << endl;
}

// ============================================================
//  GIAO DIỆN VÀ DEMO
// ============================================================
void menu() {
    cout << "\n--- HE THONG QUAN LY PHONG KHAM ---" << endl;
    cout << "1. Dang ky benh nhan moi (Vao hang cho)" << endl;
    cout << "2. Moi benh nhan tiep theo vao kham (Dequeue)" << endl;
    cout << "3. Xem lich su kham gan nhat (Stack)" << endl;
    cout << "4. Tra cuu benh nhan trong he thong (List)" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

int main() {
    Queue hangCho; initQueue(hangCho);
    Stack lichSu; initStack(lichSu);
    List danhMuc; initList(danhMuc);

    int chon, id_count = 101;
    string ten;

    do {
        menu();
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1:
                cout << "Nhap ten benh nhan: ";
                getline(cin, ten);
                enqueue(hangCho, id_count, ten);
                addToList(danhMuc, id_count, ten);
                cout << "==> Da them " << ten << " (ID: " << id_count++ << ") vao hang cho." << endl;
                break;

            case 2: {
                BenhNhan *p = dequeue(hangCho);
                if (p) {
                    cout << "==> Dang kham cho: " << p->ten << " (ID: " << p->id << ")" << endl;
                    push(lichSu, p->id, p->ten); // Lưu vào lịch sử
                    delete p;
                } else cout << "Hang cho dang rong!" << endl;
                break;
            }

            case 3:
                cout << "--- LICH SU KHAM GAN NHAT (TOP) ---" << endl;
                if (lichSu.top) 
                    cout << "Benh nhan vua kham xong: " << lichSu.top->ten << endl;
                else cout << "Chua co lich su khám." << endl;
                break;

            case 4:
                int searchId;
                cout << "Nhap ID can tim: "; cin >> searchId;
                timBenhNhan(danhMuc, searchId);
                break;
        }
    } while (chon != 0);

    return 0;
}
