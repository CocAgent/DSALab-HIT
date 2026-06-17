using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using LeNguyenKhang_2122110497.Data; // Kiểm tra lại tên namespace Data của bạn
using LeNguyenKhang_2122110497.Models;

namespace LeNguyenKhang_2122110497.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CategoryController : ControllerBase
    {
        private readonly AppDbContext _context; // Nhớ đổi tên Context cho đúng với máy bạn

        public CategoryController(AppDbContext context)
        {
            _context = context;
        }

        // --- COPY CÁC ĐOẠN DƯỚI ĐÂY ---

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Category>>> Get() => await _context.Categories.ToListAsync();

        [HttpPost]
        public async Task<ActionResult<Category>> Post(Category item)
        {
            _context.Categories.Add(item);
            await _context.SaveChangesAsync();
            return item;
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Put(int id, Category item)
        {
            if (id != item.Id) return BadRequest();
            _context.Entry(item).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var item = await _context.Categories.FindAsync(id);
            if (item == null) return NotFound();
            _context.Categories.Remove(item);
            await _context.SaveChangesAsync();
            return NoContent();
        }
    }
}