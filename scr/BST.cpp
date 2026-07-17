#include "BST.h"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>
using namespace std;

Node::Node(Contact c) {
    data = c;
    left = right = nullptr;
}

string toLower(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

bool isOnlyNumbers(string s) {
    if (s.empty()) return false;
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

bool isPrefix(string sub, string full) {
    sub = toLower(sub);
    full = toLower(full);
    return full.substr(0, sub.length()) == sub;
}

Node* insert(Node* root, Contact c) {
    if (!root) return new Node(c);

    if (toLower(c.name) == toLower(root->data.name)) {
        cout << "=> Ten da ton tai!\n";
        return root;
    }

    if (toLower(c.name) < toLower(root->data.name))
        root->left = insert(root->left, c);
    else
        root->right = insert(root->right, c);

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* removeNode(Node* root, string name) {
    if (!root) return root;

    if (toLower(name) < toLower(root->data.name))
        root->left = removeNode(root->left, name);
    else if (toLower(name) > toLower(root->data.name))
        root->right = removeNode(root->right, name);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data.name);
    }
    return root;
}

void display(Node* root) {
    if (!root) return;
    display(root->left);
    cout << root->data.name << " | " << root->data.phone << endl;
    display(root->right);
}

void searchAutocomplete(Node* root, string prefix, bool& found) {
    if (!root) return;
    searchAutocomplete(root->left, prefix, found);

    if (isPrefix(prefix, root->data.name)) {
        cout << root->data.name << " | " << root->data.phone << endl;
        found = true;
    }

    searchAutocomplete(root->right, prefix, found);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
Node* searchExact(Node* root, string name) {
    if (!root) return nullptr;

    string target = toLower(name);
    string current = toLower(root->data.name);

    if (target == current) return root;
    if (target < current)
        return searchExact(root->left, name);
    else
        return searchExact(root->right, name);
}
void collectMatches(Node* root, string prefix, vector<Node*>& result) {
    if (!root) return;

    collectMatches(root->left, prefix, result);

    if (isPrefix(prefix, root->data.name)) {
        result.push_back(root);
    }

    collectMatches(root->right, prefix, result);
}
#include <vector>

void displayWithIndex(Node* root, int& index, vector<Node*>& list) {
    if (!root) return;

    displayWithIndex(root->left, index, list);

    cout << index << ". "
        << left << setw(20) << root->data.name
        << " | " << root->data.phone << endl;

    list.push_back(root);
    index++;

    displayWithIndex(root->right, index, list);
}
#include <vector>
#include <iomanip>

void displayTable(Node* root, int& index, vector<Node*>& list) {
    if (!root) return;

    displayTable(root->left, index, list);

    cout << "| " << setw(3) << right << index
        << " | " << setw(20) << left << root->data.name
        << " | " << setw(12) << left << root->data.phone << " |\n";

    list.push_back(root);
    index++;

    displayTable(root->right, index, list);
}void saveToFile(Node* root, ofstream& out) {
    if (!root) return;

    saveToFile(root->left, out);

    out << root->data.name << "|" << root->data.phone << endl;

    saveToFile(root->right, out);
}
void saveContacts(Node* root, string filename) {
    ofstream out(filename);

    if (!out) {
        cout << "=> Loi mo file!\n";
        return;
    }

    saveToFile(root, out);
    out.close();

    cout << "=> Da luu danh ba vao file " << filename << endl;
}
#include <fstream>

Node* loadContacts(string filename) {
    ifstream in(filename);
    if (!in) return nullptr;

    Node* root = nullptr;
    string line;

    while (getline(in, line)) {
        int pos = line.find('|');
        if (pos != string::npos) {
            Contact c;
            c.name = line.substr(0, pos);
            c.phone = line.substr(pos + 1);

            root = insert(root, c);
        }
    }

    in.close();
    return root;
}