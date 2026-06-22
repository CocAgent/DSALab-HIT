<?php

include "db.php";

$id   = $_POST["id"];
$mssv = $_POST["mssv"];
$ten  = $_POST["ten"];
$diem = $_POST["diem"];

// KIỂM TRA TRÙNG MSSV (trừ chính nó)
$sqlCheck =
"SELECT * FROM dssinhvien
 WHERE mssv='$mssv'
 AND id!='$id'";

$result = $conn->query($sqlCheck);

if ($result->num_rows > 0)
{
    // MSSV đã tồn tại
    echo "duplicate";
}
else
{
    // CẬP NHẬT
    $sql =
    "UPDATE dssinhvien
     SET
     mssv='$mssv',
     ten='$ten',
     diem='$diem'
     WHERE id='$id'";

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