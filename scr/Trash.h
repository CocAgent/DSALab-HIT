#ifndef TRASH_H
#define TRASH_H

#include "Contact.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

class Trash {
private:
    vector<Contact> bin;

public:
    // Thêm vào thùng rác (tự gán thời gian)
    void add(Contact c) {
        c.deletedTime = time(nullptr);
        bin.push_back(c);
    }

    bool empty() {
        return bin.empty();
    }

    int size() {
        return bin.size();
    }

    Contact get(int index) {
        return bin[index];
    }

    void remove(int index) {
        if (index >= 0 && index < bin.size())
            bin.erase(bin.begin() + index);
    }

    // ================= HIỂN THỊ =================
    void show() {
        if (bin.empty()) {
            cout << "=> Thung rac rong!\n";
            return;
        }

        time_t now = time(nullptr);

        cout << "+-----+----------------------+--------------+----------------+\n";
        cout << "| STT | Ten                  | So dien thoai| Con lai (ngay) |\n";
        cout << "+-----+----------------------+--------------+----------------+\n";

        for (int i = 0; i < bin.size(); i++) {
            double seconds = difftime(now, bin[i].deletedTime);
            int daysPassed = (int)(seconds / (60 * 60 * 24));
            int daysLeft = 30 - daysPassed;

            if (daysLeft < 0) daysLeft = 0;

            cout << "| " << setw(3) << right << i + 1
                << " | " << setw(20) << left << bin[i].name
                << " | " << setw(12) << left << bin[i].phone
                << " | " << setw(14) << right << daysLeft << " |\n";
        }

        cout << "+-----+----------------------+--------------+----------------+\n";
    }

    // ================= LƯU FILE =================
    void saveToFile(string filename) {
        ofstream out(filename);

        if (!out) {
            cout << "=> Loi mo file thung rac!\n";
            return;
        }

        for (auto& c : bin) {
            out << c.name << "|"
                << c.phone << "|"
                << c.deletedTime << endl;
        }

        out.close();
    }

    // ================= LOAD FILE + LỌC 30 NGÀY =================
    void loadFromFile(string filename) {
        ifstream in(filename);
        if (!in) return;

        bin.clear();

        string line;
        time_t now = time(nullptr);

        while (getline(in, line)) {
            stringstream ss(line);
            string name, phone, timeStr;

            getline(ss, name, '|');
            getline(ss, phone, '|');
            getline(ss, timeStr, '|');

            if (name != "" && phone != "" && timeStr != "") {
                Contact c;
                c.name = name;
                c.phone = phone;
                c.deletedTime = stol(timeStr);

                // chỉ giữ dữ liệu <= 30 ngày
                if (difftime(now, c.deletedTime) <= 2592000) {
                    bin.push_back(c);
                }
            }
        }

        in.close();
    }
};

#endif