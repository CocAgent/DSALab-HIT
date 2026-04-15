# Recommendation Engine

## Thong tin sinh vien

- Ho ten: Vuong Nguyen Truong Hung
- MSSV: 2124110111
- De tai: Recommendation Engine

Ung dung C++ CLI mo phong he thong goi y don gian cho phim / bai hat / san pham. Chuong trinh ghi nhan lich su tuong tac cua nguoi dung, phan tich do tuong dong, sau do de xuat item phu hop theo hai huong:

- Collaborative Filtering: nguoi dung tuong tu cung thich nhung item nao.
- Item-based Recommendation: item giong voi nhung item ban da thich.

## Cau truc du lieu su dung

- `Graph`:
  Dung adjacency list de luu quan he user-item. Moi canh the hien muc do quan tam cua user voi item, phu hop vi bai toan recommendation la bai toan lien ket giua hai tap dinh.
- `BST`:
  Dung de luu catalog item theo `id`, ho tro tim kiem item nhanh hon danh sach tuyen tinh va de duyet in-order co thu tu.
- `Priority Queue (Heap)`:
  Dung de xep hang goi y theo diem relevance va lay Top-N nhanh, dap ung yeu cau cau truc du lieu dang Heap.
- `unordered_map`:
  Dung de luu lich su tuong tac cua user va chi muc item-user, truy cap trung binh O(1).

## Chuc nang

1. Them nguoi dung moi.
2. Them item vao catalog.
3. Ghi nhan hanh dong `view`, `like`, `rating`.
4. Tim item trong BST theo ID.
5. Hien thi catalog.
6. Goi y theo nguoi dung tuong tu.
7. Goi y theo item tuong tu.
8. Hien thi Top-N goi y tong hop.
9. Bao cao thong ke.
10. Xem lich su nguoi dung.
11. Nap du lieu mau de demo.

## Thiet ke file

```text
src/
  main.cpp       - Menu va dieu khien chuong trinh
  structures.h   - Khai bao struct, class, prototype
  functions.cpp  - Cai dat cac cau truc du lieu va thuat toan
tests/
  test_cases.cpp - Bo test co ban va edge cases
docs/
  .gitkeep
README.md        - Mo ta ung dung va huong dan chay
```

## Compile va chay

Build chuong trinh chinh:

```bash
g++ -std=c++17 src/main.cpp src/functions.cpp -o app
./app
```

Build bo test:

```bash
g++ -std=c++17 tests/test_cases.cpp src/functions.cpp -o test_app
./test_app
```

## Test cases chinh

1. Them user va item, kiem tra catalog duoc sap xep theo BST.
2. Tim kiem item ton tai / khong ton tai.
3. Ghi nhan `view`, `like`, `rating` va kiem tra so lieu cap nhat dung.
4. Tao goi y tren du lieu mau va dam bao co ket qua hop le.
5. Test edge case: ID rong, user/item khong ton tai, rating ngoai mien hop le.
6. Test thong ke item pho bien va user hoat dong.
