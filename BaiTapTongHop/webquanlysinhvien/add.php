<?php include 'config/database.php';

if (!isset($_SESSION['user'])) header("Location: login.php");

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $mssv = $_POST['mssv'];
    $name = $_POST['name'];
    $lop = $_POST['lop'];
    $ngaysinh = $_POST['ngaysinh'];

    $avatar = "";
    if ($_FILES['avatar']['name']) {
        $avatar = time() . $_FILES['avatar']['name'];
        move_uploaded_file($_FILES['avatar']['tmp_name'], "uploads/" . $avatar);
    }

    $conn->query("INSERT INTO sinhvien VALUES (NULL,'$mssv','$name','$lop','$ngaysinh','$avatar')");
    header("Location: index.php");
}
?>

<form method="POST" enctype="multipart/form-data">
<h2>Thêm sinh viên</h2>
<input name="mssv" placeholder="MSSV"><br><br>
<input name="name" placeholder="Tên"><br><br>
<input name="lop" placeholder="Lớp"><br><br>
<input type="date" name="ngaysinh"><br><br>
<input type="file" name="avatar"><br><br>
<button>Thêm</button>
</form>