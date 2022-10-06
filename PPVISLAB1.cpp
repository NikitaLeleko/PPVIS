#include <iostream>
#include "Matrix.h"

using namespace std;

typedef int int32_t;

int main() {
    int choice;
    RealMatrix Matrix;
    bool flag = false;
    while (flag == false)
    {
        cout << "1 - Create Matrix." << endl;
        cout << "2 - Load Matrix From File." << endl;
        cout << "3 - Print Matrix." << endl;
        cout << "4 - Print Submatrix." << endl;
        cout << "5 - Resize Matrix." << endl;
        cout << "6 - Show Matrix View." << endl;
        cout << "7 - Transpose Matrix." << endl;
        cout << "8 - End Program." << endl;
        cout << "Choose an action: " << endl;
        cin >> choice;
            switch (choice) {

            case 1:
                int number_of_lines, number_of_columns;
                cout << "Enter size of matrix" << endl;
                cin >> number_of_lines >> number_of_columns;
                Matrix.CreateMatrix(number_of_lines, number_of_columns);
                break;

            case 2:
                Matrix.MatrixFromFile();
                cout << "Matrix is load" << endl;
                break;

            case 3:
                Matrix.Print("Your Matrix");
                break;

            case 4:
                int number_of_sublines, number_of_subcolumns;
                cout << "Enter size of submatrix" << endl;
                cin >> number_of_sublines >> number_of_subcolumns;
                Matrix.PrintSubMatrix(number_of_sublines, number_of_subcolumns);
                break;

            case 5:
                int resize_lines, resize_columns;
                cout << "Enter new size of matrix" << endl;
                cin >> resize_lines >> resize_columns;
                Matrix.ResizeMatrix(resize_lines, resize_columns);
                break;

            case 6:
                Matrix.CheckMatrixView();
                break;

            case 7:
                Matrix.Print("Original Matrix");
                Matrix.TransposedMatrix();
                Matrix.Print("Transposed Matrix");
                break;

            case 8:
                flag = true;
                break;
            }
    }
	return 0;
}
