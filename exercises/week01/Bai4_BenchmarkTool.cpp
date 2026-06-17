#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

void func_O1(int n) { volatile int a = n + 1; }
void func_O_log_n(int n) { volatile int sum = 0; for (int i = 1; i < n; i *= 2) sum++; }
void func_O_n(int n) { volatile int sum = 0; for (int i = 0; i < n; i++) sum++; }
void func_O_n2(int n) { volatile int sum = 0; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sum++; }

double measureTime(void (*func)(int), int n) {
    auto start = high_resolution_clock::now();
    func(n);
    auto stop = high_resolution_clock::now();
    return duration<double, milli>(stop - start).count();
}

string formatRow(string algo, double t1, double t2, double t3) {
    char buffer[200];
    snprintf(buffer, sizeof(buffer), "║ %-10s ║ %-7.3fms ║ %-7.3fms ║ %-7.3fms ║", algo.c_str(), t1, t2, t3);
    return string(buffer);
}

int main() {
    int n1 = 1000, n2 = 10000, n3 = 100000;
    string header = "╔════════════╦══════════╦══════════╦══════════╗\n"
                    "║ Thuật toán ║  n=1000  ║ n=10000  ║ n=100000 ║\n"
                    "╠════════════╬══════════╬══════════╬══════════╣\n";
    string footer = "╚════════════╩══════════╩══════════╩══════════╝\n";

    string fullTable = header + 
                       formatRow("  O(1)", measureTime(func_O1, n1), measureTime(func_O1, n2), measureTime(func_O1, n3)) + "\n" +
                       formatRow("O(log n)", measureTime(func_O_log_n, n1), measureTime(func_O_log_n, n2), measureTime(func_O_log_n, n3)) + "\n" +
                       formatRow("  O(n)", measureTime(func_O_n, n1), measureTime(func_O_n, n2), measureTime(func_O_n, n3)) + "\n" +
                       formatRow("  O(n^2)", measureTime(func_O_n2, n1), measureTime(func_O_n2, n2), measureTime(func_O_n2, n3)) + "\n" + footer;

    cout << "Bảng so sánh tốc độ thuật toán:\n\n" << fullTable;
    
    ofstream outFile("benchmark.txt");
    if (outFile.is_open()) {
        outFile << fullTable;
        outFile.close();
    }
    return 0;
}
