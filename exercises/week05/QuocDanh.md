# Tuần 5: Sắp Xếp Nâng Cao — Bài tập

## 🎯 Mục tiêu tuần này
Cài đặt Quick Sort, Merge Sort, Heap Sort. So sánh với thuật toán cơ bản.

---

### Bài 1: Merge Sort ⭐⭐
Cài đặt Merge Sort đệ quy. Chứng minh O(n log n) bằng cách đếm số phép so sánh.

### Bài 2: Quick Sort ⭐⭐
Cài đặt Quick Sort với 3 chiến lược chọn pivot: đầu, cuối, giữa, ngẫu nhiên. So sánh hiệu năng.

### Bài 3: Heap Sort ⭐⭐⭐
Cài đặt Heap Sort từ đầu (không dùng priority_queue). In từng bước xây dựng heap.

### Bài 4: 🔥 Dự Án Mini — Sort Race ⭐⭐⭐
> **Cảm hứng:** [Divide and Conquer — algorithm-visualizer](https://algorithm-visualizer.org/divide-and-conquer/merge-sort)

Cuộc đua sắp xếp giữa 6 thuật toán trên cùng 1 dữ liệu:
```
╔══════════════╦══════════╦══════════╦═══════════╗
║  Thuật toán  ║ n=1,000  ║ n=10,000 ║ n=100,000 ║
╠══════════════╬══════════╬══════════╬═══════════╣
║ Bubble Sort  ║   8.3ms  ║  820ms   ║  timeout  ║
║ Selection    ║   4.1ms  ║  410ms   ║  timeout  ║
║ Insertion    ║   1.2ms  ║  120ms   ║  12000ms  ║
║ Merge Sort   ║   0.3ms  ║  3.1ms   ║  35ms     ║
║ Quick Sort   ║   0.2ms  ║  2.4ms   ║  28ms     ║
║ Heap Sort    ║   0.4ms  ║  4.2ms   ║  48ms     ║
╚══════════════╩══════════╩══════════╩═══════════╝
🏆 Người chiến thắng: Quick Sort!
```
**Yêu cầu:** test trên 3 loại dữ liệu (ngẫu nhiên, đã sắp xếp, ngược chiều), xuất kết quả ra file CSV.

---
📁 Tham khảo: `Chuong2_TimKiem_SapXep/Chuong2_TimKiem_SapXep.cpp`
