Maze Game (C++ CLI)Chương trình trò chơi mê cung chạy trên giao diện dòng lệnh (Terminal), cho phép người chơi trải nghiệm việc tự giải mê cung hoặc sử dụng các thuật toán tự động để tìm đường thoát.
1. Cấu trúc dữ liệu sử dụngMảng 2D (std::vector<std::vector<int>>): Dùng để lưu trữ bản đồ mê cung vì cấu trúc này phản ánh chính xác hệ tọa độ $(x, y)$ của các ô và dễ dàng truy xuất.Stack: Sử dụng trong thuật toán DFS (để tạo và giải mê cung) vì cơ chế LIFO (Last In First Out) hỗ trợ đắc lực cho việc quay lui (Backtracking) khi gặp đường cụt.Queue: Sử dụng trong thuật toán BFS để lưu trữ các đỉnh đang chờ xét theo từng lớp, đảm bảo tìm ra đường đi ngắn nhất (Shortest Path).


2. Compile và chạyĐể biên dịch tất cả các module trong thư mục src, bạn sử dụng lệnh sau trong Terminal:Bashg++ -std=c++17 src/*.cpp -o maze && ./maze


3. Chức năng chínhTạo mê cung ngẫu nhiên: Sử dụng thuật toán DFS (Recursive Backtracker) để tạo ra một mê cung hoàn hảo (Perfect Maze) - đảm bảo mọi ô đều có thể đi tới và luôn có đường thoát.Chế độ chơi thủ công: Người chơi điều khiển bằng các phím W/A/S/D để di chuyển trên giao diện ASCII.Tự động giải bằng BFS: Tìm và hiển thị đường đi ngắn nhất từ điểm bắt đầu đến đích.Tự động giải bằng DFS: Tìm đường thoát bằng cách duyệt sâu, minh họa cơ chế hoạt động của backtracking.So sánh thuật toán: Hiển thị và so sánh độ dài đường đi (Distance) giữa BFS và DFS.


4. Test casesTest 1 (Khởi tạo): Kiểm tra mê cung được tạo có đúng kích thước $N \times M$ và có đầy đủ điểm Start/End.Test 2 (Va chạm): Kiểm tra người chơi không thể di chuyển xuyên qua tường hoặc ra ngoài biên.Test 3 (BFS): Đảm bảo thuật toán luôn tìm thấy lối ra ngắn nhất trong các mê cung có nhiều ngã rẽ.Test 4 (DFS): Kiểm tra khả năng quay lui chính xác và không bị lặp vô tận khi gặp các vòng lặp.Test 5 (Hiệu năng): So sánh số bước đi của hai thuật toán trên cùng một mê cung ngẫu nhiên.


5. Cấu trúc ProjectPlaintextLabs_sv/2125110233_PhamMinhThanh_MazeGame/
├── src/
│   ├── main.cpp    : Quản lý menu và luồng điều khiển chính.
│   ├── maze.cpp/h  : Thuật toán tạo mê cung và hiển thị ASCII.
│   ├── player.cpp/h: Logic di chuyển và kiểm tra va chạm của người chơi.
│   └── solver.cpp/h: Cài đặt thuật toán giải tự động (BFS, DFS).
├── tests/
│   └── test_case.cpp: Các hàm kiểm thử tự động cho các chức năng của game.
├── docs/
│   └── bao_cao.pdf  : Tài liệu thuyết minh dự án (nếu có).
└── README.md        : Hướng dẫn và mô tả chi tiết dự án.