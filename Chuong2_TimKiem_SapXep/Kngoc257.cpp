<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Chương 2 – Tìm Kiếm & Sắp Xếp</title>
<link href="https://fonts.googleapis.com/css2?family=Space+Mono:wght@400;700&family=Syne:wght@400;600;800&display=swap" rel="stylesheet">
<style>
  :root {
    --bg: #0a0a0f;
    --panel: #13131a;
    --border: #22223a;
    --accent: #7c3aed;
    --accent2: #06b6d4;
    --accent3: #f59e0b;
    --green: #10b981;
    --red: #ef4444;
    --text: #e2e8f0;
    --muted: #64748b;
    --bar-default: #2d2d4e;
    --bar-active: #7c3aed;
    --bar-compare: #06b6d4;
    --bar-sorted: #10b981;
    --bar-found: #f59e0b;
    --bar-pivot: #f97316;
  }
  *, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }
  html { scroll-behavior: smooth; }
  body {
    background: var(--bg);
    color: var(--text);
    font-family: 'Syne', sans-serif;
    min-height: 100vh;
    overflow-x: hidden;
  }

  /* ── HEADER ── */
  header {
    padding: 28px 40px 20px;
    border-bottom: 1px solid var(--border);
    display: flex; align-items: center; gap: 20px;
    background: linear-gradient(90deg, #0a0a0f 0%, #110a1f 100%);
  }
  .logo {
    width: 44px; height: 44px;
    background: var(--accent);
    border-radius: 10px;
    display: grid; place-items: center;
    font-family: 'Space Mono', monospace;
    font-size: 18px; font-weight: 700;
    color: #fff;
    flex-shrink: 0;
  }
  header h1 { font-size: 1.4rem; font-weight: 800; letter-spacing: -0.02em; }
  header p { font-size: 0.78rem; color: var(--muted); margin-top: 2px; font-family: 'Space Mono', monospace; }

  /* ── TABS ── */
  .tabs {
    display: flex; gap: 4px;
    padding: 16px 40px 0;
    border-bottom: 1px solid var(--border);
    background: var(--bg);
    overflow-x: auto;
  }
  .tab-btn {
    padding: 10px 22px;
    border: none; border-bottom: 3px solid transparent;
    background: transparent;
    color: var(--muted);
    font-family: 'Syne', sans-serif; font-size: 0.88rem; font-weight: 600;
    cursor: pointer; transition: all .2s; white-space: nowrap;
  }
  .tab-btn:hover { color: var(--text); }
  .tab-btn.active { color: var(--accent); border-bottom-color: var(--accent); }

  /* ── LAYOUT ── */
  .page { display: none; padding: 32px 40px; max-width: 1200px; }
  .page.active { display: block; }

  /* ── SECTION TITLE ── */
  .section-title {
    font-size: 1.1rem; font-weight: 800; letter-spacing: -.01em;
    color: var(--text); margin-bottom: 6px;
  }
  .section-sub {
    font-size: 0.78rem; color: var(--muted);
    font-family: 'Space Mono', monospace; margin-bottom: 24px;
  }

  /* ── CARD ── */
  .card {
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 14px;
    padding: 24px;
    margin-bottom: 24px;
  }
  .card-title {
    font-size: 0.9rem; font-weight: 700;
    color: var(--accent2); margin-bottom: 16px;
    text-transform: uppercase; letter-spacing: .08em;
    font-family: 'Space Mono', monospace;
  }

  /* ── CONTROLS ── */
  .controls { display: flex; flex-wrap: wrap; gap: 10px; margin-bottom: 20px; align-items: center; }
  .btn {
    padding: 9px 20px; border-radius: 8px; border: none;
    font-family: 'Syne', sans-serif; font-weight: 600; font-size: 0.85rem;
    cursor: pointer; transition: all .18s;
    display: inline-flex; align-items: center; gap: 7px;
  }
  .btn-primary { background: var(--accent); color: #fff; }
  .btn-primary:hover { background: #6d28d9; }
  .btn-secondary { background: var(--border); color: var(--text); }
  .btn-secondary:hover { background: #2d2d4e; }
  .btn-green { background: var(--green); color: #fff; }
  .btn-green:hover { background: #059669; }
  .btn-cyan { background: var(--accent2); color: #000; }
  .btn-cyan:hover { background: #0891b2; }
  .btn-amber { background: var(--accent3); color: #000; }
  .btn-amber:hover { background: #d97706; }
  .btn:disabled { opacity: .4; cursor: not-allowed; }

  input[type=number], input[type=text], select {
    background: #1a1a2e; border: 1px solid var(--border);
    color: var(--text); border-radius: 8px;
    padding: 9px 14px; font-family: 'Space Mono', monospace; font-size: 0.83rem;
    outline: none; transition: border .18s;
    -moz-appearance: textfield;
  }
  input[type=number]::-webkit-outer-spin-button,
  input[type=number]::-webkit-inner-spin-button { -webkit-appearance: none; }
  input:focus, select:focus { border-color: var(--accent); }
  label { font-size: 0.82rem; color: var(--muted); font-family: 'Space Mono', monospace; }

  /* ── ARRAY DISPLAY ── */
  .array-wrap {
    display: flex; flex-wrap: wrap; gap: 6px;
    min-height: 50px; align-items: center;
    margin-bottom: 16px;
  }
  .arr-cell {
    width: 48px; height: 48px;
    border-radius: 8px;
    background: var(--bar-default);
    display: flex; flex-direction: column; align-items: center; justify-content: center;
    font-family: 'Space Mono', monospace;
    font-size: 0.88rem; font-weight: 700;
    transition: background .25s, transform .2s;
    position: relative;
    border: 2px solid transparent;
  }
  .arr-cell .idx {
    font-size: 0.55rem; color: var(--muted); font-weight: 400;
    position: absolute; bottom: 3px; right: 5px;
  }
  .arr-cell.active   { background: var(--bar-active); border-color: var(--accent); transform: translateY(-4px); }
  .arr-cell.compare  { background: var(--bar-compare); border-color: var(--accent2); transform: translateY(-4px); }
  .arr-cell.sorted   { background: var(--bar-sorted); border-color: var(--green); }
  .arr-cell.found    { background: var(--bar-found); border-color: var(--accent3); transform: scale(1.15); }
  .arr-cell.pivot    { background: var(--bar-pivot); border-color: #f97316; transform: translateY(-6px); }
  .arr-cell.searching { animation: pulse 0.5s ease-in-out; }
  @keyframes pulse { 0%,100%{transform:scale(1)} 50%{transform:scale(1.2)} }

  /* ── BAR CHART VISUAL ── */
  .bar-wrap {
    display: flex; align-items: flex-end; gap: 4px;
    height: 200px; padding: 0 4px;
    margin-bottom: 16px; border-bottom: 2px solid var(--border);
  }
  .bar {
    flex: 1; background: var(--bar-default); border-radius: 4px 4px 0 0;
    transition: height .25s ease, background .25s;
    position: relative; display: flex; align-items: flex-end; justify-content: center;
    padding-bottom: 2px;
  }
  .bar span { font-size: 0.6rem; font-family: 'Space Mono', monospace; color: rgba(255,255,255,.5); }
  .bar.active  { background: var(--bar-active); }
  .bar.compare { background: var(--bar-compare); }
  .bar.sorted  { background: var(--bar-sorted); }
  .bar.pivot   { background: var(--bar-pivot); }
  .bar.found   { background: var(--bar-found); }

  /* ── LOG ── */
  .log-box {
    background: #0d0d18;
    border: 1px solid var(--border);
    border-radius: 8px;
    padding: 14px;
    font-family: 'Space Mono', monospace;
    font-size: 0.76rem;
    max-height: 140px;
    overflow-y: auto;
    line-height: 1.7;
  }
  .log-box p { margin: 0; }
  .log-box .log-step { color: var(--muted); }
  .log-box .log-swap { color: var(--accent); }
  .log-box .log-found { color: var(--green); font-weight: 700; }
  .log-box .log-notfound { color: var(--red); }
  .log-box .log-info { color: var(--accent2); }
  .log-box .log-pivot { color: var(--bar-pivot); }

  /* ── SPEED SLIDER ── */
  .speed-wrap { display: flex; align-items: center; gap: 10px; }
  input[type=range] {
    -webkit-appearance: none; appearance: none;
    width: 110px; height: 4px;
    background: var(--border); border-radius: 2px; outline: none;
  }
  input[type=range]::-webkit-slider-thumb {
    -webkit-appearance: none; width: 14px; height: 14px;
    border-radius: 50%; background: var(--accent); cursor: pointer;
  }

  /* ── LEGEND ── */
  .legend { display: flex; flex-wrap: wrap; gap: 14px; margin-bottom: 14px; }
  .leg-item { display: flex; align-items: center; gap: 6px; font-size: 0.75rem; color: var(--muted); font-family: 'Space Mono', monospace; }
  .leg-dot { width: 12px; height: 12px; border-radius: 3px; }

  /* ── BADGE ── */
  .badge {
    display: inline-block; padding: 3px 10px; border-radius: 20px;
    font-size: 0.72rem; font-family: 'Space Mono', monospace; font-weight: 700;
  }
  .badge-purple { background: rgba(124,58,237,.2); color: var(--accent); border: 1px solid var(--accent); }
  .badge-cyan   { background: rgba(6,182,212,.2); color: var(--accent2); border: 1px solid var(--accent2); }
  .badge-green  { background: rgba(16,185,129,.2); color: var(--green); border: 1px solid var(--green); }

  /* ── GRID ── */
  .grid2 { display: grid; grid-template-columns: 1fr 1fr; gap: 20px; }
  @media(max-width:700px){ .grid2{grid-template-columns:1fr;} .page{padding:20px;} header{padding:16px 20px;} .tabs{padding:12px 20px 0;} }

  /* ── STAT BOX ── */
  .stat-row { display: flex; gap: 16px; flex-wrap: wrap; margin-bottom: 16px; }
  .stat-box {
    flex: 1; min-width: 100px;
    background: #1a1a2e; border: 1px solid var(--border); border-radius: 10px;
    padding: 14px; text-align: center;
  }
  .stat-box .val { font-size: 1.6rem; font-weight: 800; font-family: 'Space Mono', monospace; }
  .stat-box .lbl { font-size: 0.7rem; color: var(--muted); margin-top: 4px; font-family: 'Space Mono', monospace; }

  /* ── ALGO SELECT ── */
  .algo-grid { display: flex; flex-wrap: wrap; gap: 8px; margin-bottom: 20px; }
  .algo-card {
    padding: 10px 18px; border-radius: 10px;
    border: 2px solid var(--border);
    background: var(--panel); cursor: pointer;
    transition: all .18s; font-size: 0.82rem; font-weight: 600;
    text-align: center;
  }
  .algo-card:hover { border-color: var(--accent); color: var(--accent); }
  .algo-card.selected { border-color: var(--accent); background: rgba(124,58,237,.15); color: var(--accent); }
  .algo-card small { display: block; font-size: 0.68rem; color: var(--muted); font-family:'Space Mono',monospace; margin-top:2px; font-weight:400; }

  /* ── BT PAGE ── */
  .bt-card {
    background: var(--panel); border: 1px solid var(--border); border-radius: 12px;
    padding: 20px; margin-bottom: 16px;
  }
  .bt-header { display: flex; align-items: center; gap: 12px; margin-bottom: 14px; }
  .bt-num {
    width: 32px; height: 32px; border-radius: 8px;
    background: var(--accent); display: grid; place-items: center;
    font-weight: 800; font-size: 0.9rem; flex-shrink:0;
  }
  .bt-title { font-weight: 700; font-size: 0.95rem; }
  .bt-result {
    background: #0d0d18; border: 1px solid var(--border); border-radius: 8px;
    padding: 12px; font-family: 'Space Mono', monospace; font-size: 0.8rem;
    min-height: 40px; color: var(--accent2); display: none;
  }
  .bt-result.show { display: block; }

  /* Scrollbar */
  ::-webkit-scrollbar { width: 6px; height: 6px; }
  ::-webkit-scrollbar-track { background: var(--bg); }
  ::-webkit-scrollbar-thumb { background: var(--border); border-radius: 3px; }
</style>
</head>
<body>

<!-- HEADER -->
<header>
  <div class="logo">C2</div>
  <div>
    <h1>Tìm Kiếm &amp; Sắp Xếp</h1>
    <p>Cấu Trúc Dữ Liệu &amp; Giải Thuật — CDCTTP.HCM</p>
  </div>
</header>

<!-- TABS -->
<div class="tabs">
  <button class="tab-btn active" onclick="switchTab('sort')">⬆ Sắp Xếp</button>
  <button class="tab-btn" onclick="switchTab('search')">🔍 Tìm Kiếm</button>
  <button class="tab-btn" onclick="switchTab('bt')">📝 Bài Tập</button>
  <button class="tab-btn" onclick="switchTab('compare')">⚡ So Sánh</button>
</div>

<!-- ═══════════════════════════════════════════════
     PAGE: SẮP XẾP
═══════════════════════════════════════════════ -->
<div id="page-sort" class="page active">
  <div class="section-title">Trực Quan Sắp Xếp</div>
  <div class="section-sub">Chọn thuật toán → Tạo mảng → Chạy từng bước</div>

  <!-- Chọn thuật toán -->
  <div class="algo-grid" id="algoGrid">
    <div class="algo-card selected" data-algo="selection" onclick="selectAlgo(this)">
      Selection Sort
      <small>O(N²)</small>
    </div>
    <div class="algo-card" data-algo="insertion" onclick="selectAlgo(this)">
      Insertion Sort
      <small>O(N²)</small>
    </div>
    <div class="algo-card" data-algo="bubble" onclick="selectAlgo(this)">
      Bubble Sort
      <small>O(N²)</small>
    </div>
    <div class="algo-card" data-algo="quick" onclick="selectAlgo(this)">
      Quick Sort
      <small>O(N log N)</small>
    </div>
    <div class="algo-card" data-algo="heap" onclick="selectAlgo(this)">
      Heap Sort
      <small>O(N log N)</small>
    </div>
  </div>

  <div class="card">
    <div class="card-title">⚙ Cấu hình mảng</div>
    <div class="controls">
      <div>
        <label>Kích thước</label><br>
        <input type="number" id="arrSize" value="12" min="4" max="20" style="width:80px">
      </div>
      <div>
        <label>Nhập tay (cách nhau bởi dấu phẩy)</label><br>
        <input type="text" id="arrCustom" placeholder="64,25,12,22,11,90,45,33" style="width:260px">
      </div>
      <div style="align-self:flex-end">
        <button class="btn btn-secondary" onclick="genRandom()">🎲 Ngẫu nhiên</button>
        <button class="btn btn-cyan" onclick="loadCustom()">Dùng mảng tự nhập</button>
      </div>
    </div>

    <div class="controls">
      <button class="btn btn-primary" id="btnRun" onclick="runSort()">▶ Chạy</button>
      <button class="btn btn-secondary" id="btnStep" onclick="stepSort()">⏭ Bước tiếp</button>
      <button class="btn btn-secondary" onclick="resetSort()">↺ Reset</button>
      <div class="speed-wrap">
        <label>Tốc độ</label>
        <input type="range" id="speed" min="50" max="900" value="500">
        <span id="speedLabel" style="font-size:.75rem;color:var(--muted);font-family:'Space Mono',monospace">500ms</span>
      </div>
    </div>

    <div class="legend">
      <div class="leg-item"><div class="leg-dot" style="background:var(--bar-active)"></div> Đang xét</div>
      <div class="leg-item"><div class="leg-dot" style="background:var(--bar-compare)"></div> So sánh</div>
      <div class="leg-item"><div class="leg-dot" style="background:var(--bar-pivot)"></div> Pivot</div>
      <div class="leg-item"><div class="leg-dot" style="background:var(--bar-sorted)"></div> Đã xếp</div>
    </div>

    <!-- Bar chart -->
    <div class="bar-wrap" id="barWrap"></div>

    <!-- Array cells -->
    <div class="array-wrap" id="sortArr"></div>

    <!-- Stats -->
    <div class="stat-row">
      <div class="stat-box"><div class="val" id="statSwaps" style="color:var(--accent)">0</div><div class="lbl">Hoán vị</div></div>
      <div class="stat-box"><div class="val" id="statComps" style="color:var(--accent2)">0</div><div class="lbl">So sánh</div></div>
      <div class="stat-box"><div class="val" id="statStep" style="color:var(--accent3)">0</div><div class="lbl">Bước</div></div>
      <div class="stat-box"><div class="val" id="statStatus" style="color:var(--green);font-size:.9rem">–</div><div class="lbl">Trạng thái</div></div>
    </div>

    <!-- Log -->
    <div class="log-box" id="sortLog"><p class="log-step">Chọn thuật toán và nhấn Chạy...</p></div>
  </div>
</div>

<!-- ═══════════════════════════════════════════════
     PAGE: TÌM KIẾM
═══════════════════════════════════════════════ -->
<div id="page-search" class="page">
  <div class="section-title">Trực Quan Tìm Kiếm</div>
  <div class="section-sub">Tìm kiếm Tuyến tính O(N) và Nhị phân O(log N)</div>

  <div class="grid2">
    <!-- TÌM TUYẾN TÍNH -->
    <div class="card">
      <div class="card-title">🔎 Tìm kiếm tuyến tính</div>
      <div style="margin-bottom:14px;font-size:.82rem;color:var(--muted)">
        Duyệt từng phần tử từ đầu đến cuối. Hoạt động trên mảng chưa sắp xếp.
      </div>
      <div class="controls">
        <div>
          <label>Mảng (cách bởi dấu phẩy)</label><br>
          <input type="text" id="llArr" value="64,25,12,22,11,90,45,33" style="width:100%">
        </div>
      </div>
      <div class="controls">
        <div>
          <label>Tìm x =</label><br>
          <input type="number" id="llX" value="22" style="width:80px">
        </div>
        <div style="align-self:flex-end">
          <button class="btn btn-primary" onclick="runLinear()">▶ Tìm kiếm</button>
          <button class="btn btn-secondary" onclick="resetLinear()">↺ Reset</button>
        </div>
      </div>
      <div class="array-wrap" id="llArrDisplay"></div>
      <div class="log-box" id="llLog" style="max-height:110px"><p class="log-step">Nhấn Tìm kiếm để bắt đầu...</p></div>
    </div>

    <!-- TÌM NHỊ PHÂN -->
    <div class="card">
      <div class="card-title">🔭 Tìm kiếm nhị phân</div>
      <div style="margin-bottom:14px;font-size:.82rem;color:var(--muted)">
        Chia đôi không gian tìm kiếm mỗi bước. Yêu cầu mảng đã sắp xếp tăng dần.
      </div>
      <div class="controls">
        <div>
          <label>Mảng sắp xếp (cách bởi dấu phẩy)</label><br>
          <input type="text" id="bsArr" value="11,22,33,44,55,66,77,88,99" style="width:100%">
        </div>
      </div>
      <div class="controls">
        <div>
          <label>Tìm x =</label><br>
          <input type="number" id="bsX" value="55" style="width:80px">
        </div>
        <div style="align-self:flex-end">
          <button class="btn btn-cyan" onclick="runBinary()">▶ Tìm kiếm</button>
          <button class="btn btn-secondary" onclick="resetBinary()">↺ Reset</button>
        </div>
      </div>
      <div class="array-wrap" id="bsArrDisplay"></div>
      <!-- L/R/M labels -->
      <div id="bsPointers" style="display:flex;gap:6px;flex-wrap:wrap;margin-bottom:10px;font-family:'Space Mono',monospace;font-size:.75rem"></div>
      <div class="log-box" id="bsLog" style="max-height:110px"><p class="log-step">Nhấn Tìm kiếm để bắt đầu...</p></div>
    </div>
  </div>

  <!-- So sánh -->
  <div class="card">
    <div class="card-title">📊 So sánh hai thuật toán</div>
    <div class="grid2">
      <div>
        <div style="font-size:.82rem;color:var(--muted);margin-bottom:8px">Tuyến tính</div>
        <div class="stat-row">
          <div class="stat-box"><div class="val" id="llSteps" style="color:var(--accent)">–</div><div class="lbl">Bước</div></div>
          <div class="stat-box"><div class="val" id="llResult" style="color:var(--green);font-size:.85rem">–</div><div class="lbl">Kết quả</div></div>
        </div>
      </div>
      <div>
        <div style="font-size:.82rem;color:var(--muted);margin-bottom:8px">Nhị phân</div>
        <div class="stat-row">
          <div class="stat-box"><div class="val" id="bsSteps" style="color:var(--accent2)">–</div><div class="lbl">Bước</div></div>
          <div class="stat-box"><div class="val" id="bsResult" style="color:var(--green);font-size:.85rem">–</div><div class="lbl">Kết quả</div></div>
        </div>
      </div>
    </div>
  </div>
</div>

<!-- ═══════════════════════════════════════════════
     PAGE: BÀI TẬP
═══════════════════════════════════════════════ -->
<div id="page-bt" class="page">
  <div class="section-title">Bài Tập Chương 2</div>
  <div class="section-sub">Các bài tập theo sách giáo trình</div>

  <!-- BT1 -->
  <div class="bt-card">
    <div class="bt-header">
      <div class="bt-num">1</div>
      <div>
        <div class="bt-title">Tìm kiếm phần tử – Trả về vị trí đầu tiên</div>
        <div style="font-size:.78rem;color:var(--muted)">Tìm vị trí xuất hiện đầu tiên của x trong mảng bất kỳ.</div>
      </div>
    </div>
    <div class="controls">
      <div><label>Mảng</label><br><input type="text" id="bt1Arr" value="5,3,8,3,1,9,3,7,2,5" style="width:220px"></div>
      <div><label>x =</label><br><input type="number" id="bt1X" value="3" style="width:80px"></div>
      <div style="align-self:flex-end"><button class="btn btn-primary" onclick="runBT1()">Chạy</button></div>
    </div>
    <div class="array-wrap" id="bt1Display"></div>
    <div class="bt-result" id="bt1Result"></div>
  </div>

  <!-- BT2 -->
  <div class="bt-card">
    <div class="bt-header">
      <div class="bt-num">2</div>
      <div>
        <div class="bt-title">Tìm vị trí phần tử lớn nhất</div>
        <div style="font-size:.78rem;color:var(--muted)">Trả về chỉ số của phần tử max trong mảng.</div>
      </div>
    </div>
    <div class="controls">
      <div><label>Mảng</label><br><input type="text" id="bt2Arr" value="5,3,8,3,1,9,3,7,2,5" style="width:220px"></div>
      <div style="align-self:flex-end"><button class="btn btn-primary" onclick="runBT2()">Chạy</button></div>
    </div>
    <div class="array-wrap" id="bt2Display"></div>
    <div class="bt-result" id="bt2Result"></div>
  </div>

  <!-- BT3 -->
  <div class="bt-card">
    <div class="bt-header">
      <div class="bt-num">3</div>
      <div>
        <div class="bt-title">Đếm số lần xuất hiện của x</div>
        <div style="font-size:.78rem;color:var(--muted)">Đếm số lần phần tử x có mặt trong mảng.</div>
      </div>
    </div>
    <div class="controls">
      <div><label>Mảng</label><br><input type="text" id="bt3Arr" value="5,3,8,3,1,9,3,7,2,5" style="width:220px"></div>
      <div><label>x =</label><br><input type="number" id="bt3X" value="3" style="width:80px"></div>
      <div style="align-self:flex-end"><button class="btn btn-primary" onclick="runBT3()">Chạy</button></div>
    </div>
    <div class="array-wrap" id="bt3Display"></div>
    <div class="bt-result" id="bt3Result"></div>
  </div>

  <!-- BT4 -->
  <div class="bt-card">
    <div class="bt-header">
      <div class="bt-num">4</div>
      <div>
        <div class="bt-title">Sắp xếp tăng rồi Tìm nhị phân</div>
        <div style="font-size:.78rem;color:var(--muted)">Quick Sort mảng → Binary Search tìm x.</div>
      </div>
    </div>
    <div class="controls">
      <div><label>Mảng</label><br><input type="text" id="bt4Arr" value="5,3,8,3,1,9,3,7,2,5" style="width:220px"></div>
      <div><label>x =</label><br><input type="number" id="bt4X" value="8" style="width:80px"></div>
      <div style="align-self:flex-end"><button class="btn btn-primary" onclick="runBT4()">Chạy</button></div>
    </div>
    <div class="array-wrap" id="bt4Display"></div>
    <div class="bt-result" id="bt4Result"></div>
  </div>

  <!-- BT5 -->
  <div class="bt-card">
    <div class="bt-header">
      <div class="bt-num">5</div>
      <div>
        <div class="bt-title">Sắp xếp giảm dần – Bubble Sort</div>
        <div style="font-size:.78rem;color:var(--muted)">Sắp xếp mảng theo thứ tự từ lớn đến nhỏ.</div>
      </div>
    </div>
    <div class="controls">
      <div><label>Mảng</label><br><input type="text" id="bt5Arr" value="5,3,8,3,1,9,3,7,2,5" style="width:220px"></div>
      <div style="align-self:flex-end"><button class="btn btn-primary" onclick="runBT5()">Chạy</button></div>
    </div>
    <div class="array-wrap" id="bt5Display"></div>
    <div class="bt-result" id="bt5Result"></div>
  </div>

  <!-- BT6 -->
  <div class="bt-card">
    <div class="bt-header">
      <div class="bt-num">6</div>
      <div>
        <div class="bt-title">Phần tử xuất hiện nhiều nhất</div>
        <div style="font-size:.78rem;color:var(--muted)">Tìm mode (giá trị xuất hiện nhiều nhất) trong mảng.</div>
      </div>
    </div>
    <div class="controls">
      <div><label>Mảng</label><br><input type="text" id="bt6Arr" value="5,3,8,3,1,9,3,7,2,5" style="width:220px"></div>
      <div style="align-self:flex-end"><button class="btn btn-primary" onclick="runBT6()">Chạy</button></div>
    </div>
    <div class="array-wrap" id="bt6Display"></div>
    <div class="bt-result" id="bt6Result"></div>
  </div>
</div>

<!-- ═══════════════════════════════════════════════
     PAGE: SO SÁNH
═══════════════════════════════════════════════ -->
<div id="page-compare" class="page">
  <div class="section-title">So Sánh Tốc Độ Sắp Xếp</div>
  <div class="section-sub">Chạy tất cả 5 thuật toán cùng một lúc trên cùng một mảng</div>

  <div class="card">
    <div class="card-title">⚙ Cấu hình</div>
    <div class="controls">
      <div><label>Kích thước mảng</label><br><input type="number" id="cmpSize" value="16" min="4" max="24" style="width:90px"></div>
      <button class="btn btn-secondary" onclick="genCompare()">🎲 Tạo mảng mới</button>
      <button class="btn btn-amber" onclick="runCompare()">⚡ Chạy tất cả</button>
    </div>
    <div style="font-size:.8rem;color:var(--muted);font-family:'Space Mono',monospace;margin-bottom:16px" id="cmpOriginal"></div>
  </div>

  <div id="cmpResults"></div>
</div>

<!-- ════════════════════════════════════════
     JAVASCRIPT
════════════════════════════════════════ -->
<script>
// ─── Tabs ───────────────────────────────────────────────────────────────
function switchTab(id) {
  document.querySelectorAll('.page').forEach(p => p.classList.remove('active'));
  document.querySelectorAll('.tab-btn').forEach(b => b.classList.remove('active'));
  document.getElementById('page-' + id).classList.add('active');
  event.currentTarget.classList.add('active');
}

// ─── Utilities ──────────────────────────────────────────────────────────
function sleep(ms) { return new Promise(r => setTimeout(r, ms)); }
function getSpeed() { return 1000 - parseInt(document.getElementById('speed').value); }
function parseArr(str) { return str.split(',').map(s => parseInt(s.trim())).filter(n => !isNaN(n)); }
function cloneArr(a) { return [...a]; }

document.getElementById('speed').addEventListener('input', function() {
  document.getElementById('speedLabel').textContent = this.value + 'ms';
});

// ─── Array rendering ────────────────────────────────────────────────────
function renderCells(containerId, arr, highlights = {}) {
  const el = document.getElementById(containerId);
  el.innerHTML = '';
  arr.forEach((v, i) => {
    const cell = document.createElement('div');
    cell.className = 'arr-cell';
    if (highlights[i]) cell.classList.add(highlights[i]);
    cell.innerHTML = `${v}<span class="idx">${i}</span>`;
    el.appendChild(cell);
  });
}

function renderBars(arr, highlights = {}) {
  const wrap = document.getElementById('barWrap');
  const max = Math.max(...arr);
  wrap.innerHTML = '';
  arr.forEach((v, i) => {
    const bar = document.createElement('div');
    bar.className = 'bar';
    if (highlights[i]) bar.classList.add(highlights[i]);
    const pct = Math.max(8, Math.round((v / max) * 100));
    bar.style.height = pct + '%';
    bar.innerHTML = `<span>${v}</span>`;
    wrap.appendChild(bar);
  });
}

function addLog(logId, msg, cls = 'log-step') {
  const box = document.getElementById(logId);
  const p = document.createElement('p');
  p.className = cls;
  p.textContent = msg;
  box.appendChild(p);
  box.scrollTop = box.scrollHeight;
}

// ─── SORT STATE ─────────────────────────────────────────────────────────
let sortArr = [], sortSteps = [], stepIdx = 0;
let running = false, swaps = 0, comps = 0;
let selectedAlgo = 'selection';

function selectAlgo(el) {
  document.querySelectorAll('.algo-card').forEach(c => c.classList.remove('selected'));
  el.classList.add('selected');
  selectedAlgo = el.dataset.algo;
  resetSort();
}

function genRandom() {
  const n = parseInt(document.getElementById('arrSize').value) || 12;
  sortArr = Array.from({length: n}, () => Math.floor(Math.random() * 90) + 10);
  renderCells('sortArr', sortArr);
  renderBars(sortArr);
  resetStats();
  document.getElementById('sortLog').innerHTML = '<p class="log-step">Mảng mới đã tạo. Nhấn Chạy...</p>';
}

function loadCustom() {
  const str = document.getElementById('arrCustom').value;
  const arr = parseArr(str);
  if (arr.length < 2) return alert('Mảng phải có ít nhất 2 phần tử!');
  sortArr = arr;
  renderCells('sortArr', sortArr);
  renderBars(sortArr);
  resetStats();
  document.getElementById('sortLog').innerHTML = '<p class="log-step">Đã nạp mảng. Nhấn Chạy...</p>';
}

function resetStats() {
  swaps = 0; comps = 0; stepIdx = 0; sortSteps = [];
  document.getElementById('statSwaps').textContent = '0';
  document.getElementById('statComps').textContent = '0';
  document.getElementById('statStep').textContent = '0';
  document.getElementById('statStatus').textContent = '–';
}

function resetSort() {
  running = false;
  resetStats();
  if (sortArr.length) { renderCells('sortArr', sortArr); renderBars(sortArr); }
  document.getElementById('sortLog').innerHTML = '<p class="log-step">Chọn thuật toán và nhấn Chạy...</p>';
}

// ─── Generate steps ─────────────────────────────────────────────────────
function generateSteps(algo, arr) {
  const a = cloneArr(arr);
  const steps = [];
  let sw = 0, cp = 0;

  function step(a, hl, msg, cls) { steps.push({ arr: cloneArr(a), hl: {...hl}, msg, cls }); }

  if (algo === 'selection') {
    for (let i = 0; i < a.length - 1; i++) {
      let vt = i;
      for (let j = i + 1; j < a.length; j++) {
        cp++;
        const hl = {}; hl[i] = 'active'; hl[vt] = 'compare'; hl[j] = 'compare';
        for (let k = 0; k < i; k++) hl[k] = 'sorted';
        step(a, hl, `So sánh a[${j}]=${a[j]} với min hiện tại a[${vt}]=${a[vt]}`, 'log-step');
        if (a[j] < a[vt]) vt = j;
      }
      if (vt !== i) {
        sw++;
        [a[i], a[vt]] = [a[vt], a[i]];
        const hl = {}; for (let k = 0; k <= i; k++) hl[k] = 'sorted';
        step(a, hl, `Hoán vị a[${i}] ↔ a[${vt}]`, 'log-swap');
      }
    }
  } else if (algo === 'insertion') {
    for (let i = 1; i < a.length; i++) {
      let pos = i, x = a[i];
      const hl = {}; hl[i] = 'active'; for (let k = 0; k < i; k++) hl[k] = 'sorted';
      step(a, hl, `Chèn a[${i}]=${x} vào vị trí đúng`, 'log-step');
      while (pos > 0 && a[pos-1] > x) {
        cp++;
        a[pos] = a[pos-1];
        sw++;
        const hl2 = {}; hl2[pos] = 'compare'; hl2[pos-1] = 'active';
        for (let k = 0; k < pos-1; k++) hl2[k] = 'sorted';
        step(a, hl2, `Dịch a[${pos-1}]=${a[pos-1]} sang phải`, 'log-step');
        pos--;
      }
      a[pos] = x;
      const hl3 = {}; for (let k = 0; k <= i; k++) hl3[k] = 'sorted';
      step(a, hl3, `Đặt ${x} vào vị trí ${pos}`, 'log-swap');
    }
  } else if (algo === 'bubble') {
    for (let i = 0; i < a.length - 1; i++) {
      for (let j = a.length - 1; j > i; j--) {
        cp++;
        const hl = {}; hl[j] = 'active'; hl[j-1] = 'compare';
        for (let k = a.length-1; k > a.length-1-i; k--) hl[k] = 'sorted';
        step(a, hl, `So sánh a[${j-1}]=${a[j-1]} và a[${j}]=${a[j]}`, 'log-step');
        if (a[j] < a[j-1]) {
          sw++;
          [a[j], a[j-1]] = [a[j-1], a[j]];
          const hl2 = {}; hl2[j] = 'compare'; hl2[j-1] = 'active';
          for (let k = a.length-1; k > a.length-1-i; k--) hl2[k] = 'sorted';
          step(a, hl2, `Hoán vị a[${j-1}] ↔ a[${j}]`, 'log-swap');
        }
      }
    }
  } else if (algo === 'quick') {
    function qs(l, r) {
      if (l >= r) return;
      let i = l, j = r;
      const pivotIdx = Math.floor((l+r)/2);
      const x = a[pivotIdx];
      const hl0 = {}; hl0[pivotIdx] = 'pivot';
      step(a, hl0, `Pivot = a[${pivotIdx}] = ${x} (đoạn [${l}..${r}])`, 'log-pivot');
      do {
        while (a[i] < x) { cp++; i++; }
        while (a[j] > x) { cp++; j--; }
        if (i <= j) {
          if (i !== j) {
            sw++;
            [a[i], a[j]] = [a[j], a[i]];
            const hl = {}; hl[i] = 'active'; hl[j] = 'compare'; hl[pivotIdx] = 'pivot';
            step(a, hl, `Hoán vị a[${i}]=${a[j]} ↔ a[${j}]=${a[i]}`, 'log-swap');
          }
          i++; j--;
        }
      } while (i <= j);
      if (l < j) qs(l, j);
      if (i < r) qs(i, r);
    }
    qs(0, a.length - 1);
  } else if (algo === 'heap') {
    function shift(l, r) {
      let i = l, j = 2*i+1, x = a[i];
      while (j <= r) {
        if (j < r && a[j] < a[j+1]) j++;
        if (x >= a[j]) break;
        const hl = {}; hl[i] = 'active'; hl[j] = 'compare';
        step(a, hl, `Shift: a[${i}]=${a[i]} ↓ a[${j}]=${a[j]}`, 'log-step');
        a[i] = a[j]; i = j; j = 2*i+1; sw++;
      }
      a[i] = x;
    }
    // Build heap
    for (let k = Math.floor(a.length/2)-1; k >= 0; k--) shift(k, a.length-1);
    step(a, {}, 'Heap đã xây xong', 'log-info');
    for (let r = a.length-1; r > 0; r--) {
      [a[0], a[r]] = [a[r], a[0]]; sw++;
      const hl = {}; hl[r] = 'sorted';
      step(a, hl, `Đặt max a[0]=${a[r]} vào cuối (vị trí ${r})`, 'log-swap');
      shift(0, r-1);
    }
  }

  // Final sorted step
  const hl = {}; for (let i = 0; i < a.length; i++) hl[i] = 'sorted';
  step(a, hl, `✅ Sắp xếp hoàn thành! Hoán vị: ${sw}, So sánh: ${cp}`, 'log-found');
  return { steps, totalSwaps: sw, totalComps: cp };
}

// ─── Run / Step ─────────────────────────────────────────────────────────
async function runSort() {
  if (running) return;
  if (!sortArr.length) { genRandom(); }
  running = true;
  document.getElementById('btnRun').disabled = true;
  document.getElementById('sortLog').innerHTML = '';

  const { steps, totalSwaps, totalComps } = generateSteps(selectedAlgo, sortArr);
  sortSteps = steps;
  swaps = 0; comps = 0; stepIdx = 0;
  document.getElementById('statStatus').textContent = '▶';

  for (let i = 0; i < steps.length; i++) {
    if (!running) break;
    const s = steps[i];
    stepIdx = i + 1;
    renderCells('sortArr', s.arr, s.hl);
    renderBars(s.arr, s.hl);
    addLog('sortLog', `[${i+1}] ${s.msg}`, s.cls);
    if (s.cls === 'log-swap') swaps++;
    if (s.cls === 'log-step') comps++;
    document.getElementById('statSwaps').textContent = totalSwaps;
    document.getElementById('statComps').textContent = totalComps;
    document.getElementById('statStep').textContent = i + 1;
    await sleep(getSpeed());
  }

  running = false;
  document.getElementById('btnRun').disabled = false;
  document.getElementById('statStatus').textContent = '✅';
  document.getElementById('statSwaps').textContent = totalSwaps;
  document.getElementById('statComps').textContent = totalComps;
}

function stepSort() {
  if (!sortArr.length) genRandom();
  if (!sortSteps.length) {
    const { steps } = generateSteps(selectedAlgo, sortArr);
    sortSteps = steps;
    stepIdx = 0;
    document.getElementById('sortLog').innerHTML = '';
  }
  if (stepIdx >= sortSteps.length) return;
  const s = sortSteps[stepIdx];
  renderCells('sortArr', s.arr, s.hl);
  renderBars(s.arr, s.hl);
  addLog('sortLog', `[${stepIdx+1}] ${s.msg}`, s.cls);
  document.getElementById('statStep').textContent = stepIdx + 1;
  stepIdx++;
}

// ─── SEARCH ─────────────────────────────────────────────────────────────
async function runLinear() {
  const arr = parseArr(document.getElementById('llArr').value);
  const x = parseInt(document.getElementById('llX').value);
  document.getElementById('llLog').innerHTML = '';
  renderCells('llArrDisplay', arr);
  let steps = 0;

  for (let i = 0; i < arr.length; i++) {
    steps++;
    const hl = {};
    for (let k = 0; k < i; k++) hl[k] = 'compare';
    hl[i] = 'active';
    renderCells('llArrDisplay', arr, hl);
    addLog('llLog', `Bước ${i+1}: Kiểm tra a[${i}] = ${arr[i]}`, 'log-step');
    await sleep(400);
    if (arr[i] === x) {
      hl[i] = 'found';
      renderCells('llArrDisplay', arr, hl);
      addLog('llLog', `✅ Tìm thấy ${x} tại vị trí ${i}`, 'log-found');
      document.getElementById('llSteps').textContent = steps;
      document.getElementById('llResult').textContent = 'Vị trí ' + i;
      return;
    }
  }
  addLog('llLog', `❌ Không tìm thấy ${x}`, 'log-notfound');
  document.getElementById('llSteps').textContent = steps;
  document.getElementById('llResult').textContent = 'Không có';
}

function resetLinear() {
  document.getElementById('llArrDisplay').innerHTML = '';
  document.getElementById('llLog').innerHTML = '<p class="log-step">Nhấn Tìm kiếm để bắt đầu...</p>';
  document.getElementById('llSteps').textContent = '–';
  document.getElementById('llResult').textContent = '–';
}

async function runBinary() {
  const arr = parseArr(document.getElementById('bsArr').value);
  const x = parseInt(document.getElementById('bsX').value);
  document.getElementById('bsLog').innerHTML = '';
  document.getElementById('bsPointers').innerHTML = '';
  renderCells('bsArrDisplay', arr);
  let steps = 0, l = 0, r = arr.length - 1;

  while (l <= r) {
    steps++;
    const m = Math.floor((l + r) / 2);
    const hl = {};
    for (let k = 0; k < arr.length; k++) {
      if (k < l || k > r) hl[k] = 'compare';
    }
    hl[m] = 'active';
    renderCells('bsArrDisplay', arr, hl);

    document.getElementById('bsPointers').innerHTML =
      `<span style="color:var(--green)">L=${l}</span> &nbsp;
       <span style="color:var(--accent)">M=${m}</span> &nbsp;
       <span style="color:var(--accent2)">R=${r}</span> &nbsp;
       <span style="color:var(--muted)">→ a[M]=${arr[m]}</span>`;

    addLog('bsLog', `Bước ${steps}: l=${l} r=${r} m=${m} a[m]=${arr[m]}`, 'log-step');
    await sleep(500);

    if (arr[m] === x) {
      hl[m] = 'found';
      renderCells('bsArrDisplay', arr, hl);
      addLog('bsLog', `✅ Tìm thấy ${x} tại vị trí ${m}`, 'log-found');
      document.getElementById('bsSteps').textContent = steps;
      document.getElementById('bsResult').textContent = 'Vị trí ' + m;
      return;
    } else if (arr[m] > x) {
      addLog('bsLog', `a[m]=${arr[m]} > x → tìm bên trái`, 'log-info');
      r = m - 1;
    } else {
      addLog('bsLog', `a[m]=${arr[m]} < x → tìm bên phải`, 'log-info');
      l = m + 1;
    }
  }
  addLog('bsLog', `❌ Không tìm thấy ${x}`, 'log-notfound');
  document.getElementById('bsSteps').textContent = steps;
  document.getElementById('bsResult').textContent = 'Không có';
}

function resetBinary() {
  document.getElementById('bsArrDisplay').innerHTML = '';
  document.getElementById('bsPointers').innerHTML = '';
  document.getElementById('bsLog').innerHTML = '<p class="log-step">Nhấn Tìm kiếm để bắt đầu...</p>';
  document.getElementById('bsSteps').textContent = '–';
  document.getElementById('bsResult').textContent = '–';
}

// ─── BÀI TẬP ────────────────────────────────────────────────────────────
function showBTResult(id, arr, hl, msg) {
  renderCells(id + 'Display', arr, hl);
  const r = document.getElementById(id + 'Result');
  r.textContent = msg; r.classList.add('show');
}

function runBT1() {
  const arr = parseArr(document.getElementById('bt1Arr').value);
  const x = parseInt(document.getElementById('bt1X').value);
  let vt = -1;
  for (let i = 0; i < arr.length; i++) if (arr[i] === x) { vt = i; break; }
  const hl = {};
  if (vt !== -1) hl[vt] = 'found';
  showBTResult('bt1', arr, hl, vt === -1 ? `Không tìm thấy ${x}` : `Tìm thấy ${x} tại vị trí ${vt}`);
}

function runBT2() {
  const arr = parseArr(document.getElementById('bt2Arr').value);
  let vtmax = 0;
  for (let i = 1; i < arr.length; i++) if (arr[i] > arr[vtmax]) vtmax = i;
  const hl = {}; hl[vtmax] = 'found';
  showBTResult('bt2', arr, hl, `Phần tử lớn nhất = ${arr[vtmax]} tại vị trí ${vtmax}`);
}

function runBT3() {
  const arr = parseArr(document.getElementById('bt3Arr').value);
  const x = parseInt(document.getElementById('bt3X').value);
  let dem = 0; const hl = {};
  arr.forEach((v, i) => { if (v === x) { dem++; hl[i] = 'found'; } });
  showBTResult('bt3', arr, hl, `${x} xuất hiện ${dem} lần`);
}

function runBT4() {
  const arr = parseArr(document.getElementById('bt4Arr').value);
  const x = parseInt(document.getElementById('bt4X').value);
  const a = cloneArr(arr);
  // QuickSort
  function qs(l, r) {
    if (l >= r) return;
    let i = l, j = r, pv = a[Math.floor((l+r)/2)];
    do { while(a[i]<pv)i++; while(a[j]>pv)j--;
      if(i<=j){[a[i],a[j]]=[a[j],a[i]];i++;j--;} } while(i<=j);
    if(l<j)qs(l,j); if(i<r)qs(i,r);
  }
  qs(0, a.length-1);
  let l=0, r=a.length-1, vt=-1;
  while(l<=r){const m=Math.floor((l+r)/2);
    if(a[m]===x){vt=m;break;} else if(a[m]>x)r=m-1; else l=m+1;}
  const hl = {}; if(vt!==-1)hl[vt]='found';
  showBTResult('bt4', a, hl, `Sau sắp xếp: [${a.join(', ')}] → ${vt===-1?`Không tìm thấy ${x}`:`${x} tại vị trí ${vt}`}`);
}

function runBT5() {
  const arr = parseArr(document.getElementById('bt5Arr').value);
  const a = cloneArr(arr);
  for(let i=0;i<a.length-1;i++) for(let j=a.length-1;j>i;j--) if(a[j]>a[j-1])[a[j],a[j-1]]=[a[j-1],a[j]];
  const hl={}; a.forEach((_,i)=>hl[i]='sorted');
  showBTResult('bt5', a, hl, `Mảng giảm dần: [${a.join(', ')}]`);
}

function runBT6() {
  const arr = parseArr(document.getElementById('bt6Arr').value);
  let maxDem=0, maxVal=arr[0]; const hl={};
  for(let i=0;i<arr.length;i++){let d=0; for(let j=0;j<arr.length;j++) if(arr[j]===arr[i])d++; if(d>maxDem){maxDem=d;maxVal=arr[i];}}
  arr.forEach((v,i)=>{if(v===maxVal)hl[i]='found';});
  showBTResult('bt6', arr, hl, `Phần tử xuất hiện nhiều nhất: ${maxVal} (${maxDem} lần)`);
}

// ─── SO SÁNH ────────────────────────────────────────────────────────────
let cmpArr = [];

function genCompare() {
  const n = parseInt(document.getElementById('cmpSize').value) || 16;
  cmpArr = Array.from({length: n}, () => Math.floor(Math.random() * 90) + 10);
  document.getElementById('cmpOriginal').textContent = 'Mảng gốc: [' + cmpArr.join(', ') + ']';
  document.getElementById('cmpResults').innerHTML = '';
}

function sortForCompare(algo, arr) {
  const a = cloneArr(arr);
  let sw = 0, cp = 0;

  if (algo === 'selection') {
    for(let i=0;i<a.length-1;i++){let vt=i; for(let j=i+1;j<a.length;j++){cp++;if(a[j]<a[vt])vt=j;} if(vt!==i){[a[i],a[vt]]=[a[vt],a[i]];sw++;}}
  } else if (algo === 'insertion') {
    for(let i=1;i<a.length;i++){let pos=i,x=a[i]; while(pos>0&&a[pos-1]>x){cp++;a[pos]=a[pos-1];pos--;sw++;} a[pos]=x;}
  } else if (algo === 'bubble') {
    for(let i=0;i<a.length-1;i++) for(let j=a.length-1;j>i;j--){cp++;if(a[j]<a[j-1]){[a[j],a[j-1]]=[a[j-1],a[j]];sw++;}}
  } else if (algo === 'quick') {
    function qs(l,r){if(l>=r)return;let i=l,j=r,pv=a[Math.floor((l+r)/2)];
      do{while(a[i]<pv){cp++;i++;}while(a[j]>pv){cp++;j--;}if(i<=j){if(i!==j){[a[i],a[j]]=[a[j],a[i]];sw++;}i++;j--;}}while(i<=j);
      if(l<j)qs(l,j);if(i<r)qs(i,r);}
    qs(0,a.length-1);
  } else if (algo === 'heap') {
    function shift(l,r){let i=l,j=2*i+1,x=a[i];
      while(j<=r){if(j<r&&a[j]<a[j+1])j++;if(x>=a[j])break;a[i]=a[j];i=j;j=2*i+1;sw++;}a[i]=x;}
    for(let k=Math.floor(a.length/2)-1;k>=0;k--)shift(k,a.length-1);
    for(let r=a.length-1;r>0;r--){[a[0],a[r]]=[a[r],a[0]];sw++;shift(0,r-1);}
  }
  return { arr: a, swaps: sw, comps: cp };
}

function runCompare() {
  if (!cmpArr.length) genCompare();
  const algos = [
    { id: 'selection', name: 'Selection Sort', complexity: 'O(N²)', color: 'var(--accent)' },
    { id: 'insertion', name: 'Insertion Sort', complexity: 'O(N²)', color: 'var(--accent2)' },
    { id: 'bubble',    name: 'Bubble Sort',    complexity: 'O(N²)', color: 'var(--accent3)' },
    { id: 'quick',     name: 'Quick Sort',     complexity: 'O(N log N)', color: 'var(--green)' },
    { id: 'heap',      name: 'Heap Sort',      complexity: 'O(N log N)', color: '#f97316' },
  ];

  const results = algos.map(a => {
    const t0 = performance.now();
    const res = sortForCompare(a.id, cmpArr);
    const t1 = performance.now();
    return { ...a, ...res, ms: (t1 - t0).toFixed(3) };
  });

  const maxSwaps = Math.max(...results.map(r => r.swaps));
  const maxComps = Math.max(...results.map(r => r.comps));

  let html = '';
  results.forEach(r => {
    const swPct = maxSwaps ? Math.round((r.swaps / maxSwaps) * 100) : 0;
    const cpPct = maxComps ? Math.round((r.comps / maxComps) * 100) : 0;
    html += `
      <div class="card" style="border-left:4px solid ${r.color}; margin-bottom:16px">
        <div style="display:flex;justify-content:space-between;align-items:center;margin-bottom:14px">
          <div>
            <span style="font-weight:800;font-size:.95rem">${r.name}</span>
            <span class="badge badge-purple" style="margin-left:10px;font-size:.68rem">${r.complexity}</span>
          </div>
          <span style="font-family:'Space Mono',monospace;font-size:.75rem;color:var(--muted)">${r.ms}ms</span>
        </div>
        <div class="stat-row">
          <div class="stat-box"><div class="val" style="color:${r.color};font-size:1.3rem">${r.swaps}</div><div class="lbl">Hoán vị</div></div>
          <div class="stat-box"><div class="val" style="color:${r.color};font-size:1.3rem">${r.comps}</div><div class="lbl">So sánh</div></div>
        </div>
        <div style="margin:8px 0 4px;font-size:.72rem;color:var(--muted);font-family:'Space Mono',monospace">Hoán vị</div>
        <div style="background:var(--bar-default);border-radius:4px;height:8px">
          <div style="background:${r.color};width:${swPct}%;height:100%;border-radius:4px;transition:width .6s"></div>
        </div>
        <div style="margin:8px 0 4px;font-size:.72rem;color:var(--muted);font-family:'Space Mono',monospace">So sánh</div>
        <div style="background:var(--bar-default);border-radius:4px;height:8px">
          <div style="background:${r.color};width:${cpPct}%;height:100%;border-radius:4px;transition:width .6s"></div>
        </div>
        <div style="margin-top:12px;font-size:.75rem;color:var(--muted);font-family:'Space Mono',monospace">
          Kết quả: [${r.arr.slice(0,8).join(', ')}${r.arr.length>8?', ...':''}]
        </div>
      </div>`;
  });

  document.getElementById('cmpResults').innerHTML = html;
}

// ─── Init ────────────────────────────────────────────────────────────────
genRandom();
genCompare();
initSearchDisplays();

function initSearchDisplays() {
  const ll = parseArr(document.getElementById('llArr').value);
  const bs = parseArr(document.getElementById('bsArr').value);
  renderCells('llArrDisplay', ll);
  renderCells('bsArrDisplay', bs);
}
</script>
</body>
</html>
