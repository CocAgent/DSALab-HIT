# 🧩 CLI MazeGame — Hệ Thống Sinh Và Giải Mê Cung Tự Động (C++)

<div align="center">

![C++](https://img.shields.io/badge/C++-11%20%7C%2017-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D4?style=for-the-badge&logo=windows&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Features](https://img.shields.io/badge/Features-7-blueviolet?style=for-the-badge)

**Ứng dụng Console tương tác trực quan về giải thuật xây dựng và tìm đường trên đồ thị lưới** [📖 Tính Năng](#-nội-dung-tính-năng) · [🕹️ Điều Khiển](#️-hướng-dẫn-điều-khiển) · [🗂 Cấu Trúc](#-cấu-trúc-dự-án) · [📊 Giải Thuật](#-tóm-tắt-giải-thuật--độ-phức-tạp)

</div>

---

## 📌 Giới Thiệu

**CLI MazeGame** là một dự án C++ hoàn chỉnh minh họa trực quan các thuật toán duyệt đồ thị kinh điển (`DFS`, `BFS`) thông qua bài toán xây dựng và giải mê cung ô vuông. 

- ✅ **Sinh ngẫu nhiên hoàn hảo**: Sử dụng thuật toán DFS cải tiến để tạo mê cung không chu trình, luôn có lối thoát.
- ✅ **Đồ họa ASCII tối ưu**: Kỹ thuật hiển thị ký tự kép chống méo tỷ lệ trên màn hình Console.
- ✅ **Tương tác thời gian thực**: Trải nghiệm di chuyển mượt mà không cần nhấn Enter.
- ✅ **Đối sánh hiệu năng**: Báo cáo trực quan, so sánh chi tiết số bước chân thực tế giữa BFS và DFS.

---

## 🗂 Cấu Trúc Dự Án
│
├── 📁 src/
│   ├── KB.h              # Thư viện bổ trợ (bắt phím _getch() không chặn màn hình)
│   ├── MazeGame.h        # Khai báo lớp, cấu trúc Point và hằng số cấu hình
│   └── MazeGame.cpp      # Hiện thực hóa logic trò chơi và các thuật toán đồ thị
│
├── 📁 assets/            # Chứa sơ đồ minh họa, hình ảnh demo giải thuật
├── main.cpp              # Điểm khởi chạy ứng dụng (Hệ thống điều hướng Menu chính)
└── README.md
---

## 📖 Nội Dung Tính Năng

| Chức Năng | Tên Hàm Xử Lý | Thuật Toán / Cơ Chế | Đặc Điểm Kỹ Thuật |
|---|---|---|---|
| **1. Tạo mê cung** | `generate()`, `dfsGenerate()` | Recursive Backtracker (DFS) | Đảm bảo mê cung hoàn hảo, không có chu trình. |
| **2. Hiển thị ASCII** | `display()`, `displayCurrent()` | Khớp ma trận đồ họa cổ điển | In ký tự kép `##` thay thế tường để tạo tỷ lệ ô vuông cân đối. |
| **3. Người chơi tự giải** | `play()` | Bắt phím thời gian thực `_getch()` | Di chuyển liên tục bằng cụm `W/A/S/D`, cập nhật tọa độ động. |
| **4. Tự động giải BFS** | `solveBFS()` | Breadth-First Search (Queue) | Tìm kiếm theo lớp (gợn sóng), **luôn tối ưu ngắn nhất**. |
| **5. Tự động giải DFS** | `solveDFS()` | Depth-First Search (Stack) | Đâm sâu tìm đường nhanh, truy vết qua mảng `parent`. |
| **6. So sánh hiệu năng** | `compareAlgorithms()` | Phân tích biến đếm hiệu năng | In bảng đối sánh định lượng số bước chân của 2 thuật toán. |
| **7. Điều chỉnh độ khó** | `setDifficulty()` | Chuẩn hóa lưới toán học | Ép kích thước chẵn về số lẻ để thuật toán đào đường chuẩn xác. |

---

## ⚙️ Cài Đặt & Chạy

### Yêu cầu hệ thống
- **Compiler:** g++ 9+ hỗ trợ tiêu chuẩn C++11 hoặc tốt nhất là C++17.
- **Hệ điều hành:** Ưu tiên **Windows** (vì dự án sử dụng các hàm hệ thống Windows đặc trưng như `<conio.h>` và `system("cls")`).

### Biên dịch thủ công qua Terminal
Mở Command Prompt hoặc PowerShell tại thư mục gốc dự án và thực hiện:

```bash
# Biên dịch tất cả các file nguồn
g++ -std=c++17 main.cpp src/MazeGame.cpp -I src/ -o bin/MazeGame.exe

# Chạy ứng dụng
./bin/MazeGame.exe
🕹️ Hướng Dẫn Điều KhiểnKhi tham gia vào chế độ Chức năng 3: Người chơi tự giải, giao diện trò chơi sẽ hiển thị và chấp nhận các lệnh điều hướng sau:🔼 W / w: Di chuyển nhân vật lên trên một ô.🔽 S / s: Di chuyển nhân vật xuống dưới một ô.◀️ A / a: Di chuyển nhân vật sang trái một ô.▶️ D / d: Di chuyển nhân vật sang phải một ô.❌ Q / q: Bỏ cuộc giữa chừng, thoát ngay lập tức về Menu chính.💡 Mẹo: Hệ thống tự động chặn di chuyển va chạm (Collision Detection), bạn không thể đi xuyên qua các bức tường ##.🧩 Tóm Tắt Giải Thuật & Độ Phức TạpDưới đây là bảng thống kê đánh giá hiệu năng lý thuyết áp dụng trên lưới ma trận kích thước $W \times H$ (với $V = W \times H$ là số đỉnh, $E \le 4V$ là số cạnh):Thuật ToánThời Gian (Best)Thời Gian (Worst)Không Gian (Space)Mục Tiêu Cốt LõiDFS Sinh Mê CungO(V)O(V)O(V)Phá tường ngẫu nhiên để tạo bản đồ duy nhấtBFS Tìm ĐườngO(1)O(V + E)O(V)Bắt buộc tìm ra lộ trình ngắn nhất (Ký hiệu: .)DFS Tìm ĐườngO(1)O(V + E)O(V)Khám phá sâu, đường đi phụ thuộc thứ tự duyệt (Ký hiệu: *)📌 Kết luận thực nghiệm: > * BFS hoạt động theo cơ chế loang đều như làn sóng, do đó khi chạm đích lần đầu tiên, độ dài đường đi luôn là ngắn nhất.DFS đi theo thiên hướng mò mẫm một nhánh cho tới khi gặp ngõ cụt rồi mới quay lui (Backtrack), do đó độ dài đường đi thường dài hơn hoặc bằng BFS nhưng tốn ít bộ nhớ lưu trữ phần tử biên hơn trong đồ thị lớn.🤝 Đóng GópDự án mở rộng mã nguồn nhằm mục đích giáo dục, mọi đóng góp đều được trân trọng!Fork dự án này về tài khoản cá nhân.Tạo nhánh tính năng mới: git checkout -b feature/tinh-nang-moiThực hiện thay đổi và commit theo chuẩn: feat: phát triển tính năng hiển thị màu sắcPush nhánh lên GitHub và tạo một Pull Request.Quy ước viết mã (Coding Conventions)Biến cục bộ / Tham số: Định dạng camelCase (Ví dụ: tempGrid, showVisual).Thuộc tính lớp / Hàm thành viên: Định dạng camelCase hoặc theo mã gốc (grid, start, solveBFS()).Tên lớp: Định dạng PascalCase (MazeGame).📚 Tài Liệu Tham Khảo📘 Introduction to Algorithms (4th Edition) — Thomas H. Cormen (Thuật toán BFS/DFS cơ bản).📗 Maze Generation Algorithms — Jamis Buck (Tổng quan kỹ thuật sinh mê cung ngẫu nhiên).📙 Giáo trình Cấu trúc Dữ liệu & Giải thuật — Trường Đại học Công nghệ Thông tin.
