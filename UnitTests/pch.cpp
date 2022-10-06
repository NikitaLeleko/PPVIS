// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> RealMatrix::CreateMatrix(int original_lines, int original_columns)
{
    lines = original_lines;
    columns = original_columns;

    myMatrix.assign(lines, vector<int>(columns));//Задать размерность вектора векторов myMatrix.

    // Заполнить матрицу myMatrix целочисленными значениями.
   for (int i = 0; i < original_lines; i++)
        for (int j = 0; j < original_columns; j++)
            cin >> myMatrix[i][j];
    return myMatrix;
}

vector<vector <int>> RealMatrix::Print(const char* matrix_name)
{
    cout << "Matrix: " << matrix_name << endl;

    for (int i = 0; i < myMatrix.size(); i++) // Цикл, который идёт по строкам.
    {
        for (int j = 0; j < myMatrix[i].size(); j++) // Цикл, который идёт по элементам.
            cout << myMatrix[i][j] << ' '; // Вывод элементов i строки вектора.
        cout << endl;
    }
    return myMatrix;
}

void RealMatrix::PrintSubMatrix(int sub_lines, int sub_columns)
{
    if (sub_lines <= lines && sub_columns <= columns) {//Если количество строк и столбцов подматрицы меньше либо равны количесву строк и столбцов исходной матрицы, то выводит матрицу размера sub_lines на sub_columns поэлементно.

        cout << "Submatrix: " << endl;

        for (int i = 0; i < sub_lines; i++) {
            for (int j = 0; j < sub_columns; j++)
                cout << myMatrix[i][j] << " ";
            cout << endl;
        }
    }
    else {

        if (sub_lines >= lines && sub_columns >= columns) {//Если количество строк и столбцов подматрицы больше либо равны количесву строк и столбцов исходной матрицы, то выводит исходную матрицу.

            cout << "Submatrix: " << endl;

            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < columns; j++)
                    cout << myMatrix[i][j] << " ";
                cout << endl;
            }
        }
    }
}



vector<vector <int>> RealMatrix::ResizeMatrix(int new_lines, int new_columns)
{
    vector<vector<int>> helpMatrix;

    if (new_lines <= lines && new_columns <= columns) {

        helpMatrix.assign(new_lines, vector<int>(new_columns));

        for (int i = 0; i < new_lines; i++) {
            for (int j = 0; j < new_columns; j++)
                helpMatrix[i][j] = myMatrix[i][j];
        }
    }
    if (new_lines >= lines && new_columns >= columns) {

        helpMatrix.assign(lines, vector<int>(columns));

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++)
                helpMatrix[i][j] = myMatrix[i][j];
        }

    }

    if (new_lines <= lines && new_columns <= columns) {


        myMatrix.assign(new_lines, vector<int>(new_columns));

        for (int i = 0; i < new_lines; i++) {
            for (int j = 0; j < new_columns; j++)
                myMatrix[i][j] = helpMatrix[i][j];
        }
        lines = new_lines;
        columns = new_columns;
    }
    if (new_lines > lines && new_columns == columns) {

        myMatrix.assign(new_lines, vector<int>(columns));

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++)
                myMatrix[i][j] = helpMatrix[i][j];
        }

        for (int i = lines; i < new_lines; i++) {
            for (int j = 0; j < columns; j++)
                cin >> myMatrix[i][j];
        }
        lines = new_lines;
    }
    if (new_lines == lines && new_columns > columns) {

        myMatrix.assign(lines, vector<int>(new_columns));

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++)
                myMatrix[i][j] = helpMatrix[i][j];
        }

        for (int j = columns; j < new_columns; j++) {
            for (int i = 0; i < lines; i++)
                cin >> myMatrix[i][j];
        }
        columns = new_columns;
    }
    if (new_lines > lines && new_columns > columns) {

        myMatrix.assign(new_lines, vector<int>(columns));

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++)
                myMatrix[i][j] = helpMatrix[i][j];
        }

        for (int i = lines; i < new_lines; i++) {
            for (int j = 0; j < columns; j++)
                cin >> myMatrix[i][j];
        }

        helpMatrix.assign(new_lines, vector<int>(columns));

        for (int i = 0; i < new_lines; i++) {
            for (int j = 0; j < columns; j++)
                helpMatrix[i][j] = myMatrix[i][j];
        }

        myMatrix.assign(new_lines, vector<int>(new_columns));

        for (int i = 0; i < new_lines; i++) {
            for (int j = 0; j < columns; j++)
                myMatrix[i][j] = helpMatrix[i][j];
        }

        for (int j = columns; j < new_columns; j++) {
            for (int i = 0; i < new_lines; i++)
                cin >> myMatrix[i][j];
        }
        lines = new_lines;
        columns = new_columns;
    }

    return myMatrix;
}

