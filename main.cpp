#include "header.h"

int main() {
    list l;
    khoiTaoDSLK(l);
    int arr[] = { 7, 2, -3, 15, 4, -1, 9, 0, 25, -6 };
    int n = 10;
    for (int i = 0; i < n; i++) ThemCuoi(l, arr[i]);

    cout << "Danh sach ban dau: ";
    InDS(l);

    stack s;
    KhoiTaoStack(s);

    queue q;
    KhoiTaoQueue(q);

    int choice;
    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Them dau danh sach";
        cout << "\n2. Them cuoi danh sach";
        cout << "\n3. Xoa dau danh sach";
        cout << "\n4. Xoa cuoi danh sach";
        cout << "\n5. In danh sach";
        cout << "\n6. Tim max";
        cout << "\n7. Tim phan tu chan dau tien";
        cout << "\n8. Liet ke cac phan tu am";
        cout << "\n9. Tong cac phan tu duong";
        cout << "\n10. Dem so phan tu am";
        cout << "\n11. Kiem tra co so chinh phuong";
        cout << "\n12. Dem cuc dai";
        cout << "\n13. Sap xep chon truc tiep";
        cout << "\n14. Stack - Push";
        cout << "\n15. Stack - Pop";
        cout << "\n16. Stack - InStack";
        cout << "\n17. Queue - Enqueue";
        cout << "\n18. Queue - Dequeue";
        cout << "\n19. Queue - InQueue";
        cout << "\n20. Noi danh sach voi L2 = {100,200,300}";
        cout << "\n0. Thoat";
        cout << "\n================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        { 
            int x; cout << "Nhap gia tri: "; 
            cin >> x; 
            ThemDau(l, x); 
            break; 
        }
        case 2: 
        { 
            int x; cout << "Nhap gia tri: "; 
            cin >> x; 
            ThemCuoi(l, x); 
            break; 
        }
        case 3: 
            XoaDau(l); 
            break;
        case 4: 
            XoaCuoi(l); 
            break;
        case 5: 
            InDS(l); 
            break;
        case 6: 
            cout << "Max = " << TimMax(l) << "\n"; 
            break;
        case 7: 
            cout << "Phan tu chan dau tien = " << TimChanDau(l) << "\n";
            break;
        case 8: 
            LietKeAm(l); 
            break;
        case 9: 
            cout << "Tong cac phan tu duong = " << TongDuong(l) << "\n"; 
            break;
        case 10: 
            cout << "So phan tu am = " << DemAm(l) << "\n"; 
            break;
        case 11: 
            cout << (CSCP(l) ? "Co so chinh phuong\n" : "Khong co so chinh phuong\n"); 
            break;
        case 12: 
            cout << "So cuc dai = " << DemCucDai(l) << "\n"; 
            break;
        case 13: 
            ChonTrucTiep(l); cout << "Danh sach da sap xep.\n"; 
            break;
        case 14: 
            { 
                int x; cout << "Nhap gia tri: "; 
                cin >> x; 
                Push(s, x); 
                break; 
            }
        case 15: 
            cout << "Pop: " << pop(s) << "\n"; 
            break;
        case 16: 
            Instack(s); 
            break;
        case 17: 
            { 
                int x; cout << "Nhap gia tri: "; 
                cin >> x; 
                enqueue(q, x); 
                break; 
            }
        case 18: 
            cout << "Dequeue: " << Dequeue(q) << "\n"; 
            break;
        case 19: 
            InQueue(q); 
            break;
        case 20: {
            list L2; khoiTaoDSLK(L2);
            for (int x : {100, 200, 300}) ThemCuoi(L2, x);
            cout << "\nNoi L voi L2 = {100,200,300}:\n";
            NoiDS(l, L2);
            InDS(l);
            break;
        }
        case 0: cout << "Thoat chuong trinh.\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
