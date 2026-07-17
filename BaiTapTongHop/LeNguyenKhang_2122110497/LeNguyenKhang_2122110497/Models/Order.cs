namespace LeNguyenKhang_2122110497.Models
{
    public class Order
    {
        public int Id { get; set; }
        public string CustomerName { get; set; }
        public string Phone { get; set; }
        public string Address { get; set; }
        public DateTime CreatedAt { get; set; }

        public List<Order_detail> OrderDetails { get; set; }
    }
}
