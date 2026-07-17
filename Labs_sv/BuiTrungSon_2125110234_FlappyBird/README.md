FLAPPY BIRD DSA - ĐỒ ÁN CUỐI KỲ

Môn học: Cấu trúc Dữ liệu và Giải thuật (DSA)

Sinh viên thực hiện: Bùi Trung Sơn

Chuyên ngành: Công nghệ thông tin

Ngôn ngữ: C++ (Visual Studio 2022)

📝 TỔNG QUAN DỰ ÁN

Dự án này là một phiên bản mô phỏng trò chơi kinh điển Flappy Bird trên giao diện dòng lệnh (CLI). Bên cạnh mục đích giải trí, ứng dụng được thiết kế để minh chứng khả năng vận dụng các Cấu trúc dữ liệu và Giải thuật nâng cao, tập trung vào việc quản lý bộ nhớ hiệu quả và xử lý logic thời gian thực.

Với nền tảng là sinh viên ngành Nhân sự và Tiếng Anh Thương mại, tôi đặc biệt chú trọng vào Trải nghiệm người dùng (UX/UI), đảm bảo game chạy mượt mà, tài liệu hướng dẫn chuyên nghiệp và hệ thống menu trực quan.

🛠 CẤU TRÚC DỮ LIỆU SỬ DỤNG

Để đáp ứng yêu cầu chuyên môn (áp dụng ít nhất 3 cấu trúc), tôi đã triển khai:



Hàng đợi (Queue - Tự cài đặt):

Mục đích: Quản lý các cột chướng ngại vật xuất hiện trên màn hình.

Logic: Áp dụng nguyên lý FIFO (Vào trước, Ra trước). Các ống mới sẽ được vào hàng từ phía sau (rear) và khi trôi khỏi màn hình sẽ được xóa ở phía trước (front), giúp tối ưu hóa dung lượng bộ nhớ sử dụng.

Danh sách liên kết đơn (Singly Linked List):

Mục đích: Là nền tảng để xây dựng Hàng đợi (Pipe Queue).

Ưu điểm: Cho phép cấp phát bộ nhớ động. Khác với mảng, chúng ta không cần khai báo trước số lượng ống, giúp tránh lãng phí tài nguyên hoặc tràn bộ nhớ.

Vector (Thư viện chuẩn STL):

Mục đích: Quản lý "Vật thể bay bất ngờ" (Obstacle) xuất hiện ngẫu nhiên.

Logic: Cho phép thêm (push_back) và xóa (erase) linh hoạt các phần tử không thể dự đoán trước trên bản đồ game.

Lưu trữ file (File I/O):

Mục đích: Xây dựng bảng xếp hạng kỷ lục.

Cơ chế: Đọc và ghi dữ liệu vào file highscore.txt, sử dụng thuật toán sắp xếp để hiển thị Top 5 điểm cao nhất.

🚀 CÁC TÍNH NĂNG CHÍNH

Màn hình Loading chuyên nghiệp: Giả lập quá trình khởi tạo hệ thống để tạo ấn tượng ban đầu.

Tùy chỉnh độ khó: 3 mức độ (Dễ, Vừa, Khó) với tốc độ game tương ứng.

Logic ngẫu nhiên thông minh: Mỗi ống có vị trí khe hở và độ rộng khe hở (gap size) ngẫu nhiên, đảm bảo mỗi lượt chơi đều là duy nhất.

Tối ưu hóa hiệu năng: Sử dụng kỹ thuật gotoXY và in đè để loại bỏ tình trạng nháy hình (Lag-free).

Hiệu ứng âm thanh: Tích hợp API Beep cho các hành động nhảy và khi kết thúc trò chơi.

📖 HƯỚNG DẪN CÀI ĐẶT VÀ CHẠY

Yêu cầu hệ thống

Hệ điều hành Windows.

Visual Studio 2022 (đã cài đặt bộ phát triển C++).

Các bước thực hiện

Tải mã nguồn về máy.

Mở Visual Studio 2022 và tạo một Empty C++ Project.

Thêm file main.cpp vào thư mục Source Files.

Vào Project Properties -> C/C++ -> Preprocessor và thêm _CRT_SECURE_NO_WARNINGS.

Nhấn Ctrl + F5 để biên dịch và chạy game.

📈 TỰ ĐÁNH GIÁ (GÓC NHÌN NHÂN SỰ & KINH DOANH)

Việc phát triển dự án này đã giúp tôi củng cố các kỹ năng quan trọng trong quản trị hiện đại:



Tư duy phân tích: Chia nhỏ một trò chơi phức tạp thành các nút dữ liệu có thể quản lý được.

Sự tỉ mỉ: Đảm bảo mọi nhánh logic (xử lý va chạm, trọng lực) hoạt động chính xác.

Kỹ năng số (Digital Literacy): Nắm vững cách vận hành của phần mềm và quản lý dữ liệu hiệu quả.

👨‍🏫 LỜI CẢM ƠN

Xin chân thành cảm ơn giảng viên TVS đã tận tình hướng dẫn trong suốt khóa học Cấu trúc Dữ liệu và Giải thuật.
