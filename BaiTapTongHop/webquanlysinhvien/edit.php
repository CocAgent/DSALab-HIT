<?php include 'config/database.php';

$id = $_GET['id'];
$row = $conn->query("SELECT * FROM sinhvien WHERE id=$id")->fetch_assoc();

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $mssv = $_POST['mssv'];
    $name = $_POST['name'];
    $lop = $_POST['lop'];
    $ngaysinh = $_POST['ngaysinh'];

    if ($_FILES['avatar']['name']) {
        $avatar = time() . $_FILES['avatar']['name'];
        move_uploaded_file($_FILES['avatar']['tmp_name'], "uploads/" . $avatar);

        $conn->query("UPDATE sinhvien SET avatar='$avatar' WHERE id=$id");
    }

    $conn->query("UPDATE sinhvien SET 
        mssv='$mssv', name='$name', lop='$lop', ngaysinh='$ngaysinh'
        WHERE id=$id");

    header("Location: index.php");
}
?>

<form method="POST" enctype="multipart/form-data">
<h2>Sửa sinh viên</h2>
<input name="mssv" value="<?= $row['mssv'] ?>"><br><br>
<input name="name" value="<?= $row['name'] ?>"><br><br>
<input name="lop" value="<?= $row['lop'] ?>"><br><br>
<input type="date" name="ngaysinh" value="<?= $row['ngaysinh'] ?>"><br><br>
<input type="file" name="avatar"><br><br>
<button>Cập nhật</button>
</form>