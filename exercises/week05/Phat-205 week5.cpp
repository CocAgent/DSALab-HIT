#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

/* =================================================================================
📝 ĐOẠN VĂN GIẢI THÍCH CÁCH HOẠT ĐỘNG CỦA TOÀN BỘ CODE (ĐỌC KHI THUYẾT TRÌNH)
=================================================================================
Chương trình này thực hiện cài đặt thuật toán Quick Sort (Sắp xếp nhanh) theo nguyên lý
"Chia để trị" và tiến hành đo đạc, so sánh hiệu năng của 4 chiến lược chọn phần tử chốt
(Pivot) khác nhau: chọn số đầu, số cuối, số giữa và chọn một số ngẫu nhiên. Khi khởi chạy,
hàm main đầu tiên sẽ chạy thử nghiệm thuật toán với một mảng nhỏ gồm 5 phần tử [7, 3, 9, 2, 5]
để in ra kết quả kiểm chứng. Ngay sau đó, hàm doHieuNang sẽ tạo ra một mảng ngược gồm 100
phần tử (từ 100 về 1) để làm dữ liệu thử nghiệm cho cả 4 chiến lược nhằm tìm ra sự chênh lệch.

Về cách vận hành, hàm đệ quy quickSort sẽ liên tục chia mảng thành các phân đoạn nhỏ thông qua
hàm phân hoạch partition. Tại hàm partition, dựa vào chiến lược được chọn, máy tính sẽ xác định
vị trí của phần tử chốt (Pivot) rồi tạm thời đổi chỗ nó về cuối phân đoạn. Kế tiếp, một vòng lặp
sẽ quét qua toàn bộ các phần tử, tiến hành so sánh từng số với chốt; những số nào nhỏ hơn chốt
sẽ được gom sạch về phía bên trái mảng, còn những số lớn hơn hoặc bằng chốt sẽ nằm bên phải.
Khi vòng lặp kết thúc, phần tử chốt ở cuối mảng được đổi chỗ về đúng ranh giới giữa hai nhóm lớn/nhỏ.
Lúc này, phần tử chốt đã đứng đúng vị trí tuyệt đối của nó trong mảng đã sắp xếp. Quá trình này
lại tiếp tục lặp lại một cách đệ quy cho hai nửa trái và phải của chốt cho đến khi toàn bộ mảng thẳng hàng.
=================================================================================
*/

// Hàm bổ trợ dùng để in nhanh toàn bộ mảng ra màn hình
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// ==========================================
// HÀM PHÂN HOẠCH LOMUTO
// ==========================================
int partition(vector<int>& arr, int low, int high, int pivot_strategy, long long& comps, long long& swaps) {
    int pivot_idx = high; // Mặc định ban đầu chọn phần tử CUỐI làm chốt

    // Xử lý các chiến lược chọn chốt dựa vào tham số pivot_strategy truyền vào
    if (pivot_strategy == 0) {
        pivot_idx = low;              // Chiến lược 0: Chọn phần tử ĐẦU làm chốt
    }
    else if (pivot_strategy == 2) {
        pivot_idx = low + (high - low) / 2; // Chiến lược 2: Chọn phần tử GIỮA làm chốt
    }
    else if (pivot_strategy == 3) {
        pivot_idx = low + rand() % (high - low + 1); // Chiến lược 3: Chọn phần tử NGẪU NHIÊN làm chốt
    }

    swap(arr[pivot_idx], arr[high]); swaps++; // Đổi chỗ đưa chốt về cuối mảng để dễ phân hoạch

    int pivot = arr[high];            // Lấy giá trị của chốt tại vị trí cuối cùng vừa đổi
    int i = low - 1;                  // Con trỏ i đánh dấu ranh giới của nhóm nhỏ hơn chốt

    for (int j = low; j < high; j++) {
        comps++;                      // Tăng bộ đếm số lần so sánh với chốt
        if (arr[j] < pivot) {         // Nếu phần tử đang xét nhỏ hơn giá trị của chốt
            i++;
            swap(arr[i], arr[j]); swaps++; // Đổi chỗ để đưa số nhỏ về bên trái khu vực của i
        }
    }

    swap(arr[i + 1], arr[high]); swaps++; // Đưa số chốt về đứng đúng vị trí ranh giới giữa 2 nhóm lớn/nhỏ
    return i + 1;                     // Trả về vị trí đứng chuẩn xác 100% của chốt
}

// ==========================================
// HÀM ĐỆ QUY QUICK SORT (Chia để trị)
// ==========================================
void quickSort(vector<int>& arr, int low, int high, int strategy, long long& comps, long long& swaps) {
    if (low < high) {                 // Điều kiện dừng: Phân đoạn phải còn từ 2 phần tử trở lên
        int pi = partition(arr, low, high, strategy, comps, swaps); // Tìm vị trí đứng chuẩn xác (pi) của chốt

        quickSort(arr, low, pi - 1, strategy, comps, swaps);  // Gọi đệ quy sắp xếp nửa bên TRÁI chốt
        quickSort(arr, pi + 1, high, strategy, comps, swaps); // Gọi đệ quy sắp xếp nửa bên PHẢI chốt
    }
}

