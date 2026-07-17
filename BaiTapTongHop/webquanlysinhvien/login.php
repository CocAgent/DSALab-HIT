<?php include 'config/database.php'; ?>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $u = $_POST['username'];
    $p = $_POST['password'];

    $result = $conn->query("SELECT * FROM users WHERE username='$u' AND password='$p'");

    if ($result->num_rows > 0) {
        $_SESSION['user'] = $u;
        header("Location: index.php");
    } else {
        echo "Sai tài khoản!";
    }
}
?>

<form method="POST">
    <h2>Đăng nhập</h2>
    <input name="username" placeholder="User"><br><br>
    <input name="password" type="password"><br><br>
    <button>Login</button>
</form>