#include "structures.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>

namespace {
std::string normalizeName(const std::string& value) {
    std::string result = value;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char ch) {
        return static_cast<char>(std::tolower(ch));
    });
    return result;
}
}  // namespace

bool Cell::operator==(const Cell& other) const {
    return row == other.row && col == other.col;
}

AliveCellList::AliveCellList() : head(nullptr), tail(nullptr), count(0) {}

AliveCellList::~AliveCellList() {
    clear();
}

void AliveCellList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

void AliveCellList::append(const Cell& cell) {
    Node* node = new Node{cell, nullptr};
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    ++count;
}

int AliveCellList::size() const {
    return count;
}

std::vector<Cell> AliveCellList::toVector() const {
    std::vector<Cell> cells;
    cells.reserve(count);

    Node* current = head;
    while (current != nullptr) {
        cells.push_back(current->cell);
        current = current->next;
    }
    return cells;
}

HistoryQueue::HistoryQueue(std::size_t maxEntriesValue)
    : frontNode(nullptr), backNode(nullptr), maxEntries(maxEntriesValue), entryCount(0) {}

HistoryQueue::~HistoryQueue() {
    clear();
}

void HistoryQueue::clear() {
    Node* current = frontNode;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    frontNode = nullptr;
    backNode = nullptr;
    entryCount = 0;
}

void HistoryQueue::enqueue(const GenerationStat& stat) {
    if (maxEntries == 0) {
        return;
    }

    if (static_cast<std::size_t>(entryCount) == maxEntries) {
        GenerationStat discarded;
        dequeue(discarded);
    }

    Node* node = new Node{stat, nullptr};
    if (frontNode == nullptr) {
        frontNode = node;
        backNode = node;
    } else {
        backNode->next = node;
        backNode = node;
    }
    ++entryCount;
}

bool HistoryQueue::dequeue(GenerationStat& stat) {
    if (frontNode == nullptr) {
        return false;
    }

    Node* node = frontNode;
    stat = node->stat;
    frontNode = node->next;
    if (frontNode == nullptr) {
        backNode = nullptr;
    }

    delete node;
    --entryCount;
    return true;
}

std::vector<GenerationStat> HistoryQueue::toVector() const {
    std::vector<GenerationStat> stats;
    stats.reserve(entryCount);

    Node* current = frontNode;
    while (current != nullptr) {
        stats.push_back(current->stat);
        current = current->next;
    }
    return stats;
}

int HistoryQueue::size() const {
    return entryCount;
}

SnapshotStack::SnapshotStack() : topNode(nullptr) {}

SnapshotStack::~SnapshotStack() {
    clear();
}

void SnapshotStack::clear() {
    Node* current = topNode;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    topNode = nullptr;
}

void SnapshotStack::push(const std::vector<std::vector<int>>& board, int generation) {
    topNode = new Node{board, generation, topNode};
}

bool SnapshotStack::pop(std::vector<std::vector<int>>& board, int& generation) {
    if (topNode == nullptr) {
        return false;
    }

    Node* node = topNode;
    board = node->board;
    generation = node->generation;
    topNode = node->next;
    delete node;
    return true;
}

bool SnapshotStack::empty() const {
    return topNode == nullptr;
}

PatternBST::PatternBST() : root(nullptr) {}

PatternBST::~PatternBST() {
    clear();
}

void PatternBST::clear() {
    clearRecursive(root);
    root = nullptr;
}

bool PatternBST::insert(const Pattern& pattern) {
    bool inserted = false;
    root = insertRecursive(root, pattern, inserted);
    return inserted;
}

const Pattern* PatternBST::find(const std::string& name) const {
    return findRecursive(root, normalizeName(name));
}

std::vector<Pattern> PatternBST::listPatterns() const {
    std::vector<Pattern> patternsOut;
    inOrderRecursive(root, patternsOut);
    return patternsOut;
}

PatternBST::Node* PatternBST::insertRecursive(Node* node, const Pattern& pattern, bool& inserted) {
    if (node == nullptr) {
        inserted = true;
        return new Node{pattern, nullptr, nullptr};
    }

    if (pattern.name < node->pattern.name) {
        node->left = insertRecursive(node->left, pattern, inserted);
    } else if (pattern.name > node->pattern.name) {
        node->right = insertRecursive(node->right, pattern, inserted);
    }

    return node;
}

const Pattern* PatternBST::findRecursive(Node* node, const std::string& name) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (name < node->pattern.name) {
        return findRecursive(node->left, name);
    }

    if (name > node->pattern.name) {
        return findRecursive(node->right, name);
    }

    return &node->pattern;
}

void PatternBST::inOrderRecursive(Node* node, std::vector<Pattern>& patternsOut) const {
    if (node == nullptr) {
        return;
    }

    inOrderRecursive(node->left, patternsOut);
    patternsOut.push_back(node->pattern);
    inOrderRecursive(node->right, patternsOut);
}

