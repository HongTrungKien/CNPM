// See https://aka.ms/new-console-template for more information
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace testclassC_
{
    internal class Program
    {
        static void Main(string[] arr)
        {
            // Tạo các đối tượng Person
            Person student1 = new Person(1, "Nguyen Van Kien");
            Person student2 = new Person(2, "Lan");

            // So sánh chiều dài tên
            Console.WriteLine(student1.CompareNameLength(student2));
        }

    }
}



