using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Authentication;
using System.Text;
using System.Threading.Tasks;


namespace HomeWork 
{
 class Tasks1 
    {
    //    static void Main() 
    //    {
    //        int a;
    //       Console.Write("Запишите числа в диапазоне от 1 до 100: ");
    //        string input = Console.ReadLine();
    //        if(int.TryParse(input, out a)) 
    //        {
    //            if(a >= 1 && a <= 100) 
    //            { if (a % 3 == 0)
    //                {
    //                    Console.WriteLine($"Fizz");
    //                }
    //                if (a % 5 == 0)
    //                {
    //                    Console.WriteLine($"Buzz");
    //                } 
    //                else if (a % 3 == 0 && a % 5 == 0) 
    //                {
    //                    Console.WriteLine($"Fizz Buzz");
    //                }
    //                else
    //                {
    //                    Console.WriteLine($"Вы ввели число: {a}");
    //                }
    //            }
    //            else 
    //            {
    //                Console.WriteLine("Число не входит в диапазон от 1 до 100.");
    //            }
    //        }
    //        else 
    //        {
    //            Console.WriteLine("Введено не число.");
    //        }

    //    }
    }

    //class Tasks2 
    //{
    //    public static void Main() 
    //    {
    //        Console.Write("Введите число, первое-значение: ");
    //        double num = Convert.ToDouble(Console.ReadLine());
    //        Console.Write("Введите число, второе-процент: ");
    //        double per = Convert.ToDouble(Console.ReadLine());

    //        double result = (num * per) / 100;

    //        Console.WriteLine($"Результат: {result}%");
    //    }
    //}

    //class Tasks3 
    //{
    //    public static void Main() 
    //    {
    //        Console.Write("Ведите первое число: ");
    //        int a = Convert.ToInt32(Console.ReadLine());

    //        Console.Write("Ведите второе число: ");
    //        int b = Convert.ToInt32(Console.ReadLine());

    //        Console.Write("Ведите третье число: ");
    //        int c = Convert.ToInt32(Console.ReadLine());

    //        Console.Write("Ведите четвёртое число: ");
    //        int d = Convert.ToInt32(Console.ReadLine());

    //        Console.WriteLine("Результат:" + " " + a + b + c + d);
    //    }
    //}

    //class Task4 
    //{
    //    public static void Main() 
    //    {
    //        Console.Write("Введите шестизначное число: ");
    //        string input = Console.ReadLine();

    //        if (input.Length != 6 || !int.TryParse(input, out _))
    //        {
    //            Console.WriteLine("Ошибка: введите корректное шестизначное число.");
    //            return;
    //        }

    //        Console.Write("Введите первый номер разряда для обмена (от 1 до 6): ");
    //        int pos1 = Convert.ToInt32(Console.ReadLine()) - 1;

    //        Console.Write("Введите второй номер разряда для обмена (от 1 до 6): ");
    //        int pos2 = Convert.ToInt32(Console.ReadLine()) - 1;

    //        if (pos1 < 0 || pos1 > 5 || pos2 < 0 || pos2 > 5)
    //        {
    //            Console.WriteLine("Ошибка: номера разрядов должны быть в диапазоне от 1 до 6.");
    //            return;
    //        }

    //        char[] digits = input.ToCharArray();

    //        // Обмен местами цифр
    //        (digits[pos1], digits[pos2]) = (digits[pos2], digits[pos1]);

    //        Console.WriteLine("Результат: " + new string(digits));
    //    }
    //}
}