// ==========================================
// HÀM ĐÁNH GIÁ HIỆU NĂNG VỚI MẢNG 100 PHẦN TỬ
// ==========================================
void doHieuNang() {
    int N = 100;
    vector<int> original_arr(N);
    for (int i = 0; i < N; i++) original_arr[i] = N - i; // Tạo mảng NGƯỢC từ 100 về 1 (Worst Case)

    string names[] = { "Chot DAU", "Chot CUOI", "Chot GIUA", "Chot NGAU NHIEN" };

    cout << "\n=================================================================\n";
    cout << "     SO SANH 4 CHIEN LUOC CHON PIVOT (MANG NGUOC 100 PHAN TU)     \n";
    cout << "=================================================================\n";

    for (int strat = 0; strat < 4; strat++) {
        vector<int> temp = original_arr;
        long long comps = 0, swaps = 0;

        auto start = high_resolution_clock::now();
        quickSort(temp, 0, N - 1, strat, comps, swaps);
        auto stop = high_resolution_clock::now();
        duration<double, micro> diff = stop - start;

        cout << names[strat] << " -> So sanh: " << comps
            << " | Hoan vi: " << swaps << " | Thoi gian: " << diff.count() << " us\n";
    }
    cout << "=================================================================\n";
}

int main() {
    srand((unsigned int)time(0));     // Khởi tạo hạt giống ngẫu nhiên

    // 1. Chạy thử nghiệm với mảng nhỏ (Chiến lược chốt cuối - mã số 1)
    vector<int> demo_data;
    demo_data.push_back(7); demo_data.push_back(3); demo_data.push_back(9);
    demo_data.push_back(2); demo_data.push_back(5);

    cout << "--- QUICK SORT TRACE (Chot Cuoi) ---\nBan dau: "; printArray(demo_data);
    long long c = 0, s = 0;
    quickSort(demo_data, 0, (int)demo_data.size() - 1, 1, c, s);
    cout << "Ket qua: "; printArray(demo_data);

    // 2. Chạy bài toán đo hiệu năng so sánh 4 chiến lược chọn chốt
    doHieuNang();

    return 0;
}

/* =================================================================================
🔥 GHI CHÚ: PHẦN CODE QUAN TRỌNG NHẤT CỦA BÀI 2 (TẬP TRUNG VÀO LỆNH IF / ĐIỀU KIỆN)
=================================================================================
Trong Quick Sort, mọi quyết định phân chia mảng lớn/nhỏ và sự chênh lệch về mặt hiệu năng
đều phụ thuộc trực tiếp vào câu lệnh IF và ĐIỀU KIỆN SO SÁNH:

1. ĐIỀU KIỆN PHÂN CHIA MẢNG (Trong hàm partition):
   - Đoạn quan trọng: Câu lệnh `if (arr[j] < pivot)`.
   - Lý do: Đây là trái tim điều khiển dòng chảy dữ liệu của toàn bộ giải thuật. Câu lệnh này
     so sánh phần tử đang duyệt với giá trị của chốt. Nếu điều kiện đúng (nhỏ hơn chốt), nó
     mới cho phép dịch chuyển con trỏ ranh giới 'i' và thực hiện swap để gom phần tử đó về bên trái.

2. ĐIỀU KIỆN ĐÁNH GIÁ CHIẾN LƯỢC CHỌN PIVOT (Bản chất logic của Bài 2):
   - Đoạn quan trọng: Khối lệnh rẽ nhánh `if (pivot_strategy == 0) ... else if ...` ở đầu hàm partition.
   - Lý do: Điều kiện này quyết định "vị trí đứng" của phần tử chốt được chọn. Nó trực tiếp tác động
     đến việc mảng được bẻ đôi cân bằng hay lệch hẳn về một bên:
     + Khi gặp mảng ngược (Worst Case), nếu điều kiện kích hoạt trúng chiến lược chọn chốt ĐẦU hoặc CUỐI,
       mảng sẽ bị chia cực kỳ lệch (một bên rỗng, một bên ôm hết). Lúc này thuật toán suy biến thành O(N^2)
       và số phép so sánh vọt lên cực đại (~4950 lần đối với mảng 100 phần tử).
     + Ngược lại, nếu điều kiện kích hoạt chiến lược chọn chốt GIỮA hoặc NGẪU NHIÊN, mảng luôn được bẻ đôi
       đồng đều, giúp giữ vững tốc độ tối ưu lý thuyết của Quick Sort là O(N log N) (số phép so sánh giảm
       mạnh chỉ còn vài trăm lần).
=================================================================================
*/