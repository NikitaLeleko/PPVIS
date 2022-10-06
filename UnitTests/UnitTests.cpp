#include "pch.h"
#include "CppUnitTest.h"
#include <iostream> 
#include <fstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		RealMatrix testMatrix;
		TEST_METHOD(Test_transposed)
		{
			vector <vector <int>> testtransposed = { {2, 4, 5}, {4, 6, 2}, {6, 9, 0} };
			testMatrix.myMatrix = { {2, 4, 6}, {4, 6, 9}, {5, 2, 0} };
			testMatrix.TransposedMatrix();
			Assert::IsTrue(testMatrix.myMatrix == testtransposed);
		}
		TEST_METHOD(Test_print)
		{
			testMatrix.myMatrix = { {1, 2, 3, 4}, {2, 5, 6, 7}, {3, 6, 8, 9}, {4, 7, 9, 3} };
			vector <vector <int>> testcreate = { {1, 2, 3, 4}, {2, 5, 6, 7}, {3, 6, 8, 9}, {4, 7, 9, 3} };
			Assert::IsTrue(testMatrix.Print("My Matrix") == testcreate);
		}
		TEST_METHOD(Test_view_1)
		{
			vector <string> view_1 = {"y","n","n","n","n","y","n"};
			testMatrix.myMatrix = { {1, 2, 3, 4}, {0, 5, 6, 7}, {0, 0, 8, 9}, {0, 0, 0, 3} };
			Assert::IsTrue(testMatrix.CheckMatrixView() == view_1);
		}
		TEST_METHOD(Test_view_2)
		{
			vector <string> view_2 = { "y","n","y","n","n","n","n" };
			testMatrix.myMatrix = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
			Assert::IsTrue(testMatrix.CheckMatrixView() == view_2);
		}
		TEST_METHOD(Test_resize) 
		{
			int a = 3, b = 3;
			testMatrix.myMatrix = { {1, 2, 3, 4}, {2, 5, 6, 7}, {3, 6, 8, 9}, {4, 7, 9, 3} };
			vector <vector <int>> testresize = { {1, 2, 3}, {2, 5, 6}, {3, 6, 8} };
			Assert::IsTrue(testMatrix.ResizeMatrix(a, b) == testresize);
		
		}
	};
}
