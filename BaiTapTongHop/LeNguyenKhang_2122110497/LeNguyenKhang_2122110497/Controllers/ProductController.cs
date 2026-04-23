using LeNguyenKhang_2122110497.Data;
using LeNguyenKhang_2122110497.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace LeNguyenKhang_2122110497.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ProductController : ControllerBase
    {
        private readonly AppDbContext _context;
        public ProductController(AppDbContext context) { _context = context; }

        // GET: api/Product
        [HttpGet]
        public IActionResult GetAll()
        {
            var products = _context.Products
                .Include(p => p.Category)
                .Include(p => p.Brand)
                .Select(p => new {
                    p.Id,
                    p.Name,
                    p.Slug,
                    p.Price,
                    p.StockQuantity,
                    p.Image,
                    CategoryName = p.Category != null ? p.Category.Name : "N/A",
                    BrandName = p.Brand != null ? p.Brand.Name : "N/A"
                })
                .ToList();

            return Ok(products);
        }

   
        [HttpPost]
        public async Task<ActionResult<Product>> Post(Product item)
        {
            _context.Products.Add(item);
            await _context.SaveChangesAsync();
            return item;
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Put(int id, Product item)
        {
            if (id != item.Id) return BadRequest();
            _context.Entry(item).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var item = await _context.Products.FindAsync(id);
            if (item == null) return NotFound();
            _context.Products.Remove(item);
            await _context.SaveChangesAsync();
            return NoContent();
        }
    }
}