void PatternBST::clearRecursive(Node* node) {
    if (node == nullptr) {
        return;
    }

    clearRecursive(node->left);
    clearRecursive(node->right);
    delete node;
}

ConwayGame::ConwayGame(int rowsValue, int colsValue)
    : rows(rowsValue),
      cols(colsValue),
      generation(0),
      board(rowsValue, std::vector<int>(colsValue, 0)),
      history(100) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Board size must be positive.");
    }

    loadDefaultPatterns();
    rebuildAliveCells();
}

ConwayGame::~ConwayGame() = default;

void ConwayGame::resizeBoard(int rowsValue, int colsValue) {
    if (rowsValue <= 0 || colsValue <= 0) {
        throw std::invalid_argument("Board size must be positive.");
    }

    rows = rowsValue;
    cols = colsValue;
    board.assign(rows, std::vector<int>(cols, 0));
    resetBoardState();
}

void ConwayGame::clearBoard() {
    for (int row = 0; row < rows; row += 1) {
        std::fill(board[row].begin(), board[row].end(), 0);
    }
    resetBoardState();
}

void ConwayGame::seedRandom(double densityPercent) {
    if (densityPercent < 0.0 || densityPercent > 100.0) {
        throw std::invalid_argument("Density must be in [0, 100].");
    }

    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_real_distribution<double> distribution(0.0, 100.0);

    for (int row = 0; row < rows; row += 1) {
        for (int col = 0; col < cols; col += 1) {
            board[row][col] = distribution(generator) < densityPercent ? 1 : 0;
        }
    }

    resetBoardState();
}

bool ConwayGame::setCell(int row, int col, bool alive) {
    if (!inBounds(row, col)) {
        return false;
    }

    board[row][col] = alive ? 1 : 0;
    rebuildAliveCells();
    return true;
}

bool ConwayGame::toggleCell(int row, int col) {
    if (!inBounds(row, col)) {
        return false;
    }

    board[row][col] = board[row][col] == 1 ? 0 : 1;
    rebuildAliveCells();
    return true;
}

bool ConwayGame::loadPattern(const std::string& name) {
    const Pattern* pattern = patterns.find(name);
    if (pattern == nullptr) {
        return false;
    }

    int patternHeight = 0;
    int patternWidth = 0;
    for (const Cell& cell : pattern->cells) {
        patternHeight = std::max(patternHeight, cell.row + 1);
        patternWidth = std::max(patternWidth, cell.col + 1);
    }

    const int offsetRow = std::max(0, (rows - patternHeight) / 2);
    const int offsetCol = std::max(0, (cols - patternWidth) / 2);
    return loadPatternAt(name, offsetRow, offsetCol);
}

bool ConwayGame::loadPatternAt(const std::string& name, int topRow, int leftCol) {
    const Pattern* pattern = patterns.find(name);
    if (pattern == nullptr) {
        return false;
    }

    clearBoard();
    for (const Cell& cell : pattern->cells) {
        const int row = topRow + cell.row;
        const int col = leftCol + cell.col;
        if (inBounds(row, col)) {
            board[row][col] = 1;
        }
    }

    resetBoardState();
    return true;
}

bool ConwayGame::step() {
    pushUndoState();

    std::vector<std::vector<int>> nextBoard(rows, std::vector<int>(cols, 0));
    int born = 0;
    int died = 0;

    for (int row = 0; row < rows; row += 1) {
        for (int col = 0; col < cols; col += 1) {
            const int neighbors = countAliveNeighbors(row, col);
            const bool alive = board[row][col] == 1;
            const bool nextAlive = alive ? (neighbors == 2 || neighbors == 3) : (neighbors == 3);

            nextBoard[row][col] = nextAlive ? 1 : 0;

            if (!alive && nextAlive) {
                ++born;
            } else if (alive && !nextAlive) {
                ++died;
            }
        }
    }

    board.swap(nextBoard);
    ++generation;
    rebuildAliveCells();
    recordHistory(born, died);
    return born > 0 || died > 0;
}

void ConwayGame::runSteps(int steps) {
    for (int i = 0; i < steps; i += 1) {
        step();
    }
}

bool ConwayGame::undo() {
    std::vector<std::vector<int>> previousBoard;
    int previousGeneration = 0;
    if (!undoHistory.pop(previousBoard, previousGeneration)) {
        return false;
    }

    board = previousBoard;
    generation = previousGeneration;
    rebuildAliveCells();

    std::vector<GenerationStat> stats = history.toVector();
    history.clear();
    if (!stats.empty()) {
        stats.pop_back();
    }
    for (const GenerationStat& stat : stats) {
        history.enqueue(stat);
    }

    return true;
}

