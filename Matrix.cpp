#include "Matrix.h"
#include <fstream>

/*!
    \brief  ����� �������� �������.

    ������ ������� ������� original_lines �� original_columns. �������� original_lines � original_columns �������� ������������� � ����������.

    \param original_lines - ���������� ����� �������� �������.
    \param original_columns - ���������� �������� �������� �������.

    \code
    lines = original_lines;
    columns = original_columns;

    myMatrix.assign(lines, vector<int>(columns));//������ ����������� ������� �������� myMatrix.

    // ��������� ������� myMatrix �������������� ����������.
    for (int i = 0; i < original_lines; i++)
        for (int j = 0; j < original_columns; j++)
            cin >> myMatrix[i][j];
    \endcode
*/
void RealMatrix::CreateMatrix(int original_lines, int original_columns)
{
    lines = original_lines;
    columns = original_columns;

    myMatrix.assign(lines, vector<int>(columns));//������ ����������� ������� �������� myMatrix.

    // ��������� ������� myMatrix �������������� ����������.
    for (int i = 0; i < original_lines; i++)
        for (int j = 0; j < original_columns; j++)
            cin >> myMatrix[i][j];
}

/*!
    \brief  ����� ������ ������� � ���������� ����.

    ������� � ���������� ���� ��� ������� � ������� �����������.

    \param matrix_name - ��� �������, �������� �������������.

    \warning ���������� matrix_name ������� � ������������ ������ �������������.

    \code
    cout << "Matrix: " << matrix_name << endl;

    for (int i = 0; i < myMatrix.size(); i++) // ����, ������� ��� �� �������.
    {
        for (int j = 0; j < myMatrix[i].size(); j++) // ����, ������� ��� �� ���������.
            cout << myMatrix[i][j] << ' '; // ����� ��������� i ������ �������.
        cout << endl;
    }
    \endcode
*/
void RealMatrix::Print(const char* matrix_name)
{
    cout << "Matrix: " << matrix_name << endl;

    for (int i = 0; i < myMatrix.size(); i++) // ����, ������� ��� �� �������.
    {
        for (int j = 0; j < myMatrix[i].size(); j++) // ����, ������� ��� �� ���������.
            cout << myMatrix[i][j] << ' '; // ����� ��������� i ������ �������.
        cout << endl;
    }
}

/*!
    \brief  ����� ������ ���������� ��������� ������� � ���������� ����.

    ������� � ���������� ���� ��� ���������� � ���������� ������� sub_lines �� sub_columns �����������. �������� sub_lines � sub_columns �������� ������������� � ����������.

    \param sub_lines - ���������� ����� ����������.
    \param sub_columns - ���������� �������� ����������.


    \code
    if (sub_lines <= lines && sub_columns <= columns) {//���� ���������� ����� � �������� ���������� ������ ���� ����� ��������� ����� � �������� �������� �������, �� ������� ������� ������� sub_lines �� sub_columns �����������.

        cout << "Submatrix: " << endl;

        for (int i = 0; i < sub_lines; i++) {
            for (int j = 0; j < sub_columns; j++)
                cout << myMatrix[i][j] << " ";
            cout << endl;
        }
    }
    else {

        if (sub_lines >= lines && sub_columns >= columns) {//���� ���������� ����� � �������� ���������� ������ ���� ����� ��������� ����� � �������� �������� �������, �� ������� �������� �������.

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
    if (sub_lines <= lines && sub_columns <= columns) {//���� ���������� ����� � �������� ���������� ������ ���� ����� ��������� ����� � �������� �������� �������, �� ������� ������� ������� sub_lines �� sub_columns �����������.

        cout << "Submatrix: " << endl;

        for (int i = 0; i < sub_lines; i++) {
            for (int j = 0; j < sub_columns; j++)
                cout << myMatrix[i][j] << " ";
            cout << endl;
        }
    }
    else {

        if (sub_lines >= lines && sub_columns >= columns) {//���� ���������� ����� � �������� ���������� ������ ���� ����� ��������� ����� � �������� �������� �������, �� ������� �������� �������.

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
    \brief  ����� ��������� ������� �������� � ������ ����� ������� � ���������� ����.

    �������� ������ �������� ������� �� new_lines � new_columns � ������� ����� ������� � ���������� ����. �������� new_lines � new_columns �������� ������������� � ����������.

    \param new_lines - ���������� ����� ��������� �������.
    \param new_columns - ���������� �������� ��������� �������.


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
    \brief  ����� �������� ������� �� �����.

    ��������� �� ����� ���������� ����� � ���������� �������� �������. ��������� �������� ������� �� �����.


    \code
    ifstream fin("matrix.txt");
    int file_lines, file_columns;//��������� ���������� ��� ������ ���������� ����� � �������� �������.
    fin >> file_lines >> file_columns;//��������� �������� ���������� ����� � �������� �� �����.
    lines = file_lines;
    columns = file_columns;

    myMatrix.assign(lines, vector<int>(columns));//������ ����������� ���������� ������� myMatrix.

    // ��������� ������� myMatrix ���������� �� �����.
    for (int i = 0; i < file_lines; i++)
        for (int j = 0; j < file_columns; j++)
            fin >> myMatrix[i][j];
    \endcode
*/
void RealMatrix::MatrixFromFile()
{
    ifstream fin("matrix.txt");
    int file_lines, file_columns;//��������� ���������� ��� ������ ���������� ����� � �������� �������.
    fin >> file_lines >> file_columns;//��������� �������� ���������� ����� � �������� �� �����.
    lines = file_lines;
    columns = file_columns;

    myMatrix.assign(lines, vector<int>(columns));//������ ����������� ���������� ������� myMatrix.

    // ��������� ������� myMatrix ���������� �� �����.
    for (int i = 0; i < file_lines; i++)
        for (int j = 0; j < file_columns; j++)
            fin >> myMatrix[i][j];
}

