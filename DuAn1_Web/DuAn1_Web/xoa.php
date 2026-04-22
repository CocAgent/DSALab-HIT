<?php

include "db.php";

$id = $_POST["id"];

$sql =
"DELETE FROM dssinhvien
WHERE id='$id'";

$conn->query($sql);

$conn->close();

?>