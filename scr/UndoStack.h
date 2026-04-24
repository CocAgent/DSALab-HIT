#ifndef UNDOSTACK_H
#define UNDOSTACK_H

#include "Contact.h"
#include <stack>

using namespace std;

class UndoStack {
private:
    stack<Contact> st;

public:
    void push(Contact c) {
        st.push(c);
    }

    bool empty() {
        return st.empty();
    }

    Contact pop() {
        Contact c = st.top();
        st.pop();
        return c;
    }
};

#endif#pragma once
