let ds = []

let dangSua = false
let idSua = ""

let cotSapXep = ""
let tang = true

// LOAD DATA
async function loadData()
{
    let res = await fetch("get.php")

    ds = await res.json()

    hienThi(ds)
}

// HIỂN THỊ BẢNG
function hienThi(data = ds)
{
    let tbody =
    document.getElementById("bangSinhVien")

    tbody.innerHTML = ""

    let tong = 0

    let gioi=0
    let kha=0
    let tb=0
    let yeu=0

    data.forEach(sv => {

        let hl = xepLoai(sv.diem)

        tong += Number(sv.diem)

        if(hl=="Giỏi") gioi++
        if(hl=="Khá") kha++
        if(hl=="Trung bình") tb++
        if(hl=="Yếu") yeu++

        tbody.innerHTML += `

        <tr>

        <td>${sv.mssv}</td>

        <td>${sv.ten}</td>

        <td>${sv.diem}</td>

        <td>${hl}</td>

        <td>

        <button onclick="suaSinhVien(
        ${sv.id},
        '${sv.mssv}',
        '${sv.ten}',
        ${sv.diem})">

        Sửa
        </button>

        <button onclick="xoaSinhVien(${sv.id})">

        Xóa

        </button>

        </td>

        </tr>

        `
    })

    thongKe(data,tong,gioi,kha,tb,yeu)
}

// XẾP LOẠI
function xepLoai(d)
{
    if(d>=8) return "Giỏi"
    if(d>=6.5) return "Khá"
    if(d>=5) return "Trung bình"
    return "Yếu"
}

// LƯU SINH VIÊN
async function luuSinhVien()
{
    let mssv =
    document.getElementById("mssv").value

    let ten =
    document.getElementById("ten").value

    let diem =
    document.getElementById("diem").value

    if(mssv=="" || ten=="")
    {
        alert("⚠️ Nhập đủ thông tin")
        return
    }

    let form = new FormData()

    form.append("id",idSua)
    form.append("mssv",mssv)
    form.append("ten",ten)
    form.append("diem",diem)

    let res

    if(dangSua)
        res = await fetch("sua.php",
        {method:"POST",body:form})
    else
        res = await fetch("them.php",
        {method:"POST",body:form})

    let text =
    await res.text()

    // THÔNG BÁO TRÙNG MSSV
    if(text == "duplicate")
    {
        alert("❌ MSSV đã tồn tại!");
        return;
    }

    if(text == "success")
    {
        alert("✅ Thành công!");
    }

    resetForm()

    loadData()
}

// SỬA
function suaSinhVien(id,mssv,ten,diem)
{
    document.getElementById("mssv").value=mssv
    document.getElementById("ten").value=ten
    document.getElementById("diem").value=diem

    idSua=id

    dangSua=true

    document.getElementById("formTitle")
    .innerText="Sửa Sinh Viên"
}

// XÓA
async function xoaSinhVien(id)
{
    if(confirm("Xóa sinh viên?"))
    {
        let f = new FormData()

        f.append("id",id)

        await fetch("xoa.php",
        {method:"POST",body:f})

        loadData()
    }
}

// RESET
function resetForm()
{
    document.getElementById("mssv").value=""
    document.getElementById("ten").value=""
    document.getElementById("diem").value=""

    dangSua=false

    idSua=""

    document.getElementById("formTitle")
    .innerText="Thêm Sinh Viên"
}

// SẮP XẾP
function sapXep(cot)
{
    tang =
    (cotSapXep==cot)? !tang:true

    cotSapXep=cot

    ds.sort((a,b)=>{

        if(a[cot]<b[cot])
            return tang?-1:1

        if(a[cot]>b[cot])
            return tang?1:-1

        return 0
    })

    hienThi(ds)
}

// TÌM KIẾM
function timKiem()
{
    let t =
    document.getElementById("tuKhoa")
    .value.toLowerCase()

    let kq =
    ds.filter(sv =>

        sv.ten.toLowerCase().includes(t)

        ||

        sv.mssv.toLowerCase().includes(t)

    )

    hienThi(kq)
}

// THỐNG KÊ
function thongKe(data,tong,gioi,kha,tb,yeu)
{
    if(data.length==0) return

    let max =
    Math.max(...data.map(s=>s.diem))

    let min =
    Math.min(...data.map(s=>s.diem))

    let avg =
    tong/data.length

    document.getElementById("max")
    .innerText="Điểm cao nhất: "+max

    document.getElementById("min")
    .innerText="Điểm thấp nhất: "+min

    document.getElementById("avg")
    .innerText="Điểm trung bình: "+avg.toFixed(2)

    document.getElementById("hocLucTK")
    .innerText=
    `Giỏi:${gioi}
     Khá:${kha}
     TB:${tb}
     Yếu:${yeu}`
}

// XUẤT FILE
function xuatFile()
{
    if(ds.length === 0)
    {
        alert("Không có dữ liệu để xuất!");
        return;
    }

    let text = "";

    text += "DANH SACH SINH VIEN\n";
    text += "============================\n\n";

    // tiêu đề bảng
    text += "MSSV\tTen\tDiem\tHoc luc\n";
    text += "----------------------------------------\n";

    let tong = 0;

    let gioi=0;
    let kha=0;
    let tb=0;
    let yeu=0;

    ds.forEach(sv => {

        let hl = xepLoai(sv.diem);

        tong += Number(sv.diem);

        if(hl=="Giỏi") gioi++;
        if(hl=="Khá") kha++;
        if(hl=="Trung bình") tb++;
        if(hl=="Yếu") yeu++;

        text +=
            sv.mssv + "\t" +
            sv.ten + "\t" +
            sv.diem + "\t" +
            hl + "\n";

    });

    // thống kê
    let max =
    Math.max(...ds.map(s=>Number(s.diem)));

    let min =
    Math.min(...ds.map(s=>Number(s.diem)));

    let avg =
    tong / ds.length;

    text += "\n============================\n";
    text += "THONG KE\n";
    text += "============================\n";

    text += "Tong sinh vien: " + ds.length + "\n";
    text += "Diem cao nhat: " + max + "\n";
    text += "Diem thap nhat: " + min + "\n";
    text += "Diem trung binh: " + avg.toFixed(2) + "\n";

    text += "\nHoc luc:\n";
    text += "Gioi: " + gioi + "\n";
    text += "Kha: " + kha + "\n";
    text += "Trung binh: " + tb + "\n";
    text += "Yeu: " + yeu + "\n";

    // tạo file TXT
    let blob =
    new Blob([text], {
        type: "text/plain"
    });

    let a =
    document.createElement("a");

    a.href =
    URL.createObjectURL(blob);

    // ⚠️ QUAN TRỌNG: đổi tên file sang .txt
    a.download =
    "DanhSachSinhVien.txt";

    document.body.appendChild(a);

    a.click();

    document.body.removeChild(a);
}

// START
loadData()