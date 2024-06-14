using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Authentication;
using System.Text;
using System.Threading.Tasks;


namespace HomeWork 
{
    internal class Program
    {
        static void Main(string[] args) 
        {
            Console.WriteLine("Введите номер задания:");
            int taskNumber = int.Parse(Console.ReadLine());
            switch (taskNumber) 
            {
                case 1: Task1();
                    break;
                case 2: Task2();
                    break;
                case 3: Task3();
                    break;
                case 4: Task4();
                    break;
                case 5: Task5();
                    break;
                case 6: Task6();
                    break;
                case 7: Task7();
                    break;
                default: Console.WriteLine("Неизвестный номер");
                    break;
            }

            Console.WriteLine("Нажмите любую кнопку для выхода..");
            Console.ReadKey();

        }


        private static void Task1()
        {
            int a;
            Console.Write("Запишите числа в диапазоне от 1 до 100: ");
            string input = Console.ReadLine();
            if (int.TryParse(input, out a))
            {
                if (a >= 1 && a <= 100)
                {
                    if (a % 3 == 0)
                    {
                        Console.WriteLine($"Fizz");
                    }
                    if (a % 5 == 0)
                    {
                        Console.WriteLine($"Buzz");
                    }
                    else if (a % 3 == 0 && a % 5 == 0)
                    {
                        Console.WriteLine($"Fizz Buzz");
                    }
                    else
                    {
                        Console.WriteLine($"Вы ввели число: {a}");
                    }
                }
                else
                {
                    Console.WriteLine("Число не входит в диапазон от 1 до 100.");
                }
            }
            else
            {
                Console.WriteLine("Введено не число.");
            }

        }


        private static void Task2()
        {

            Console.Write("Введите число, первое-значение: ");
            double num = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите число, второе-процент: ");
            double per = Convert.ToDouble(Console.ReadLine());

            double result = (num * per) / 100;

            Console.WriteLine($"Результат: {result}%");

        }

        private static void Task3()
        {

            Console.Write("Ведите первое число: ");
            int a = Convert.ToInt32(Console.ReadLine());

            Console.Write("Ведите второе число: ");
            int b = Convert.ToInt32(Console.ReadLine());

            Console.Write("Ведите третье число: ");
            int c = Convert.ToInt32(Console.ReadLine());

            Console.Write("Ведите четвёртое число: ");
            int d = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Результат:" + " " + a + b + c + d);

        }

        private static void Task4()
        {

            Console.Write("Введите шестизначное число: ");
            string input = Console.ReadLine();

            if (input.Length != 6 || !int.TryParse(input, out _))
            {
                Console.WriteLine("Ошибка: введите корректное шестизначное число.");
                return;
            }

            Console.Write("Введите первый номер разряда для обмена (от 1 до 6): ");
            int pos1 = Convert.ToInt32(Console.ReadLine()) - 1;

            Console.Write("Введите второй номер разряда для обмена (от 1 до 6): ");
            int pos2 = Convert.ToInt32(Console.ReadLine()) - 1;

            if (pos1 < 0 || pos1 > 5 || pos2 < 0 || pos2 > 5)
            {
                Console.WriteLine("Ошибка: номера разрядов должны быть в диапазоне от 1 до 6.");
                return;
            }

            char[] digits = input.ToCharArray();

            // Обмен местами цифр
            (digits[pos1], digits[pos2]) = (digits[pos2], digits[pos1]);

            Console.WriteLine("Результат: " + new string(digits));

        }

        private static void Task5() 
        {
            String date;
            Console.WriteLine("Введите дату ММ:DD:YY");
            date = Console.ReadLine();
            DateTime dt = Convert.ToDateTime(date);
            Console.WriteLine(dt.ToLongDateString());
        }

        private static void Task6() 
        {
            Console.Write("Введите температуру в градусах Цельсия: ");
            double c = Convert.ToDouble(Console.ReadLine());
            double f = c * 9 / 5 + 32;
            Console.WriteLine("Температура по Фаренгейту равна: {0}", f);
            Console.ReadKey();
        }

        private static void Task7() 
        {
            Console.Write("Ведите первое число: ");
            int a = Convert.ToInt32(Console.ReadLine());

            Console.Write("Ведите второе число: ");
            int b = Convert.ToInt32(Console.ReadLine());

           for (int i = a; i < b; i++) 
            {
                if (i% 2 == 0) 
                {
                    Console.Write(i + " ");
                }
            }
            Console.ReadKey();

        }

    }
}