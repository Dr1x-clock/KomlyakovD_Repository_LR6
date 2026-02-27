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
            Console.WriteLine("=== Лайнландия - одномерный мир ===\n");
            
            try
            {
                Console.Write("Введите количество городов N (2 ≤ N ≤ 100): ");
                int N = int.Parse(Console.ReadLine());
                
                if (N < 2 || N > 100)
                {
                    Console.WriteLine("Ошибка: N должно быть от 2 до 100!");
                    Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
                    Console.ReadKey();
                    return;
                }
                
                Console.WriteLine($"Введите {N} чисел - цены проживания в городах (от 0 до 10^9):");
                string[] input = Console.ReadLine().Split();
                
                if (input.Length != N)
                {
                    Console.WriteLine($"Ошибка: нужно ввести ровно {N} чисел!");
                    Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
                    Console.ReadKey();
                    return;
                }
                
                long[] prices = new long[N];
                for (int i = 0; i < N; i++)
                {
                    prices[i] = long.Parse(input[i]);
                    if (prices[i] < 0 || prices[i] > 1000000000)
                    {
                        Console.WriteLine("Ошибка: цена должна быть от 0 до 10^9!");
                        Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
                        Console.ReadKey();
                        return;
                    }
                }
                
                int[] result = new int[N];
                
                for (int i = 0; i < N; i++)
                {
                    result[i] = -1;
                    
                    for (int j = i + 1; j < N; j++)
                    {
                        if (prices[j] < prices[i])
                        {
                            result[i] = j;
                            break;
                        }
                    }
                }
                
                Console.WriteLine("\nРезультат (для каждого города номер города переселения):");
                for (int i = 0; i < N; i++)
                {
                    Console.Write(result[i] + " ");
                }
                Console.WriteLine();
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: введены некорректные данные!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
            
            Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
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