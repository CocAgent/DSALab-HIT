#include "structures.h"

// Hàm kh?i t?o (Constructor)
MazeGame::MazeGame(int w, int h) {
    bfs_path_len = 0;
    dfs_path_len = 0;
    setDifficulty(w, h);
}

// Cài ??t ?? khó (Kích th??c)
void MazeGame::setDifficulty(int w, int h) {
    width = (w % 2 == 0) ? w + 1 : w;
    height = (h % 2 == 0) ? h + 1 : h;
    generate();
}

// Kh?i t?o ti?n trình t?o mê cung m?i
void MazeGame::generate() {
    grid.assign(height, vector<char>(width, WALL_CHAR));
    srand(static_cast<unsigned int>(time(0)));

    // B?t ??u ?ào ???ng ng?u nhiên t? ô (1, 1)
    dfsGenerate(1, 1);

    // Cài ??t ?i?m xu?t phát và ?ích c? ??nh ? 2 góc
    start = { 1, 1 };
    target = { height - 2, width - 2 };
    grid[start.r][start.c] = PATH_CHAR;
    grid[target.r][target.c] = PATH_CHAR;

    player = start;
    bfs_path_len = 0;
    dfs_path_len = 0;
}

// Thu?t toán ?ào ???ng ng?u nhiên t?o mê cung (Recursive Backtracker)
void MazeGame::dfsGenerate(int r, int c) {
    grid[r][c] = PATH_CHAR;

    int dr[] = { -2, 2, 0, 0 };
    int dc[] = { 0, 0, -2, 2 };

    int dirs[] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; i++) {
        int rIdx = rand() % 4;
        swap(dirs[i], dirs[rIdx]);
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[dirs[i]];
        int nc = c + dc[dirs[i]];

        if (nr > 0 && nr < height - 1 && nc > 0 && nc < width - 1) {
            if (grid[nr][nc] == WALL_CHAR) {
                grid[r + dr[dirs[i]] / 2][c + dc[dirs[i]] / 2] = PATH_CHAR;
                dfsGenerate(nr, nc);
            }
        }
    }
}

// Hàm hi?n th? mê cung ASCII lên màn hình console
void MazeGame::display(const vector<vector<char>>& currentGrid) {
    system("cls");
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            if (r == player.r && c == player.c) {
                cout << PLAYER_CHAR << " ";
            }
            else if (r == start.r && c == start.c) {
                cout << START_CHAR << " ";
            }
            else if (r == target.r && c == target.c) {
                cout << END_CHAR << " ";
            }
            else {
                if (currentGrid[r][c] == WALL_CHAR) {
                    cout << "##";
                }
                else if (currentGrid[r][c] == ROUTE_BFS) {
                    cout << ". ";
                }
                else if (currentGrid[r][c] == ROUTE_DFS) {
                    cout << "* ";
                }
                else {
                    cout << "  ";
                }
            }
        }
        cout << "\n";
    }
}

// Hàm b? tr? g?i nhanh ma tr?n l??i hi?n t?i
void MazeGame::displayCurrent() {
    display(grid);
}

// Hàm x? lý ch? ?? ng??i ch?i t? di chuy?n gi?i mê cung
void MazeGame::play() {
    player = start;
    while (!(player == target)) {
        displayCurrent();
        cout << "\n=== DIEU KHIEN ===================================\n";
        cout << "Dung W (Len), S (Xuong), A (Trai), D (Phai). Bam Q de thoat.\n";
        cout << "==================================================\n";

        char ch = _getch();
        if (ch == 'q' || ch == 'Q') return;

        int nr = player.r;
        int nc = player.c;
        if (ch == 'w' || ch == 'W') nr--;
        else if (ch == 's' || ch == 'S') nr++;
        else if (ch == 'a' || ch == 'A') nc--;
        else if (ch == 'd' || ch == 'D') nc++;

        if (nr >= 0 && nr < height && nc >= 0 && nc < width && grid[nr][nc] != WALL_CHAR) {
            player = { nr, nc };
        }
    }
    displayCurrent();
    cout << "\n[CHUC MUNG] Ban da tu giai va thoat khoi me cung thanh cong!\n";
    cout << "Nhan phim bat ky de tiep tuc...";
    _getch();
}

