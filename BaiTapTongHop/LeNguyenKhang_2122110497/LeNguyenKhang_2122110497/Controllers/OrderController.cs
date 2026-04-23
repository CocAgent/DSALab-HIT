using LeNguyenKhang_2122110497.Data;
using LeNguyenKhang_2122110497.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace LeNguyenKhang_2122110497.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class OrderController : ControllerBase
    {
        private readonly AppDbContext _context;
        public OrderController(AppDbContext context) { _context = context; }

        [HttpPost]
        public IActionResult CreateOrder(Order order)
        {
            // 1. Lưu thông tin đơn hàng tổng quát
            _context.Orders.Add(order);
            _context.SaveChanges(); // Lúc này order.Id sẽ tự sinh ra

            // 2. Lưu chi tiết từng sản phẩm trong đơn hàng đó
            if (order.OrderDetails != null)
            {
                foreach (var detail in order.OrderDetails)
                {
                    detail.OrderId = order.Id; // Gán ID đơn hàng vừa tạo cho chi tiết
                    _context.OrderDetails.Add(detail);
                }
                _context.SaveChanges();
            }

            return Ok(new { message = "Đặt hàng thành công!", orderId = order.Id });
        }

        [HttpGet("{id}")]
        public IActionResult GetOrder(int id)
        {
            // Lấy đơn hàng kèm theo chi tiết sản phẩm bên trong
            var order = _context.Orders
                .Include(o => o.OrderDetails)
                .ThenInclude(d => d.Product)
                .FirstOrDefault(o => o.Id == id);

            if (order == null) return NotFound();
            return Ok(order);
        }
    
        // 3. CẬP NHẬT ĐƠN HÀNG (PUT) - Ví dụ đổi trạng thái đơn hàng
        [HttpPut("{id}")]
        public async Task<IActionResult> Put(int id, Order item)
        {
            if (id != item.Id) return BadRequest();
            _context.Entry(item).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return NoContent();
        }

        // 4. HỦY/XÓA ĐƠN HÀNG (DELETE)
        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var item = await _context.Orders.FindAsync(id);
            if (item == null) return NotFound();
            _context.Orders.Remove(item);
            await _context.SaveChangesAsync();
            return NoContent();
        }
    }
}
