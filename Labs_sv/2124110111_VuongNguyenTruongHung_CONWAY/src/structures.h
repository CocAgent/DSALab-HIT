#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

struct Cell {
    int row = 0;
    int col = 0;

    bool operator==(const Cell& other) const;
};

struct GenerationStat {
    int generation = 0;
    int aliveCells = 0;
    int born = 0;
    int died = 0;
};

class AliveCellList {
public:
    AliveCellList();
    ~AliveCellList();

    AliveCellList(const AliveCellList&) = delete;
    AliveCellList& operator=(const AliveCellList&) = delete;

    void clear();
    void append(const Cell& cell);
    int size() const;
    std::vector<Cell> toVector() const;

private:
    struct Node {
        Cell cell;
        Node* next;
    };

    Node* head;
    Node* tail;
    int count;
};

class HistoryQueue {
public:
    explicit HistoryQueue(std::size_t maxEntries = 100);
    ~HistoryQueue();

    HistoryQueue(const HistoryQueue&) = delete;
    HistoryQueue& operator=(const HistoryQueue&) = delete;

    void clear();
    void enqueue(const GenerationStat& stat);
    bool dequeue(GenerationStat& stat);
    std::vector<GenerationStat> toVector() const;
    int size() const;

private:
    struct Node {
        GenerationStat stat;
        Node* next;
    };

    Node* frontNode;
    Node* backNode;
    std::size_t maxEntries;
    int entryCount;
};

class SnapshotStack {
public:
    SnapshotStack();
    ~SnapshotStack();

    SnapshotStack(const SnapshotStack&) = delete;
    SnapshotStack& operator=(const SnapshotStack&) = delete;

    void clear();
    void push(const std::vector<std::vector<int>>& board, int generation);
    bool pop(std::vector<std::vector<int>>& board, int& generation);
    bool empty() const;

private:
    struct Node {
        std::vector<std::vector<int>> board;
        int generation;
        Node* next;
    };

    Node* topNode;
};

struct Pattern {
    std::string name;
    std::string description;
    std::vector<Cell> cells;
};

class PatternBST {
public:
    PatternBST();
    ~PatternBST();

    PatternBST(const PatternBST&) = delete;
    PatternBST& operator=(const PatternBST&) = delete;

    void clear();
    bool insert(const Pattern& pattern);
    const Pattern* find(const std::string& name) const;
    std::vector<Pattern> listPatterns() const;

private:
    struct Node {
        Pattern pattern;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insertRecursive(Node* node, const Pattern& pattern, bool& inserted);
    const Pattern* findRecursive(Node* node, const std::string& name) const;
    void inOrderRecursive(Node* node, std::vector<Pattern>& patterns) const;
    void clearRecursive(Node* node);
};

class ConwayGame {
public:
    ConwayGame(int rows = 20, int cols = 40);
    ~ConwayGame();

    ConwayGame(const ConwayGame&) = delete;
    ConwayGame& operator=(const ConwayGame&) = delete;

    void resizeBoard(int rows, int cols);
    void clearBoard();
    void seedRandom(double densityPercent);
    bool setCell(int row, int col, bool alive);
    bool toggleCell(int row, int col);
    bool loadPattern(const std::string& name);
    bool loadPatternAt(const std::string& name, int topRow, int leftCol);
    bool step();
    void runSteps(int steps);
    bool undo();

    int getRows() const;
    int getCols() const;
    int getGeneration() const;
    int getAliveCount() const;
    bool isCellAlive(int row, int col) const;

    std::vector<std::vector<int>> getBoard() const;
    std::vector<GenerationStat> getHistoryStats() const;
    std::vector<Pattern> listPatterns() const;

    void printBoard(std::ostream& out) const;
    void printHistory(std::ostream& out, int limit = 10) const;

private:
    int rows;
    int cols;
    int generation;
    std::vector<std::vector<int>> board;
    AliveCellList aliveCells;
    HistoryQueue history;
    SnapshotStack undoHistory;
    PatternBST patterns;

    void loadDefaultPatterns();
    void resetBoardState();
    void rebuildAliveCells();
    void recordHistory(int born, int died);
    void pushUndoState();
    bool inBounds(int row, int col) const;
    int countAliveNeighbors(int row, int col) const;
};

#endif
