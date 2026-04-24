# 🧩 Chương 6: Quy Hoạch Động (Dynamic Programming)

> **Mục tiêu:** Hiểu tư duy DP, phân biệt memoization vs tabulation, áp dụng vào các bài toán kinh điển.

---

## 1. Quy Hoạch Động Là Gì?

### 1.1 Định Nghĩa

> **Quy hoạch động (DP)** là kỹ thuật giải bài toán bằng cách chia nhỏ thành các **bài toán con chồng lặp**, lưu kết quả đã tính để **không tính lại**.

### 1.2 Khi Nào Dùng DP?

Bài toán phù hợp DP khi có **2 tính chất**:

1. **Optimal Substructure (Cấu trúc con tối ưu)**  
   Nghiệm tối ưu của bài toán lớn chứa nghiệm tối ưu của bài toán con.
   
2. **Overlapping Subproblems (Bài toán con chồng lặp)**  
   Nhiều bài toán lớn dùng chung các bài toán con → cần lưu kết quả.

### 1.3 DP vs Đệ Quy Thường

```
Fibonacci(5) — Đệ quy ngây thơ:
                    fib(5)
                   /       \
               fib(4)       fib(3)   ← tính lại!
              /     \       /    \
          fib(3)  fib(2) fib(2) fib(1)  ← tính lại!
          /   \
       fib(2) fib(1)

Số lần gọi hàm: O(2ᴺ) ← rất chậm!

Fibonacci(5) — DP (Tabulation):
dp[0]=0, dp[1]=1, dp[2]=1, dp[3]=2, dp[4]=3, dp[5]=5
Chỉ tính mỗi giá trị 1 lần: O(N) ✅
```

---

## 2. Hai Cách Cài Đặt DP

### 2.1 Top-Down (Memoization)

```
Ý tưởng: Viết đệ quy bình thường + lưu kết quả vào bảng memo.

int memo[1001] = {-1};  // -1 = chưa tính

int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];  // đã tính rồi
    return memo[n] = fib(n-1) + fib(n-2);  // lưu lại
}
```

**Ưu điểm:** Code tự nhiên, chỉ tính những gì cần.  
**Nhược điểm:** Overhead stack đệ quy.

### 2.2 Bottom-Up (Tabulation)

```
Ý tưởng: Điền bảng từ bài toán nhỏ → lớn (không đệ quy).

int dp[1001];
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++)
    dp[i] = dp[i-1] + dp[i-2];
```

**Ưu điểm:** Không overhead đệ quy, cache-friendly.  
**Nhược điểm:** Phải xác định thứ tự điền bảng.

---

## 3. Các Bài Toán Kinh Điển

### 3.1 Dãy Fibonacci — O(N)

```
Công thức: F(n) = F(n-1) + F(n-2), F(0)=0, F(1)=1

dp: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...]
```

### 3.2 Leo Cầu Thang — O(N)

```
Bài toán: Leo N bậc, mỗi lần leo 1 hoặc 2 bậc. Có bao nhiêu cách?

Công thức: ways(n) = ways(n-1) + ways(n-2)
(Giống Fibonacci!)

n=1: 1 cách {1}
n=2: 2 cách {1+1, 2}
n=3: 3 cách {1+1+1, 1+2, 2+1}
n=4: 5 cách
n=5: 8 cách
```

### 3.3 Bài Toán Xâu Con Chung Dài Nhất (LCS) — O(M·N)

```
Input: s1 = "ABCBDAB", s2 = "BDCAB"
Output: LCS = "BCAB" hoặc "BDAB", độ dài = 4

Bảng DP:
      ""  B  D  C  A  B
  ""   0  0  0  0  0  0
  A    0  0  0  0  1  1
  B    0  1  1  1  1  2
  C    0  1  1  2  2  2
  B    0  1  1  2  2  3
  D    0  1  2  2  2  3
  A    0  1  2  2  3  3
  B    0  1  2  2  3  4  ← LCS = 4 ✅

Công thức:
  dp[i][j] = dp[i-1][j-1] + 1        nếu s1[i] == s2[j]
  dp[i][j] = max(dp[i-1][j], dp[i][j-1])  ngược lại
```

### 3.4 Bài Toán Ba Lô (0/1 Knapsack) — O(N·W)

```
Input: N vật, mỗi vật có trọng số w[i] và giá trị v[i].
       Túi sức chứa W kg. Chọn vật để tổng giá trị max.

Ví dụ: N=4, W=5
Vật:  1:(w=2,v=6), 2:(w=2,v=10), 3:(w=3,v=12), 4:(w=1,v=3)

Bảng dp[i][j] = giá trị max dùng i vật đầu, sức chứa j:

     0  1   2   3   4   5
  0: 0  0   0   0   0   0
  1: 0  0   6   6   6   6   (vật 1: w=2,v=6)
  2: 0  0  10  10  16  16   (vật 2: w=2,v=10)
  3: 0  0  10  12  16  22   (vật 3: w=3,v=12)
  4: 0  3  10  13  16  22   (vật 4: w=1,v=3)

Đáp án: dp[4][5] = 22 ✅ (chọn vật 2 + vật 3)

Công thức:
  dp[i][j] = dp[i-1][j]                            nếu w[i] > j
  dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]) ngược lại
```

