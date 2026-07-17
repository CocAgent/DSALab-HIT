#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <ctime>

using namespace std;

struct Contact {
    string name;
    string phone;
    time_t deletedTime;

    // Constructor mặc định
    Contact() {
        name = "";
        phone = "";
        deletedTime = 0;
    }

    // Constructor đầy đủ
    Contact(string n, string p) {
        name = n;
        phone = p;
        deletedTime = 0; // mặc định chưa bị xóa
    }
};

#endif