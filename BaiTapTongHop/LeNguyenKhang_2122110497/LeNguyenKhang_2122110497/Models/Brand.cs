namespace LeNguyenKhang_2122110497.Models
{
    public class Brand
    {
        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Description { get; set; } // Mô tả hãng
        public string? Slug { get; set; } // Ví dụ: dokidoki (cho SEO)
        public string? Logo { get; set; } // Link ảnh logo

        // Liên kết: Một hãng có nhiều sản phẩm
        public virtual ICollection<Product>? Products { get; set; }
    }
}
