using Microsoft.AspNetCore.Mvc;

namespace MyFirstApplication.Controllers
{
    public class RegisterController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
