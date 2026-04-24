#ifndef HISTORY_H
#define HISTORY_H

#include <queue>
#include <string>
#include <iostream>

using namespace std;

class History {
private:
    queue<string> q;

public:
    void add(string s) {
        q.push(s);
    }

    void show() {
        queue<string> temp = q;
        cout << "Lich su tim kiem:\n";
        while (!temp.empty()) {
            cout << "- " << temp.front() << endl;
            temp.pop();
        }
    }
};

#endif