#ifndef BST_H
#define BST_H

#include "Contact.h"

struct Node {
    Contact data;
    Node* left;
    Node* right;

    Node(Contact c);
};

string toLower(string s);
bool isOnlyNumbers(string s);
bool isPrefix(string sub, string full);

Node* insert(Node* root, Contact c);
Node* removeNode(Node* root, string name);
Node* findMin(Node* root);

void display(Node* root);
void searchAutocomplete(Node* root, string prefix, bool& found);

void freeTree(Node* root);
Node* searchExact(Node* root, string name);
#include <vector>
void collectMatches(Node* root, string prefix, vector<Node*>& result);
void displayWithIndex(Node* root, int& index, vector<Node*>& list);
#include <vector>
void displayTable(Node* root, int& index, vector<Node*>& list);
#include <fstream>

void saveContacts(Node* root, string filename);
Node* loadContacts(string filename);

#endif#pragma once
