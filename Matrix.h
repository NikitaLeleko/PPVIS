#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*!
 
    \brief  Класс "Вещественная матрица".
      \authors Никита Лелеко.

   Реализует тип данных "Вещественная матрица" и некоторые дополнительные возможности:
   1. Матрица произвольного размера с динамическим выделением памяти;
   2. Изменение числа строк и числа столбцов;
   3. Загрузка матрицы из файла;
   4. Извлечение подматрицы заданного размера;
   5. Проверка типа матрицы (квадратная, диагональная, нулевая, единичная, симметрическая,
верхняя треугольная, нижняя треугольная);
   6. Транспонированние матрицы.
*/
class RealMatrix {

private:

    vector<vector<int>> myMatrix;

    int lines;

    int columns;

public:

    void CreateMatrix(int original_lines, int original_columns);
    void Print(const char* matrix_name);
    void PrintSubMatrix(int sub_lines, int sub_columns);
    vector <vector <int>> ResizeMatrix(int new_lines, int new_columns);
    void MatrixFromFile();
    void CheckMatrixView();
    void TransposedMatrix();
};