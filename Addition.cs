using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BasicCode
{
    internal class Addition
    {
        void add(int a, int b)
        {
            Console.WriteLine(  a + b);
        }

        void add(int a, float b)
        {
            Console.WriteLine(a + b);
        }

        void add(float a, int b)
        {
            Console.WriteLine(a + b);
        }

        void add(float a, float b)
        {
            Console.WriteLine(a + b);
        }

        void add(double a, float b,int c)
        {
            Console.WriteLine(a + b +c);
        }

        static void Main(string[] args)
        {
            Addition obj = new Addition();
            obj.add(1.0f, 20.0f,1);
        }
    }
}
