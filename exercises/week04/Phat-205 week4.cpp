#include <iostream>
#include <vector>

using namespace std;

/* =================================================================================
📝 ĐOẠN VĂN GIẢI THÍCH CÁCH HOẠT ĐỘNG CỦA TOÀN BỘ CODE (ĐỌC KHI THUYẾT TRÌNH)
=================================================================================
Chương trình này là một chuỗi thực thi liên tục nhằm cài đặt và mô phỏng từng bước
thay đổi của mảng dữ liệu qua 3 thuật toán sắp xếp cơ bản là Bubble Sort, Selection Sort
và Insertion Sort. Khi khởi chạy, mảng mẫu gồm 5 phần tử [7, 3, 9, 2, 5] sẽ lần lượt
được truyền vào từng hàm dưới dạng tham trị để đảm bảo mỗi thuật toán đều được thử nghiệm
trên mảng gốc ban đầu.

- Đầu tiên, BUBBLE SORT hoạt động theo cơ chế "nổi bọt", liên tục duyệt qua mảng và
  bắt cặp so sánh hai phần tử kề nhau, nếu số trước lớn hơn số sau thì ngay lập tức
  hoán đổi vị trí, giúp đẩy dần các phần tử lớn nhất về cuối mảng sau mỗi lượt quét lớn.

- Tiếp theo, SELECTION SORT lại tiếp cận theo hướng "chọn lọc", cố định vị trí đầu tiên
  của vùng chưa xếp rồi quét toàn bộ đoạn mảng phía sau để tìm ra phần tử nhỏ nhất thực sự,
  sau khi quét xong xuôi mới tiến hành đổi chỗ đúng một lần duy nhất về vị trí đầu đoạn đó.

- Cuối cùng, INSERTION SORT hoạt động tương tự như cách con người sắp xếp bài Tây;
  thuật toán rút lần lượt từng quân bài ra làm vật trung gian, duyệt lùi về phía trước
  để tìm vị trí thích hợp, hễ thấy số nào lớn hơn quân bài đó thì dịch chuyển nó sang phải
  một bước để nhường chỗ, rồi mới chèn quân bài vào khoảng trống vừa tạo ra.

Kết thúc mỗi lượt quét lớn của cả 3 thuật toán, hàm bổ trợ printArray sẽ lập tức in
kết quả mảng ra màn hình giúp người dùng dễ dàng theo dõi toàn bộ vết dịch chuyển của dữ liệu.
=================================================================================
*/

// Hàm bổ trợ dùng để in nhanh toàn bộ mảng ra màn hình sau mỗi lượt
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// ==========================================
// 1. BUBBLE SORT (Sắp xếp nổi bọt)
// ==========================================
void bubbleSort(vector<int> arr) {
    int n = (int)arr.size();
    cout << "\n--- BUBBLE SORT TRACE ---\nBan dau: "; printArray(arr);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout << "Luot " << i + 1 << ": "; printArray(arr);
    }
}

// ==========================================
// 2. SELECTION SORT (Sắp xếp chọn)
// ==========================================
void selectionSort(vector<int> arr) {
    int n = (int)arr.size();
    cout << "\n--- SELECTION SORT TRACE ---\nBan dau: "; printArray(arr);

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
        cout << "Luot " << i + 1 << ": "; printArray(arr);
    }
}

// ==========================================
// 3. INSERTION SORT (Sắp xếp chèn)
// ==========================================
void insertionSort(vector<int> arr) {
    int n = (int)arr.size();
    cout << "\n--- INSERTION SORT TRACE ---\nBan dau: "; printArray(arr);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "Luot " << i << ": "; printArray(arr);
    }
}

int main() {
    vector<int> data;
    data.push_back(7); data.push_back(3); data.push_back(9); data.push_back(2); data.push_back(5);

    bubbleSort(data);
    selectionSort(data);
    insertionSort(data);

    return 0;
}

/* =================================================================================
🔥 GHI CHÚ: PHẦN CODE QUAN TRỌNG NHẤT CỦA TỪNG BÀI (TẬP TRUNG VÀO LỆNH IF / ĐIỀU KIỆN)
=================================================================================
Mọi thuật toán sắp xếp đều được vận hành dựa trên các quyết định so sánh. Vì vậy, câu
lệnh IF và ĐIỀU KIỆN SO SÁNH chính là phần quan trọng nhất quyết định hành vi dữ liệu:

1. Ở BUBBLE SORT:
   - Đoạn quan trọng: Câu lệnh `if (arr[j] > arr[j + 1])`.
   - Lý do: Đây là điều kiện kích hoạt hoán đổi. Nó kiểm tra xem hai phần tử liên tiếp
     có bị ngược thứ tự hay không (số trước lớn hơn số sau). Nếu thỏa mãn, lệnh swap mới
     chạy để đưa số lớn trôi về phía bên phải.

2. Ở SELECTION SORT:
   - Đoạn quan trọng: Câu lệnh `if (arr[j] < arr[min_idx])`.
   - Lý do: Đây là điều kiện cốt lõi để tìm ra giá trị nhỏ nhất. Máy tính liên tục so sánh
     phần tử đang duyệt với phần tử nhỏ nhất tạm thời. Điều kiện này quyết định việc cập nhật
     lại biến `min_idx` trước khi thực hiện đúng một lệnh swap duy nhất ở cuối lượt.

3. Ở INSERTION SORT:
   - Đoạn quan trọng: Điều kiện so sánh `arr[j] > key` nằm trong câu lệnh vòng lặp while.
   - Lý do: Bản chất điều kiện này hoạt động như một câu lệnh IF liên tục. Nó kiểm tra xem
     các phần tử đứng trước có lớn hơn quân bài đang xét (key) hay không. Chỉ khi điều kiện
     này đúng, mảng mới thực hiện dịch chuyển sang phải để tạo khe hở chèn bài.
=================================================================================
*/