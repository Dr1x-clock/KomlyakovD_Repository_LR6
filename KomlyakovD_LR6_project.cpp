using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KomlyakovD_LR3_project
{
    public class Program
    {
        static void Main(string[] args)
        {
            //Комляков Д.
            while (true)
            {
                Console.Clear();
                Console.WriteLine("Выберите задание:");
                Console.WriteLine("1: Лайнландия - одномерный мир");
                Console.WriteLine("2: Работа очереди");
                Console.WriteLine("3: Коэффициенты уравнения");
                Console.WriteLine("4: Карточная игра");
                Console.WriteLine("5: Работа с классом Rectangle ");
                Console.WriteLine("6: Минимальный вес еды");
                Console.WriteLine("7: Неориентированный невзвешенный граф");
                Console.WriteLine("0: Выход из программы");
                Console.Write("Введите ваш выбор: ");

                string choice = Console.ReadLine();

                if (choice == "0")
                {
                    break;
                }

                switch (choice)
                {
                    case "1":
                        Zadanie1();
                        break;
                    case "2":
                        Zadanie2();
                        break;
                    case "3":
                        Zadanie3();
                        break;
                    case "4":
                        Zadanie4();
                        break;
                    case "5":
                        Zadanie5();
                        break;
                    case "6":
                        Zadanie6();
                        break;
                    case "7":
                        Zadanie7();
                        break;
                    default:
                        Console.WriteLine("Некорректный выбор! Введите число от 0 до 7");
                        Console.WriteLine("Нажмите любую клавишу для продолжения...");
                        Console.ReadKey();
                        break;
                }
            }
        }

        static void Zadanie1()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню.");
        Console.ReadKey();
        }

        static void Zadanie2()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
        Console.ReadKey();
        }


        static void Zadanie3()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
        Console.ReadKey();
        }

        static void Zadanie4()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
        Console.ReadKey();
        }

        static void Zadanie5()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
        Console.ReadKey();
        }

        static void Zadanie6()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
        Console.ReadKey();
        }

        static void Zadanie7()
        {
        Console.Clear();


        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
        Console.ReadKey();
        }

        
    }
}