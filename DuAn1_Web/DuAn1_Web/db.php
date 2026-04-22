<?php

$host = "localhost";
$user = "root";
$pass = "";
$db   = "quanly_sinhvien";

$conn = new mysqli($host,$user,$pass,$db);

if ($conn->connect_error)
{
    die("Ket noi that bai");
}

?>