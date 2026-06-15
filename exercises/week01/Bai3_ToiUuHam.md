### Bài 3: Tối ưu hàm (Từ O(n^2) xuống O(n) hoặc O(n log n))

**1. Bài toán Two Sum (Tìm 2 số có tổng bằng X)**
- **Brute-force O(n^2):** Dùng 2 vòng lặp lồng nhau duyệt tất cả các cặp.
- **Tối ưu O(n):** Dùng Hash Map (Bảng băm). Vừa duyệt vừa lưu các giá trị đã gặp vào Hash Map, tra cứu chỉ mất O(1). Thời gian giảm từ vài giây xuống còn ~1ms với n = 100,000.

**2. Bài toán Sắp xếp (Sorting)**
- **Brute-force O(n^2):** Dùng Bubble Sort hoặc Selection Sort.
- **Tối ưu O(n log n):** Dùng Merge Sort hoặc `std::sort` của C++. Áp dụng chia để trị giúp giảm triệt để số phép so sánh. Thời gian giảm từ ~80,000ms xuống còn ~5ms với n = 100,000.

**3. Bài toán Maximum Subarray (Dãy con có tổng lớn nhất)**
- **Brute-force O(n^2):** Dùng 2 vòng lặp tính tổng mọi đoạn con.
- **Tối ưu O(n):** Dùng Thuật toán Kadane. Chỉ cần duyệt mảng đúng 1 lần, cộng dồn tổng, nếu tổng < 0 thì reset về 0. Thời gian giảm từ vài giây xuống còn ~1ms với n = 100,000.
