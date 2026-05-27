# Tuần 3: Tìm Kiếm — Bài tậpBài 1: Tìm kiếm tuyến tính ⭐
Tìm kiếm tính toán tuyến tính trên mảng số nguyên và mảng chuỗi. So sánh số bước.

#include <stdio.h>
#include <string.h>

// 1. Tìm kiếm tính toán trên mảng số
int linearSearchInt(int arr [ ] , int n, int x, int * steps) {
    * bước = 0;
    for (int i = 0; i < n; i++) {
        ( * bước)++;
        nếu (arr [ i ] == x) {
            trả lại tôi; // Trả về số phần tử được tìm thấy
        }
    }
    trả về -1; // Không thể tìm thấy
}

// 2. Tìm kiếm tính năng tuyến tính trên mảng chuỗi
int linearSearchString(char arr [ ] [ 50 ] , int n, char x [ ] , int * steps) {
    * bước = 0;
    for (int i = 0; i < n; i++) {
        ( * bước)++;
        nếu (strcmp(arr [ i ] , x) == 0) {
            trả về i;
        }
    }
    trả về -1;
}

Bài 2: Tìm kiếm nhị phân ⭐⭐
Cài đặt trình phân tích tìm kiếm + quy tắc đệ quy. Tìm vị trí đầu tiên và cuối cùng của bản sao phần tử.

1 . Cài đặt Lặp và Đệ quy (Cơ bản)
// Cách 1: Sử dụng vòng lặp
int binarySearchIterative(int arr [ ] , int n, int x) {
    int left = 0, right = n - 1;
    trong khi (trái <= phải) {
        int mid = left + (right - left) / 2;
        if (arr [ mid ] == x) return mid;
        nếu (arr [ mid ] < x) left = mid + 1;
        Ngược lại, bên phải = giữa - 1;
    }
    trả về -1;
}

// Cách 2: Use recursive
int binarySearchRecursive(int arr [ ] , int left, int right, int x) {
    nếu (trái > phải) trả về -1;
    int mid = left + (right - left) / 2;
    if (arr [ mid ] == x) return mid;
    if (arr [ mid ] < x) return binarySearchRecursive(arr, mid + 1, right, x);
    return binarySearchRecursive(arr, left, mid - 1, x);
}
2 . Tìm vị trí đầu tiên và cuối cùng
int findFirstOccurrence(int arr [ ] , int n, int x) {
    int left = 0, right = n - 1, result = -1;
    trong khi (trái <= phải) {
        int mid = left + (right - left) / 2;
        nếu (arr [ mid ] == x) {
            kết quả = giữa; // Ghi nhận tạm thời vị trí
            phải = giữa - 1; // Tiếp tục tìm kiếm bên trái
        } else if (arr [ mid ] < x) left = mid + 1;
        Ngược lại, bên phải = giữa - 1;
    }
    Trả về kết quả;
}

int findLastOccurrence(int arr [ ] , int n, int x) {
    int left = 0, right = n - 1, result = -1;
    trong khi (trái <= phải) {
        int mid = left + (right - left) / 2;
        nếu (arr [ mid ] == x) {
            kết quả = giữa; // Ghi nhận tạm thời vị trí
            trái = giữa + 1; // Tiếp tục tìm kiếm bên phải
        } else if (arr [ mid ] < x) left = mid + 1;
        Ngược lại, bên phải = giữa - 1;
    }
    Trả về kết quả;
}


Bài 3: So sánh hiệu năng ⭐⭐
Đo thời gian tìm kiếm với n = 10.000, 100.000, 1.000.000 phần tử. Vẽ bảng so sánh.

#include <time.h>

