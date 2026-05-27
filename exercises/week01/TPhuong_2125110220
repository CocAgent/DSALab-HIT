#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Cấu trúc dữ liệu Tài sản mạng cần bảo vệ
struct TaiSanMang {
    string id;
    string tenThietBi;
    string loaiDevice; // Server, Router, Firewall, PC
    string diaChiIP;
    string trangThaiBaoMat; // "An toan", "Canh bao", "Nguy hiem"
};

// Cấu trúc dữ liệu Sự cố An ninh mạng
struct SuCoAnNinh {
    string maSuCo;
    string tenSuCo; // DDoS, Ransomware, Phishing, Malware...
    string mucDo;   // Low, Medium, High, Critical
    string thietBiAnhHuong; // IP hoặc ID tài sản
    string trangThaiXuLy; // "Chua xu ly", "Dang xu ly", "Da khac phuc"
};

// Lớp Quản lý Năng lực An ninh mạng tổng thể
class HeThongAnNinh {
private:
    vector<TaiSanMang> danhSachTaiSan;
    vector<SuCoAnNinh> danhSachSuCo;

    // Điểm số năng lực bảo mật theo khung NIST (Thang điểm 100)
    double diemPhongNgua;  // Nhận diện & Bảo vệ
    double diemPhatHien;   // Giám sát an ninh
    double diemUngPho;     // Khắc phục sự cố

public:
    // Constructor: Nạp sẵn dữ liệu giả lập hệ thống doanh nghiệp
    HeThongAnNinh() {
        diemPhongNgua = 75.0;
        diemPhatHien = 68.5;
        diemUngPho = 70.0;

        // Khởi tạo tài sản mẫu
        danhSachTaiSan.push_back({ "TS01", "Server Du Lieu Ke Toan", "Server", "192.168.1.10", "An toan" });
        danhSachTaiSan.push_back({ "TS02", "Firewall GateWay Chinh", "Firewall", "192.168.1.1", "Canh bao" });
        danhSachTaiSan.push_back({ "TS03", "Core Router Tang 1", "Router", "192.168.1.2", "An toan" });
        danhSachTaiSan.push_back({ "TS04", "May Tram CEO", "PC", "192.168.1.50", "Nguy hiem" });

        // Khởi tạo sự cố mẫu
        danhSachSuCo.push_back({ "SC01", "Tan cong DDoS vao Web", "High", "192.168.1.1", "Dang xu ly" });
        danhSachSuCo.push_back({ "SC02", "Phat hien Ma doc Tong tien", "Critical", "192.168.1.50", "Chua xu ly" });
    }

    // 1. Hiển thị trạng thái các tài sản mạng
    void hienThiTaiSan() {
        cout << "\n======================= TRẠNG THÁI TÀI SẢN MẠNG =======================\n";
        cout << left << setw(8) << "ID" << setw(28) << "Tên Thiết Bị" << setw(12) << "Loại" << setw(16) << "Địa chỉ IP" << "Trạng Thái" << endl;
        cout << "-----------------------------------------------------------------------\n";
        for (const auto& ts : danhSachTaiSan) {
            cout << left << setw(8) << ts.id
                << setw(28) << ts.tenThietBi
                << setw(12) << ts.loaiDevice
                << setw(16) << ts.diaChiIP
                << ts.trangThaiBaoMat << endl;
        }
        cout << "=======================================================================\n";
    }

    // 2. Ghi nhận sự cố an ninh mạng mới (SIEM Log)
    void ghiNhanSuCo() {
        SuCoAnNinh sc;
        cout << "\n--- GHI NHẬN SỰ CỐ AN NINH MỚI ---\n";
        sc.maSuCo = "SC" + to_string(100 + danhSachSuCo.size() + 1);

        cin.ignore();
        cout << "Nhập tên loại hình tấn công (ví dụ: Phishing, Brute Force): ";
        getline(cin, sc.tenSuCo);

        cout << "Mức độ nghiêm trọng (Low / Medium / High / Critical): ";
        cin >> sc.mucDo;

        cout << "IP thiết bị/hệ thống bị ảnh hưởng: ";
        cin >> sc.thietBiAnhHuong;

        sc.trangThaiXuLy = "Chua xu ly";

        // Cập nhật trạng thái thiết bị tương ứng sang cảnh báo/nguy hiểm
        for (auto& ts : danhSachTaiSan) {
            if (ts.diaChiIP == sc.thietBiAnhHuong) {
                if (sc.mucDo == "Critical" || sc.mucDo == "High") {
                    ts.trangThaiBaoMat = "Nguy hiem";
                }
                else {
                    ts.trangThaiBaoMat = "Canh bao";
                }
            }
        }

        danhSachSuCo.push_back(sc);
        cout << "=> Hệ thống SOC đã ghi nhận sự cố thành công với mã: " << sc.maSuCo << endl;
    }

