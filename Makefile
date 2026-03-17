# ============================================================
#  Makefile - Du an: Cau truc du lieu & Giai thuat
#  Giao trinh: CD Cong Thuong TP.HCM - 2025
# ============================================================

CXX     = g++
CXXFLAGS = -std=c++17 -Wall -I./include

all: Chuong1 Chuong2 Chuong3 Chuong4 TongHop
	@echo "==> Build thanh cong tat ca cac chuong!"

Chuong1:
	$(CXX) $(CXXFLAGS) Chuong1_TongQuan/Chuong1_TongQuan.cpp -o bin/Chuong1

Chuong2:
	$(CXX) $(CXXFLAGS) Chuong2_TimKiem_SapXep/Chuong2_TimKiem_SapXep.cpp -o bin/Chuong2

Chuong3:
	$(CXX) $(CXXFLAGS) Chuong3_DanhSachLienKet/Chuong3_DanhSachLienKet.cpp -o bin/Chuong3 -lm

Chuong4:
	$(CXX) $(CXXFLAGS) Chuong4_CauTrucCay/Chuong4_CauTrucCay.cpp -o bin/Chuong4

TongHop:
	$(CXX) $(CXXFLAGS) BaiTapTongHop/BaiTapTongHop.cpp -o bin/TongHop

clean:
	rm -f bin/*

run_all: all
	@echo "\n========== CHUONG 1 =========="; ./bin/Chuong1
	@echo "\n========== CHUONG 2 =========="; echo "5" | ./bin/Chuong2
	@echo "\n========== CHUONG 3 =========="; ./bin/Chuong3
	@echo "\n========== CHUONG 4 =========="; ./bin/Chuong4
	@echo "\n========== TONG HOP =========="; ./bin/TongHop
