# 📚 Dự Án C++: Cấu Trúc Dữ Liệu và Giải Thuật

> **Giáo trình:** Cấu trúc dữ liệu và Giải thuật  
> **Ngôn ngữ:** C++17

---

## 📁 Cấu Trúc Dự Án

```text
CTDL_GT/
├── include/
│   └── utils.h                        # Hàm tiện ích dùng chung
│
├── Chuong1_TongQuan/
│   └── Chuong1_TongQuan.cpp           # Kiểu DL, CTDL, Big-O
│
├── Chuong2_TimKiem_SapXep/
│   └── Chuong2_TimKiem_SapXep.cpp     # 2 tìm kiếm + các thuật toán sắp xếp cơ bản
│
├── Chuong3_DanhSachLienKet/
│   └── Chuong3_DanhSachLienKet.cpp    # DSLK đơn, Stack, Queue
│
├── Chuong4_CauTrucCay/
│   └── Chuong4_CauTrucCay.cpp         # Cây nhị phân, BST
│
├── BaiTapTongHop/
│   └── BaiTapTongHop.cpp              # 5 ứng dụng thực tế
│
├── Makefile
└── README.md
```

---

## 📖 Nội Dung Từng File

### Chương 1 — Tổng Quan CTDL & GT
- Kiểu dữ liệu C/C++, nguyên tắc chọn kiểu dữ liệu
- Minh họa mối liên hệ giữa cấu trúc dữ liệu và giải thuật
- 7 phân lớp độ phức tạp Big-O: `O(1)`, `O(log N)`, `O(N)`, `O(N log N)`, `O(N²)`, `O(N³)`, `O(2^N)`
- Bài tập minh họa: tính tổng chữ số, giải phương trình bậc nhất

### Chương 2 — Tìm Kiếm & Sắp Xếp

| Giải thuật | Độ phức tạp | Ghi chú |
|---|---|---|
| Linear Search | O(N) | Không yêu cầu mảng đã sắp xếp |
| Binary Search | O(log N) | Cần mảng đã sắp xếp |
| Selection Sort | O(N²) | Dễ cài đặt |
| Insertion Sort | O(N²) | Tốt với mảng gần sắp xếp |
| Bubble Sort | O(N²) | Dễ quan sát từng bước |
| Quick Sort | O(N log N) | Trung bình rất nhanh |
| Heap Sort | O(N log N) | Phù hợp khi cần hiệu năng ổn định |

### Chương 3 — Danh Sách Liên Kết
- Con trỏ, cấp phát động, node và liên kết
- Danh sách liên kết đơn: tạo, duyệt, thêm, xóa
- Các thao tác đầu/cuối/vị trí bất kỳ
- Nối và tách danh sách
- **Stack**: Push, Pop và ứng dụng kiểm tra ngoặc, đổi nhị phân
- **Queue**: Enqueue, Dequeue và ứng dụng hàng chờ in ấn

### Chương 4 — Cây Nhị Phân
- Cây nhị phân: biểu diễn bằng mảng và con trỏ
- Duyệt cây theo 3 thứ tự: Pre-order, In-order, Post-order
- Duyệt theo mức (BFS)
- **Binary Search Tree (BST)**: Insert, Search, Delete
- Các thao tác thường dùng: tính chiều cao, đếm nút, tính tổng, tìm nút lớn thứ `k`

### Bài Tập Tổng Hợp — 5 Ứng Dụng Thực Tế
1. **Quản lý sinh viên** — mảng + sắp xếp + tìm kiếm
2. **Lịch sử trình duyệt** — Stack (quay lại / tiến tới)
3. **Hàng chờ in ấn** — Queue (FIFO)
4. **Tính biểu thức hậu tố** — Stack (Postfix Calculator)
5. **Từ điển Anh-Việt** — BST (lưu trữ và tìm kiếm)

---

## ⚙️ Biên Dịch và Chạy

### Yêu cầu
- Trình biên dịch: **g++ (C++17)**
- Hoặc có thể dùng: **Visual Studio**, **Code::Blocks**, **Dev-C++**

### Biên dịch từng file bằng g++
```bash
# Tạo thư mục chứa file biên dịch
mkdir -p bin

# Biên dịch từng chương
 g++ -std=c++17 Chuong1_TongQuan/Chuong1_TongQuan.cpp -o bin/Chuong1
 g++ -std=c++17 Chuong2_TimKiem_SapXep/Chuong2_TimKiem_SapXep.cpp -o bin/Chuong2
 g++ -std=c++17 Chuong3_DanhSachLienKet/Chuong3_DanhSachLienKet.cpp -o bin/Chuong3 -lm
 g++ -std=c++17 Chuong4_CauTrucCay/Chuong4_CauTrucCay.cpp -o bin/Chuong4
 g++ -std=c++17 BaiTapTongHop/BaiTapTongHop.cpp -o bin/TongHop

# Chạy chương trình
./bin/Chuong1
./bin/Chuong2
./bin/Chuong3
./bin/Chuong4
./bin/TongHop
```

