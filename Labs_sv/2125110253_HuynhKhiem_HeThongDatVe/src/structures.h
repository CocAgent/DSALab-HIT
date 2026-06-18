#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <string>
#include<stack>
#include<queue>
#include<fstream>
using namespace std;

const int MAX_ROW = 5;
const int MAX_COL = 5;

struct Seat {
    int row;
    int col;
    bool booked;
    string customerID;
};
struct Transaction {
    string type;
    int row, col;
    string customerID;
};
struct Customer {
    string id;
    int priority;
};
struct Compare {
    bool operator()(Customer a, Customer b) {
        return a.priority < b.priority;
    }
};

// function prototypes
void initSeats(Seat seats[][MAX_COL], int rows, int cols);
void displaySeats(Seat seats[][MAX_COL], int rows, int cols);
bool bookSeat(Seat seats[][MAX_COL], int row, int col, string customerID);
bool cancelSeat(Seat seats[][MAX_COL], int row, int col);
void undo(stack<Transaction>& st, Seat seats[][MAX_COL]);
void addToWaitingQueue(priority_queue<Customer, vector<Customer>, Compare>& pq, string id, int priority);
void assignSeatFromQueue(priority_queue<Customer, vector<Customer>, Compare>& pq, Seat seats[][MAX_COL]);
void statistics(Seat seats[][MAX_COL], int rows, int cols);
void saveToFile(Seat seats[][MAX_COL], int rows, int cols);
void loadFromFile(Seat seats[][MAX_COL], int rows, int cols);
#endif
