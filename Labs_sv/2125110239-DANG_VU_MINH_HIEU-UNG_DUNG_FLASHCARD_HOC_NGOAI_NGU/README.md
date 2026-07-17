
# FLASHCARD DSA SYSTEM

Ứng dụng hỗ trợ học ngoại ngữ 

## 1. Cấu trúc dữ liệu sử dụng

* **Binary Search Tree (BST):** Dùng để lưu trữ bộ từ điển chính. Cho phép tìm kiếm, thêm và xóa từ vựng với độ phức tạp trung bình $O(\log n)$, giúp việc tra cứu từ điển nhanh chóng.
* **Priority Queue (Hàng đợi ưu tiên):** Dùng để sắp xếp thứ tự học trong mỗi phiên (Session). Tự động đưa các từ có `weight` cao (từ khó, hay quên) lên đầu hàng đợi để người dùng ôn tập trước.
* **Queue (Hàng đợi):** Dùng để quản lý luồng câu hỏi trong một phiên học. Đảm bảo tính tuần tự (FIFO) khi người dùng trả lời từng câu hỏi đã được trích xuất từ Priority Queue.
* **Stack (Ngăn xếp):** Dùng để lưu trữ lịch sử các từ vừa trả lời. Hỗ trợ chức năng hoàn tác (Undo) nếu người dùng muốn quay lại câu hỏi trước đó.

## 2. Chức năng chính

1.  **Quản lý từ vựng (BST):** Thêm từ mới kèm nghĩa và ví dụ minh họa. Từ điển tự động sắp xếp theo thứ tự bảng chữ cái của từ (word).
2.  **Tìm kiếm thông minh:** Tra cứu nhanh định nghĩa và ví dụ của một từ bất kỳ trong cây nhị phân.
3.  **Phiên học Spaced Repetition:** Hệ thống trích xuất các từ khó dựa trên trọng số (`weight`). Trả lời đúng sẽ giảm trọng số, trả lời sai sẽ tăng trọng số để từ đó xuất hiện thường xuyên hơn.
4.  **Thống kê hiệu suất:** Theo dõi tổng số câu đã làm và tỉ lệ chính xác (%) trong phiên học.
5.  **Lưu trữ dữ liệu:** Tự động đọc/ghi dữ liệu vào file `data.txt` để bảo toàn nội dung sau mỗi lần thoát.

## 3. Cấu trúc file

* `src/main.cpp`: Chứa menu điều khiển và luồng chính của chương trình.
* `src/Flashcard.h`: Khai báo các cấu trúc dữ liệu (`Card`, `Node`) và nguyên mẫu hàm của lớp `FlashcardSystem`.
* `src/Flashcard.cpp`: Cài đặt chi tiết các thuật toán xử lý cây nhị phân, hàng đợi và logic học tập.

## 4. Hướng dẫn biên dịch và chạy

```bash
g++ -std=c++17 main.cpp Flashcard.cpp -o app && ./app