    // 3. Xử lý và khắc phục sự cố (Incident Response)
    void xuLySuCo() {
        if (danhSachSuCo.empty()) {
            cout << "=> Không có sự cố nào cần xử lý trên hệ thống.\n";
            return;
        }

        string maTim;
        cout << "\nNhập Mã Sự Cố cần xử lý/cập nhật trạng thái: ";
        cin >> maTim;

        for (auto& sc : danhSachSuCo) {
            if (sc.maSuCo == maTim) {
                cout << "Sự cố tìm thấy: " << sc.tenSuCo << " [" << sc.trangThaiXuLy << "]\n";
                cout << "Cập nhật trạng thái mới:\n1. Dang xu ly\n2. Da khac phuc (An toan)\nChọn (1-2): ";
                int chon;
                cin >> chon;

                if (chon == 1) {
                    sc.trangThaiXuLy = "Dang xu ly";
                }
                else if (chon == 2) {
                    sc.trangThaiXuLy = "Da khac phuc";
                    // Khôi phục trạng thái tài sản về an toàn
                    for (auto& ts : danhSachTaiSan) {
                        if (ts.diaChiIP == sc.thietBiAnhHuong) {
                            ts.trangThaiBaoMat = "An toan";
                        }
                    }
                    // Tăng điểm năng lực ứng phó khi xử lý thành công sự cố
                    if (diemUngPho < 98.0) diemUngPho += 1.5;
                }
                cout << "=> Cập nhật tiến trình xử lý sự cố thành công!\n";
                return;
            }
        }
        cout << "=> Không tìm thấy Mã Sự Cố hợp lệ!\n";
    }

    // 4. Đánh giá và nâng cấp điểm năng lực an ninh (Security Assessment)
    void danhGiaVaNângCap() {
        double diemTrungBinh = (diemPhongNgua + diemPhatHien + diemUngPho) / 3.0;

        cout << "\n================ ĐÁNH GIÁ NĂNG LỰC AN NINH (NIST) ================\n";
        cout << "+ 1. Năng lực Phòng ngừa (Identify & Protect): " << fixed << setprecision(1) << diemPhongNgua << "/100\n";
        cout << "+ 2. Năng lực Phát hiện (Detect/SIEM):         " << diemPhatHien << "/100\n";
        cout << "+ 3. Năng lực Ứng phó & Phục hồi (Respond):    " << diemUngPho << "/100\n";
        cout << "------------------------------------------------------------------\n";
        cout << "=> ĐIỂM CHỈ SỐ AN TOÀN HỆ THỐNG TỔNG THỂ: " << diemTrungBinh << "/100\n";

        cout << "\nXếp hạng năng lực phòng thủ: ";
        if (diemTrungBinh >= 85) cout << "TỐT (Đủ khả năng chống chịu APT nâng cao)\n";
        else if (diemTrungBinh >= 70) cout << "TRUNG BÌNH (Cần vá bảo mật và cập nhật chính sách)\n";
        else cout << "YẾU (Nguy cơ bị Ransomware/Tấn công phá hoại cao)\n";
        cout << "------------------------------------------------------------------\n";

        cout << "Bạn có muốn nâng cấp năng lực hệ thống không?\n";
        cout << "1. Diễn tập ứng phó sự cố (+Phòng ngừa)\n";
        cout << "2. Triển khai thêm hệ thống EDR/SOC mới (+Phát hiện)\n";
        cout << "3. Bỏ qua\nLựa chọn: ";
        int lc; cin >> lc;
        if (lc == 1) {
            if (diemPhongNgua <= 95) diemPhongNgua += 3.5;
            cout << "=> Điểm phòng ngừa tăng lên: " << diemPhongNgua << endl;
        }
        else if (lc == 2) {
            if (diemPhatHien <= 95) diemPhatHien += 4.0;
            cout << "=> Điểm phát hiện tăng lên: " << diemPhatHien << endl;
        }
    }

