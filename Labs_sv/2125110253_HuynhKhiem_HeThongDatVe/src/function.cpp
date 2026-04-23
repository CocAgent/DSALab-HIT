#include "structures.h"

void initSeats(Seat seats[][MAX_COL], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            seats[i][j].row = i;
            seats[i][j].col = j;
            seats[i][j].booked = false;
            seats[i][j].customerID = "";
        }
    }
}

void displaySeats(Seat seats[][MAX_COL], int rows, int cols) {
    cout << "\nSo do ghe:\n";
    
    cout << "  ";
    for (int j = 0; j < cols; j++)cout << j << " ";
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << i << " ";
        for (int j = 0; j < cols; j++) {
       
            if (seats[i][j].booked)
                cout << "[X]";
            else
                cout << "[O]";
        }
        cout << endl;
    }
}
bool bookSeat(Seat seats[][MAX_COL], int row, int col, string customerID) {
    if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
        cout << "Vi tri khong hop le!\n";
        return false;
    }
    if (seats[row][col].booked) {
        cout << "Ghe (" << row << "," << col << ") da duoc dat boi khach" << seats[row][col].customerID << "!\n";
        return false;
    }
    seats[row][col].booked = true;
    seats[row][col].customerID = customerID;

    cout << "Dat ghe (" << row << "," << col << ") thanh cong cho khach" << customerID << "!\n";
    return true;
}
bool cancelSeat(Seat seats[][MAX_COL], int row, int col) {
    if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
        cout << "Vi tri khong hop le!\n";
        return false;
    }
    if (!seats[row][col].booked) {
        cout << "Ghe nay chua duoc dat!\n";
        return false;
    }
    seats[row][col].booked = false;
    seats[row][col].customerID = "";

    cout << "Huy ghe (" << row << "," << col << ") thanh cong!\n";
    return true;
}
void undo(stack<Transaction>& st, Seat seats[][MAX_COL]) {
    if (st.empty()) {
        cout << "Khong co thao tac de undo!\n";
        return;
    }
    Transaction t = st.top();
    st.pop();

    if (t.type == "BOOK") {
        seats[t.row][t.col].booked = false;
        seats[t.row][t.col].customerID = "";
        cout << "Undo dat ghe!\n";
    }
    else if (t.type == "CANCEL") {
        seats[t.row][t.col].booked = true;
        seats[t.row][t.col].customerID = t.customerID;
        cout << "Undo huy ghe!\n";
    }
}
void addToWaitingQueue(priority_queue<Customer, vector<Customer>, Compare>& pq, string id, int priority) {
    Customer c = { id,priority };
    pq.push(c);
    cout << "Khach" << id << " da duoc them vao hang cho!\n";
}
void assignSeatFromQueue(priority_queue<Customer, vector<Customer>, Compare>& pq, Seat seats[][MAX_COL]) {
    if (pq.empty()) {
        cout << "Khong co ai trong hang cho\n";
        return;
    }
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (!seats[i][j].booked) {
                Customer c = pq.top();
                pq.pop();
                
                seats[i][j].booked = true;
                seats[i][j].customerID = c.id;

                cout << "Cap ghe cho khach " << c.id << endl;
                return;
            }
        }
    }
    cout << "Van chua co ghe trong!\n";
}
void statistics(Seat seats[][MAX_COL], int rows, int cols) {
    int bookedCount = 0;
    int emptyCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (seats[i][j].booked)
                bookedCount++;
            else
                emptyCount++;
        }
    }
    cout << "\n===== THONG KE =====\n";
    cout << "So ghe da dat:" << bookedCount << endl;
    cout << "So ghe con trong: " << emptyCount << endl;
}
void saveToFile(Seat seats[][MAX_COL], int rows, int cols) {
    ofstream fout("seats.txt");

    if (!fout) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fout << seats[i][j].booked << " "
                << seats[i][j].customerID << endl;
        }
    }
    fout.close();
    cout << "Da luu du lieu vao file!\n";
}
void loadFromFile(Seat seats[][MAX_COL], int rows, int cols) {
    ifstream fin("seats.txt");

    if (!fin) {
        cout << "Chua co du lieu de load!\n";
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fin >> seats[i][j].booked;
            fin >> seats[i][j].customerID;
        }
    }
    fin.close();
    cout << "Da load du lieu tu file!\n";
}