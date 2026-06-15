#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "structures.h"
#define _HAS_STD_BYTE 0
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Location {
    int    id;
    string name;
    string description;
};

struct Edge {
    int to;
    int weight; 
};

struct BSTNode {
    Location data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Location loc);
};

class CampusMap {
private:
    BSTNode* root;
    int numLocations;
    vector<vector<Edge>> adjList;   

    BSTNode* insertBST(BSTNode* node, Location loc);
    BSTNode* searchBST(BSTNode* node, int id) const;
    BSTNode* minNode(BSTNode* node);
    BSTNode* deleteBST(BSTNode* node, int id);

    void inOrder(BSTNode* node) const;
    void destroyBST(BSTNode* node);

    bool dijkstra(int start, int target,
                  vector<int>& dist, vector<int>& parent) const;

    bool bfsConnected(int s) const;

public:
    CampusMap(int n);
    ~CampusMap();

    void addLocation(int id, const string& name, const string& desc);
    void removeLocation(int id);
    void searchAndPrint(int id) const;
    void printAllLocations() const;

    void addPath(int u, int v, int weight = 100);
    void removePath(int u, int v);
    void showNeighbors(int id) const;

    void findShortestPath(int start, int target) const;
    void checkConnectivity() const;
};

#endif