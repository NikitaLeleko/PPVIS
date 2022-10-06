#ifndef PCH_H
#include <iostream>
#include <fstream>
#include <vector>
#define PCH_H

using namespace std;

class RealMatrix {

private:

public:

    int lines;
    int columns;

    vector <vector<int>> myMatrix;
    vector<vector <int>> CreateMatrix(int original_lines, int original_columns);
    vector<vector <int>> Print(const char* matrix_name);
    void PrintSubMatrix(int sub_lines, int sub_columns);
    vector<vector <int>> ResizeMatrix(int new_lines, int new_columns);
    vector<vector <int>> MatrixFromFile();
    vector <string> CheckMatrixView();
    vector<vector <int>> TransposedMatrix();
};

#endif //PCH_H
