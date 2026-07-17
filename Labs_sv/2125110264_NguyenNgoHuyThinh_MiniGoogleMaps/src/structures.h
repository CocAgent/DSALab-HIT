#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

extern int nodeCount;
extern vector<string> names;
extern vector<vector<pair<int,int>>> adj;

int  findNode(const string& name);
void addLocation();
void addRoad();
void showMap();
void printPath(vector<int>& parent, int src, int dest);
void dijkstra();
void bfsPath();
void dfsHelper(int u, vector<bool>& visited);
void dfsTraversal();

#endif
