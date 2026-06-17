using Microsoft.AspNetCore.Mvc;
using Microsoft.VisualStudio.Web.CodeGeneration.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Http.HttpResults;
using LeNguyenKhang_2122110497.Models;
namespace LeNguyenKhang_2122110497.Data
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

        public DbSet<Brand> Brands { get; set; }
        public DbSet<Category> Categories { get; set; }
        public DbSet<Product> Products { get; set; }
        public DbSet<Order> Orders { get; set; }
        public DbSet<Order_detail> OrderDetails { get; set; } // Kiểm tra kỹ tên class Order_detail này
        public DbSet<User> Users { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            // 1. Seed Category
            modelBuilder.Entity<Category>().HasData(
                new Category { Id = 1, Name = "Trang phục Cosplay", Slug = "trang-phuc" },
                new Category { Id = 2, Name = "Tóc giả (Wig)", Slug = "wig" },
                new Category { Id = 3, Name = "Phụ kiện & Vũ khí", Slug = "props" }
            );

            // 2. Seed Brand
            modelBuilder.Entity<Brand>().HasData(
                new Brand { Id = 1, Name = "DokiDoki", Slug = "dokidoki", Description = "Hãng cosplay nổi tiếng Trung Quốc" },
                new Brand { Id = 2, Name = "Rolecos", Slug = "rolecos", Description = "Chuyên đồ cosplay anime" },
                new Brand { Id = 3, Name = "Manmei", Slug = "manmei", Description = "Hãng tại Trung Quốc" }
            );

            // 3. Seed Product
            modelBuilder.Entity<Product>().HasData(
                new Product
                {
                    Id = 1,
                    Name = "Bộ đồ Raiden Shogun (Genshin Impact)",
                    Slug = "bo-do-raiden-shogun",
                    Price = 1500000m,
                    StockQuantity = 10,
                    CategoryId = 1,
                    BrandId = 1,
                    Image = "raiden.jpg"
                },
                new Product
                {
                    Id = 2,
                    Name = "Wig Furina xanh trắng",
                    Slug = "wig-furina-xanh-trang",
                    Price = 450000m,
                    StockQuantity = 20,
                    CategoryId = 2,
                    BrandId = 3,
                    Image = "furina-wig.jpg"
                },
                new Product
                {
                    Id = 3,
                    Name = "Đồ Agnes Tachyon cosplay",
                    Slug = "Agnes-Tachyon-cosplay",
                    Price = 300000m,
                    StockQuantity = 15,
                    CategoryId = 3,
                    BrandId = 2,
                    Image = "IMG_8626.jpg"
                },
                new Product
                {
                    Id = 4,
                    Name = "Đồ Gao Red coplay",
                    Slug = "gao-red-cosplay",
                    Price = 1200000m,
                    StockQuantity = 8,
                    CategoryId = 1,
                    BrandId = 1,
                    Image = "IMG_8601.jpg"
                },
                new Product
                {
                    Id = 5,
                    Name = "Đồ Columbina Cosplay",
                    Slug = "do-columbina-cosplay",
                    Price = 500000m,
                    StockQuantity = 25,
                    CategoryId = 2,
                    BrandId = 3,
                    Image = "IMG_8662.jpg"
                }
            );
        }
    }
}
