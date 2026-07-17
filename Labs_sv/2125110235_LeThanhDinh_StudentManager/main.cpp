#include <iostream>
#include <string>
using namespace std;

// ===== STRUCT =====
struct Student {
    int id;
    string name;
    float gpa;
};

struct Node {
    Student data;
    Node* next;
};

// ===== LINKED LIST =====
void addStudent(Node*& head, Student s) {
    Node* newNode = new Node{s, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void displayStudents(Node* head) {
    if (!head) {
        cout << "List empty!\n";
        return;
    }
    while (head) {
        cout << head->data.id << " - "
             << head->data.name << " - "
             << head->data.gpa << endl;
        head = head->next;
    }
}

// ===== STACK (UNDO) =====
struct Stack {
    Node* top;
};

void initStack(Stack& st) {
    st.top = NULL;
}

void push(Stack& st, Student s) {
    Node* newNode = new Node{s, st.top};
    st.top = newNode;
}

bool pop(Stack& st, Student& s) {
    if (!st.top) return false;
    Node* temp = st.top;
    s = temp->data;
    st.top = st.top->next;
    delete temp;
    return true;
}

// ===== DELETE + UNDO =====
bool deleteStudent(Node*& head, int id, Stack& st) {
    Node *temp = head, *prev = NULL;

    while (temp) {
        if (temp->data.id == id) {
            push(st, temp->data); // lưu vào stack

            if (!prev) head = temp->next;
            else prev->next = temp->next;

            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}

void undoDelete(Node*& head, Stack& st) {
    Student s;
    if (pop(st, s)) {
        addStudent(head, s);
        cout << "Undo successful!\n";
    } else {
        cout << "Nothing to undo!\n";
    }
}

// ===== QUEUE =====
struct Queue {
    Node* front;
    Node* rear;
};

void initQueue(Queue& q) {
    q.front = q.rear = NULL;
}

void enqueue(Queue& q, Student s) {
    Node* newNode = new Node{s, NULL};
    if (!q.rear) {
        q.front = q.rear = newNode;
        return;
    }
    q.rear->next = newNode;
    q.rear = newNode;
}

void displayQueue(Queue q) {
    if (!q.front) {
        cout << "Queue empty!\n";
        return;
    }
    Node* temp = q.front;
    while (temp) {
        cout << temp->data.name << endl;
        temp = temp->next;
    }
}

// ===== MAIN =====
int main() {
    Node* head = NULL;
    Stack st;
    Queue q;

    initStack(st);
    initQueue(q);

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add student\n";
        cout << "2. Display students\n";
        cout << "3. Delete student\n";
        cout << "4. Undo delete\n";
        cout << "5. Add to queue\n";
        cout << "6. Show queue\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "ID: "; cin >> s.id;
            cin.ignore();
            cout << "Name: "; getline(cin, s.name);
            cout << "GPA: "; cin >> s.gpa;
            addStudent(head, s);
        }
        else if (choice == 2) {
            displayStudents(head);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            if (deleteStudent(head, id, st))
                cout << "Deleted!\n";
            else
                cout << "Not found!\n";
        }
        else if (choice == 4) {
            undoDelete(head, st);
        }
        else if (choice == 5) {
            Student s;
            cout << "Name: ";
            cin >> s.name;
            enqueue(q, s);
        }
        else if (choice == 6) {
            displayQueue(q);
        }

    } while (choice != 0);

    return 0;
}
