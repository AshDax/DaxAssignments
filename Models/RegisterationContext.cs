using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;


namespace DotNet_Assign.Models
{
    public class RegisterationContext : DbContext
    {
        public RegisterationContext(DbContextOptions<RegisterationContext> options) : base(options)
        {

        }
        public DbSet<Registeration> Registeration { get; set; }
    }
}