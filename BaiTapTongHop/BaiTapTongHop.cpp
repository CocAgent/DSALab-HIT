// ============================================================
//  BaiTapTongHop.cpp
//  Ung dung tong hop cac CTDL da hoc vao bai toan thuc te
//  Giao trinh: Cau truc du lieu & Giai thuat - CDCTTP.HCM
// ============================================================
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
//  UNG DUNG 1: QUAN LY SINH VIEN (Mang + Sap xep)
// ============================================================
struct SinhVien {
    int masv;
    char hoten[51];
    float dtb;
};

const int MAX_SV = 100;

void NhapSV(SinhVien ds[], int &n) {
    cout << "  Nhap so sinh vien: "; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "  SV " << i+1 << ":\n";
        cout << "    Ma SV: "; cin >> ds[i].masv;
        cin.ignore();
        cout << "    Ho ten: "; cin.getline(ds[i].hoten, 51);
        cout << "    DTB: "; cin >> ds[i].dtb;
    }
}

void InDsSV(const SinhVien ds[], int n) {
    cout << "  " << string(55, '-') << "\n";
    cout << "  " << setw(6) << "MaSV"
         << setw(25) << "Ho Ten"
         << setw(8) << "DTB" << "\n";
    cout << "  " << string(55, '-') << "\n";
    for (int i = 0; i < n; i++) {
        cout << "  " << setw(6) << ds[i].masv
             << setw(25) << ds[i].hoten
             << setw(8) << fixed << setprecision(2) << ds[i].dtb << "\n";
    }
    cout << "  " << string(55, '-') << "\n";
}

// Sap xep SV theo DTB giam dan (Selection Sort)
void SapXepSVTheoDTB(SinhVien ds[], int n) {
    for (int i = 0; i < n-1; i++) {
        int vt = i;
        for (int j = i+1; j < n; j++)
            if (ds[j].dtb > ds[vt].dtb) vt = j;
        if (vt != i) {
            SinhVien t = ds[i]; ds[i] = ds[vt]; ds[vt] = t;
        }
    }
}

// Tim SV co DTB cao nhat
int TimSVMaxDTB(const SinhVien ds[], int n) {
    int vt = 0;
    for (int i = 1; i < n; i++)
        if (ds[i].dtb > ds[vt].dtb) vt = i;
    return vt;
}

void DemoQLSinhVien() {
    cout << "\n=== UNG DUNG 1: QUAN LY SINH VIEN ===\n";
    SinhVien ds[] = {
        {1001, "Nguyen Van An",   7.5f},
        {1002, "Tran Thi Binh",  8.2f},
        {1003, "Le Van Cuong",    6.9f},
        {1004, "Pham Thi Dung",   9.1f},
        {1005, "Hoang Van Em",    5.8f},
        {1006, "Vo Thi Phuong",   8.7f},
    };
    int n = 6;

    cout << "\n  [1] Danh sach ban dau:\n";
    InDsSV(ds, n);

    int vt = TimSVMaxDTB(ds, n);
    cout << "\n  [2] SV dat diem cao nhat: " << ds[vt].hoten
         << " - DTB: " << ds[vt].dtb << "\n";

    SapXepSVTheoDTB(ds, n);
    cout << "\n  [3] Sap xep theo DTB giam dan:\n";
    InDsSV(ds, n);

    // Xep loai
    cout << "\n  [4] Xep loai:\n";
    for (int i = 0; i < n; i++) {
        string xloai;
        if (ds[i].dtb >= 9.0) xloai = "Xuat sac";
        else if (ds[i].dtb >= 8.0) xloai = "Gioi";
        else if (ds[i].dtb >= 6.5) xloai = "Kha";
        else if (ds[i].dtb >= 5.0) xloai = "Trung binh";
        else xloai = "Yeu";
        cout << "    " << setw(25) << ds[i].hoten
             << " -> " << xloai << "\n";
    }
}

// ============================================================
//  UNG DUNG 2: LICH SU TRINH DUYET (Stack)
// ============================================================
struct StackStr {
    string data[100];
    int top;
};

void KhoiTao(StackStr &S) { S.top = -1; }
bool Rong(const StackStr &S) { return S.top == -1; }
void Push(StackStr &S, const string &s) {
    if (S.top < 99) S.data[++S.top] = s;
}
string Pop(StackStr &S) {
    if (Rong(S)) return "";
    return S.data[S.top--];
}
string Peek(const StackStr &S) {
    return Rong(S) ? "" : S.data[S.top];
}

