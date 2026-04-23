#include "structures.h"
#include <stack>

int main() {
    Seat seats[MAX_ROW][MAX_COL];

    initSeats(seats, MAX_ROW, MAX_COL);

    stack<Transaction>history;
    priority_queue<Customer, vector<Customer>, Compare>WaitingQueue;

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "7. Doc file\n";
        cout << "6. Luu file\n";
        cout << "5. Thong ke\n";
        cout << "4. Undo\n";
        cout << "3. Huy ve\n";
        cout << "2. Dat ve\n";
        cout << "1. Hien thi ghe\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeats(seats, MAX_ROW, MAX_COL);
            break;
        case 2: {
            int row, col;
            string id;

            cout << "Nhap ID khach:";
            cin >> id;

            cout << "Nhap hang(0-" << MAX_ROW - 1 << "):";
            cin >> row;

            cout << "Nhap cot(0-" << MAX_COL - 1 << "):";
            cin >> col;
            bookSeat(seats, row, col, id);
            if (bookSeat(seats, row, col, id)) {
                Transaction t = { "BOOK",row,col,id };
                history.push(t);
            }
            bool success = bookSeat(seats, row, col, id);

            if(success) {
                Transaction t = { "BOOK",row,col,id };
                history.push(t);
            }
            else {
                int priority;
                cout << "Nhap muc uu tien(VIP=10,thuong=1):";
                cin >> priority;
                addToWaitingQueue(WaitingQueue, id, priority);
            }
            break;

        }
        case 3: {
            int row, col;
            cout << "Nhap hang: ";
            cin >> row;
            cout << "Nhap cot: ";
            cin >> col;

            if (seats[row][col].booked) {
                Transaction t = { "CANCEL", row, col, seats[row][col].customerID };
                history.push(t);
            }

            cancelSeat(seats, row, col);
            assignSeatFromQueue(WaitingQueue, seats);
            break;
        }
        case 4:
            undo(history, seats);
            break;
        case 5:
            statistics(seats, MAX_ROW, MAX_COL);
            break;

        case 6:
            saveToFile(seats, MAX_ROW, MAX_COL);
            break;
        case 7:
            loadFromFile(seats, MAX_ROW, MAX_COL);
            break;
        }

    } while (choice != 0);

    return 0;
}