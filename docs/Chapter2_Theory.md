# 📗 Chương 2: Tìm Kiếm & Sắp Xếp

> **Mục tiêu:** Nắm vững 2 giải thuật tìm kiếm và 5 giải thuật sắp xếp kinh điển.

---

## 1. Giải Thuật Tìm Kiếm

### 1.1 Tìm Kiếm Tuyến Tính (Linear Search) — O(N)

**Ý tưởng:** Duyệt tuần tự từng phần tử, so sánh với giá trị cần tìm.

```
Mảng: [ 64  25  12  22  11  90  45  33 ]
Tìm x = 22:
  i=0: 64 ≠ 22 → tiếp
  i=1: 25 ≠ 22 → tiếp
  i=2: 12 ≠ 22 → tiếp
  i=3: 22 = 22 → TÌM THẤY tại vị trí 3 ✅
```

| | Giá Trị |
|--|---------|
| **Best case** | O(1) — phần tử ở đầu |
| **Average** | O(N/2) ≈ O(N) |
| **Worst case** | O(N) — không có hoặc ở cuối |
| **Yêu cầu** | Không cần sắp xếp trước |

---

### 1.2 Tìm Kiếm Nhị Phân (Binary Search) — O(log N)

**Ý tưởng:** Chia đôi không gian tìm kiếm mỗi bước. **Yêu cầu mảng đã sắp xếp.**

```
Mảng đã sắp xếp: [ 11  22  33  44  55  66  77  88  99 ]
Tìm x = 66:

Bước 1: l=0, r=8, mid=4 → a[4]=55 < 66 → tìm nửa phải
Bước 2: l=5, r=8, mid=6 → a[6]=77 > 66 → tìm nửa trái
Bước 3: l=5, r=5, mid=5 → a[5]=66 = 66 → TÌM THẤY ✅

Chỉ mất 3 bước thay vì 6 bước (linear)!
```

| | Giá Trị |
|--|---------|
| **Best case** | O(1) — phần tử ở giữa |
| **Average/Worst** | O(log₂ N) |
| **Yêu cầu** | Mảng **đã sắp xếp** |

### 1.3 So Sánh 2 Giải Thuật

| Tiêu Chí | Tuyến Tính | Nhị Phân |
|----------|-----------|---------|
| Cần sắp xếp? | ❌ Không | ✅ Bắt buộc |
| Best case | O(1) | O(1) |
| Worst case | O(N) | O(log N) |
| N = 1,000,000 | 1,000,000 bước | ~20 bước |
| Cài đặt | Đơn giản | Phức tạp hơn |
| Phù hợp | Mảng nhỏ/không sắp xếp | Mảng lớn đã sắp xếp |

---

## 2. Giải Thuật Sắp Xếp

### 2.1 Selection Sort — O(N²)

**Ý tưởng:** Tìm phần tử nhỏ nhất trong phần chưa sắp xếp → đưa về đầu.

```
Dãy gốc: [ 64  25  12  22  11  90  45  33 ]

i=0: min=11(vt=4) → hoán vị a[0]↔a[4]: [ 11  25  12  22  64  90  45  33 ]
i=1: min=12(vt=2) → hoán vị a[1]↔a[2]: [ 11  12  25  22  64  90  45  33 ]
i=2: min=22(vt=3) → hoán vị a[2]↔a[3]: [ 11  12  22  25  64  90  45  33 ]
i=3: min=25(vt=3) → không đổi          [ 11  12  22  25  64  90  45  33 ]
i=4: min=33(vt=7) → hoán vị a[4]↔a[7]: [ 11  12  22  25  33  90  45  64 ]
i=5: min=45(vt=6) → hoán vị a[5]↔a[6]: [ 11  12  22  25  33  45  90  64 ]
i=6: min=64(vt=7) → hoán vị a[6]↔a[7]: [ 11  12  22  25  33  45  64  90 ] ✅
```

**Nhận xét:** Số lần hoán vị ≤ N-1 (ít nhất trong 3 sort đơn giản).

---

### 2.2 Insertion Sort — O(N²)

**Ý tưởng:** Như chơi bài — lấy từng lá bài chèn vào đúng vị trí trong tay bài đã sắp xếp.

```
Dãy gốc: [ 64 | 25  12  22  11 ]
          ↑ sắp xếp  | chưa sắp xếp

i=1: x=25 → chèn vào: [ 25  64 | 12  22  11 ]
i=2: x=12 → chèn vào: [ 12  25  64 | 22  11 ]
i=3: x=22 → chèn vào: [ 12  22  25  64 | 11 ]
i=4: x=11 → chèn vào: [ 11  12  22  25  64 ] ✅
```

