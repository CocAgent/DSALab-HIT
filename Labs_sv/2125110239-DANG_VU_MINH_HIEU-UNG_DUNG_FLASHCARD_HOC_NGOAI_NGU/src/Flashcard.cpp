#include "Flashcard.h"

Node* FlashcardSystem::insert(Node* node, Card c) {
    if (!node) return new Node(c);
    if (c.word < node->data.word) node->left = insert(node->left, c);
    else if (c.word > node->data.word) node->right = insert(node->right, c);
    return node;
}

Node* FlashcardSystem::search(Node* node, string word) {
    if (!node || node->data.word == word) return node;
    if (word < node->data.word) return search(node->left, word);
    return search(node->right, word);
}

Node* FlashcardSystem::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* FlashcardSystem::remove(Node* node, string word) {
    if (!node) return nullptr;
    if (word < node->data.word) node->left = remove(node->left, word);
    else if (word > node->data.word) node->right = remove(node->right, word);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data.word);
    }
    return node;
}

void FlashcardSystem::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void FlashcardSystem::addCard(string w, string m, string e, int weight) {
    root = insert(root, { w, m, e, weight });
}

void FlashcardSystem::removeCard(string w) {
    root = remove(root, w);
}

void FlashcardSystem::searchWord(string w) {
    Node* res = search(root, w);
    if (res) {
        cout << "\n[Ket qua] " << res->data.word << ": " << res->data.meaning;
        cout << "\nVi du: " << res->data.example << " (Weight: " << res->data.weight << ")\n";
    }
    else cout << ">> Khong tim thay tu!\n";
}

void FlashcardSystem::startSession() {
    if (!root) {
        cout << ">> Tu dien trong!\n";
        return;
    }

    priority_queue<Card> pq;
    auto fillPQ = [&](auto self, Node* n) -> void {
        if (!n) return;
        self(self, n->left);
        pq.push(n->data);
        self(self, n->right);
        };
    fillPQ(fillPQ, root);

    queue<Card> sessionQueue;
    while (!pq.empty()) {
        sessionQueue.push(pq.top());
        pq.pop();
    }

    cout << "\n--- PHIEN HOC BAT DAU ---" << endl;
    while (!sessionQueue.empty()) {
        Card current = sessionQueue.front();
        sessionQueue.pop();

        cout << "\nTu: " << current.word << " | Nhap nghia: ";
        string input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xoa bo dem
        getline(cin, input);

        totalAttempts++;
        if (input == current.meaning) {
            cout << "CHINH XAC!" << endl;
            correctAttempts++;
            current.weight = max(1, current.weight - 1);
        }
        else {
            cout << "SAI! Nghia dung: " << current.meaning << endl;
            current.weight += 2;
        }

        removeCard(current.word);
        addCard(current.word, current.meaning, current.example, current.weight);

        cout << "Tiep tuc? (y/n): ";
        char choice; cin >> choice;
        if (choice == 'n') break;
    }
}

void FlashcardSystem::showStats() {
    double rate = (totalAttempts == 0) ? 0 : (double)correctAttempts / totalAttempts * 100;
    cout << "\n--- THONG KE ---" << endl;
    cout << "Tong: " << totalAttempts << " | Dung: " << correctAttempts << " (" << rate << "%)" << endl;
}

void FlashcardSystem::saveFile(string filename) {
    ofstream out(filename);
    auto save = [&](auto self, Node* n) -> void {
        if (!n) return;
        out << n->data.word << "|" << n->data.meaning << "|" << n->data.example << "|" << n->data.weight << "\n";
        self(self, n->left);
        self(self, n->right);
        };
    save(save, root);
    out.close();
}

void FlashcardSystem::loadFile(string filename) {
    ifstream in(filename);
    if (!in) return;
    string w, m, e, weightStr;
    while (getline(in, w, '|') && getline(in, m, '|') && getline(in, e, '|') && getline(in, weightStr)) {
        if (!w.empty()) addCard(w, m, e, stoi(weightStr));
    }
}