void DemoLichSuTrinhDuyet() {
    cout << "\n=== UNG DUNG 2: LICH SU TRINH DUYET (Stack) ===\n";
    StackStr lichSu; KhoiTao(lichSu);
    StackStr tiepTheo; KhoiTao(tiepTheo);

    auto trangHienTai = [&]() -> string {
        return Rong(lichSu) ? "(trang chu)" : Peek(lichSu);
    };

    cout << "  Vao trang: google.com\n";
    Push(lichSu, "google.com");
    cout << "    Trang hien tai: " << trangHienTai() << "\n";

    cout << "  Vao trang: youtube.com\n";
    Push(lichSu, "youtube.com");
    cout << "    Trang hien tai: " << trangHienTai() << "\n";

    cout << "  Vao trang: facebook.com\n";
    Push(lichSu, "facebook.com");
    cout << "    Trang hien tai: " << trangHienTai() << "\n";

    cout << "  [Nhan Quay Lai]\n";
    string prev = Pop(lichSu);
    Push(tiepTheo, prev);
    cout << "    Trang hien tai: " << trangHienTai() << "\n";

    cout << "  [Nhan Quay Lai]\n";
    prev = Pop(lichSu);
    Push(tiepTheo, prev);
    cout << "    Trang hien tai: " << trangHienTai() << "\n";

    cout << "  [Nhan Tien]\n";
    string next_p = Pop(tiepTheo);
    Push(lichSu, next_p);
    cout << "    Trang hien tai: " << trangHienTai() << "\n";
}

// ============================================================
//  UNG DUNG 3: HANG CHO IN AN (Queue)
// ============================================================
struct PrintJob {
    int id;
    string tenFile;
    int soTrang;
};

struct Queue {
    PrintJob data[50];
    int front, rear;
    int size;
};

void KhoiTaoQ(Queue &Q) { Q.front = Q.rear = Q.size = 0; }
bool QRong(const Queue &Q) { return Q.size == 0; }

void Enqueue(Queue &Q, const PrintJob &job) {
    if (Q.size >= 50) { cout << "  Hang doi day!\n"; return; }
    Q.data[Q.rear] = job;
    Q.rear = (Q.rear + 1) % 50;
    Q.size++;
}

PrintJob Dequeue(Queue &Q) {
    PrintJob j = Q.data[Q.front];
    Q.front = (Q.front + 1) % 50;
    Q.size--;
    return j;
}

void DemoHangChoIn() {
    cout << "\n=== UNG DUNG 3: HANG CHO IN AN (Queue) ===\n";
    Queue Q; KhoiTaoQ(Q);

    // Them cac lenh in
    PrintJob jobs[] = {
        {1, "BaoCao_Q1.docx", 5},
        {2, "HinhAnh.pdf", 1},
        {3, "BangDiem.xlsx", 3},
        {4, "HopDong.pdf", 10},
        {5, "ThongBao.docx", 2}
    };

    cout << "  --- Them vao hang doi ---\n";
    for (auto &j : jobs) {
        Enqueue(Q, j);
        cout << "  + [Job#" << j.id << "] " << j.tenFile
             << " (" << j.soTrang << " trang)\n";
    }

    cout << "\n  --- May in dang xu ly ---\n";
    while (!QRong(Q)) {
        PrintJob j = Dequeue(Q);
        cout << "  ==> In xong: [Job#" << j.id << "] "
             << j.tenFile << " (" << j.soTrang << " trang)\n";
    }
    cout << "  Hang doi trong. Tat ca da in xong!\n";
}

