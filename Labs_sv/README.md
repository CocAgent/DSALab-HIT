# DSA Labs C++ — Hướng dẫn thực hành & Học cùng AI

> **Môn:** Cấu Trúc Dữ Liệu & Giải Thuật &nbsp;|&nbsp; **GV:** TVS 
> **Mục tiêu:** Không chỉ code được — mà *hiểu tại sao* và *tự xây dựng ứng dụng riêng*

---

## Mục lục

1. [Bộ file thực hành](#1-bộ-file-thực-hành)
2. [Compile & Chạy nhanh](#2-compile--chạy-nhanh)
3. [Triết lý học với AI](#3-triết-lý-học-với-ai)
4. [Hướng dẫn dùng AI theo từng chương](#4-hướng-dẫn-dùng-ai-theo-từng-chương)
5. [Từ lý thuyết đến ứng dụng cá nhân](#5-từ-lý-thuyết-đến-ứng-dụng-cá-nhân)
6. [So sánh Claude · ChatGPT · Gemini](#6-so-sánh-claude--chatgpt--gemini)
7. [Prompt mẫu theo tình huống](#7-prompt-mẫu-theo-tình-huống)
8. [Quy tắc vàng & Cảnh báo](#8-quy-tắc-vàng--cảnh-báo)
9. [Bài tập lớn — Xây dựng ứng dụng](#9-bài-tập-lớn--xây-dựng-ứng-dụng)

---

## 1. Bộ file thực hành

| File | Chương | Nội dung chính | Buổi lab |
|------|--------|----------------|----------|
| `ch1_bigO.cpp` | Chương 1 | Big-O, Recursion, Benchmark | Buổi 1–2 |
| `ch2_sort.cpp` | Chương 2 | Binary Search, Bubble/Quick/Merge Sort | Buổi 3–4 |
| `ch3_list.cpp` | Chương 3 | Linked List, Stack, Queue, Min-Heap | Buổi 5–6 |
| `ch4_tree.cpp` | Chương 4 | BST, Traversal, ASCII Tree | Buổi 7 |
| `ch4_bst_buoi07.cpp` | Chương 4 | **Bài tập 12 — BST đầy đủ + Menu** | Buổi 7 |
| `ch5_graph.cpp` | Chương 5 | BFS, DFS, Dijkstra, Maze | Buổi 8–9 |

---

## 2. Compile & Chạy nhanh

### Yêu cầu

- `g++` hỗ trợ C++17 — kiểm tra: `g++ --version` (cần >= 9.0)
- Windows: cài [MinGW](https://www.mingw-w64.org/) hoặc dùng WSL
- Mac: `xcode-select --install`

### Lệnh compile từng file

```bash
# Cú pháp chung
g++ -std=c++17 <file>.cpp -o <output> && ./<output>

# Từng chương
g++ -std=c++17 ch1_bigO.cpp        -o ch1 && ./ch1
g++ -std=c++17 ch2_sort.cpp        -o ch2 && ./ch2
g++ -std=c++17 ch3_list.cpp        -o ch3 && ./ch3
g++ -std=c++17 ch4_tree.cpp        -o ch4 && ./ch4
g++ -std=c++17 ch4_bst_buoi07.cpp  -o bst && ./bst
g++ -std=c++17 ch5_graph.cpp       -o ch5 && ./ch5
```

### Compile với debug (phát hiện lỗi memory)

```bash
g++ -std=c++17 -g -fsanitize=address,undefined ch4_bst_buoi07.cpp -o bst_dbg
./bst_dbg
```

---

## 3. Triết lý học với AI

### Ba mức độ sử dụng AI

```
Mức 1 — HIỂU  (Luôn khuyến khích)
  Hỏi AI giải thích concept, ví dụ minh họa, so sánh thuật toán

Mức 2 — GỢI Ý  (Chỉ sau khi tự suy nghĩ >= 20 phút)
  Hỏi AI gợi ý hướng tiếp cận — không phải code sẵn

Mức 3 — REVIEW  (Sau khi tự viết xong)
  Nhờ AI review và cải thiện code của chính mình
```

### Điều AI không thể thay thế bạn

| Việc bạn phải tự làm | Lý do |
|----------------------|-------|
| Tự gõ code từng dòng | Ngón tay nhớ, não mới hiểu |
| Tự debug >= 15 phút trước khi hỏi | Kỹ năng debug = 50% công việc thực tế |
| Tự giải thích code cho người khác | Giải thích được = thực sự hiểu |
| Tự nghĩ ý tưởng ứng dụng | AI không biết bạn thích gì, muốn gì |

---

## 4. Hướng dẫn dùng AI theo từng chương

### Chương 1 — Big-O & Recursion

**Trước khi chạy `ch1_bigO.cpp`, hỏi AI:**

```
Prompt — HIỂU CONCEPT:
"Tôi là sinh viên học DSA C++.
Giải thích Big-O Notation bằng 1 ví dụ đời thực
(không dùng code). Sau đó cho tôi biết:
- O(log n) nhanh hơn O(n) bao nhiêu lần khi n = 1,000,000?
- Tại sao Fibonacci đệ quy ngây thơ là O(2^n)?"
```

**Sau khi chạy và thấy output, hỏi tiếp:**

```
Prompt — ĐÀO SÂU:
"Output cho thấy fib_naive(30) cần 1,346,269 lần gọi hàm.
Giải thích con số này từ đâu ra.
Vẽ cây đệ quy cho fib(4) để tôi hiểu trực quan."
```

---

### Chương 2 — Search & Sort

**Trước khi code Binary Search:**

```
Prompt — HIỂU CONCEPT:
"Giải thích Binary Search bằng trò chơi đoán số 1-100.
Tại sao mỗi lần đoán ta loại được một nửa?
Liên hệ với code C++ như thế nào?"
```

**Sau khi chạy sorting benchmark:**

```
Prompt — PHÂN TÍCH KẾT QUẢ:
"Benchmark của tôi cho thấy:
  Bubble Sort n=8000: 89ms
  Quick Sort  n=8000: 0.3ms
Tại sao chênh lệch lớn vậy?
Giải thích bằng Big-O, không cần code."
```

**Sau khi xong chương 2, tìm ý tưởng ứng dụng:**

```
Prompt — TÌM Ý TƯỞNG:
"Tôi học xong Binary Search và Sorting.
Gợi ý 5 ứng dụng thực tế một sinh viên năm 2
có thể tự build trong 1 tuần bằng C++.
Mỗi ứng dụng: tên + thuật toán dùng + độ khó."
```

---

### Chương 3 — Linked List, Stack, Queue

**Trước khi code Stack:**

```
Prompt — HIỂU CONCEPT:
"Giải thích Stack (LIFO) bằng 2 ví dụ:
1 ví dụ đời thực, 1 ví dụ trong lập trình.
Tại sao trình duyệt web dùng Stack cho nút Back?"
```

**Sau khi code xong, nhờ review:**

```
Prompt — REVIEW CODE:
"Review code Linked List của tôi:

[paste code]

Tập trung kiểm tra: hàm reverse() có đúng không?
Vẽ sơ đồ bộ nhớ trước và sau khi reverse."
```

**Tìm ý tưởng ứng dụng theo sở thích:**

```
Prompt — TÌM Ý TƯỞNG CÁ NHÂN:
"Tôi biết Linked List, Stack, Queue.
Tôi muốn build ứng dụng quản lý [LĨNH VỰC BẠN THÍCH].
Cấu trúc dữ liệu nào phù hợp nhất? Tại sao?
Phác thảo 5 chức năng cơ bản."
```

---

### Chương 4 — BST (Bài tập 12, Buổi 07)

**Tiết 1-2: Trước khi implement ThemNut:**

```
Prompt — HIỂU TRƯỚC KHI CODE:
"Tôi đang làm Bài tập 12 BST, môn DSA C++.
Giải thích BST Insert bằng ví dụ với dãy:
74, 125, 32, 17, 50, 320, 62
Vẽ cây sau mỗi lần insert.
KHÔNG viết code, chỉ dùng hình ảnh/text."
```

**Tiết 3: Trước khi code 3 hàm duyệt:**

```
Prompt — PHÂN BIỆT 3 KIỂU DUYỆT:
"Với cây BST gốc=74, giải thích:
- NLR cho kết quả gì?
- LNR cho kết quả gì? Tại sao là dãy tăng dần?
- LRN được dùng trong tình huống nào thực tế?
Hỏi tôi 1 câu kiểm tra hiểu bài sau khi giải thích."
```

**Tiết 4: Trước khi code BSTDelete — phần khó nhất:**

```
Prompt — SUY NGHĨ TRƯỚC KHI XEM CODE:
"Mô tả 3 trường hợp xóa node trong BST bằng lời (không code).
Nếu tôi xóa node 32 (có 2 con: 17 và 50) trong cây:
gốc=74, trái=32, phải=125
Node nào sẽ thay thế và tại sao?
Chờ tôi trả lời trước khi giải thích."
```

**Sau khi hoàn thành Bài tập 12:**

```
Prompt — HỌC SÂU HƠN:
"Tôi vừa xong BST. Giải thích:
1. BST degenerate là gì? Khi nào xảy ra?
2. AVL Tree khác BST thế nào?
3. Nếu phỏng vấn, họ hỏi gì về BST?
   Cho 3 câu hỏi phổ biến + cách trả lời ngắn gọn."
```

---

### Chương 5 — Graph

**Trước khi code BFS:**

```
Prompt — HIỂU CONCEPT:
"Giải thích BFS bằng bài toán: tìm đường ngắn nhất
trong mê cung. Queue được dùng như thế nào?
Tại sao BFS đảm bảo tìm được đường ngắn nhất
với unweighted graph?"
```

**Sau khi chạy Dijkstra:**

```
Prompt — PHÂN TÍCH GIỚI HẠN:
"Dijkstra của tôi đúng với graph dương
nhưng sai với graph có cạnh âm.
Giải thích tại sao KHÔNG dùng code.
Bellman-Ford khác gì? Khi nào dùng cái nào?"
```

---

## 5. Từ lý thuyết đến ứng dụng cá nhân

### Hành trình 4 bước

#### Bước 1 — Khám phá ý tưởng

Sau mỗi chương, dùng prompt này để tìm ý tưởng **phù hợp sở thích của bạn**:

```
Prompt — KHÁM PHÁ:
"Tôi vừa học xong [TÊN CHƯƠNG/CẤU TRÚC DỮ LIỆU].
Tôi thích [LĨNH VỰC: game / âm nhạc / thể thao /
           tài chính / y tế / giáo dục / ...].

Gợi ý 3 ứng dụng nhỏ kết hợp DSA vừa học với
lĩnh vực tôi thích. Mỗi ý gồm:
- Tên ứng dụng
- Dùng cấu trúc dữ liệu nào, tại sao
- Chức năng chính (3-5 chức năng)
- Ước tính thời gian: X ngày
- Độ khó: Dễ / Trung bình / Khó"
```

#### Bước 2 — Thiết kế với AI (không code)

```
Prompt — THIẾT KẾ:
"Tôi muốn build: [TÊN ỨNG DỤNG]
Ngôn ngữ: C++, chạy CLI (terminal)
Thời gian: [X] ngày

Giúp tôi thiết kế:
1. Struct/class cần dùng
2. Danh sách hàm (chỉ tên + mô tả ngắn)
3. Thứ tự implement — cái nào trước
4. Menu CLI trông như thế nào

QUAN TRỌNG: Chỉ thiết kế, KHÔNG viết code.
Tôi sẽ tự code từng hàm."
```

#### Bước 3 — Tự code, AI hỗ trợ khi stuck

```
Prompt — KHI BỊ STUCK:
"Tôi đang implement hàm [TÊN HÀM]
cho ứng dụng [TÊN APP].
Signature: [paste function signature]
Tôi nghĩ approach: [mô tả hướng bạn nghĩ]

Hỏi tôi 2 câu để tự tìm ra vấn đề.
Không viết code giúp tôi."
```

#### Bước 4 — Review & cải thiện

```
Prompt — REVIEW TRƯỚC KHI HOÀN THÀNH:
"Review code C++ của tôi cho ứng dụng [TÊN APP]:

[paste toàn bộ code]

Review theo thứ tự ưu tiên:
[CRITICAL] Lỗi logic, crash, memory leak
[MAJOR]    Thiếu xử lý edge case
[MINOR]    Code style, đặt tên, comment

Sau review, gợi ý 1 tính năng nâng cao có thể thêm."
```

### Ví dụ hành trình thực tế

```
Sinh viên thích âm nhạc + vừa học Linked List:

Bước 1: Hỏi AI -> gợi ý "Playlist Manager"
  - Dùng Doubly Linked List
  - Chức năng: thêm/xóa bài, next/prev, shuffle, repeat

Bước 2: AI thiết kế struct Song, struct Playlist,
  danh sách 8 hàm, menu 6 lựa chọn

Bước 3: Tự code AddSong(), RemoveSong()
  Bị stuck ở Shuffle -> hỏi AI gợi ý Fisher-Yates
  Tự implement theo gợi ý

Bước 4: AI phát hiện memory leak trong RemoveSong()
  Tự sửa, hiểu tại sao bị leak

Kết quả: 1 ứng dụng thực sự của riêng mình,
  hiểu từng dòng code, tự giải thích được.
```

---

## 6. So sánh Claude · ChatGPT · Gemini

| Tiêu chí | Claude | ChatGPT | Gemini |
|----------|--------|---------|--------|
| Giải thích concept sâu | Xuất sắc | Rất tốt | Tốt |
| Debug C++ | Xuất sắc | Xuất sắc | Tốt |
| Gợi ý ý tưởng sáng tạo | Xuất sắc | Xuất sắc | Tốt |
| Code review chi tiết | Xuất sắc | Tốt | Trung bình |
| Tìm kiếm thông tin mới | Tốt | Tốt | Xuất sắc |
| Miễn phí | Có giới hạn | Có giới hạn | Rộng rãi |
| Tiếng Việt | Xuất sắc | Xuất sắc | Xuất sắc |

### Khi nào dùng AI nào?

```
Claude    -> Giải thích lý thuyết sâu, thiết kế hệ thống, hỏi "tại sao"
ChatGPT   -> Debug nhanh, generate test cases, viết documentation
Gemini    -> Tìm tài liệu mới nhất, so sánh thư viện, câu hỏi về công nghệ mới
```

### Cách đặt câu hỏi hiệu quả với MỌI AI

```
Câu hỏi tệ:   "Viết code BST cho tôi"
Câu hỏi tốt:  "Tôi đang implement BSTDelete nhưng trường hợp
                xóa node có 2 con bị sai. Code của tôi: [paste].
                Giải thích lỗi ở đâu mà không fix hộ tôi."

Câu hỏi tệ:   "Linked list là gì?"
Câu hỏi tốt:  "So sánh Array và Linked List về:
                1) Truy cập phần tử thứ k
                2) Chèn vào giữa
                3) Bộ nhớ sử dụng
                Cho ví dụ khi nào nên dùng cái nào."
```

---

## 7. Prompt mẫu theo tình huống

### Tình huống 1 — Chưa hiểu concept

```
"Tôi là sinh viên năm 2 học DSA C++.
Giải thích [CONCEPT] theo 3 bước:
1. Ví dụ đời thực (không dùng code, không thuật ngữ kỹ thuật)
2. Cách hoạt động step-by-step (có thể dùng ASCII art)
3. Code C++ đơn giản nhất có thể
Sau đó hỏi tôi 1 câu kiểm tra hiểu bài."
```

### Tình huống 2 — Bị stuck khi code

```
"Tôi đang implement [TÊN HÀM] trong C++.
Code của tôi: [paste code]
Lỗi/kết quả sai: [mô tả]
Tôi nghĩ vấn đề ở: [phỏng đoán của bạn]

Xác nhận tôi đúng/sai, rồi hỏi tôi câu hỏi
để tôi tự tìm ra cách sửa. Không sửa hộ."
```

### Tình huống 3 — Muốn hiểu sâu hơn

```
"Tôi vừa implement [CẤU TRÚC DỮ LIỆU] xong.
Câu hỏi nâng cao:
1. Trong thực tế, cấu trúc này dùng ở đâu?
   (database, OS, game engine, ...)
2. Giới hạn của nó? Khi nào không nên dùng?
3. Phiên bản nâng cao là gì?
   (ví dụ: BST -> AVL -> Red-Black Tree)
4. Câu hỏi phỏng vấn FAANG phổ biến về topic này?"
```

### Tình huống 4 — Thiết kế ứng dụng cá nhân

```
"Tôi muốn làm đồ án về [CHỦ ĐỀ BẠN THÍCH].
Các cấu trúc dữ liệu tôi đã học: [liệt kê].
Thời gian: [X] tuần, làm một mình.

Đề xuất 3 ý tưởng ứng dụng:
- Phù hợp kỹ năng hiện tại
- Hoàn thành được trong thời gian trên
- Ấn tượng khi demo

Với mỗi ý: mô tả ngắn + cấu trúc dữ liệu chính + điểm độc đáo."
```

### Tình huống 5 — Chuẩn bị thi / phỏng vấn

```
"Mock interview DSA với tôi theo phong cách FAANG.
Topic: [CHAPTER]. Language: C++. Level: [Easy/Medium/Hard].

Quy tắc:
- Hỏi tôi 1 câu, đợi tôi trả lời
- Feedback sau mỗi câu trả lời
- Hỏi follow-up nếu trả lời đúng
- Gợi ý hướng nếu tôi stuck quá 5 phút

Bắt đầu ngay!"
```

---

## 8. Quy tắc vàng & Cảnh báo

### Được phép — Dùng AI để:

- Giải thích concept mà giáo trình chưa rõ
- Debug lỗi sau khi đã tự tìm >= 15 phút
- Review code sau khi đã tự viết xong
- Gợi ý ý tưởng ứng dụng
- Giải thích output của chương trình
- Học cách đặt tên biến, viết comment chuẩn

### Cần thận trọng — Chỉ dùng AI sau khi:

- Đã đọc lý thuyết trong slide/giáo trình
- Đã tự suy nghĩ >= 20 phút
- Đã thử ít nhất 2 cách tiếp cận khác nhau

### Không nên — Những việc làm giảm hiệu quả học:

| Hành động | Hậu quả thực tế |
|-----------|-----------------|
| Copy code AI về submit ngay | Fail khi thi vì không hiểu |
| Paste cả đề bài xin code luôn | Mất kỹ năng tư duy thuật toán |
| Không gõ tay mà copy-paste code | Tay không quen, debug không biết |
| Chấp nhận code AI mà không đọc | Bug lạ không tìm ra nguyên nhân |

### Tự kiểm tra — Bạn có thực sự hiểu không?

Sau mỗi buổi lab, trả lời 4 câu này:

```
1. Tôi có thể giải thích hàm này cho bạn cùng lớp không?
2. Nếu xóa code đi, tôi có tự viết lại được không?
3. Tôi biết hàm sẽ sai ở đâu khi gặp input bất thường?
4. Tôi biết tại sao chọn cấu trúc này, không phải cái khác?
```

4/4 câu YES = thực sự hiểu bài. Dưới 4 = cần ôn lại.

---

## 9. Bài tập lớn — Xây dựng ứng dụng

### Mục tiêu

Mỗi sinh viên tự xây dựng **1 ứng dụng CLI bằng C++** áp dụng ít nhất **2 cấu trúc dữ liệu** đã học, chủ đề theo đúng sở thích cá nhân.

### Ý tưởng theo lĩnh vực

| Lĩnh vực | Ứng dụng gợi ý | Cấu trúc dữ liệu |
|----------|----------------|-----------------|
| Game | Text RPG với inventory, enemy AI | Linked List + BST |
| Âm nhạc | Playlist manager + shuffle | Doubly Linked List + Heap |
| Học tập | Flashcard app với spaced repetition | Queue + BST |
| Y tế | Quản lý bệnh nhân + ưu tiên khẩn cấp | Priority Queue |
| Bán hàng | Quản lý kho + tìm kiếm nhanh | Hash Table + BST |
| Di chuyển | Tìm đường trong campus | Graph + Dijkstra |
| Tài chính | Quản lý chi tiêu + báo cáo | BST + Stack |

### Cách bắt đầu bằng AI — theo đúng thứ tự

**Bước 1** — Chọn lĩnh vực và khám phá ý tưởng:

```
"Tôi thích [LĨNH VỰC]. Tôi đã học: Linked List, Stack,
Queue, BST, BFS/DFS. Gợi ý 3 ứng dụng CLI C++ tôi có thể
tự build trong 2 tuần. Mỗi ý: tên + chức năng + cấu trúc dữ liệu."
```

**Bước 2** — Thiết kế kiến trúc với AI (chỉ thiết kế, không code):

```
"Tôi chọn làm [TÊN ỨNG DỤNG]. Giúp tôi thiết kế:
1. Các struct cần dùng
2. Danh sách hàm (tên + mô tả ngắn gọn)
3. Thứ tự implement từng phần
4. Cấu trúc Menu CLI
KHÔNG viết code — chỉ phác thảo kiến trúc."
```

**Bước 3** — Tự code từng hàm, AI làm mentor khi cần.

**Bước 4** — Demo và giải thích được mọi dòng code của mình.

---

## Tài nguyên tham khảo

- [VisuAlgo](https://visualgo.net/en) — Animation BST, BFS, Sorting trực quan
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com) — Bảng tra cứu độ phức tạp
- [CP-Algorithms](https://cp-algorithms.com) — Thuật toán nâng cao có code
- [Claude AI](https://claude.ai) — Hỏi lý thuyết, thiết kế, review code
- [ChatGPT](https://chat.openai.com) — Debug nhanh, sinh test cases
- [Gemini](https://gemini.google.com) — Tìm tài liệu, so sánh công nghệ

---

*"Công cụ AI không làm bạn thông minh hơn — nhưng nó giúp người chăm chỉ và tò mò học nhanh hơn gấp 10 lần."*

*Hãy dùng AI để **hiểu sâu hơn**, không phải để **học ít đi**.*
