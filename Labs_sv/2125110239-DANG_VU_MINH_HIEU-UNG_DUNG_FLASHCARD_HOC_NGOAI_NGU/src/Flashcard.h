#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <algorithm>
#include <limits> // Thêm thư viện này để dùng numeric_limits

using namespace std;

struct Card {
    string word;
    string meaning;
    string example;
    int weight;

    bool operator<(const Card& other) const {
        return weight < other.weight;
    }
};

struct Node {
    Card data;
    Node* left, * right;
    Node(Card c) : data(c), left(nullptr), right(nullptr) {}
};

class FlashcardSystem {
private:
    Node* root;
    stack<Card> history;
    int totalAttempts = 0;
    int correctAttempts = 0;

    Node* insert(Node* node, Card c);
    Node* search(Node* node, string word);
    Node* findMin(Node* node); 
    Node* remove(Node* node, string word);
    void deleteTree(Node* node);

public:
    FlashcardSystem() : root(nullptr) {}
    ~FlashcardSystem() { deleteTree(root); }

    void addCard(string w, string m, string e, int weight = 1);
    void removeCard(string w);
    void searchWord(string w);
    void startSession();
    void showStats();
    void saveFile(string filename);
    void loadFile(string filename);
};

#endif