using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using LeNguyenKhang_2122110497.Data;
using LeNguyenKhang_2122110497.Models;

// ĐƯA CÁC MODEL RA NGOÀI ĐỂ KHÔNG LÀM NHIỄU CONTROLLER
public class LoginDTO
{
    public string Username { get; set; }
    public string Password { get; set; }
}

public class LoginModel
{
    public string Username { get; set; }
    public string Password { get; set; }
}

[Route("api/[controller]")]
[ApiController]
public class UserController : ControllerBase
{
    private readonly AppDbContext _context;

    public UserController(AppDbContext context)
    {
        _context = context;
    }

    // 1. GET ALL
    [HttpGet]
    public async Task<ActionResult<IEnumerable<User>>> GetUsers()
    {
        return await _context.Users.ToListAsync();
    }

    // 2. GET BY ID
    [HttpGet("{id}")]
    public async Task<ActionResult<User>> GetUser(int id)
    {
        var user = await _context.Users.FindAsync(id);
        if (user == null) return NotFound();
        return user;
    }

    // 3. LOGIN
    [HttpPost("login")]
    public IActionResult Login([FromBody] LoginModel loginInfo)
    {
        var user = _context.Users.FirstOrDefault(u =>
            u.Username == loginInfo.Username && u.Password == loginInfo.Password);

        if (user == null)
        {
            return Unauthorized(new { message = "Sai tài khoản hoặc mật khẩu!" });
        }

        return Ok(new { id = user.Id, username = user.Username, fullName = user.FullName, role = user.Role });
    }

    // 4. POST (THÊM)
    [HttpPost]
    public async Task<ActionResult<User>> PostUser(User user)
    {
        _context.Users.Add(user);
        await _context.SaveChangesAsync();
        return CreatedAtAction("GetUser", new { id = user.Id }, user);
    }

    // 5. PUT (SỬA)
    [HttpPut("{id}")]
    public async Task<IActionResult> PutUser(int id, User user)
    {
        if (id != user.Id) return BadRequest();
        _context.Entry(user).State = EntityState.Modified;
        try { await _context.SaveChangesAsync(); }
        catch (DbUpdateConcurrencyException)
        {
            if (!_context.Users.Any(e => e.Id == id)) return NotFound();
            else throw;
        }
        return NoContent();
    }

    // 6. DELETE (XÓA)
    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteUser(int id)
    {
        var user = await _context.Users.FindAsync(id);
        if (user == null) return NotFound();
        _context.Users.Remove(user);
        await _context.SaveChangesAsync();
        return NoContent();
    }
}