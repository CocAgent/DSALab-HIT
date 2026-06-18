#include "../src/structures.h"

#include <cassert>
#include <iostream>
#include <vector>

namespace {
bool boardsEqual(const std::vector<std::vector<int>>& left, const std::vector<std::vector<int>>& right) {
    return left == right;
}
}  // namespace

void test_block_is_stable() {
    ConwayGame game(6, 6);
    game.clearBoard();
    game.setCell(2, 2, true);
    game.setCell(2, 3, true);
    game.setCell(3, 2, true);
    game.setCell(3, 3, true);

    const auto before = game.getBoard();
    game.step();

    assert(boardsEqual(before, game.getBoard()));
    assert(game.getAliveCount() == 4);
    assert(game.getGeneration() == 1);
}

void test_blinker_oscillates() {
    ConwayGame game(5, 5);
    game.clearBoard();
    game.setCell(1, 2, true);
    game.setCell(2, 2, true);
    game.setCell(3, 2, true);

    game.step();
    assert(game.isCellAlive(2, 1));
    assert(game.isCellAlive(2, 2));
    assert(game.isCellAlive(2, 3));
    assert(!game.isCellAlive(1, 2));
    assert(!game.isCellAlive(3, 2));

    game.step();
    assert(game.isCellAlive(1, 2));
    assert(game.isCellAlive(2, 2));
    assert(game.isCellAlive(3, 2));
}

void test_pattern_bst_contains_glider() {
    ConwayGame game(20, 20);
    const std::vector<Pattern> patterns = game.listPatterns();

    bool hasGlider = false;
    bool hasGosper = false;
    for (const Pattern& pattern : patterns) {
        hasGlider = hasGlider || pattern.name == "glider";
        hasGosper = hasGosper || pattern.name == "gosper";
    }

    assert(hasGlider);
    assert(hasGosper);
}

void test_load_pattern_and_alive_count() {
    ConwayGame game(10, 10);
    assert(game.loadPattern("glider"));
    assert(game.getAliveCount() == 5);
    assert(game.getGeneration() == 0);
}

void test_undo_restores_previous_generation() {
    ConwayGame game(5, 5);
    game.clearBoard();
    game.setCell(1, 2, true);
    game.setCell(2, 2, true);
    game.setCell(3, 2, true);

    const auto before = game.getBoard();
    game.step();
    assert(!boardsEqual(before, game.getBoard()));

    assert(game.undo());
    assert(boardsEqual(before, game.getBoard()));
    assert(game.getGeneration() == 0);
}

void test_history_queue_records_generations() {
    ConwayGame game(5, 5);
    game.clearBoard();
    game.loadPatternAt("blinker", 1, 1);
    game.step();
    game.step();

    const std::vector<GenerationStat> history = game.getHistoryStats();
    assert(history.size() >= 3);
    assert(history.back().generation == 2);
    assert(history.back().aliveCells == 3);
}

int main() {
    test_block_is_stable();
    test_blinker_oscillates();
    test_pattern_bst_contains_glider();
    test_load_pattern_and_alive_count();
    test_undo_restores_previous_generation();
    test_history_queue_records_generations();

    std::cout << "All Conway test cases passed.\n";
    return 0;
}
