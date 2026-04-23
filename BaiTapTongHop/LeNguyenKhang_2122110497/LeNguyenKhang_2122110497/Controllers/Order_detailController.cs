using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using LeNguyenKhang_2122110497.Data;
using LeNguyenKhang_2122110497.Models;

namespace LeNguyenKhang_2122110497.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class OrderDetailController : ControllerBase
    {
        private readonly AppDbContext _context;
        public OrderDetailController(AppDbContext context) { _context = context; }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Order_detail>>> Get() => await _context.OrderDetails.ToListAsync();

        [HttpPost]
        public async Task<ActionResult<Order_detail>> Post(Order_detail item)
        {
            _context.OrderDetails.Add(item);
            await _context.SaveChangesAsync();
            return item;
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Put(int id, Order_detail item)
        {
            if (id != item.Id) return BadRequest();
            _context.Entry(item).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var item = await _context.OrderDetails.FindAsync(id);
            if (item == null) return NotFound();
            _context.OrderDetails.Remove(item);
            await _context.SaveChangesAsync();
            return NoContent();
        }
    }
}