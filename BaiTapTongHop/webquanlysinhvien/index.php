<?php include 'config/database.php';

if (!isset($_SESSION['user'])) {
    header("Location: login.php");
}

$keyword = $_GET['keyword'] ?? '';
$sql = "SELECT * FROM sinhvien WHERE name LIKE '%$keyword%'";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html>
<head>
<title>QLSV</title>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="container">

<h2>Quản lý sinh viên</h2>

<a href="logout.php" class="btn btn-danger">Đăng xuất</a>
<a href="add.php" class="btn btn-success">Thêm</a>

<form method="GET" class="mt-3 mb-3">
    <input name="keyword" placeholder="Tìm tên..." class="form-control">
</form>

<table class="table table-bordered">
<tr>
<th>MSSV</th><th>Tên</th><th>Lớp</th><th>Ngày sinh</th><th>Ảnh</th><th></th>
</tr>

<?php while ($row = $result->fetch_assoc()) { ?>
<tr>
<td><?= $row['mssv'] ?></td>
<td><?= $row['name'] ?></td>
<td><?= $row['lop'] ?></td>
<td><?= $row['ngaysinh'] ?></td>
<td>
<?php if ($row['avatar']) { ?>
<img src="uploads/<?= $row['avatar'] ?>" width="50">
<?php } ?>
</td>
<td>
<a href="edit.php?id=<?= $row['id'] ?>" class="btn btn-warning btn-sm">Sửa</a>
<a href="delete.php?id=<?= $row['id'] ?>" class="btn btn-danger btn-sm">Xóa</a>
</td>
</tr>
<?php } ?>

</table>

</body>
</html>