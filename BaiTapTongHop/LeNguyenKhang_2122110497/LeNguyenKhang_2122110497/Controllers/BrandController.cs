using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using LeNguyenKhang_2122110497.Data;
using LeNguyenKhang_2122110497.Models;

namespace LeNguyenKhang_2122110497.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class BrandController : ControllerBase
    {
        private readonly AppDbContext _context;
        public BrandController(AppDbContext context) { _context = context; }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Brand>>> Get() => await _context.Brands.ToListAsync();

        [HttpPost]
        public async Task<ActionResult<Brand>> Post(Brand item)
        {
            _context.Brands.Add(item);
            await _context.SaveChangesAsync();
            return item;
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Put(int id, Brand item)
        {
            if (id != item.Id) return BadRequest();
            _context.Entry(item).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var item = await _context.Brands.FindAsync(id);
            if (item == null) return NotFound();
            _context.Brands.Remove(item);
            await _context.SaveChangesAsync();
            return NoContent();
        }
    }
}