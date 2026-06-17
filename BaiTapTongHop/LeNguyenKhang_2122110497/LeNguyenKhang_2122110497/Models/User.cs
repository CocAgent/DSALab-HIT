namespace LeNguyenKhang_2122110497.Models
{
    public class User
    {
        public int Id { get; set; }
        public string Username { get; set; }
        public string Password { get; set; } // Trong đồ án thì để text, thực tế phải hash
        public string? FullName { get; set; }
        public string? Role { get; set; } // "Admin" hoặc "Customer"
    }
}
