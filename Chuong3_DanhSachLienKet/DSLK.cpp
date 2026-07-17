// ============================================================
//  QuanLySinhVien.cpp
//  Ví dụ thực tế: Quản lý danh sách sinh viên bằng DSLK đơn
//  Chức năng: Thêm/xóa, Tìm kiếm, Sắp xếp
// ============================================================
#include <iostream>
#include <string>
using namespace std;

// ===== CẤU TRÚC =====

struct SinhVien {
    string mssv;
    string ten;
    float  diem;
};

struct Node {
    SinhVien sv;
    Node *next;
};

struct DanhSach {
    Node *head, *tail;
};

// ===== TIỆN ÍCH =====

void KhoiTao(DanhSach &L) { L.head = L.tail = nullptr; }
bool Rong(const DanhSach &L) { return !L.head; }

Node* TaoNode(const SinhVien &sv) {
    return new Node{ sv, nullptr };
}

// In thông tin một sinh viên
void InSV(const SinhVien &sv) {
    cout << "  [" << sv.mssv << "] " << sv.ten << " - Diem: " << sv.diem << "\n";
}

// In toàn bộ danh sách
void InDS(const DanhSach &L) {
    if (Rong(L)) { cout << "  (Danh sach rong)\n"; return; }
    for (Node *p = L.head; p; p = p->next)
        InSV(p->sv);
}

// ===== THÊM =====

// Thêm sinh viên vào cuối danh sách
void ThemCuoi(DanhSach &L, const SinhVien &sv) {
    Node *p = TaoNode(sv);
    if (Rong(L)) L.head = L.tail = p;
    else { L.tail->next = p; L.tail = p; }
}

// Thêm sinh viên, giữ thứ tự tăng dần theo điểm
void ThemTheoThuTu(DanhSach &L, const SinhVien &sv) {
    Node *p = TaoNode(sv);
    // Chèn vào đầu nếu danh sách rỗng hoặc điểm nhỏ nhất
    if (Rong(L) || sv.diem <= L.head->sv.diem) {
        p->next = L.head; L.head = p;
        if (!L.tail) L.tail = p;
        return;
    }
    // Tìm vị trí chèn
    Node *cur = L.head;
    while (cur->next && cur->next->sv.diem < sv.diem)
        cur = cur->next;
    p->next = cur->next;
    cur->next = p;
    if (!p->next) L.tail = p;
}

// ===== XÓA =====

// Xóa sinh viên theo MSSV; trả về true nếu xóa thành công
bool XoaTheoMSSV(DanhSach &L, const string &mssv) {
    Node *cur = L.head, *prev = nullptr;
    while (cur && cur->sv.mssv != mssv) {
        prev = cur; cur = cur->next;
    }
    if (!cur) { cout << "  Khong tim thay MSSV: " << mssv << "\n"; return false; }
    if (!prev) L.head = cur->next;
    else prev->next = cur->next;
    if (cur == L.tail) L.tail = prev;
    delete cur;
    cout << "  Da xoa sinh vien co MSSV: " << mssv << "\n";
    return true;
}

// Giải phóng toàn bộ danh sách
void XoaDS(DanhSach &L) {
    while (!Rong(L)) {
        Node *p = L.head;
        L.head = L.head->next;
        delete p;
    }
    L.tail = nullptr;
}

// ===== TÌM KIẾM =====

// Tìm sinh viên theo MSSV; trả về nullptr nếu không có
Node* TimTheoMSSV(const DanhSach &L, const string &mssv) {
    for (Node *p = L.head; p; p = p->next)
        if (p->sv.mssv == mssv) return p;
    return nullptr;
}

// Tìm tất cả sinh viên có tên chứa chuỗi 'tukhoa' (không phân biệt hoa/thường)
void TimTheoTen(const DanhSach &L, const string &tukhoa) {
    bool co = false;
    for (Node *p = L.head; p; p = p->next) {
        // So sánh không phân biệt hoa/thường
        string ten = p->sv.ten, tk = tukhoa;
        for (char &c : ten) c = tolower(c);
        for (char &c : tk)  c = tolower(c);
        if (ten.find(tk) != string::npos) {
            InSV(p->sv); co = true;
        }
    }
    if (!co) cout << "  Khong tim thay sinh vien nao co ten \"" << tukhoa << "\"\n";
}

// ===== SẮP XẾP =====

// Sắp xếp tăng dần theo điểm (đổi data, không đổi con trỏ)
void SapXepTheoDiem(DanhSach &L) {
    for (Node *i = L.head; i && i->next; i = i->next)
        for (Node *j = i->next; j; j = j->next)
            if (i->sv.diem > j->sv.diem)
                swap(i->sv, j->sv);
}

// Sắp xếp tăng dần theo tên (A → Z)
void SapXepTheoTen(DanhSach &L) {
    for (Node *i = L.head; i && i->next; i = i->next)
        for (Node *j = i->next; j; j = j->next)
            if (i->sv.ten > j->sv.ten)
                swap(i->sv, j->sv);
}

// ===== MAIN =====

int main() {
    DanhSach L; KhoiTao(L);

    // Dữ liệu mẫu
    SinhVien dsv[] = {
        {"SV001", "Nguyen Van An",    7.5},
        {"SV002", "Tran Thi Bich",    8.2},
        {"SV003", "Le Van Cuong",     5.0},
        {"SV004", "Pham Thi Dung",    9.1},
        {"SV005", "Hoang Van Em",     6.3},
        {"SV006", "Nguyen Thi Phuong",8.0},
    };
    for (auto &sv : dsv) ThemCuoi(L, sv);

    cout << "========== DANH SACH SINH VIEN ==========\n";
    InDS(L);

    // --- Thêm mới ---
    cout << "\n>> Them sinh vien moi: SV007 - Do Minh Quan (7.0)\n";
    ThemCuoi(L, {"SV007", "Do Minh Quan", 7.0});
    InDS(L);

    // --- Xóa ---
    cout << "\n>> Xoa sinh vien SV003:\n";
    XoaTheoMSSV(L, "SV003");
    InDS(L);

    // --- Tìm theo MSSV ---
    cout << "\n>> Tim MSSV = SV004:\n";
    Node *kq = TimTheoMSSV(L, "SV004");
    if (kq) InSV(kq->sv);
    else cout << "  Khong tim thay.\n";

    // --- Tìm theo tên ---
    cout << "\n>> Tim tat ca sinh vien ten co \"nguyen\":\n";
    TimTheoTen(L, "nguyen");

    // --- Sắp xếp theo điểm ---
    cout << "\n>> Sap xep theo diem (tang dan):\n";
    SapXepTheoDiem(L);
    InDS(L);

    // --- Sắp xếp theo tên ---
    cout << "\n>> Sap xep theo ten (A -> Z):\n";
    SapXepTheoTen(L);
    InDS(L);

    XoaDS(L);
    return 0;
}
