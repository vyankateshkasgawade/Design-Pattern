using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BasicCode
{
    internal class UserInput
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Insert Your Name:");
            String name =  Console.ReadLine();

            Console.WriteLine("Insert Your Age:");
            String Age = Console.ReadLine();

            Console.WriteLine("Your Name Is :" + name + "\n"+ "Your Age Is :" + Age);
        }
    }
}
