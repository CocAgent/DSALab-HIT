#include "../Project1/structures.h"

void test_bookSeat() {
    Seat seats[MAX_ROW][MAX_COL];
    initSeats(seats, MAX_ROW, MAX_COL);

    bool result = bookSeat(seats, 1, 1, "A");
    cout << "Test dat ghe: " << (result ? "PASS" : "FAIL") << endl;
}

void test_bookedSeatAgain() {
    Seat seats[MAX_ROW][MAX_COL];
    initSeats(seats, MAX_ROW, MAX_COL);

    bookSeat(seats, 1, 1, "A");
    bool result = bookSeat(seats, 1, 1, "B");

    cout << "Test dat trung ghe: " << (!result ? "PASS" : "FAIL") << endl;
}

void test_cancelSeat() {
    Seat seats[MAX_ROW][MAX_COL];
    initSeats(seats, MAX_ROW, MAX_COL);

    bookSeat(seats, 1, 1, "A");
    bool result = cancelSeat(seats, 1, 1);

    cout << "Test huy ghe: " << (result ? "PASS" : "FAIL") << endl;
}

void test_undo() {
    Seat seats[MAX_ROW][MAX_COL];
    initSeats(seats, MAX_ROW, MAX_COL);

    stack<Transaction> st;

    bookSeat(seats, 1, 1, "A");
    st.push({ "BOOK", 1, 1, "A" });

    undo(st, seats);

    cout << "Test undo: "
        << (!seats[1][1].booked ? "PASS" : "FAIL") << endl;
}

void test_queue() {
    priority_queue<Customer, vector<Customer>, Compare> pq;

    addToWaitingQueue(pq, "A", 1);
    addToWaitingQueue(pq, "B", 10);

    Customer top = pq.top();

    cout << "Test priority queue: "
        << (top.id == "B" ? "PASS" : "FAIL") << endl;
}

int main() {
    test_bookSeat();
    test_bookedSeatAgain();
    test_cancelSeat();
    test_undo();
    test_queue();

    return 0;
}