void comparePerformance() {
    // Giải thích mảng cài đặt lớn nhất được sắp xếp thành phần tử...
    int n = 100000;
    int * arr = (int * )malloc(n * sizeof(int));
    for(int i=0; i<n; i++) arr [ i ] = i;

    mục tiêu int = n - 1; // Tìm phần tử cuối cùng để xác định độ lệch (Trường hợp xấu nhất)
    int steps = 0;

    // Tìm kiếm tuyến tính Đo
    clock_t start = clock();
    linearSearchInt(arr, n, target, &steps);
    clock_t end = clock();
    gấp đôi thời gian_tuyến tính = (gấp đôi)(kết thúc - bắt đầu) / CLOCKS_PER_SEC * 1000; // Đổi sang mili-giây (ms)

    // Tìm kiếm nhị phân
    bắt đầu = đồng hồ();
    binarySearchIterative(arr, n, target);
    kết thúc = đồng hồ();
    double time_binary = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    // Vẽ bảng so sánh ra màn hình console
    printf("\n+------------+-----------------+-----------------+\n");
    printf("|Thuat ton | So buoc lap | Thời gian (ms) |\n");
    printf("+------------+-----------------+-----------------+\n");
    printf("| Tuyến tính | %-15d | %-15.4f |\n", steps, time_linear);
    printf("| Nhị phân | %-15d | %-15.4f |\n", (int)log2(n), time_binary);
    printf("+------------+-----------------+-----------------+\n");

    giải phóng(arr);
}


Bài 4: 🔥 Dự Án Mini — Công cụ tìm kiếm thông minh ⭐⭐⭐
Cảm hứng: Brute Force Search — thuật toán trực hóa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONTACTS 50

// Liên hệ dữ liệu cấu hình
typedef struct {
    tên ký tự [ 50 ] ;
    điện thoại char [ 15 ] ;
} Liên hệ;

// Hàm so sánh hai số điện thoại (dùng cho qsort sắp xếp thuật toán)
int compareByPhone(const void * a, const void * b) {
    return strcmp(((Contact * )a)->phone, ((Contact * )b)->phone);
}

// Hàm chuyển đổi chuỗi thành normal để tìm kiếm không phân biệt chữ hoa/chữ thường
void toLowerCase(char dest [ ] , const char src [ ] ) {
    int i = 0;
    trong khi (src [ i ] != '\0') {
        nếu (src [ i ] >= 'A' && src [ i ] <= 'Z') {
            dest [ i ] = src [ i ] + 32;
        } khác {
            dest [ i ] = src [ i ] ;
        }
        i++;
    }
    dest [ i ] = '\0';
}

// Hàm thực hiện Tìm kiếm mờ (Tìm kiếm con chuỗi hỗ trợ tính năng tuyến tính)
void searchByName(Contact book [ ] , int n, char query [ ] ) {
    char lowerQuery [ 50 ] , lowerName [ 50 ] ;
    toLowerCase(lowerQuery, query);

    int foundCount = 0;
    int steps = 0;

    // Bắt đầu đo thời gian
    clock_t start = clock();

    printf("\n->Tìm thấy kết quả:\n");
    for (int i = 0; i < n; i++) {
        bước++; // Mỗi lần kiểm tra một phần tử là một bước
        toLowerCase(lowerName, book[i].name);
        
        // Kiểm tra tìm kiếm chuỗi xem có nằm trong liên hệ tên không
        nếu (strstr(lowerName, lowerQuery) != NULL) {
            foundCount++;
            printf(" %d. %-22s - %s\n", foundCount, book[i].name, book[i].phone);
        }
    }

    clock_t end = clock();
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC * 1000; // Đổi sang ms

    // Nếu kết quả không được tìm thấy, hãy đưa ra gợi ý top 3 tên đầu tiên
    nếu (foundCount == 0) {
        printf(" Không tìm thấy kết quả nào phù hợp với \"%s\"!\n", query);
        printf("\n Gợi ý 3 liên hệ gần giống (có sẵn):\n");
        for (int i = 0; i < 3 && i < n; i++) {
            printf(" * %-22s - %s\n", book[i].name, book[i].phone);
        }
    } khác {
        printf(" (Đã so sánh %d/%d phần tử — %.3fms)\n", các bước, n, timeSpent);
    }
}

