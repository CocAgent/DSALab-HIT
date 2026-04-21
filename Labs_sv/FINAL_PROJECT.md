# FINAL PROJECT — Cấu Trúc Dữ Liệu & Giải Thuật

> **Môn:** Cấu Trúc Dữ Liệu & Giải Thuật &nbsp;|&nbsp; **GV:** TVS  
> **Hình thức:** Cá nhân hoặc nhóm 2 người  
> **Ngôn ngữ:** C++ (CLI, compile được bằng `g++ -std=c++17`)  
> **Yêu cầu tối thiểu:** Áp dụng **ít nhất 3** cấu trúc dữ liệu đã học

---

## Mục lục

- [Yêu cầu chung](#yêu-cầu-chung)
- [Gợi ý đề tài](#gợi-ý-đề-tài)
- [Hướng dẫn làm từng bước](#hướng-dẫn-làm-từng-bước)
- [Tiêu chí chấm điểm](#tiêu-chí-chấm-điểm)
- [Cách nộp bài qua GitHub](#cách-nộp-bài-qua-github)
- [Prompt AI hỗ trợ](#prompt-ai-hỗ-trợ)

---

## Yêu cầu chung

### Bắt buộc

- [ ] Chạy được bằng `g++ -std=c++17` — không lỗi compile
- [ ] Có **Menu** điều hướng toàn bộ chức năng
- [ ] Áp dụng **>= 3 cấu trúc dữ liệu**: Linked List / Stack / Queue / BST / Graph / Heap
- [ ] Tách file rõ ràng: `.h` khai báo — `.cpp` cài đặt — `main.cpp` điều khiển
- [ ] Có **README.md** giải thích ứng dụng và cách chạy
- [ ] Có **ít nhất 5 test case** kiểm thử các chức năng chính

### Không được phép

- Submit code do AI viết hoàn toàn mà không hiểu
- Sao chép code của nhóm khác

> **Lưu ý:** Buổi bảo vệ, giảng viên sẽ hỏi trực tiếp về bất kỳ dòng code nào.  
> Nếu không giải thích được → điểm bị trừ theo mức độ.

---

## Gợi ý đề tài

Chọn **1 trong 8 đề tài** bên dưới, hoặc tự đề xuất đề tài riêng (cần được duyệt trước).

---

### Đề tài 1 — Hệ thống Quản lý Thư Viện

**Mô tả:** Ứng dụng quản lý sách, độc giả và lịch sử mượn trả.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| BST | Lưu trữ sách, tìm kiếm theo mã/tên — O(log n) |
| Queue | Danh sách chờ mượn khi sách hết |
| Stack | Lịch sử thao tác — hỗ trợ Undo |
| Linked List | Danh sách độc giả |

**Chức năng chính:**

```
1. Thêm / Xóa / Sửa thông tin sách
2. Tìm kiếm sách theo mã hoặc tên (BST)
3. Mượn sách → tự động vào Queue nếu sách đang được mượn
4. Trả sách → cập nhật trạng thái, thông báo người chờ tiếp theo
5. Xem lịch sử mượn/trả (Stack — có thể Undo thao tác cuối)
6. Thống kê: sách được mượn nhiều nhất, độc giả tích cực nhất
7. Lưu/Đọc dữ liệu từ file .txt
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build Hệ thống Quản lý Thư Viện bằng C++ CLI.
Thiết kế struct Book và struct Reader cho tôi.
Tại sao nên dùng BST cho danh sách sách thay vì mảng?"
```

---

### Đề tài 2 — Mini Google Maps (Tìm đường CLI)

**Mô tả:** Bản đồ đơn giản dạng text, tìm đường ngắn nhất giữa các địa điểm.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| Graph (Adjacency List) | Lưu mạng lưới đường đi |
| Priority Queue (Min-Heap) | Dijkstra tìm đường ngắn nhất |
| Stack | Truy vết và in lại đường đi |
| Queue | BFS tìm đường ít điểm nhất |

**Chức năng chính:**

```
1. Tải bản đồ từ file .txt (danh sách cạnh + trọng số)
2. Hiển thị bản đồ dạng ASCII hoặc danh sách kết nối
3. Tìm đường ngắn nhất giữa 2 điểm (Dijkstra)
4. Tìm đường qua ít điểm nhất (BFS)
5. Thêm / Xóa địa điểm hoặc tuyến đường
6. Tìm tất cả địa điểm có thể đến từ điểm A (DFS)
7. Kiểm tra bản đồ có bị ngắt kết nối không
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build Mini Google Maps bằng C++ CLI.
Giải thích tại sao Dijkstra cần Min-Heap (Priority Queue).
Thiết kế struct Edge và Graph cho tôi."
```

---

### Đề tài 3 — Hệ thống Đặt Vé (Rạp chiếu phim / Xe khách)

**Mô tả:** Quản lý ghế ngồi, đặt vé, hủy vé và danh sách chờ.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| BST | Lưu danh sách khách hàng, tìm kiếm nhanh |
| Priority Queue | Danh sách chờ ưu tiên (VIP, người cao tuổi) |
| Stack | Lịch sử giao dịch — hỗ trợ hủy vé |
| 2D Array / Linked List | Sơ đồ ghế ngồi |

**Chức năng chính:**

```
1. Hiển thị sơ đồ ghế (trống / đã đặt) dạng ASCII
2. Đặt vé — tự động vào Priority Queue nếu hết chỗ
3. Hủy vé — Stack ghi lại, tự động cấp cho người chờ tiếp theo
4. Tìm kiếm khách hàng theo tên hoặc mã (BST)
5. Xuất danh sách đã đặt vé
6. Thống kê: số ghế còn trống, doanh thu
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build hệ thống đặt vé rạp chiếu phim bằng C++ CLI.
Tại sao cần Priority Queue cho danh sách chờ?
Thiết kế struct Seat và struct Customer cho tôi."
```

---

### Đề tài 4 — Trình Quản Lý File (Mini File Explorer)

**Mô tả:** Mô phỏng hệ thống file/thư mục dạng cây thư mục.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| Tree (N-ary) | Cây thư mục — mỗi node là folder/file |
| Stack | Navigation lịch sử (Back/Forward) |
| Queue | BFS duyệt toàn bộ thư mục |
| Linked List | Danh sách file trong một thư mục |

**Chức năng chính:**

```
1. Hiển thị cây thư mục dạng ASCII (giống lệnh tree)
2. Tạo / Xóa / Đổi tên folder và file
3. Di chuyển giữa thư mục (cd, ls, pwd)
4. Back / Forward bằng Stack lịch sử
5. Tìm kiếm file theo tên (DFS hoặc BFS)
6. Tính tổng dung lượng của một thư mục (Post-order traversal)
7. Lưu/Đọc cấu trúc từ file .txt
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build Mini File Explorer bằng C++ CLI.
Giải thích tại sao hệ thống file dùng cấu trúc cây.
Thiết kế struct FileNode cho folder và file."
```

---

### Đề tài 5 — Ứng Dụng Flashcard Học Ngoại Ngữ

**Mô tả:** App ôn từ vựng theo thuật toán Spaced Repetition.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| BST | Lưu từ điển, tìm kiếm theo từ |
| Priority Queue | Spaced Repetition — từ khó được ôn sớm hơn |
| Queue | Flashcard queue trong mỗi phiên học |
| Stack | Undo — quay lại thẻ vừa trả lời |

**Chức năng chính:**

```
1. Thêm / Xóa / Sửa flashcard (từ + nghĩa + ví dụ)
2. Phiên học: hiển thị từ, nhập nghĩa, tự chấm đúng/sai
3. Spaced Repetition: từ trả lời sai → ưu tiên ôn sớm hơn
4. Tìm kiếm từ trong từ điển (BST)
5. Thống kê: tỷ lệ đúng, từ hay quên nhất
6. Lưu tiến độ học ra file
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build app học từ vựng Spaced Repetition bằng C++ CLI.
Giải thích thuật toán Spaced Repetition đơn giản nhất.
Tại sao Priority Queue phù hợp để implement nó?"
```

---

### Đề tài 6 — Trình Soạn Thảo Biểu Thức Toán Học

**Mô tả:** Nhập biểu thức toán học, parse, tính giá trị, vẽ cây.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| Stack | Shunting-Yard: Infix → Postfix |
| Binary Tree | Expression Tree lưu cấu trúc biểu thức |
| Queue | Token queue trong quá trình parse |

**Chức năng chính:**

```
1. Nhập biểu thức dạng Infix: (3 + 4) * 2 - 1
2. Chuyển sang Postfix (RPN): 3 4 + 2 * 1 -
3. Tính giá trị biểu thức
4. Vẽ Expression Tree dạng ASCII
5. In 3 dạng: Infix / Prefix / Postfix từ cây
6. Hỗ trợ biến: gán x=5 rồi tính x^2 + 2*x + 1
7. Lịch sử tính toán (Stack)
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build Expression Parser bằng C++ CLI.
Giải thích thuật toán Shunting-Yard bằng ví dụ cụ thể.
Tại sao dùng 2 Stack để chuyển Infix sang Postfix?"
```

---

### Đề tài 7 — Game Mê Cung (Maze Game)

**Mô tả:** Tạo mê cung ngẫu nhiên, giải bằng thuật toán, cho người chơi tự giải.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| 2D Array / Graph | Lưu cấu trúc mê cung |
| Stack | DFS giải mê cung + Backtracking |
| Queue | BFS tìm đường ngắn nhất |
| Priority Queue | A* nếu có thêm trọng số |

**Chức năng chính:**

```
1. Tạo mê cung ngẫu nhiên bằng DFS (Recursive Backtracker)
2. Hiển thị mê cung ASCII trên terminal
3. Người chơi tự giải bằng phím W/A/S/D
4. Tự động giải bằng BFS (đường ngắn nhất)
5. Tự động giải bằng DFS (hiển thị backtrack)
6. So sánh: BFS vs DFS — đường nào ngắn hơn?
7. Điều chỉnh độ khó (kích thước mê cung)
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build Maze Game bằng C++ CLI.
Giải thích thuật toán Recursive Backtracker để tạo mê cung.
Tại sao BFS đảm bảo tìm đường ngắn nhất trong maze?"
```

---

### Đề tài 8 — Hệ thống Gợi Ý (Recommendation Engine)

**Mô tả:** Gợi ý sản phẩm / bài hát / phim dựa trên lịch sử người dùng.

**Cấu trúc dữ liệu sử dụng:**

| Cấu trúc | Vai trò |
|----------|---------|
| Graph | Mạng quan hệ người dùng — item |
| BST | Lưu catalog sản phẩm, tìm kiếm nhanh |
| Priority Queue | Xếp hạng gợi ý theo điểm relevance |
| Hash Map (unordered_map) | Lưu lịch sử tương tác |

**Chức năng chính:**

```
1. Thêm người dùng và danh mục sản phẩm/bài hát/phim
2. Ghi lại hành động: like, rating, xem lại
3. Gợi ý dựa trên: "người dùng tương tự cũng thích..."
4. Gợi ý dựa trên: "item tương tự với item bạn đã thích"
5. Tìm kiếm item trong catalog (BST)
6. Hiển thị Top-N gợi ý có điểm cao nhất
7. Xuất báo cáo: item phổ biến nhất, người dùng hoạt động nhất
```

**Prompt AI để bắt đầu:**
```
"Tôi muốn build Recommendation Engine đơn giản bằng C++ CLI.
Giải thích Collaborative Filtering theo cách đơn giản nhất.
Tại sao Graph phù hợp để lưu quan hệ user-item?"
```

---

## Hướng dẫn làm từng bước

### Tuần 1 — Lên ý tưởng & Thiết kế

**Ngày 1-2: Chọn đề tài và nghiên cứu**

- [ ] Đọc kỹ mô tả đề tài, chọn đề tài phù hợp sở thích
- [ ] Dùng prompt AI để hiểu sâu hơn về cấu trúc dữ liệu sẽ dùng
- [ ] Vẽ tay sơ đồ kiến trúc ứng dụng (không cần máy tính)

```
Prompt — NGHIÊN CỨU:
"Tôi chọn đề tài [TÊN ĐỀ TÀI]. Trước khi code,
giải thích tại sao [CẤU TRÚC DỮ LIỆU X] phù hợp
cho bài toán [MÔ TẢ VẤN ĐỀ].
So sánh với ít nhất 1 cấu trúc khác không phù hợp bằng."
```

**Ngày 3-4: Thiết kế kỹ thuật**

- [ ] Xác định tất cả `struct` và `class` cần dùng
- [ ] Liệt kê tất cả hàm: tên + input + output + mô tả ngắn
- [ ] Phác thảo Menu và luồng chương trình

```
Prompt — THIẾT KẾ:
"Tôi làm [TÊN ĐỀ TÀI] bằng C++ CLI.
Đây là sơ đồ kiến trúc tôi vẽ tay: [mô tả].
Thiết kế các struct cần dùng và danh sách hàm.
KHÔNG viết code — chỉ thiết kế interface."
```

**Ngày 5: Tạo repo GitHub và khung project**

```bash
# Tạo repo trên github.com trước, sau đó:
git clone https://github.com/username/TenProject.git
cd TenProject

# Tạo cấu trúc thư mục
mkdir -p src tests docs

# Tạo file khung (rỗng)
touch src/main.cpp src/structures.h src/functions.cpp
touch README.md tests/test_cases.cpp

git add .
git commit -m "chore: khoi tao project structure"
git push
```

---

### Tuần 2 — Implement cấu trúc dữ liệu

**Mục tiêu:** Hoàn thành tất cả struct và hàm cơ bản.

**Thứ tự khuyến nghị:**

```
Ngày 1: Implement struct + KhoiTao + hàm thêm dữ liệu
Ngày 2: Implement hàm tìm kiếm + xóa
Ngày 3: Implement hàm duyệt + xuất dữ liệu
Ngày 4: Kết nối các cấu trúc với nhau
Ngày 5: Test và debug từng hàm
```

**Sau mỗi hàm hoàn thành, commit ngay:**

```bash
git add src/functions.cpp
git commit -m "feat: implement [TenHam] - [mo ta ngan]"
# Ví dụ:
git commit -m "feat: implement BSTInsert - them nut de quy"
git commit -m "feat: implement Dijkstra - tim duong ngan nhat"
git push
```

**Prompt khi bị stuck:**

```
Prompt — DEBUG:
"Hàm [TÊN HÀM] của tôi bị lỗi:
Code: [paste code]
Lỗi: [mô tả lỗi / error message]
Tôi nghĩ nguyên nhân là: [phỏng đoán]

Xác nhận đúng/sai và hỏi tôi câu hỏi
để tự tìm ra cách sửa. Không sửa hộ."
```

---

### Tuần 3 — Hoàn thiện & Nâng cao

**Ngày 1-2: Xây dựng Menu và kết nối chức năng**

- [ ] Implement `Menu()` đầy đủ
- [ ] Kết nối tất cả chức năng vào `main.cpp`
- [ ] Test toàn bộ luồng từ đầu đến cuối

**Ngày 3: Thêm tính năng nâng cao**

- [ ] Lưu/Đọc dữ liệu từ file `.txt`
- [ ] Xử lý input lỗi (người dùng nhập sai)
- [ ] Thêm màu sắc terminal (tùy chọn)

**Ngày 4: Viết test cases**

```cpp
// tests/test_cases.cpp — Viết ít nhất 5 test
void test_them_du_lieu()   { /* ... */ }
void test_tim_kiem()       { /* ... */ }
void test_xoa_du_lieu()    { /* ... */ }
void test_edge_cases()     { /* ... */ }  // Input rỗng, trùng lặp
void test_hieu_nang()      { /* ... */ }  // Test với n = 1000
```

**Ngày 5: Viết README và chuẩn bị bảo vệ**

README của project cần có:

```markdown
## Tên ứng dụng
Mô tả ngắn gọn.

## Cấu trúc dữ liệu sử dụng
- BST: dùng để... vì...
- Queue: dùng để... vì...
- ...

## Compile và chạy
g++ -std=c++17 src/main.cpp src/functions.cpp -o app && ./app

## Chức năng
1. ...
2. ...

## Test cases
Mô tả 5 test case chính.

## Cấu trúc file
src/
  main.cpp       — Menu và điều khiển
  structures.h   — Khai báo struct + nguyên mẫu hàm
  functions.cpp  — Cài đặt chi tiết
```

---

### Tuần 4 — Hoàn thiện & Nộp bài

**Checklist trước khi nộp:**

```
Kỹ thuật:
□ Compile không lỗi, không warning nghiêm trọng
□ Chạy đúng tất cả chức năng trong menu
□ Xử lý được input sai (không bị crash)
□ >= 3 cấu trúc dữ liệu được áp dụng đúng
□ File được tách đúng: .h / .cpp / main.cpp

Tài liệu:
□ README.md đầy đủ (mô tả + compile + chức năng)
□ Comment trong code giải thích các đoạn khó
□ Commit history rõ ràng trên GitHub

Chuẩn bị bảo vệ:
□ Giải thích được tại sao chọn cấu trúc đó
□ Giải thích được Big-O của các hàm chính
□ Demo chạy được trên máy giảng viên
□ Trả lời được: "Nếu thêm tính năng X thì sửa ở đâu?"
```

**Push bài hoàn chỉnh:**

```bash
git add .
git commit -m "feat: complete project - [ten de tai]"
git tag v1.0
git push origin main --tags
```

---

## Tiêu chí chấm điểm

| Tiêu chí | Điểm | Mô tả |
|----------|------|-------|
| **Chức năng hoạt động** | 30đ | Tất cả menu chạy đúng, không crash |
| **Cấu trúc dữ liệu** | 25đ | Áp dụng đúng >= 3 CTDL, có lý do chọn |
| **Chất lượng code** | 20đ | Tách file, đặt tên rõ, có comment |
| **Test cases** | 10đ | >= 5 test, bao gồm edge cases |
| **README & Git history** | 10đ | README đầy đủ, commit có ý nghĩa |
| **Bảo vệ** | 5đ | Giải thích được code và lựa chọn thiết kế |

### Điểm cộng

| Tính năng nâng cao | Điểm cộng |
|--------------------|-----------|
| Lưu/Đọc file hoạt động tốt | +2đ |
| Visualization ASCII đẹp | +1đ |
| Đề xuất đề tài riêng sáng tạo | +2đ |
| Hỗ trợ nhiều cấu trúc dữ liệu (>= 4) | +2đ |

---

## Cách nộp bài qua GitHub

### Bước 1 — Clone repo môn học về máy

```bash
git clone https://github.com/CocAgent/DSALab-HIT.git
cd DSALab-HIT
```

### Bước 2 — Tạo thư mục bài nộp

Tạo đúng theo cấu trúc sau trong thư mục `Labs_sv/`:

```
Labs_sv/
└── MSSV_HoTen_DeTai/        ← đặt tên theo mẫu này
    ├── src/
    │   ├── main.cpp
    │   ├── structures.h
    │   └── functions.cpp
    ├── tests/
    │   └── test_cases.cpp
    ├── docs/
    │   └── bao_cao.pdf       ← tuỳ chọn
    └── README.md
```

Ví dụ: `Labs_sv/21IT001_NguyenVanA_ThuVien/`

### Bước 3 — Đẩy bài lên

```bash
# Tạo thư mục đúng tên
mkdir -p Labs_sv/MSSV_HoTen_DeTai/src
mkdir -p Labs_sv/MSSV_HoTen_DeTai/tests

# Copy toàn bộ code vào thư mục vừa tạo, sau đó:
git add Labs_sv/MSSV_HoTen_DeTai/
git commit -m "submit: MSSV_HoTen - [Ten De Tai]"
git push origin main
```

### Bước 4 — Kiểm tra bài đã lên chưa

Vào link sau để xác nhận thư mục đã xuất hiện:

```
https://github.com/CocAgent/DSALab-HIT/tree/main/Labs_sv
```

### Nộp đúng 2 thứ

```
1. Thư mục trên GitHub: Labs_sv/MSSV_HoTen_DeTai/
2. Gửi link thư mục cho giảng viên qua email hoặc LMS
   Ví dụ: https://github.com/CocAgent/DSALab-HIT/tree/main/Labs_sv/21IT001_NguyenVanA_ThuVien
```

> **Lưu ý:** Nếu chưa có quyền push, tạo **Pull Request** từ fork của bạn về repo chính.

### Convention commit message (bắt buộc)

```bash
git commit -m "feat: them chuc nang [ten chuc nang]"
git commit -m "fix: sua loi [mo ta loi]"
git commit -m "refactor: cai thien [phan code]"
git commit -m "test: them test case cho [ten ham]"
git commit -m "docs: cap nhat README"
```

---

## Prompt AI hỗ trợ

### Khi bắt đầu đề tài

```
"Tôi chọn đề tài [TÊN ĐỀ TÀI] cho môn DSA C++.
Phân tích bài toán này:
1. Thao tác nào được thực hiện nhiều nhất?
2. Cấu trúc dữ liệu nào tối ưu nhất cho thao tác đó? Tại sao?
3. Trade-off nào tôi phải chấp nhận với lựa chọn này?"
```

### Khi thiết kế struct

```
"Tôi cần thiết kế struct cho [ĐỐI TƯỢNG] trong ứng dụng [TÊN APP].
Các thông tin cần lưu: [liệt kê].
Gợi ý cách thiết kế struct C++ tốt nhất.
Giải thích tại sao dùng pointer thay vì value ở một số trường."
```

### Khi không biết implement thế nào

```
"Tôi cần implement [CHỨC NĂNG] cho ứng dụng [TÊN APP].
Tôi đã biết cách dùng [CẤU TRÚC DỮ LIỆU].
Mô tả thuật toán bằng pseudocode (không code C++).
Sau đó hỏi tôi có hiểu không trước khi đưa code."
```

### Khi review code trước khi nộp

```
"Review toàn bộ project của tôi trước khi nộp:
[paste code hoặc mô tả]

Kiểm tra:
1. Có lỗi logic nào không?
2. Có memory leak không?
3. Edge cases nào tôi chưa xử lý?
4. Nếu giảng viên hỏi 'tại sao dùng X thay vì Y',
   tôi trả lời thế nào?"
```

### Khi chuẩn bị bảo vệ

```
"Mock bảo vệ đồ án với tôi. Đề tài: [TÊN ĐỀ TÀI].
Cấu trúc dữ liệu dùng: [liệt kê].

Đóng vai giảng viên khó tính, hỏi tôi:
- Tại sao chọn cấu trúc này?
- Big-O của hàm quan trọng nhất?
- Nếu n = 1,000,000 thì ứng dụng còn chạy được không?
- Điểm yếu nhất của thiết kế này là gì?"
```

---

> *"Ứng dụng tốt nhất không phải là ứng dụng có nhiều tính năng nhất,  
> mà là ứng dụng bạn hiểu từng dòng code và tự hào khi demo."*

---

**Chúc các bạn hoàn thành project thành công!**  
Mọi thắc mắc: liên hệ giảng viên qua email hoặc đặt câu hỏi trên GitHub Issues của repo môn học.
