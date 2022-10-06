#include "Matrix.h"
#include <fstream>

/*!
    \brief  Метод создания матрицы.

    Создаёт матрицу размера original_lines на original_columns. Значения original_lines и original_columns вводятся пользователем с клавиатуры.

    \param original_lines - количество строк исходной матрицы.
    \param original_columns - количество столбцов исходной матрицы.

    \code
    lines = original_lines;
    columns = original_columns;

    myMatrix.assign(lines, vector<int>(columns));//Задать размерность вектора векторов myMatrix.

    // Заполнить матрицу myMatrix целочисленными значениями.
    for (int i = 0; i < original_lines; i++)
        for (int j = 0; j < original_columns; j++)
            cin >> myMatrix[i][j];
    \endcode
*/
void RealMatrix::CreateMatrix(int original_lines, int original_columns)
{
    lines = original_lines;
    columns = original_columns;

    myMatrix.assign(lines, vector<int>(columns));//Задать размерность вектора векторов myMatrix.

    // Заполнить матрицу myMatrix целочисленными значениями.
    for (int i = 0; i < original_lines; i++)
        for (int j = 0; j < original_columns; j++)
            cin >> myMatrix[i][j];
}

/*!
    \brief  Метод вывода матрицы в консольное окно.

    Выводит в консольное окно имя матрицы и матрицу поэлементно.

    \param matrix_name - имя матрицы, вводится разработчиком.

    \warning Переменная matrix_name задаётся и используется только разработчиком.

    \code
    cout << "Matrix: " << matrix_name << endl;

    for (int i = 0; i < myMatrix.size(); i++) // Цикл, который идёт по строкам.
    {
        for (int j = 0; j < myMatrix[i].size(); j++) // Цикл, который идёт по элементам.
            cout << myMatrix[i][j] << ' '; // Вывод элементов i строки вектора.
        cout << endl;
    }
    \endcode
*/
void RealMatrix::Print(const char* matrix_name)
{
    cout << "Matrix: " << matrix_name << endl;

    for (int i = 0; i < myMatrix.size(); i++) // Цикл, который идёт по строкам.
    {
        for (int j = 0; j < myMatrix[i].size(); j++) // Цикл, который идёт по элементам.
            cout << myMatrix[i][j] << ' '; // Вывод элементов i строки вектора.
        cout << endl;
    }
}

/*!
    \brief  Метод вывода подматрицы заданного размера в консольное окно.

    Выводит в консольное окно имя подматрицы и подматрицу размера sub_lines на sub_columns поэлементно. Значения sub_lines и sub_columns вводятся пользователем с клавиатуры.

    \param sub_lines - количество строк подматрицы.
    \param sub_columns - количество столбцов подматрицы.


    \code
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
    \endcode
*/
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

/*!
    \brief  Метод изменения размера матрицыи и вывода новой матрицы в консольное окно.

    Изменяет размер исходной матрицы на new_lines и new_columns и выводит новую матрицу в консольное окно. Значения new_lines и new_columns вводятся пользователем с клавиатуры.

    \param new_lines - количество строк изменённой матрицы.
    \param new_columns - количество столбцов изменённой матрицы.


    \code
    vector<vector<int>> helpMatrix;

    helpMatrix.assign(lines, vector<int>(columns));

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++)
            helpMatrix[i][j] = myMatrix[i][j];
    }

    if (new_lines <= lines && new_columns <= columns) {


        myMatrix.assign(new_lines, vector<int>(new_columns));

        for (int i = 0; i < new_lines; i++) {
            for (int j = 0; j < new_columns; j++)
                myMatrix[i][j] = helpMatrix[i][j];
        }
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
    }
    return myMatrix;
    \endcode
*/
vector <vector <int>> RealMatrix::ResizeMatrix(int new_lines, int new_columns)
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

/*!
    \brief  Метод загрузки матрицы из файла.

    Загружает из файла количество строк и количество столбцов матрицы. Загружает элементы матрицы из файла.


    \code
    ifstream fin("matrix.txt");
    int file_lines, file_columns;//Объявляем переменные для записи количества строк и столбуов матрицы.
    fin >> file_lines >> file_columns;//Считываем значения количества строк и столбцов из файла.
    lines = file_lines;
    columns = file_columns;

    myMatrix.assign(lines, vector<int>(columns));//Задать размерность двумерного вектора myMatrix.

    // Заполнить матрицу myMatrix значениями из файла.
    for (int i = 0; i < file_lines; i++)
        for (int j = 0; j < file_columns; j++)
            fin >> myMatrix[i][j];
    \endcode
*/
void RealMatrix::MatrixFromFile()
{
    ifstream fin("matrix.txt");
    int file_lines, file_columns;//Объявляем переменные для записи количества строк и столбуов матрицы.
    fin >> file_lines >> file_columns;//Считываем значения количества строк и столбцов из файла.
    lines = file_lines;
    columns = file_columns;

    myMatrix.assign(lines, vector<int>(columns));//Задать размерность двумерного вектора myMatrix.

    // Заполнить матрицу myMatrix значениями из файла.
    for (int i = 0; i < file_lines; i++)
        for (int j = 0; j < file_columns; j++)
            fin >> myMatrix[i][j];
}

/*!
    \brief  Метод проверки и вывода вида матрицы.

    Проверяет виды матрицы. Выводит виды матрицы.


    \code
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
    if (square == true)
     cout << "Square matrix " << endl;

    if (diagonal == true)
    cout << "Diagonal matrix " << endl;

    if (zero == true)
    cout << "Zero matrix " << endl;

    if (single == true)
    cout << "Single matrix " << endl;

    if (symmetric == true)
    cout << "Symmetric matrix " << endl;

    if (uptriagular == true)
    cout << "Uptriagular matrix " << endl;

    if (lowtriagular == true)
    cout << "Lowtriagular matrix " << endl;
    \endcode
*/
void RealMatrix::CheckMatrixView()
{
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
    if (square) {//Если матрица квадратная, проверяет на виды: диагональная ли, единичная ли, симметричная ли, верхняя или нижняя треугольная ли?
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
        cout << "Arbitrary matrix " << endl;
    }
    if (zero)//Если матрица нулевая, то она не диагональная.
        diagonal = false;
    //Вывод вида матрицы.
    if (square)

     cout << "Square matrix " << endl;

    if (diagonal)

    cout << "Diagonal matrix " << endl;

    if (zero)

    cout << "Zero matrix " << endl;

    if (single)

    cout << "Single matrix " << endl;

    if (symmetric)

    cout << "Symmetric matrix " << endl;

    if (uptriagular)

    cout << "Uptriagular matrix " << endl;

    if (lowtriagular)

    cout << "Lowtriagular matrix " << endl;
}
/*!
    \brief  Метод транспонирования матрицы.

    Проходит по элементам матрицы и транспонирует её.


    \code
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
    \endcode
*/
void RealMatrix::TransposedMatrix()
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
}