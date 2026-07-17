#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Customer {
    int id;
    string name;
    bool isVIP;

    // Ưu tiên VIP, sau đó đến ID thấp hơn (đến trước)
    bool operator<(const Customer& other) const {
        if (isVIP != other.isVIP) return !isVIP;
        return id > other.id;
    }
};

struct Seat {
    int row, col;
    bool isBooked = false;
    int customerId = -1;
};

enum ActionType { BOOK, CANCEL };
struct Transaction {
    ActionType type;
    int row, col, customerId;
};

struct BSTNode {
    Customer data;
    BSTNode *left, *right;
    BSTNode(Customer c) : data(c), left(nullptr), right(nullptr) {}
};

#endif
