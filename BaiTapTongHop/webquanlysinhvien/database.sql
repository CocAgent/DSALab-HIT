CREATE DATABASE qlsv;
USE qlsv;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50),
    password VARCHAR(255)
);

-- mật khẩu: 123 (đã hash sẵn)
INSERT INTO users(username, password) VALUES 
('admin', '$2y$10$wH8QnSx7K9z1cWZQzY7p9u6mQYQzJYl3hKQYg5z8Q8Zl6JkFhTQ3G');

CREATE TABLE sinhvien (
    id INT AUTO_INCREMENT PRIMARY KEY,
    mssv VARCHAR(20),
    name VARCHAR(100),
    lop VARCHAR(50),
    ngaysinh DATE,
    avatar VARCHAR(255)
);