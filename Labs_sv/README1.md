 Temple Run Mini (C++ Console Game)

## 1. Giới thiệu

Trong quá trình học lập trình C++, việc xây dựng một chương trình mang tính ứng dụng thực tế là rất quan trọng để củng cố kiến thức. 
Dựa trên ý tưởng đó, chương trình "Temple Run Mini" được thực hiện nhằm mô phỏng một trò chơi đơn giản chạy trên môi trường console.

Game được lấy cảm hứng từ trò chơi Temple Run, trong đó người chơi điều khiển nhân vật di chuyển để tránh các chướng ngại vật xuất hiện liên tục. 
Mặc dù không có đồ họa phức tạp như các game hiện đại, chương trình vẫn thể hiện được các thành phần cơ bản của một trò chơi như xử lý input, cập nhật trạng thái và hiển thị kết quả.

Đây là một bài tập giúp người học hiểu rõ hơn về cách xây dựng logic game bằng ngôn ngữ C++.

---

## 2. Mục tiêu của chương trình

Chương trình được xây dựng với các mục tiêu chính như sau:

- Áp dụng kiến thức lập trình C++ vào một bài toán thực tế
- Hiểu và triển khai vòng lặp game (game loop)
- Xử lý sự kiện từ bàn phím
- Xây dựng logic chuyển động cho nhân vật
- Kiểm tra va chạm giữa các đối tượng trong game
- Quản lý dữ liệu bằng cấu trúc như mảng hoặc vector
- Hiển thị thông tin trên màn hình console

Thông qua bài tập này, người học có thể nâng cao khả năng tư duy logic và kỹ năng lập trình.

---

## 3. Mô tả hoạt động của game

Khi chương trình được chạy, người chơi sẽ điều khiển một nhân vật xuất hiện trên màn hình. 
Các chướng ngại vật sẽ liên tục được sinh ra và di chuyển về phía nhân vật.

Người chơi cần sử dụng các phím điều khiển để di chuyển nhân vật sang trái, phải hoặc nhảy lên để tránh va chạm với các vật cản.

Nếu nhân vật va chạm với chướng ngại vật, trò chơi sẽ kết thúc. 
Trong quá trình chơi, điểm số sẽ tăng dần theo thời gian sống của nhân vật.

---

## 4. Chức năng chính

Chương trình bao gồm các chức năng chính sau:

- Điều khiển nhân vật bằng bàn phím
- Di chuyển nhân vật theo các hướng cơ bản
- Tạo chướng ngại vật ngẫu nhiên
- Di chuyển chướng ngại vật theo thời gian
- Phát hiện va chạm giữa nhân vật và vật cản
- Hiển thị điểm số
- Kết thúc game khi có va chạm xảy ra

Các chức năng này được xây dựng đơn giản nhưng đầy đủ để tạo nên một trò chơi hoàn chỉnh ở mức cơ bản.

---

## 5. Hướng dẫn điều khiển

Người chơi sử dụng bàn phím để điều khiển nhân vật:

- Phím A: di chuyển nhân vật sang trái
- Phím D: di chuyển nhân vật sang phải
- Phím W: giúp nhân vật nhảy lên để tránh chướng ngại vật

Các thao tác điều khiển được thiết kế đơn giản, dễ sử dụng và phù hợp với người mới.

---

## 6. Cách chạy chương trình

### 6.1 Sử dụng Dev C++

- Mở phần mềm Dev C++
- Tạo một file mới với phần mở rộng `.cpp`
- Sao chép toàn bộ mã nguồn vào file
- Nhấn nút Run để biên dịch và chạy chương trình

### 6.2 Sử dụng trình biên dịch g++

- Mở Command Prompt hoặc Terminal
- Di chuyển đến thư mục chứa file chương trình
- Thực hiện lệnh biên dịch:

---

## 7. Cấu trúc chương trình

Chương trình được tổ chức thành các phần chính như sau:

- Hàm main(): điều khiển toàn bộ quá trình chạy của game
- Hàm draw(): hiển thị trạng thái game lên màn hình console
- Hàm input(): nhận và xử lý dữ liệu từ bàn phím
- Hàm update(): cập nhật vị trí nhân vật, vật cản và xử lý va chạm

Việc tách chương trình thành các hàm riêng biệt giúp code dễ hiểu và dễ bảo trì hơn.

---

## 8. Thuật toán và logic xử lý

Chương trình hoạt động dựa trên vòng lặp game liên tục:

1. Nhận input từ người chơi
2. Cập nhật trạng thái nhân vật và vật cản
3. Kiểm tra va chạm
4. Hiển thị lại màn hình

Chướng ngại vật được tạo ra ngẫu nhiên và di chuyển về phía người chơi. 
Va chạm được kiểm tra bằng cách so sánh vị trí của nhân vật và vật cản.

Điểm số được tăng dần theo thời gian để tạo động lực cho người chơi cố gắng đạt điểm cao hơn.

---

## 9. Kết quả đạt được

Sau khi hoàn thành chương trình, các kết quả đạt được bao gồm:

- Xây dựng được một trò chơi đơn giản bằng C++
- Hiểu rõ hơn về cách tổ chức chương trình
- Nắm được cách xử lý input từ bàn phím
- Áp dụng được các cấu trúc dữ liệu cơ bản
- Làm quen với tư duy phát triển game

---

## 10. Hạn chế

Do chương trình chạy trên môi trường console nên còn một số hạn chế:

- Đồ họa đơn giản, không có hình ảnh trực quan
- Chưa có âm thanh
- Gameplay còn đơn giản
- Chưa có nhiều cấp độ hoặc tính năng nâng cao

---

## 11. Hướng phát triển

Trong tương lai, chương trình có thể được cải tiến thêm:

- Nâng cấp đồ họa bằng thư viện như SDL hoặc OpenGL
- Thêm nhiều loại chướng ngại vật
- Tăng độ khó theo thời gian
- Thêm hệ thống điểm cao (high score)
- Thêm hiệu ứng âm thanh

---

## 12. Kết luận

Chương trình "Temple Run Mini" là một bước khởi đầu tốt cho việc học lập trình game bằng C++. 
Mặc dù còn đơn giản, nhưng chương trình đã thể hiện đầy đủ các thành phần cơ bản của một trò chơi.

Thông qua bài tập này, người thực hiện đã hiểu rõ hơn về cách xây dựng logic game, xử lý sự kiện và tổ chức chương trình một cách hợp lý.

---

## 13. Thông tin sinh viên

- Họ và tên: (Điền tên của bạn)
- Lớp: (Điền lớp của bạn)
