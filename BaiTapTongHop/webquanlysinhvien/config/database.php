<?php
$conn = new mysqli("localhost", "root", "", "qlsv");

if ($conn->connect_error) {
    die("Lỗi kết nối!");
}

session_start();
?>