// Hàm thực hiện Tìm kiếm theo số điện thoại (Sắp xếp rồi tìm kiếm nhị phân)
void searchByPhone(Contact book [ ] , int n, char queryPhone [ ] ) {
    // 1. Sắp xếp danh bạ theo số điện thoại trước khi tìm nhị phân
    qsort(book, n, sizeof(Contact), compareByPhone);

    int left = 0, right = n - 1;
    int steps = 0;
    int foundIdx = -1;

    clock_t start = clock();
    trong khi (trái <= phải) {
        các bước++;
        int mid = left + (right - left) / 2;
        int cmp = strcmp(book[mid].phone, queryPhone);

        nếu (cmp == 0) {
            foundIdx = mid;
            break; // Tìm thấy
        } nếu (cmp < 0) {
            trái = giữa + 1;
        } khác {
            bên phải = giữa - 1;
        }
    }
    clock_t end = clock();
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    nếu (foundIdx != -1) {
        printf("\n->Tìm thấy 1 kết quả:\n");
        printf(" 1. %-22s - %s\n", book[foundIdx].name, book[foundIdx].phone);
        printf(" (Tìm kiếm nhị phân: hoàn thành sau %d bước — %.3fms)\n", các bước, timeSpent);
    } khác {
        printf("\n Không tìm thấy số điện thoại %s trong danh bạ!\n", queryPhone);
    }
}

int main() {
    // Giả lập danh bạ 50 phần tử để thống kê các bài viết tương tự
    Danh bạ liên hệ [ MAX_CONTACTS ] = {
        {"Nguyễn Văn Minh", "0901234567"}, {"Trần Thị Minh Anh", "0912345678"},
        {"Lê Minh Tuấn", "0923456789"}, {"Hoàng Nguyên Vũ", "0888888888"},
        {"Phạm Thanh Long", "0777777777"}, {"Nguyễn Mai Chi", "0934567890"},
        {"Trần Tuấn Kiệt", "0945678901"}, {"Lê Thị Hương", "0956789012"},
        {"Vũ Hoàng Long", "0967890123"}, {"Đặng Đình Toàn", "0978901234"}
    };
    // Điền dữ liệu ghi chú cho đủ 50 phần tử
    for(int i = 10; i < MAX_CONTACTS; i++) {
        sprintf(phonebook [ i ] .name, "Nguoi dung %d", i + 1);
        sprintf(phonebook [ i ] .phone, "0915%06d", i);
    }
    int n = MAX_CONTACTS;

    lựa chọn int;
    char searchKey[50];

    trong khi (1) {
        printf("\n====================================\n");
        printf(" CÔNG CỤ TÌM KIẾM DANH BẠ SMART \n");
        printf("=====================================\n");
        printf("1. Tìm theo Tên (Linear - Tìm Blur)\n");
        printf("2. Tìm kiếm theo SĐT (Tìm kiếm nhị phân)\n");
        printf("0. Thoát khỏi hệ thống\n");
        printf("------------------------------------\n");
        printf("Lựa chọn chức năng (0-2): ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự \n còn sót lại trong bộ nhớ đệm

        nếu (lựa chọn == 0) {
            printf("\nĐã đóng hệ thống tìm kiếm.\n");
            phá vỡ;
        }

        switch(choice) {
            Trường hợp 1:
                printf("Nhập tên cần tìm: ");
                fgets(searchKey, sizeof(searchKey), stdin);
                searchKey[strcspn(searchKey, "\n")] = 0; // Xóa ký tự xuống dòng từ fgets
                tìm kiếm theo tên (sổ điện thoại, n, khóa tìm kiếm);
                phá vỡ;
            trường hợp 2:
                printf("Nhập chính xác số điện thoại cần tìm: ");
                scanf("%s", searchKey);
                tìm kiếm theo số điện thoại (sổ điện thoại, n, khóa tìm kiếm);
                phá vỡ;
            mặc định:
                printf("Chức năng không hợp lệ! Vui lòng chọn lại.\n");
        }
    }
    trả về 0;
}

Xây dựng hệ thống tìm kiếm danh bạ điện thoại:

Tìm theo tên: Linear Search (hỗ trợ tìm kiếm mờ — chứa chuỗi)
Tìm theo số điện thoại: Binary Search (sau khi sắp xếp theo SĐT)
Thống kê: hiển thị số bước so sánh, tìm kiếm thời gian
Gợi ý: nếu không tìm thấy, tip 3 tên gần giống nhất
Nhập tên cần tìm: "Minh"
→ Tìm thấy 3 kết quả:
   1 . Nguyễn Văn Minh - 0901234567
   2 . Trần Thị Minh Anh - 0912345678
   3 . Lê Minh Tuấn - 0923456789
   (Đã so sánh 15/50 phần tử — 0,002ms)
