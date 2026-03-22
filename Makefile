# ================================================================
#  Makefile — DSALab: Cau Truc Du Lieu & Giai Thuat (C++17)
#  GitHub: https://github.com/CocAgent/DSALab
# ================================================================

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I./src/Utils
BINDIR   = bin

# Tao thu muc bin neu chua co
$(shell mkdir -p $(BINDIR))

# ================================================================
#  BUILD TARGETS
# ================================================================
.PHONY: all ch1 ch2 ch3 ch4 ch5 ch6 apps clean test help

all: ch1 ch2 ch3 ch4 ch5 ch6
	@echo ""
	@echo "  ✅ Build thanh cong tat ca 6 chuong!"
	@echo "  Chay: make test"

ch1:
	@echo "  [CH1] Building Chapter 1: Tong Quan CTDL & GT..."
	@$(CXX) $(CXXFLAGS) src/Chapter1_Overview/Chapter1_Overview.cpp -o $(BINDIR)/ch1
	@echo "  ✅ ch1 OK"

ch2:
	@echo "  [CH2] Building Chapter 2: Tim Kiem & Sap Xep..."
	@$(CXX) $(CXXFLAGS) src/Chapter2_SearchSort/Chapter2_SearchSort.cpp -o $(BINDIR)/ch2
	@echo "  ✅ ch2 OK"

ch3:
	@echo "  [CH3] Building Chapter 3: Danh Sach Lien Ket..."
	@$(CXX) $(CXXFLAGS) src/Chapter3_LinkedList/Chapter3_LinkedList.cpp -o $(BINDIR)/ch3 -lm
	@echo "  ✅ ch3 OK"

ch4:
	@echo "  [CH4] Building Chapter 4: Cau Truc Cay..."
	@$(CXX) $(CXXFLAGS) src/Chapter4_Tree/Chapter4_Tree.cpp -o $(BINDIR)/ch4
	@echo "  ✅ ch4 OK"

ch5:
	@echo "  [CH5] Building Chapter 5: Do Thi (Graph)..."
	@$(CXX) $(CXXFLAGS) src/Chapter5_Graph/Chapter5_Graph.cpp -o $(BINDIR)/ch5
	@echo "  ✅ ch5 OK"

ch6:
	@echo "  [CH6] Building Chapter 6: Quy Hoach Dong (DP)..."
	@$(CXX) $(CXXFLAGS) src/Chapter6_DynamicProgramming/Chapter6_DP.cpp -o $(BINDIR)/ch6
	@echo "  ✅ ch6 OK"

# ================================================================
#  CHAY DEMO
# ================================================================
test: all
	@echo ""
	@echo "================================================================"
	@echo "  CHAY DEMO TU DONG — DSALab"
	@echo "================================================================"
	@echo "\n--- CHAPTER 1: TONG QUAN ---"
	@echo "0" | ./$(BINDIR)/ch1
	@echo "\n--- CHAPTER 2: TIM KIEM & SAP XEP ---"
	@echo "55" | ./$(BINDIR)/ch2
	@echo "\n--- CHAPTER 3: DANH SACH LIEN KET ---"
	@./$(BINDIR)/ch3
	@echo "\n--- CHAPTER 4: CAU TRUC CAY ---"
	@./$(BINDIR)/ch4
	@echo "\n--- CHAPTER 5: DO THI ---"
	@./$(BINDIR)/ch5
	@echo "\n--- CHAPTER 6: QUY HOACH DONG ---"
	@./$(BINDIR)/ch6

# ================================================================
#  DON DEP
# ================================================================
clean:
	@rm -f $(BINDIR)/*
	@echo "  Cleaned bin/"

# ================================================================
#  TRO GIUP
# ================================================================
help:
	@echo ""
	@echo "  DSALab — Cau Truc Du Lieu & Giai Thuat (C++17)"
	@echo "  ================================================"
	@echo "  make all    — Build tat ca 6 chuong"
	@echo "  make ch1    — Chapter 1: Tong Quan CTDL & GT"
	@echo "  make ch2    — Chapter 2: Tim Kiem & Sap Xep"
	@echo "  make ch3    — Chapter 3: Danh Sach Lien Ket"
	@echo "  make ch4    — Chapter 4: Cau Truc Cay (BST)"
	@echo "  make ch5    — Chapter 5: Do Thi (Graph)"
	@echo "  make ch6    — Chapter 6: Quy Hoach Dong (DP)"
	@echo "  make test   — Chay demo tat ca chuong"
	@echo "  make clean  — Xoa file binary"
	@echo ""
