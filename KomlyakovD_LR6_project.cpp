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
            Console.WriteLine("=== Работа с очередью ===\n");
            Console.WriteLine("Команды: push n, pop, front, size, clear, exit\n");
            
            Queue<int> queue = new Queue<int>();
            bool isRunning = true;
            
            while (isRunning)
            {
                Console.Write("> ");
                string input = Console.ReadLine();
                string[] parts = input.Split(' ');
                string command = parts[0].ToLower();
                
                switch (command)
                {
                    case "push":
                        if (parts.Length > 1 && int.TryParse(parts[1], out int n))
                        {
                            queue.Enqueue(n);
                            Console.WriteLine("ok");
                        }
                        else
                        {
                            Console.WriteLine("error");
                        }
                        break;
                        
                    case "pop":
                        if (queue.Count > 0)
                        {
                            Console.WriteLine(queue.Dequeue());
                        }
                        else
                        {
                            Console.WriteLine("error");
                        }
                        break;
                        
                    case "front":
                        if (queue.Count > 0)
                        {
                            Console.WriteLine(queue.Peek());
                        }
                        else
                        {
                            Console.WriteLine("error");
                        }
                        break;
                        
                    case "size":
                        Console.WriteLine(queue.Count);
                        break;
                        
                    case "clear":
                        queue.Clear();
                        Console.WriteLine("ok");
                        break;
                        
                    case "exit":
                        Console.WriteLine("bye");
                        isRunning = false;
                        break;
                        
                    default:
                        Console.WriteLine("error");
                        break;
                }
            }
            
            Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
            Console.ReadKey();
        }


        static void Zadanie3()
        {
            Console.Clear();
            Console.WriteLine("=== Решение уравнений ===\n");
            Console.WriteLine("Введите коэффициенты уравнения (от 1 до 3 чисел через пробел):");
            
            string input = Console.ReadLine();
            string[] parts = input.Split(' ', StringSplitOptions.RemoveEmptyEntries);
            double[] coefficients = new double[parts.Length];
            
            for (int i = 0; i < parts.Length; i++)
            {
                coefficients[i] = double.Parse(parts[i]);
            }
            
            double[] Solve(params double[] coeffs)
            {
                if (coeffs.Length == 3)
                {
                    double a = coeffs[0];
                    double b = coeffs[1];
                    double c = coeffs[2];
                    
                    if (Math.Abs(a) < 1e-10)
                    {
                        if (Math.Abs(b) < 1e-10)
                        {
                            return new double[0];
                        }
                        return new double[] { -c / b };
                    }
                    
                    double discriminant = b * b - 4 * a * c;
                    
                    if (discriminant < -1e-10)
                    {
                        return new double[0];
                    }
                    
                    if (Math.Abs(discriminant) < 1e-10)
                    {
                        double root = -b / (2 * a);
                        return new double[] { root };
                    }
                    
                    double sqrtDiscriminant = Math.Sqrt(discriminant);
                    double root1 = (-b - sqrtDiscriminant) / (2 * a);
                    double root2 = (-b + sqrtDiscriminant) / (2 * a);
                    
                    if (root1 < root2)
                    {
                        return new double[] { root1, root2 };
                    }
                    return new double[] { root2, root1 };
                }
                
                if (coeffs.Length == 2)
                {
                    double b = coeffs[0];
                    double c = coeffs[1];
                    
                    if (Math.Abs(b) < 1e-10)
                    {
                        return new double[0];
                    }
                    
                    return new double[] { -c / b };
                }
                
                if (coeffs.Length == 1)
                {
                    double c = coeffs[0];
                    
                    if (Math.Abs(c) < 1e-10)
                    {
                        return new double[] { 0 };
                    }
                    
                    return new double[0];
                }
                
                return new double[0];
            }
            
            void Print(params double[] roots)
            {
                if (roots.Length == 0)
                {
                    Console.WriteLine();
                    return;
                }
                
                for (int i = 0; i < roots.Length; i++)
                {
                    Console.Write(roots[i] + " ");
                }
                Console.WriteLine();
            }
            
            double[] roots = Solve(coefficients);
            Print(roots);
            
            Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
            Console.ReadKey();
        }

        static void Zadanie4()
        {
            Console.Clear();
            Console.WriteLine("=== Карточная игра ===\n");
            
            try
            {
                Console.WriteLine("Введите 3 карты первого игрока (числа от 1 до 9 через пробел):");
                string[] firstInput = Console.ReadLine().Split();
                
                Console.WriteLine("Введите 3 карты второго игрока (числа от 1 до 9 через пробел):");
                string[] secondInput = Console.ReadLine().Split();
                
                Queue<int> firstPlayer = new Queue<int>();
                Queue<int> secondPlayer = new Queue<int>();
                
                for (int i = 0; i < 3; i++)
                {
                    firstPlayer.Enqueue(int.Parse(firstInput[i]));
                    secondPlayer.Enqueue(int.Parse(secondInput[i]));
                }
                
                int moves = 0;
                bool gameOver = false;
                
                while (moves < 100 && !gameOver)
                {
                    if (firstPlayer.Count == 0)
                    {
                        Console.WriteLine($"second {moves}");
                        gameOver = true;
                        break;
                    }
                    
                    if (secondPlayer.Count == 0)
                    {
                        Console.WriteLine($"first {moves}");
                        gameOver = true;
                        break;
                    }
                    
                    int firstCard = firstPlayer.Dequeue();
                    int secondCard = secondPlayer.Dequeue();
                    
                    if (firstCard > secondCard)
                    {
                        firstPlayer.Enqueue(firstCard);
                        firstPlayer.Enqueue(secondCard);
                    }
                    else
                    {
                        secondPlayer.Enqueue(secondCard);
                        secondPlayer.Enqueue(firstCard);
                    }
                    
                    moves++;
                }
                
                if (!gameOver)
                {
                    Console.WriteLine("botva");
                }
            }
            catch
            {
                Console.WriteLine("Ошибка ввода данных");
            }
            
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