    // 5. Thống kê tình hình an ninh mạng hiện tại
    void thongKeBaoCao() {
        int chuaXuLy = 0, dangXuLy = 0, daKhacPhuc = 0;
        int nguyHiem = 0;

        for (const auto& sc : danhSachSuCo) {
            if (sc.trangThaiXuLy == "Chua xu ly") chuaXuLy++;
            else if (sc.trangThaiXuLy == "Dang xu ly") dangXuLy++;
            else if (sc.trangThaiXuLy == "Da khac phuc") daKhacPhuc++;
        }

        for (const auto& ts : danhSachTaiSan) {
            if (ts.trangThaiBaoMat == "Nguy hiem") nguyHiem++;
        }

        cout << "\n================ THỐNG KÊ TÌNH HÌNH AN NINH MẠNG ================\n";
        cout << " Tổng số sự cố ghi nhận hệ thống: " << danhSachSuCo.size() << endl;
        cout << "  - Số sự cố chưa xử lý  [!]     : " << chuaXuLy << endl;
        cout << "  - Số sự cố đang xử lý  [...]   : " << dangXuLy << endl;
        cout << "  - Số sự cố đã khắc phục [v]    : " << daKhacPhuc << endl;
        cout << "-----------------------------------------------------------------\n";
        cout << " Số lượng tài sản đang ở trạng thái NGUY HIỂM: " << nguyHiem << " thiết bị.\n";
        cout << "=================================================================\n";
    }

    // 6. Xuất báo cáo kiểm toán an ninh ra file để báo cáo cấp trên
    void xuatBaoCaoFile() {
        ofstream fileOut("baocao_anninh.txt");
        if (!fileOut) {
            cout << "=> Lỗi: Không thể khởi tạo file báo cáo!\n";
            return;
        }

        fileOut << "===================================================================\n";
        fileOut << "               BÁO CÁO KIỂM TOÁN AN NINH MẠNG DOANH NGHIỆP         \n";
        fileOut << "===================================================================\n\n";

        fileOut << "[1] CHỈ SỐ NĂNG LỰC PHÒNG THỦ (NIST):\n";
        fileOut << " - Phòng ngừa: " << diemPhongNgua << "/100\n";
        fileOut << " - Phát hiện : " << diemPhatHien << "/100\n";
        fileOut << " - Ứng phó   : " << diemUngPho << "/100\n\n";

        fileOut << "[2] DANH SÁCH SỰ CỐ AN NINH ĐANG GHI NHẬN TRÊN HỆ THỐNG:\n";
        fileOut << left << setw(10) << "Mã SC" << setw(25) << "Loại Tấn Công" << setw(15) << "Mức Độ" << setw(18) << "IP Ảnh Hưởng" << "Trạng Thái" << endl;
        fileOut << "--------------------------------------------------------------------------------\n";
        for (const auto& sc : danhSachSuCo) {
            fileOut << left << setw(10) << sc.maSuCo
                << setw(25) << sc.tenSuCo
                << setw(15) << sc.mucDo
                << setw(18) << sc.thietBiAnhHuong
                << sc.trangThaiXuLy << endl;
        }

        fileOut << "\n===================== KẾT THÚC BÁO CÁO =====================\n";
        fileOut.close();
        cout << "=> Đã kết xuất báo cáo an ninh mạng thành công ra file 'baocao_anninh.txt'!\n";
    }
};

// --- CHƯƠNG TRÌNH CHÍNH ĐIỀU KHIỂN SỬ DỤNG HỆ THỐNG ---
#include <Windows.h>
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    HeThongAnNinh soc;
    int luaChon;

    do {
        cout << "\n================ TRUNG TÂM ĐIỀU HÀNH AN NINH MẠNG (SOC) ================\n";
        cout << "1. Giám sát trạng thái an toàn các tài sản mạng (Assets)\n";
        cout << "2. Ghi nhận mã sự cố / Cảnh báo tấn công mới (SIEM Log)\n";
        cout << "3. Điều phối phản ứng & khắc phục sự cố (Incident Response)\n";
        cout << "4. Kiểm tra chỉ số đánh giá năng lực an ninh mạng (NIST Framework)\n";
        cout << "5. Thống kê tổng quan rủi ro & tình hình hệ thống\n";
        cout << "6. Xuất file báo cáo kiểm toán bảo mật 'baocao_anninh.txt'\n";
        cout << "0. Đóng hệ thống SOC\n";
        cout << "========================================================================\n";
        cout << "Vui lòng nhập nghiệp vụ cần xử lý (0-6): ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            soc.hienThiTaiSan();
            break;
        case 2:
            soc.ghiNhanSuCo();
            break;
        case 3:
            soc.xuLySuCo();
            break;
        case 4:
            soc.danhGiaVaNângCap();
            break;
        case 5:
            soc.thongKeBaoCao();
            break;
        case 6:
            soc.xuatBaoCaoFile();
            break;
        case 0:
            cout << "\n[!] Hệ thống giám sát an ninh mạng đang tắt. Goodbye!\n";
            break;
        default:
            cout << "=> Lựa chọn không hợp lệ. Vui lòng nhập lại số trong danh mục từ 0 đến 6.\n";
        }
    } while (luaChon != 0);

    return 0;
}
