#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* prev;
    Song* next;
};

struct Playlist {
    Song* head = nullptr;
    Song* tail = nullptr;
    Song* current = nullptr;
};

// Tạo bài hát
Song* createSong(string name) {
    Song* s = new Song;
    s->name = name;
    s->prev = s->next = nullptr;
    return s;
}

// Thêm bài vào cuối
void addSong(Playlist& pl, string name) {
    Song* s = createSong(name);
    if (!pl.head) {
        pl.head = pl.tail = pl.current = s;
    }
    else {
        pl.tail->next = s;
        s->prev = pl.tail;
        pl.tail = s;
    }
}

// Xóa bài
void removeSong(Playlist& pl, string name) {
    Song* temp = pl.head;
    while (temp) {
        if (temp->name == name) {
            if (temp == pl.head) pl.head = temp->next;
            if (temp == pl.tail) pl.tail = temp->prev;

            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;

            if (pl.current == temp)
                pl.current = temp->next ? temp->next : temp->prev;

            delete temp;
            cout << "Da xoa!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Khong tim thay!\n";
}

// Hiển thị playlist
void showPlaylist(Playlist pl) {
    Song* temp = pl.head;
    cout << "\nPlaylist:\n";
    while (temp) {
        if (temp == pl.current)
            cout << "-> ";
        else
            cout << "   ";
        cout << temp->name << endl;
        temp = temp->next;
    }
}

// Next
void nextSong(Playlist& pl) {
    if (pl.current && pl.current->next)
        pl.current = pl.current->next;
}

// Previous
void prevSong(Playlist& pl) {
    if (pl.current && pl.current->prev)
        pl.current = pl.current->prev;
}

// Play current
void playCurrent(Playlist pl) {
    if (pl.current)
        cout << "Dang phat: " << pl.current->name << endl;
    else
        cout << "Playlist rong!\n";
}

int main() {
    Playlist pl;
    int choice;
    string name;

    do {
        cout << "\n=== PLAYLIST MANAGER ===\n";
        cout << "1. Them bai hat\n";
        cout << "2. Xoa bai hat\n";
        cout << "3. Hien thi playlist\n";
        cout << "4. Next\n";
        cout << "5. Previous\n";
        cout << "6. Phat bai hien tai\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Nhap ten bai: ";
            getline(cin, name);
            addSong(pl, name);
            break;
        case 2:
            cout << "Nhap ten bai can xoa: ";
            getline(cin, name);
            removeSong(pl, name);
            break;
        case 3:
            showPlaylist(pl);
            break;
        case 4:
            nextSong(pl);
            break;
        case 5:
            prevSong(pl);
            break;
        case 6:
            playCurrent(pl);
            break;
        }

    } while (choice != 0);

    return 0;
}