int ConwayGame::getRows() const {
    return rows;
}

int ConwayGame::getCols() const {
    return cols;
}

int ConwayGame::getGeneration() const {
    return generation;
}

int ConwayGame::getAliveCount() const {
    return aliveCells.size();
}

bool ConwayGame::isCellAlive(int row, int col) const {
    return inBounds(row, col) && board[row][col] == 1;
}

std::vector<std::vector<int>> ConwayGame::getBoard() const {
    return board;
}

std::vector<GenerationStat> ConwayGame::getHistoryStats() const {
    return history.toVector();
}

std::vector<Pattern> ConwayGame::listPatterns() const {
    return patterns.listPatterns();
}

void ConwayGame::printBoard(std::ostream& out) const {
    out << "\nGeneration: " << generation
        << " | Alive cells: " << getAliveCount()
        << " | Size: " << rows << "x" << cols << "\n";

    out << "   ";
    for (int col = 0; col < cols; col += 1) {
        out << (col % 10);
    }
    out << "\n";

    for (int row = 0; row < rows; row += 1) {
        out << std::setw(2) << row << " ";
        for (int col = 0; col < cols; col += 1) {
            out << (board[row][col] == 1 ? '#' : '.');
        }
        out << "\n";
    }
}

void ConwayGame::printHistory(std::ostream& out, int limit) const {
    std::vector<GenerationStat> stats = history.toVector();
    if (stats.empty()) {
        out << "Chua co lich su mo phong.\n";
        return;
    }

    const int startIndex = std::max(0, static_cast<int>(stats.size()) - limit);
    for (std::size_t index = static_cast<std::size_t>(startIndex); index < stats.size(); index += 1) {
        const GenerationStat& stat = stats[index];
        out << "Gen " << stat.generation
            << " | alive=" << stat.aliveCells
            << " | born=" << stat.born
            << " | died=" << stat.died << "\n";
    }
}

void ConwayGame::loadDefaultPatterns() {
    patterns.insert(Pattern{
        "beacon",
        "Oscillator 2x2 block pair.",
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 2}, {2, 3}, {3, 2}, {3, 3}},
    });
    patterns.insert(Pattern{
        "blinker",
        "Period-2 line oscillator.",
        {{0, 1}, {1, 1}, {2, 1}},
    });
    patterns.insert(Pattern{
        "block",
        "Stable 2x2 still life.",
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    });
    patterns.insert(Pattern{
        "glider",
        "Small spaceship that moves diagonally.",
        {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}},
    });
    patterns.insert(Pattern{
        "toad",
        "Period-2 oscillator with six cells.",
        {{0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 1}, {1, 2}},
    });
    patterns.insert(Pattern{
        "gosper",
        "Gosper glider gun.",
        {
            {0, 24},
            {1, 22}, {1, 24},
            {2, 12}, {2, 13}, {2, 20}, {2, 21}, {2, 34}, {2, 35},
            {3, 11}, {3, 15}, {3, 20}, {3, 21}, {3, 34}, {3, 35},
            {4, 0}, {4, 1}, {4, 10}, {4, 16}, {4, 20}, {4, 21},
            {5, 0}, {5, 1}, {5, 10}, {5, 14}, {5, 16}, {5, 17}, {5, 22}, {5, 24},
            {6, 10}, {6, 16}, {6, 24},
            {7, 11}, {7, 15},
            {8, 12}, {8, 13},
        },
    });
}

void ConwayGame::resetBoardState() {
    generation = 0;
    undoHistory.clear();
    history.clear();
    rebuildAliveCells();
    recordHistory(getAliveCount(), 0);
}

void ConwayGame::rebuildAliveCells() {
    aliveCells.clear();
    for (int row = 0; row < rows; row += 1) {
        for (int col = 0; col < cols; col += 1) {
            if (board[row][col] == 1) {
                aliveCells.append(Cell{row, col});
            }
        }
    }
}

void ConwayGame::recordHistory(int born, int died) {
    history.enqueue(GenerationStat{generation, getAliveCount(), born, died});
}

void ConwayGame::pushUndoState() {
    undoHistory.push(board, generation);
}

bool ConwayGame::inBounds(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int ConwayGame::countAliveNeighbors(int row, int col) const {
    int aliveNeighbors = 0;

    for (int deltaRow = -1; deltaRow <= 1; deltaRow += 1) {
        for (int deltaCol = -1; deltaCol <= 1; deltaCol += 1) {
            if (deltaRow == 0 && deltaCol == 0) {
                continue;
            }

            const int nextRow = row + deltaRow;
            const int nextCol = col + deltaCol;
            if (inBounds(nextRow, nextCol) && board[nextRow][nextCol] == 1) {
                ++aliveNeighbors;
            }
        }
    }

    return aliveNeighbors;
}