// ============================================================
//  UNG DUNG 4: TINH BIEU THUC HAUT TO (Postfix - Stack)
//  Vi du: "3 4 + 5 *" = (3+4)*5 = 35
// ============================================================
double TinhPostfix(const string &expr) {
    double stack[100]; int top = -1;
    string token = "";
    for (int i = 0; i <= (int)expr.size(); i++) {
        char c = (i < (int)expr.size()) ? expr[i] : ' ';
        if (c == ' ' || i == (int)expr.size()) {
            if (token.empty()) continue;
            // Kiem tra so
            bool isNum = true;
            int start = 0;
            if (token[0] == '-' && token.size() > 1) start = 1;
            for (int j = start; j < (int)token.size(); j++)
                if (!isdigit(token[j]) && token[j] != '.') { isNum = false; break; }
            if (isNum) {
                stack[++top] = stod(token);
            } else if (token.size() == 1) {
                char op = token[0];
                double b = stack[top--], a = stack[top--];
                if (op == '+') stack[++top] = a + b;
                else if (op == '-') stack[++top] = a - b;
                else if (op == '*') stack[++top] = a * b;
                else if (op == '/' && b != 0) stack[++top] = a / b;
            }
            token = "";
        } else {
            token += c;
        }
    }
    return (top >= 0) ? stack[top] : 0;
}

void DemoTinhBieuThuc() {
    cout << "\n=== UNG DUNG 4: TINH BIEU THUC HAUT TO (Stack) ===\n";
    struct { string expr; string desc; } tests[] = {
        {"3 4 +",       "3 + 4 = "},
        {"3 4 + 5 *",   "(3+4)*5 = "},
        {"5 1 2 + 4 * + 3 -", "5+((1+2)*4)-3 = "},
        {"2 3 * 4 5 * +", "2*3 + 4*5 = "}
    };
    for (auto &t : tests) {
        cout << "  " << t.desc << TinhPostfix(t.expr) << "\n";
    }
}

// ============================================================
//  UNG DUNG 5: TU DIEN (BST)
// ============================================================
struct TuNode {
    string tu;
    string nghia;
    TuNode *left, *right;
    TuNode(string t, string n) : tu(t), nghia(n), left(nullptr), right(nullptr) {}
};

TuNode* ChemTu(TuNode *root, const string &tu, const string &nghia) {
    if (!root) return new TuNode(tu, nghia);
    if (tu < root->tu) root->left  = ChemTu(root->left,  tu, nghia);
    else if (tu > root->tu) root->right = ChemTu(root->right, tu, nghia);
    else root->nghia = nghia; // cap nhat neu da co
    return root;
}

string TimNghia(TuNode *root, const string &tu) {
    if (!root) return "Khong tim thay";
    if (tu == root->tu) return root->nghia;
    if (tu < root->tu) return TimNghia(root->left, tu);
    return TimNghia(root->right, tu);
}

void InTuDien(TuNode *root) { // In-order
    if (!root) return;
    InTuDien(root->left);
    cout << "  " << setw(15) << left << root->tu << " : " << root->nghia << "\n";
    InTuDien(root->right);
}

void XoaTuDien(TuNode *root) {
    if (!root) return;
    XoaTuDien(root->left); XoaTuDien(root->right); delete root;
}

void DemoTuDien() {
    cout << "\n=== UNG DUNG 5: TU DIEN ANH-VIET (BST) ===\n";
    TuNode *dic = nullptr;
    struct { string e, v; } words[] = {
        {"algorithm",  "giai thuat"},
        {"array",      "mang"},
        {"binary",     "nhi phan"},
        {"data",       "du lieu"},
        {"heap",       "dong"},
        {"list",       "danh sach"},
        {"node",       "nut"},
        {"queue",      "hang doi"},
        {"sort",       "sap xep"},
        {"stack",      "ngan xep"},
        {"tree",       "cay"},
        {"search",     "tim kiem"},
    };
    for (auto &w : words) dic = ChemTu(dic, w.e, w.v);

    cout << "  --- Tu dien (theo thu tu abc) ---\n";
    InTuDien(dic);

    cout << "\n  --- Tim kiem ---\n";
    for (string w : {"tree", "heap", "graph"})
        cout << "  \"" << w << "\" => " << TimNghia(dic, w) << "\n";

    XoaTuDien(dic);
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "============================================================\n";
    cout << "  BAI TAP TONG HOP - UNG DUNG CTDL & GIAI THUAT\n";
    cout << "  Giao trinh: CD Cong Thuong TP.HCM - 2025\n";
    cout << "============================================================\n";

    DemoQLSinhVien();
    DemoLichSuTrinhDuyet();
    DemoHangChoIn();
    DemoTinhBieuThuc();
    DemoTuDien();

    cout << "\n============================================================\n";
    cout << "  HOAN THANH TAT CA UNG DUNG!\n";
    cout << "============================================================\n";
    return 0;
}
