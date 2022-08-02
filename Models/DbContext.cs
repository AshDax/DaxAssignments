namespace DotNet_Assign.Models
{
    public class DbContext
    {
        private DbContextOptions<RegisterationContext> options;

        public DbContext(DbContextOptions<RegisterationContext> options)
        {
            this.options = options;
        }
    }
}