### Dùng Makefile
```bash
make        # Biên dịch tất cả
make clean  # Xóa file đã build
```

### Dùng IDE (Visual Studio / Code::Blocks)
1. Mở file `.cpp` cần chạy
2. Chọn **Build** hoặc **Build & Run**
3. Quan sát kết quả trong cửa sổ terminal / console

---

## 📌 Hướng Dẫn Fork, Làm Bài và Nộp Bài

Phần này dành cho sinh viên mới bắt đầu học GitHub và Git. Mục tiêu là giúp sinh viên biết cách tạo repo riêng, làm bài trên máy cá nhân và nộp bài đúng cách.

### 1. Fork là gì?

**Fork** là tạo một bản sao của repo gốc về tài khoản GitHub cá nhân của mình.

Ví dụ:
- Repo gốc của giảng viên: `https://github.com/CocAgent/DSALab`
- Repo sau khi sinh viên fork: `https://github.com/nguyenvana/DSALab`

Sinh viên sẽ làm bài trên repo của mình, không làm trực tiếp trên repo gốc.

### 2. Sinh viên cần làm gì đầu tiên?

1. Truy cập repo gốc:  
   **https://github.com/CocAgent/DSALab**
2. Nhấn nút **Fork** ở góc trên bên phải
3. Chọn tài khoản GitHub cá nhân
4. Nhấn **Create fork**

Sau bước này, sinh viên sẽ có một repo riêng của mình trên GitHub.

### 3. Clone là gì?

**Clone** là tải repo từ GitHub về máy tính cá nhân để bắt đầu làm bài.

Ví dụ:

```bash
git clone https://github.com/nguyenvana/DSALab.git
cd DSALab
```

Giải thích:
- `git clone ...` : tải repo về máy
- `cd DSALab` : đi vào thư mục dự án

### 4. Commit là gì?

**Commit** là ghi lại một mốc thay đổi của bài làm.

Ví dụ, sau khi sinh viên sửa code xong, dùng lệnh:

```bash
git add .
git commit -m "Hoan thanh bai tap tuan 1"
```

Giải thích:
- `git add .` : chọn các file đã thay đổi để chuẩn bị lưu
- `git commit -m "..."` : lưu lại thay đổi và đặt tên cho lần cập nhật đó

Nên viết nội dung commit rõ ràng, ví dụ:
- `Hoan thanh bai tap tuan 1`
- `Sua loi bai tim kiem nhi phan`
- `Bo sung bai tap Linked List`

Không nên viết quá chung chung như:
- `update`
- `fix`
- `123`

### 5. Push là gì?

**Push** là đưa bài làm từ máy tính cá nhân lên GitHub.

Ví dụ:

```bash
git push origin main
```

Lệnh này giúp cập nhật bài làm mới nhất của sinh viên lên repo GitHub cá nhân.

### 6. Ví dụ đầy đủ từ đầu đến cuối

```bash
git clone https://github.com/nguyenvana/DSALab.git
cd DSALab
git add .
git commit -m "Hoan thanh bai tap tuan 1"
git push origin main
```

Ý nghĩa của cả quy trình trên:
- tải repo về máy
- vào thư mục dự án
- thêm các file đã sửa
- lưu lại lần cập nhật
- đẩy bài lên GitHub

### 7. Sinh viên nộp bài cho giảng viên bằng cách nào?

Có hai cách phổ biến.

#### Cách 1: Nộp bằng Pull Request

**Pull Request (PR)** là cách gửi bài từ repo cá nhân về repo gốc để giảng viên xem và nhận xét.

Ưu điểm:
- Giảng viên xem được toàn bộ phần thay đổi
- Có thể nhận xét trực tiếp trên từng dòng code
- Dễ theo dõi quá trình sửa bài

Nếu nộp bằng Pull Request, sinh viên cần đặt tiêu đề theo mẫu thống nhất:

```text
[MSSV] - [Ho ten] - Bai tap tuan X
```

Ví dụ:

```text
[22010456] - Nguyen Van A - Bai tap tuan 1
[22010888] - Tran Thi B - Bai tap tuan 2
```

Giải thích:
- `MSSV` = mã số sinh viên
- `Ho ten` = họ và tên sinh viên
- `Bai tap tuan X` = bài tập của tuần tương ứng

