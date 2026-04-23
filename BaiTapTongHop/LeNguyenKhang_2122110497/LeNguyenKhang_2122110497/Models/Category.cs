namespace LeNguyenKhang_2122110497.Models
{
    public class Category
    {
        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Slug { get; set; } // Ví dụ: trang-phuc-cosplay (cho SEO)

        // Liên kết: Một danh mục có nhiều sản phẩm
        public virtual ICollection<Product>? Products { get; set; }
    }
}
