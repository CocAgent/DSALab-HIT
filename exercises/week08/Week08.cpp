#include <iostream>
#include <string>
#include <stack>

using namespace std;

// ============================================================================
// BÀI 1: CÀI ĐẶT STACK
// ============================================================================

// 1. Cài đặt Stack bằng Mảng (Array-based)
#define MAX 100 // Kích thước tối đa của mảng

class ArrayStack {
private:
    int top;
    int arr[MAX];

public:
    ArrayStack() {
        top = -1; // Khởi tạo Stack rỗng
    }

    // Thêm phần tử vào Stack
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "[ArrayStack] Stack Overflow (Stack da day!)\n";
            return false;
        }
        else {
            arr[++top] = x;
            return true;
        }
    }

    // Xóa và lấy phần tử ở đỉnh Stack
    int pop() {
        if (top < 0) {
            cout << "[ArrayStack] Stack Underflow (Stack rong!)\n";
            return 0;
        }
        else {
            return arr[top--];
        }
    }

    // Xem phần tử ở đỉnh Stack mà không xóa
    int peek() {
        if (top < 0) {
            cout << "[ArrayStack] Stack rong!\n";
            return 0;
        }
        else {
            return arr[top];
        }
    }

    // Kiểm tra Stack có rỗng không
    bool isEmpty() {
        return (top < 0);
    }
};

// 2. Cài đặt Stack bằng Danh sách liên kết (Linked List)
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr; // Khởi tạo Stack rỗng
    }

    // Thêm phần tử vào Stack
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    // Xóa và lấy phần tử ở đỉnh Stack
    int pop() {
        if (top == nullptr) {
            cout << "[LinkedListStack] Stack Underflow (Stack rong!)\n";
            return 0;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp; // Giải phóng bộ nhớ
        return poppedValue;
    }

    // Xem phần tử ở đỉnh Stack
    int peek() {
        if (top == nullptr) {
            cout << "[LinkedListStack] Stack rong!\n";
            return 0;
        }
        return top->data;
    }

    // Kiểm tra Stack rỗng
    bool isEmpty() {
        return top == nullptr;
    }

    // Hàm hủy để giải phóng bộ nhớ khi kết thúc chương trình
    ~LinkedListStack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};


// ============================================================================
// BÀI 2: KIỂM TRA NGOẶC HỢP LỆ
// ============================================================================
bool isValidParentheses(string s) {
    stack<char> st; // Sử dụng STL stack của C++ cho bài toán ứng dụng

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // Nếu là dấu ngoặc mở, đẩy vào stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // Nếu là dấu ngoặc đóng, kiểm tra sự trùng khớp
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false; // Thừa dấu ngoặc đóng

            char topChar = st.top();
            st.pop();

            // Nếu không khớp cặp ngoặc tương ứng -> Sai
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']') && topChar != '[') {
                return false;
            }
        }
        // Bỏ qua các ký tự khác (chữ cái, chữ số, toán tử...), giúp xử lý được mã nguồn thực tế
    }

    // Nếu stack rỗng hoàn toàn tức là mọi ngoặc mở đều được đóng đúng cách
    return st.empty();
}


// ============================================================================
// BÀI 3: CHUYỂN ĐỔI BIỂU THỨC (INFIX TO POSTFIX)
// ============================================================================

// Hàm trả về độ ưu tiên của các toán tử
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Hàm chuyển từ Trung tố (Infix) sang Hậu tố (Postfix) kèm in từng bước
void infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    cout << "\n--- BAT DAU CHUYEN DOI (INFIX -> POSTFIX) ---\n";
    cout << "Bieu thuc goc: " << s << "\n\n";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // 1. Nếu là toán hạng (chữ hoặc số), viết thẳng vào chuỗi kết quả
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        // 2. Nếu là dấu '(', đưa vào stack
        else if (c == '(') {
            st.push('(');
        }
        // 3. Nếu là dấu ')', pop toàn bộ toán tử ra kết quả cho đến khi gặp '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Xóa bỏ dấu '(' tương ứng ra khỏi stack
        }
        // 4. Nếu là toán tử (+, -, *, /, ^)
        else {
            // Pop các toán tử có độ ưu tiên lớn hơn hoặc bằng toán tử hiện tại ra chuỗi kết quả
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c); // Đẩy toán tử hiện tại vào stack
        }

        // In ra từng bước thực hiện theo yêu cầu đề bài
        cout << "Ky tu dang xet: " << c << " \t| Bieu thuc ket qua hien tai: " << result << "\n";
    }

    // Đưa tất cả các toán tử còn lại trong stack ra kết quả
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "\n--> KET QUA CUOI CUNG (Postfix): " << result << "\n";
    cout << "---------------------------------------------\n";
}


// ============================================================================
// HÀM MAIN CHẠY THỬ NGHIỆM CẢ 3 BÀI
// ============================================================================
int main() {
    // ---- KIỂM THỬ BÀI 1 ----
    cout << "=========================================\n";
    cout << "KIEU THU BAI 1: CAI DAT STACK\n";
    cout << "=========================================\n";

    cout << "1. Test ArrayStack (Stack bang Mang):\n";
    ArrayStack arrStack;
    arrStack.push(10);
    arrStack.push(20);
    arrStack.push(30);
    cout << "Phan tu tren cung (peek): " << arrStack.peek() << "\n";
    cout << "Lay ra (pop): " << arrStack.pop() << "\n";
    cout << "Phan tu tren cung sau pop: " << arrStack.peek() << "\n\n";

    cout << "2. Test LinkedListStack (Stack bang DS Lien Ket):\n";
    LinkedListStack listStack;
    listStack.push(100);
    listStack.push(200);
    cout << "Phan tu tren cung (peek): " << listStack.peek() << "\n";
    cout << "Lay ra (pop): " << listStack.pop() << "\n";
    cout << "Phan tu tren cung sau pop: " << listStack.peek() << "\n\n";


    // ---- KIỂM THỬ BÀI 2 ----
    cout << "=========================================\n";
    cout << "KIEU THU BAI 2: KIEM TRA NGOAC HOP LE\n";
    cout << "=========================================\n";

    string codeSample1 = "if (a[i] == {1, 2}) { cout << \"Chinh xac\"; }";
    string codeSample2 = "if (a[i] == (1, 2]) { }"; // Sai cặp ngoặc ( ]

    cout << "Chuoi code 1: " << codeSample1 << "\n -> Ket qua: "
        << (isValidParentheses(codeSample1) ? "HOP LE" : "KHONG HOP LE") << "\n\n";

    cout << "Chuoi code 2: " << codeSample2 << "\n -> Ket qua: "
        << (isValidParentheses(codeSample2) ? "HOP LE" : "KHONG HOP LE") << "\n\n";


    // ---- KIỂM THỬ BÀI 3 ----
    cout << "=========================================\n";
    cout << "KIEU THU BAI 3: CHUYEN DOI BIEU THUC\n";
    cout << "=========================================\n";

    string infixExp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infixExp);

    return 0;
}