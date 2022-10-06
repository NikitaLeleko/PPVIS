#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*!
 
    \brief  ����� "������������ �������".
      \authors ������ ������.

   ��������� ��� ������ "������������ �������" � ��������� �������������� �����������:
   1. ������� ������������� ������� � ������������ ���������� ������;
   2. ��������� ����� ����� � ����� ��������;
   3. �������� ������� �� �����;
   4. ���������� ���������� ��������� �������;
   5. �������� ���� ������� (����������, ������������, �������, ���������, ��������������,
������� �����������, ������ �����������);
   6. ����������������� �������.
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