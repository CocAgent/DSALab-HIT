using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

#pragma warning disable CA1814 // Prefer jagged arrays over multidimensional

namespace LeNguyenKhang_2122110497.Migrations
{
    /// <inheritdoc />
    public partial class UpdateDatabaseV1 : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.InsertData(
                table: "Products",
                columns: new[] { "Id", "BrandId", "CategoryId", "Image", "Name", "Price", "Slug", "StockQuantity" },
                values: new object[,]
                {
                    { 3, 2, 3, "IMG_8626.jpg", "Đồ Agnes Tachyon cosplay", 300000m, "Agnes-Tachyon-cosplay", 15 },
                    { 4, 1, 1, "IMG_8601.jpg", "Đồ Gao Red coplay", 1200000m, "gao-red-cosplay", 8 },
                    { 5, 3, 2, "IMG_8662.jpg", "Đồ Columbina Cosplay", 500000m, "do-columbina-cosplay", 25 }
                });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Products",
                keyColumn: "Id",
                keyValue: 3);

            migrationBuilder.DeleteData(
                table: "Products",
                keyColumn: "Id",
                keyValue: 4);

            migrationBuilder.DeleteData(
                table: "Products",
                keyColumn: "Id",
                keyValue: 5);
        }
    }
}