// Thu?t toán t? ??ng tìm ???ng b?ng BFS (Tìm ki?m theo chi?u r?ng)
void MazeGame::solveBFS(bool showVisual) {
    vector<vector<Point>> parent(height, vector<Point>(width, { -1, -1 }));
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<Point> q;

    q.push(start);
    visited[start.r][start.c] = true;

    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    bool found = false;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr == target) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < height && nc >= 0 && nc < width) {
                if (grid[nr][nc] != WALL_CHAR && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    parent[nr][nc] = curr;
                    q.push({ nr, nc });
                }
            }
        }
    }

    if (found) {
        vector<vector<char>> tempGrid = grid;
        Point curr = target;
        bfs_path_len = 0;
        while (!(curr == start)) {
            if (!(curr == target)) tempGrid[curr.r][curr.c] = ROUTE_BFS;
            curr = parent[curr.r][curr.c];
            bfs_path_len++;
        }
        if (showVisual) {
            player = start;
            display(tempGrid);
            cout << "\n[BFS SUCCESS] Tim thay duong di ngan nhat: " << bfs_path_len << " buoc (Ky hieu: .)\n";
            cout << "Nhan phim bat ky de quay lai...";
            _getch();
        }
    }
}

// Thu?t toán t? ??ng tìm ???ng b?ng DFS (Tìm ki?m theo chi?u sâu)
void MazeGame::solveDFS(bool showVisual) {
    vector<vector<Point>> parent(height, vector<Point>(width, { -1, -1 }));
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    stack<Point> s;

    s.push(start);
    visited[start.r][start.c] = true;

    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    bool found = false;

    while (!s.empty()) {
        Point curr = s.top();
        s.pop();

        if (curr == target) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < height && nc >= 0 && nc < width) {
                if (grid[nr][nc] != WALL_CHAR && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    parent[nr][nc] = curr;
                    s.push({ nr, nc });
                }
            }
        }
    }

    if (found) {
        vector<vector<char>> tempGrid = grid;
        Point curr = target;
        dfs_path_len = 0;
        while (!(curr == start)) {
            if (!(curr == target)) tempGrid[curr.r][curr.c] = ROUTE_DFS;
            curr = parent[curr.r][curr.c];
            dfs_path_len++;
        }
        if (showVisual) {
            player = start;
            display(tempGrid);
            cout << "\n[DFS SUCCESS] Tim thay duong giai bang DFS: " << dfs_path_len << " buoc (Ky hieu: *)\n";
            cout << "Nhan phim bat ky de quay lai...";
            _getch();
        }
    }
}

// Hàm so sánh chi phí ???ng ?i c?a 2 thu?t toán BFS và DFS
void MazeGame::compareAlgorithms() {
    solveBFS(false);
    solveDFS(false);

    system("cls");
    cout << "==================================================\n";
    cout << "         SO SANH THUAT TOAN: BFS VS DFS           \n";
    cout << "==================================================\n";
    cout << "1. Thuat toan BFS (Tim kiem theo chieu rong):\n";
    cout << "   - Chi phi duong di: " << bfs_path_len << " buoc.\n";
    cout << "   - Tinh toi uu: LUON dam bao tim ra duong ngan nhat.\n\n";

    cout << "2. Thuat toan DFS (Tim kiem theo chieu sau):\n";
    cout << "   - Chi phi duong di: " << dfs_path_len << " buoc.\n";
    cout << "   - Tinh toi uu: Khong dam bao ngan nhat.\n\n";

    cout << "--------------------------------------------------\n";
    cout << "=> KET LUAN: ";
    if (bfs_path_len < dfs_path_len) {
        cout << "BFS ngan hon DFS dung " << (dfs_path_len - bfs_path_len) << " buoc.\n";
    }
    else if (bfs_path_len == dfs_path_len) {
        cout << "Trong kich ban me cung nay, ca BFS va DFS ngau nhien cho ra cung do dai.\n";
    }
    else {
        cout << "Loi logic hoac do thi dac biet.\n";
    }
    cout << "==================================================\n";
    cout << "Nhan phim bat ky de ve Menu chinh...";
    _getch();
}