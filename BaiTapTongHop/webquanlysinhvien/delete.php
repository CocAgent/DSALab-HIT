<?php include 'config/database.php';

$id = $_GET['id'];
$conn->query("DELETE FROM sinhvien WHERE id=$id");

header("Location: index.php");
?>