#### Cách 2: Nộp bằng link repo đã fork

Nếu không dùng Pull Request, sinh viên có thể gửi đường link repo GitHub cá nhân qua:
- Moodle
- Google Classroom
- Google Form
- Microsoft Teams

Ví dụ:

```text
https://github.com/nguyenvana/DSALab
```

Cách này đơn giản, nhưng giảng viên sẽ khó nhận xét chi tiết trên từng dòng code hơn so với Pull Request.

### 8. Một số lưu ý quan trọng cho sinh viên

- Chỉ làm việc trên repo đã fork của mình
- Không push trực tiếp vào repo gốc của giảng viên
- Đặt commit message rõ ràng
- Nếu nộp bằng Pull Request, đặt tiêu đề đúng mẫu
- Chỉ push các file cần thiết như `.cpp`, `.c`, `.h`, `README.md` khi được yêu cầu
- Không push các file không cần thiết như `.exe`, `bin/`, `build/`, `obj/`, `.vscode/`

### 9. Mẫu hướng dẫn ngắn gửi cho sinh viên

```text
Huong dan nop bai DSALab

1. Vao repo goc:
   https://github.com/CocAgent/DSALab

2. Nhan Fork de tao repo rieng

3. Clone repo fork ve may:
   git clone https://github.com/nguyenvana/DSALab.git
   cd DSALab

4. Lam bai dung thu muc duoc yeu cau

5. Day bai len GitHub ca nhan bang cac lenh:
   git add .
   git commit -m "Hoan thanh bai tap tuan 1"
   git push origin main

6. Nop bai bang mot trong hai cach:
   - Tao Pull Request ve repo goc
   - Hoac gui link repo fork len he thong hoc tap

Neu nop bang Pull Request, dat tieu de theo mau:
[MSSV] - [Ho ten] - Bai tap tuan X
```

### 10. Lời khuyên dành cho sinh viên

Để việc nộp bài được thuận lợi và dễ chấm hơn, các em nên:

- đặt bài làm đúng thư mục theo hướng dẫn
- viết tiêu đề Pull Request đúng mẫu quy định
- ghi commit message rõ ràng, dễ hiểu
- không đẩy lên các file không cần thiết như file `.exe`, thư mục `build/`, `bin/`, `obj/`
- kiểm tra kỹ bài trước khi push lên GitHub
### 11. Hướng dẫn sinh viên tạo Pull Request sau khi fork
Sau khi fork repo `DSALab` và làm bài xong trên repo cá nhân, sinh viên cần tạo **Pull Request** để giảng viên dễ xem và nhận xét bài làm.
Các bước thực hiện:
1. Vào repo fork của mình trên GitHub
2. Chọn tab **Code**
3. Nhấn **Contribute**
4. Chọn **Open pull request**
5. Kiểm tra đúng nơi gửi về là:
   - **base repository**: `CocAgent/DSALab`
   - **base branch**: `main`
6. Đặt tiêu đề Pull Request theo mẫu:

```text
[MSSV] - [Ho ten] - Bai tap tuan X
**Ví dụ `.gitignore` cơ bản:**

```gitignore
bin/
build/
obj/
*.exe
*.out
.vscode/
.idea/

---

## 📝 Ghi Chú
- Tất cả code sử dụng **tiếng Việt không dấu** trong tên hàm/biến để tránh lỗi encoding
- Mỗi file có thể biên dịch **độc lập**, không phụ thuộc nhau

- Các hàm đặt tên theo phong cách **giáo trình** (`HoanVi`, `ThemDau`, `XoaCuoi`, ...)

- Các hàm đặt tên theo phong cách **giáo trình** (HoanVi, ThemDau, XoaCuoi, ...)
---

## 📌 Quy Trình Fork và Nộp Bài

### Huong dan nop bai DSALab

Huong dan nop bai DSALab

1. Vao repo goc:
   https://github.com/CocAgent/DSALab

2. Nhan Fork de tao repo rieng

3. Clone repo fork ve may

4. Lam bai dung thu muc duoc yeu cau

5. Day bai len GitHub ca nhan bang cac lenh:

   git add .
   git commit -m "Hoan thanh bai tap tuan 1"
   git push origin main

6. Nop bai bang mot trong hai cach:
   - Tao Pull Request ve repo goc
   - Hoac gui link repo fork len he thong hoc tap

   Neu nop bang Pull Request, dat tieu de theo mau:
   [MSSV] - [Ho ten] - Bai tap tuan X
----
Ví dụ:
1. git clone https://github.com/nguyenvana/DSALab.git
2. cd DSALab
3. git add .
4. git commit -m "Hoan thanh bai tap tuan 1"
5. git push origin main
---