vector<vector <int>> RealMatrix::MatrixFromFile()
{
    ifstream fin("testmatrix.txt");
    int file_lines, file_columns;//Объявляем переменные для записи количества строк и столбуов матрицы.
    fin >> file_lines >> file_columns;//Считываем значения количества строк и столбцов из файла.
    lines = file_lines;
    columns = file_columns;

    myMatrix.assign(file_lines, vector<int>(file_columns));//Задать размерность двумерного вектора myMatrix.

    // Заполнить матрицу myMatrix значениями из файла.
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            fin >> myMatrix[i][j];
    return myMatrix;
}


vector <string> RealMatrix::CheckMatrixView()
{
    vector <string> view(7, "n");
    bool zero = true;
    bool diagonal = true;
    bool single = true;
    bool square = true;
    bool symmetric = true;
    bool uptriagular = true;
    bool lowtriagular = true;

    for (int i = 0; i < myMatrix.size(); i++)// Цикл, который идёт по строкам.
        for (int j = 0; j < myMatrix[i].size(); j++) {// Цикл, который идёт по элементам.
            if (myMatrix.size() != myMatrix[i].size())// Проверка на квадратную матрицу.
                square = false;

            if (myMatrix[i][j] != 0)//Проверка на нулевую матрицу.
                zero = false; // не нулевая
        }
    if (square == true) {//Если матрица квадратная, проверяет на виды: диагональная ли, единичная ли, симметричная ли, верхняя или нижняя треугольная ли?
        for (int i = 0; i < myMatrix.size(); i++)
            for (int j = 0; j < myMatrix[i].size(); j++) {

                if (i != j && (myMatrix[i][j] != myMatrix[j][i]))
                    symmetric = false;

                if (myMatrix[i][j] != 0) {
                    zero = false; // не нулевая

                    if (i != j) {
                        diagonal = false; // не диагональная
                        single = false; // не единичная
                    }
                }

                if (i == j && myMatrix[i][j] != 1)
                    single = false; // не единичная
            }
        for (int i = 0; i < myMatrix.size(); i++)
            for (int j = i + 1; j < myMatrix[i].size(); j++) {
                if (myMatrix[i][j] != 0)
                    lowtriagular = false;
            }
        for (int i = myMatrix.size() - 1; i > 0; i--)
            for (int j = i - 1; j >= 0; j--) {
                if (myMatrix[i][j] != 0)
                    uptriagular = false;
            }
    }
    else {//Если матрица не квадратная, то она не может являться ни диагональной, ни единичной, ни симметричной, ни верхней или нижней треугольной.
        single = false;
        diagonal = false;
        symmetric = false;
        uptriagular = false;
        lowtriagular = false;
    }
    if (zero == true)//Если матрица нулевая, то она не диагональная.
        diagonal = false;
    //Вывод вида матрицы.
    if (square == true) {
        cout << "Square matrix " << endl;
        view[0] = "y";
    }
    if (diagonal == true) {
        cout << "Diagonal matrix " << endl;
        view[1] = "y";
    }
    if (zero == true) {
        cout << "Zero matrix " << endl;
        view[2] = "y";
    }
    if (single == true) {
        cout << "Single matrix " << endl;
        view[3] = "y";
    }
    if (symmetric == true) {
        cout << "Symmetric matrix " << endl;
        view[4] = "y";
    }
    if (uptriagular == true) {
        cout << "Uptriagular matrix " << endl;
        view[5] = "y";
    }
    if (lowtriagular == true) {
        cout << "Lowtriagular matrix " << endl;
        view[6] = "y";
    }
    return view;
}

vector<vector <int>> RealMatrix::TransposedMatrix()
{
    int counter;//Переменная для записи значений элементов матрицы.
    for (int i = 0; i < myMatrix.size(); ++i)//Цикл, проходящий по строкам.
    {
        for (int j = i; j < myMatrix[i].size(); ++j)//Цикл, проходящий по элементам матрицы.
        {
            //Транспонирование матрицы.
            counter = myMatrix[i][j];
            myMatrix[i][j] = myMatrix[j][i];
            myMatrix[j][i] = counter;
        }
    }
    return myMatrix;
}


// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