**Nhận xét:** Hiệu quả với mảng **gần như đã sắp xếp** — O(N) best case.

---

### 2.3 Bubble Sort — O(N²)

**Ý tưởng:** So sánh và hoán vị các cặp liền kề, phần tử lớn "nổi bọt" về cuối.

```
Pass i=0: [ 64  25  12  22  11 ] → (64,25)↔ → (64,12)↔ → (64,22)↔ → (64,11)↔
           → [ 11  25  12  22  64 ] (64 đã đúng chỗ)
Pass i=1: → [ 11  12  22  25  64 ] (25 đúng chỗ)
Pass i=2: → [ 11  12  22  25  64 ] ✅
```

**Nhận xét:** Dễ hiểu nhất nhưng chậm nhất — nhiều hoán vị không cần thiết.

---

### 2.4 Quick Sort — O(N log N) trung bình

**Ý tưởng:** Chọn phần tử chốt (pivot), chia mảng thành 2 phần (< pivot, > pivot), đệ quy.

```
Dãy: [ 18  2  8  5  1  6  4  15 ], chọn pivot = a[3] = 5

Phân hoạch:
  i→ tìm a[i] >= 5: i=0 (18≥5)
  j← tìm a[j] <= 5: j=6 (4≤5)
  i<j → hoán vị a[0]↔a[6]: [ 4  2  8  5  1  6  18  15 ]
  ...tiếp tục...

Kết quả phân hoạch: [ 4  2  1 | 5 | 8  6  18  15 ]
                      < 5   pivot  > 5

Đệ quy 2 phần → sắp xếp hoàn chỉnh ✅
```

**Tại sao nhanh?** Ít lần truy cập bộ nhớ, cache-friendly.

| Case | Độ Phức Tạp |
|------|------------|
| Best/Average | O(N log N) |
| Worst (mảng đã sắp xếp) | O(N²) |
| Space | O(log N) — stack đệ quy |

---

### 2.5 Heap Sort — O(N log N) mọi trường hợp

**Ý tưởng:** Dùng cấu trúc Heap (đống) để tìm max hiệu quả.

**Định nghĩa Heap:** Mảng a[0..n-1] thỏa: `a[i] ≥ max(a[2i+1], a[2i+2])`

```
Giai đoạn 1 — Xây dựng Heap:
Dãy:  [ 18  2  8  5  1  6  4  15 ]
       ↓ biến đổi thành max-heap
Heap: [ 18  15  8  5  1  6  4  2 ]
      ← a[0] luôn là phần tử lớn nhất ✅

Giai đoạn 2 — Sắp xếp:
r=7: hoán vị a[0]↔a[7] → hiệu chỉnh heap → lặp lại
     → dần dần mảng được sắp xếp tăng dần ✅
```

**Ưu điểm:** O(N log N) **đảm bảo** kể cả worst case. Không cần bộ nhớ phụ.

---

## 3. Tổng Kết So Sánh

```
Nên dùng khi nào?
─────────────────────────────────────────────────────
Mảng nhỏ (N < 20):      Insertion Sort (overhead thấp)
Mảng lớn, tổng quát:    Quick Sort (thực tế nhanh nhất)
Cần worst-case đảm bảo: Heap Sort (O(N log N) mọi case)
Gần đã sắp xếp:         Insertion Sort (O(N) best case)
Cần sắp xếp ổn định:    Merge Sort (không có trong sách)
─────────────────────────────────────────────────────
```

---

## 4. Bài Tập Tự Luyện

### Cơ Bản
1. Mô phỏng tay Selection Sort với: `[5, 3, 8, 1, 9, 2, 7, 4]`
2. Mô phỏng Binary Search tìm x=7 trong: `[1, 3, 5, 7, 9, 11, 13]`
3. So sánh số lần hoán vị của Selection vs Bubble Sort cùng một mảng.

### Nâng Cao
4. Cài đặt Bubble Sort có cờ tối ưu (dừng sớm khi không có hoán vị).
5. Cài đặt Quick Sort với pivot là median-of-three.
6. Viết hàm đếm số lần so sánh của từng giải thuật sắp xếp.

---

*📌 File code: [`src/Chapter2_SearchSort/Chapter2_SearchSort.cpp`](../src/Chapter2_SearchSort/Chapter2_SearchSort.cpp)*
