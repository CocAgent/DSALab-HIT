using System.ComponentModel.DataAnnotations.Schema;

namespace LeNguyenKhang_2122110497.Models
{
    public class Order_detail
    {
        public int Id { get; set; }

        public int OrderId { get; set; }
        public Order Order { get; set; }

        public int ProductId { get; set; }
        public Product Product { get; set; }

        public int Quantity { get; set; }
        public decimal Price { get; set; }
    }
}
