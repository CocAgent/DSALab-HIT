<?php

include "db.php";

$mssv = $_POST["mssv"];
$ten  = $_POST["ten"];
$diem = $_POST["diem"];

// KIỂM TRA TRÙNG MSSV
$sqlCheck =
"SELECT * FROM dssinhvien
 WHERE mssv = '$mssv'";

$result = $conn->query($sqlCheck);

if ($result->num_rows > 0)
{
    // MSSV đã tồn tại
    echo "duplicate";
}
else
{
    // THÊM SINH VIÊN
    $sql =
    "INSERT INTO dssinhvien
    (mssv,ten,diem)
    VALUES
    ('$mssv','$ten','$diem')";

    if ($conn->query($sql))
    {
        echo "success";
    }
    else
    {
        echo "error";
    }
}

$conn->close();

?>