# Conway: Game of Life

## Thong tin sinh vien

- Ho ten: Vuong Nguyen Truong Hung
- MSSV: 2124110111
- De tai: Conway: Game of Life

Day la ung dung C++ CLI mo phong tro choi te bao Conway's Game of Life tren ma tran 2 chieu. Nguoi dung co the tao ban co, gieo te bao song, nap pattern co san, chay mo phong theo tung the he, hoan tac va xem lich su bien doi.

## Muc tieu bai toan

- Mo phong luat song chet kinh dien cua Conway:
  - O song song tiep neu co 2 hoac 3 hang xom song.
  - O chet se duoc sinh ra neu co dung 3 hang xom song.
- Cho phep thu nghiem cac pattern kinh dien nhu `block`, `blinker`, `glider`, `beacon`, `toad`, `gosper`.
- Trinh bay bang menu de phu hop yeu cau bai nop mon hoc.

## Cau truc du lieu su dung

- `Linked List`:
  Dung trong `AliveCellList` de luu danh sach cac o dang song tren ban co hien tai.
- `Queue`:
  Dung trong `HistoryQueue` de luu lich su cac the he gan day, gom so o song, so o moi sinh va so o chet.
- `Stack`:
  Dung trong `SnapshotStack` de ho tro thao tac `undo`, quay lai trang thai truoc do cua ban co.
- `BST`:
  Dung trong `PatternBST` de luu va tim kiem pattern co san theo ten.

## Chuc nang

1. Hien thi ban co hien tai.
2. Thay doi kich thuoc ban co.
3. Bat/tat mot o thu cong.
4. Gieo ngau nhien theo mat do phan tram.
5. Nap pattern Conway tu cay BST.
6. Chay 1 the he.
7. Chay N the he lien tiep.
8. Hoan tac 1 buoc.
9. Xem lich su mo phong.
10. Liet ke pattern co san.
11. Xoa ban co.

## Thiet ke file

```text
src/
  main.cpp       - Menu va dieu khien chuong trinh
  structures.h   - Khai bao cau truc du lieu va prototype
  functions.cpp  - Cai dat Conway va cac cau truc du lieu
tests/
  test_cases.cpp - Bo test cac chuc nang chinh
docs/
  .gitkeep
README.md        - Mo ta bai toan va huong dan chay
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

1. `block` la still life nen khong doi sau 1 the he.
2. `blinker` dao dong dung chu ky 2.
3. BST chua va liet ke duoc pattern `glider`, `gosper`.
4. Nap pattern `glider` dung so luong te bao song.
5. `undo` khoi phuc dung trang thai truoc khi step.
6. `HistoryQueue` ghi nhan dung thong tin the he.

## Danh gia thiet ke

- Uu diem:
  - Menu ro rang, de demo tren terminal.
  - Dung nhieu cau truc du lieu co y nghia voi bai toan.
  - De mo rong them pattern moi hoac che do wrap board.
- Han che:
  - Ban co hien tai su dung ma tran trong RAM nen khong toi uu cho kich thuoc rat lon.
  - Hien thi la dang text, chua co giao dien do hoa.
