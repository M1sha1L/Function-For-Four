#include <iostream>
#include <vector>       // vector
#include <algorithm>    // sort()
#include <string>       // to_string()
#include <windows.h>    // Sleep()
#include <fstream>      // Взаимодействие с .txt
#include <chrono>       // Для секундомера

using namespace std;

//----------------------------------------------------------
// Реализация унарных функций целочисленного типа
//----------------------------------------------------------
// int ExampleFunction(int parameter)
// {
//      int output;
//      "Function: parameter -> output";
//      return output;
// }
//----------------------------------------------------------
// Треугольное число
int TriangularNumber(int parameter)
{
    int output = 0;
    for (int i = 1; i <= parameter; i++)
        output += i;
    return output;
}
//----------------------------------------------------------
// Треугольное число (нерекурсивная реализация)
int TriangularNumber_2(int parameter)
{
    return parameter * (parameter + 1) / 2;
}
//----------------------------------------------------------
// Фаториал
int Factorial(int parameter)
{
    int output = 1;
    for (int i = 1; i <= parameter; i++)
        output *= i;
    return output;
}
//----------------------------------------------------------
// Аликвотная сумма
int AliquotSum(int parameter)
{
    int output = 0;
    for (int i = 1; i < parameter; i++)
        if (parameter % i == 0)
            output += i;
    return output;
}
//----------------------------------------------------------
// Функция Эйлера
int EulerTotientFunction(int parameter)
{
    int output = parameter - 1;
    for (int i = 2; i < parameter; i++)
        for (int j = 2; j <= i; j++)
            if (parameter % j == 0 && i % j == 0)
            {
                output--;
                break;
            }
    return output;
}
//----------------------------------------------------------
// Добавление элемента в вектор чисел и сортировка
void AddToVector(int number, vector<int>& main_vector)
{
    for (int i = 0; i < main_vector.size(); i++)
        if (main_vector[i] == number)
            return;
    main_vector.push_back(number);
    sort(main_vector.begin(),main_vector.end());
    return;
}
//----------------------------------------------------------
// Прорабока функций для всех найденных чисел и добавление новых в массив
void UseFunctions(vector<int>& main_vector)
{
    vector<int> results = {};
    vector<string> output = {};
    for (int i = 0; i < main_vector.size(); i++)
    {
        // Название некой функции
        // if (main_vector[i] < ограничитель входного значения)
        //    results.push_back(функция(main_vector[i]));
        
        // Треугольное число
        if (main_vector[i] < 200 && main_vector[i] > 0)
            results.push_back(TriangularNumber(main_vector[i]));

        // Факториал
        if (main_vector[i] < 10 && main_vector[i] > 0)
            results.push_back(Factorial(main_vector[i]));

        // Аликвотная сумма
        if (main_vector[i] < 10000 && main_vector[i] > 0)
            results.push_back(AliquotSum(main_vector[i]));

        // Функция Эйлера
        if (main_vector[i] < 10000 && main_vector[i] > 0)
            results.push_back(EulerTotientFunction(main_vector[i]));
    }

    for (int i = 0; i < results.size(); i++)
        AddToVector(results[i], main_vector);
}
//----------------------------------------------------------
// Вывод результатов в консоль
void ConsoleOutput(vector<int>& main_vector)
{
    vector<string> output = {};
    for (int i = 0; i < main_vector.size(); i++)
    {
        // Треугольное число
        if (main_vector[i] < 200)
            output.push_back(to_string(TriangularNumber(main_vector[i])));
        else
            output.push_back(">20k");

        // Факториал
        if (main_vector[i] < 10)
            output.push_back(to_string(Factorial(main_vector[i])));
        else
            output.push_back(">1kk");

        // Аликвотная сумма
        if (main_vector[i] < 10000)
            output.push_back(to_string(AliquotSum(main_vector[i])));
        else
            output.push_back(">10k");

        cout << main_vector[i] << "\t\t" << output[0] << "\t\t" << output[1] << "\t\t" << output[2] << "\n"; //"\t" << EulerTotientFunction(main_vector[i]) << endl;

        output = {};
    }
}
//----------------------------------------------------------
// Вывод результатов в файл
void FileOutput(vector<int>& main_vector)
{
    ofstream file("data.txt");
    if (!file.is_open())
        return;

    vector<string> output = {};
    file << "Number\t\tTriangular\tFactorial\tAliquot Sum\tEuler's Fun\n";

    for (int i = 0; i < main_vector.size(); i++)
    {
        // Треугольное число
        if (main_vector[i] < 200)
            output.push_back(to_string(TriangularNumber(main_vector[i])));
        else
            output.push_back(">20k");

        // Факториал
        if (main_vector[i] < 10)
            output.push_back(to_string(Factorial(main_vector[i])));
        else
            output.push_back(">1kk");

        // Аликвотная сумма
        if (main_vector[i] < 10000)
            output.push_back(to_string(AliquotSum(main_vector[i])));
        else
            output.push_back(">10k");

        // Функция Эйлера
        if (main_vector[i] < 10000)
            output.push_back(to_string(EulerTotientFunction(main_vector[i])));
        else
            output.push_back(">10k");

        file << main_vector[i] << "\t\t" << output[0] << "\t\t" << output[1] << "\t\t" << output[2] << "\t\t" << output[3] << "\n";

        //file << main_vector[i] << "\n";

        output = {};
    }
}

int main()
{
    // Вектор для всех найденных чисел. Задать начальное число в виде { n }
    vector<int> main_vector = { 4 };

    // Счётчик кол-ва итераций, для исключения зацикливания
    int counter = 0;

    //
    int size = 0;

    cout << "Iter\tNumbers\tTime\n";

Functions:
    // Создание секундомера
    auto start_time = chrono::high_resolution_clock::now();

    size = int(main_vector.size());
    UseFunctions(main_vector);

    // Подсчёт времени итерации
    auto stop_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = stop_time - start_time;

    // Вывод информации об итерации
    cout << counter << "\t" << main_vector.size() << "\t" << elapsed_time.count() << endl;
    counter++;

    if (size == main_vector.size())
    {
        FileOutput(main_vector);
        return 0;
    }

    if (main_vector.size() < 100)
        goto Functions;
    for (int i = 0; i < 100; i++)
        if (main_vector[i] != i)
            goto Functions;

    return 0;
}