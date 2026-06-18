#include "structures.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace {
int readInt(const std::string& prompt, int minValue, int maxValue) {
    while (true) {
        std::cout << prompt;
        int value = 0;
        if (std::cin >> value && value >= minValue && value <= maxValue) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double readDouble(const std::string& prompt, double minValue, double maxValue) {
    while (true) {
        std::cout << prompt;
        double value = 0.0;
        if (std::cin >> value && value >= minValue && value <= maxValue) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    return value;
}

void printMenu() {
    std::cout << "\n===== CONWAY GAME OF LIFE =====\n";
    std::cout << "1. Hien thi ban co\n";
    std::cout << "2. Thay doi kich thuoc ban co\n";
    std::cout << "3. Bat/tat mot o thu cong\n";
    std::cout << "4. Gieo ngau nhien theo mat do\n";
    std::cout << "5. Nap pattern tu BST\n";
    std::cout << "6. Chay 1 the he\n";
    std::cout << "7. Chay N the he\n";
    std::cout << "8. Hoan tac 1 buoc\n";
    std::cout << "9. Xem lich su mo phong (Queue)\n";
    std::cout << "10. Liet ke pattern co san\n";
    std::cout << "11. Xoa ban co\n";
    std::cout << "0. Thoat\n";
}

void printPatterns(const std::vector<Pattern>& patterns) {
    for (const Pattern& pattern : patterns) {
        std::cout << "- " << pattern.name << ": " << pattern.description << "\n";
    }
}
}  // namespace

int main() {
    ConwayGame game(20, 40);

    while (true) {
        printMenu();
        const int choice = readInt("Chon chuc nang: ", 0, 11);

        if (choice == 0) {
            std::cout << "Tam biet.\n";
            break;
        }

        if (choice == 1) {
            game.printBoard(std::cout);
            continue;
        }

        if (choice == 2) {
            const int rows = readInt("Nhap so dong (5-60): ", 5, 60);
            const int cols = readInt("Nhap so cot (5-80): ", 5, 80);
            game.resizeBoard(rows, cols);
            std::cout << "Da thay doi kich thuoc ban co.\n";
            continue;
        }

        if (choice == 3) {
            const int row = readInt("Nhap dong: ", 0, game.getRows() - 1);
            const int col = readInt("Nhap cot: ", 0, game.getCols() - 1);
            game.toggleCell(row, col);
            std::cout << "Da cap nhat trang thai o.\n";
            continue;
        }

        if (choice == 4) {
            const double density = readDouble("Nhap mat do song (0-100): ", 0.0, 100.0);
            game.seedRandom(density);
            std::cout << "Da gieo ngau nhien.\n";
            continue;
        }

        if (choice == 5) {
            const std::vector<Pattern> patterns = game.listPatterns();
            printPatterns(patterns);
            const std::string name = readLine("Nhap ten pattern: ");
            if (game.loadPattern(name)) {
                std::cout << "Da nap pattern vao giua ban co.\n";
            } else {
                std::cout << "Khong tim thay pattern.\n";
            }
            continue;
        }

        if (choice == 6) {
            game.step();
            game.printBoard(std::cout);
            continue;
        }

        if (choice == 7) {
            const int steps = readInt("Nhap so the he muon chay (1-100): ", 1, 100);
            game.runSteps(steps);
            game.printBoard(std::cout);
            continue;
        }

        if (choice == 8) {
            if (game.undo()) {
                std::cout << "Da hoan tac 1 buoc.\n";
                game.printBoard(std::cout);
            } else {
                std::cout << "Khong con trang thai nao de hoan tac.\n";
            }
            continue;
        }

        if (choice == 9) {
            game.printHistory(std::cout, 15);
            continue;
        }

        if (choice == 10) {
            printPatterns(game.listPatterns());
            continue;
        }

        if (choice == 11) {
            game.clearBoard();
            std::cout << "Da xoa ban co.\n";
        }
    }

    return 0;
}