### 3.5 Dãy Con Tăng Dài Nhất (LIS) — O(N²) hoặc O(N log N)

```
Input: [10, 9, 2, 5, 3, 7, 101, 18]
Output: [2, 3, 7, 18] hoặc [2, 5, 7, 101], độ dài = 4

dp[i] = độ dài LIS kết thúc tại vị trí i:
i=0: dp[0]=1 (10)
i=1: dp[1]=1 (9 — không tăng từ 10)
i=2: dp[2]=1 (2)
i=3: dp[3]=2 (2→5)
i=4: dp[4]=2 (2→3)
i=5: dp[5]=3 (2→3→7 hoặc 2→5→7)
i=6: dp[6]=4 (2→3→7→101)
i=7: dp[7]=4 (2→3→7→18)

Đáp án: max(dp) = 4 ✅
```

### 3.6 Đường Đi Trên Lưới — O(M·N)

```
Input: Lưới M×N, xuất phát (0,0), đến (M-1,N-1).
       Chỉ đi phải hoặc xuống. Đếm số đường đi.

dp[i][j] = số đường đi đến ô (i,j)
dp[0][j] = 1 (hàng đầu — chỉ có 1 cách đi qua)
dp[i][0] = 1 (cột đầu — chỉ có 1 cách đi xuống)
dp[i][j] = dp[i-1][j] + dp[i][j-1]

Lưới 3×3:
1  1  1
1  2  3
1  3  6  ← dp[2][2] = 6 đường ✅
```

### 3.7 Chia Tiền Xu (Coin Change) — O(Amount · N)

```
Input: Mệnh giá xu [1, 2, 5], cần đổi Amount=11
Output: Số xu ít nhất = 3 (5+5+1)

dp[j] = số xu ít nhất để đổi j đồng:
dp[0] = 0
dp[1] = 1  (1)
dp[2] = 1  (2)
dp[3] = 2  (2+1)
dp[4] = 2  (2+2)
dp[5] = 1  (5)
dp[6] = 2  (5+1)
...
dp[11] = 3  (5+5+1) ✅

Công thức: dp[j] = min(dp[j], 1 + dp[j - coin[i]])
```

---

## 4. Kỹ Thuật Tối Ưu Không Gian

```
Nhiều bài DP chỉ cần hàng trước → tiết kiệm từ O(N²) xuống O(N):

// Knapsack — từ 2D xuống 1D:
int dp[W+1] = {0};
for (int i = 0; i < N; i++)
    for (int j = W; j >= w[i]; j--)  // duyệt ngược!
        dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
```

---

## 5. Bảng Tóm Tắt

| Bài Toán | Công Thức | Độ Phức Tạp | Space |
|----------|-----------|------------|-------|
| Fibonacci | dp[i] = dp[i-1]+dp[i-2] | O(N) | O(1)* |
| Cầu thang | dp[i] = dp[i-1]+dp[i-2] | O(N) | O(N) |
| LCS | dp[i][j] = dp[i-1][j-1]+1 hoặc max | O(MN) | O(MN) |
| Knapsack | dp[i][j] = max(skip, take) | O(NW) | O(W)* |
| LIS | dp[i] = max(dp[j]+1) | O(N²) | O(N) |
| Lưới | dp[i][j] = dp[i-1][j]+dp[i][j-1] | O(MN) | O(N)* |
| Coin Change | dp[j] = min(dp[j-c]+1) | O(A·N) | O(A) |

*Sau tối ưu không gian*

---

## 6. Bài Tập Tự Luyện

### Cơ Bản
1. Tính F(50) bằng DP (so sánh với đệ quy thường).
2. Đếm số cách leo 10 bậc (leo 1, 2, hoặc 3 bậc mỗi lần).
3. Tìm dãy con tăng dài nhất: `[3, 10, 2, 1, 20, 5, 4, 23, 3, 11]`

### Nâng Cao
4. Bài toán ba lô: N=5, W=10, w=[2,3,4,5,1], v=[3,4,5,6,1].
5. Đếm số cách đổi tiền: mệnh giá [1,5,10,25], Amount=100.
6. Tìm xâu con palindrome dài nhất trong một chuỗi.

---

*📌 File code: [`src/Chapter6_DynamicProgramming/Chapter6_DP.cpp`](../src/Chapter6_DynamicProgramming/Chapter6_DP.cpp)*