/*!
    \brief  ����� �������� � ������ ���� �������.

    ��������� ���� �������. ������� ���� �������.


    \code
      bool zero = true;
    bool diagonal = true;
    bool single = true;
    bool square = true;
    bool symmetric = true;
    bool uptriagular = true;
    bool lowtriagular = true;

    for (int i = 0; i < myMatrix.size(); i++)// ����, ������� ��� �� �������.
        for (int j = 0; j < myMatrix[i].size(); j++) {// ����, ������� ��� �� ���������.
            if (myMatrix.size() != myMatrix[i].size())// �������� �� ���������� �������.
                square = false;

            if (myMatrix[i][j] != 0)//�������� �� ������� �������.
                zero = false; // �� �������
        }
    if (square == true) {//���� ������� ����������, ��������� �� ����: ������������ ��, ��������� ��, ������������ ��, ������� ��� ������ ����������� ��?
        for (int i = 0; i < myMatrix.size(); i++)
            for (int j = 0; j < myMatrix[i].size(); j++) {

                if (i != j && (myMatrix[i][j] != myMatrix[j][i]))
                    symmetric = false;

                if (myMatrix[i][j] != 0) {
                    zero = false; // �� �������

                    if (i != j) {
                        diagonal = false; // �� ������������
                        single = false; // �� ���������
                    }
                }

                if (i == j && myMatrix[i][j] != 1)
                    single = false; // �� ���������
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
    else {//���� ������� �� ����������, �� ��� �� ����� �������� �� ������������, �� ���������, �� ������������, �� ������� ��� ������ �����������.
        single = false;
        diagonal = false;
        symmetric = false;
        uptriagular = false;
        lowtriagular = false;
    }
    if (zero == true)//���� ������� �������, �� ��� �� ������������.
        diagonal = false;
    //����� ���� �������.
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

    for (int i = 0; i < myMatrix.size(); i++)// ����, ������� ��� �� �������.
        for (int j = 0; j < myMatrix[i].size(); j++) {// ����, ������� ��� �� ���������.
            if (myMatrix.size() != myMatrix[i].size())// �������� �� ���������� �������.
                square = false;

            if (myMatrix[i][j] != 0)//�������� �� ������� �������.
                zero = false; // �� �������
        }
    if (square) {//���� ������� ����������, ��������� �� ����: ������������ ��, ��������� ��, ������������ ��, ������� ��� ������ ����������� ��?
        for (int i = 0; i < myMatrix.size(); i++)
            for (int j = 0; j < myMatrix[i].size(); j++) {

                if (i != j && (myMatrix[i][j] != myMatrix[j][i]))
                    symmetric = false;

                if (myMatrix[i][j] != 0) {
                    zero = false; // �� �������

                    if (i != j) {
                        diagonal = false; // �� ������������
                        single = false; // �� ���������
                    }
                }

                if (i == j && myMatrix[i][j] != 1)
                    single = false; // �� ���������
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
    else {//���� ������� �� ����������, �� ��� �� ����� �������� �� ������������, �� ���������, �� ������������, �� ������� ��� ������ �����������.
        single = false;
        diagonal = false;
        symmetric = false;
        uptriagular = false;
        lowtriagular = false;
        cout << "Arbitrary matrix " << endl;
    }
    if (zero)//���� ������� �������, �� ��� �� ������������.
        diagonal = false;
    //����� ���� �������.
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
    \brief  ����� ���������������� �������.

    �������� �� ��������� ������� � ������������� �.


    \code
       int counter;//���������� ��� ������ �������� ��������� �������.
    for (int i = 0; i < myMatrix.size(); ++i)//����, ���������� �� �������.
    {
        for (int j = i; j < myMatrix[i].size(); ++j)//����, ���������� �� ��������� �������.
        {
            //���������������� �������.
            counter = myMatrix[i][j];
            myMatrix[i][j] = myMatrix[j][i];
            myMatrix[j][i] = counter;
        }
    }
    \endcode
*/
void RealMatrix::TransposedMatrix()
{
    int counter;//���������� ��� ������ �������� ��������� �������.
    for (int i = 0; i < myMatrix.size(); ++i)//����, ���������� �� �������.
    {
        for (int j = i; j < myMatrix[i].size(); ++j)//����, ���������� �� ��������� �������.
        {
            //���������������� �������.
            counter = myMatrix[i][j];
            myMatrix[i][j] = myMatrix[j][i];
            myMatrix[j][i] = counter;
        }
    }
}