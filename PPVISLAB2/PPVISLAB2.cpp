// 
#include "Figure.h"
#include "RotationFigure.h"
#include "Sphere.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Cube.h"
#include "Parallelepiped.h"
#include<iostream>
#include<iomanip>
#include "RhombusBasePrism .h"
using namespace std;
using namespace Vol_Figures;

	int main() {

		cout << setw(50) << "****************** Figures *******************" << endl << endl;

		cout << setw(50) << "****************** Sphere *******************" << endl;
		Sphere example_sphere("Sphere", 4);
		cout << setw(20) << "Name: " << example_sphere.GetName() << endl;
		cout << setw(20) << "Radius: " << example_sphere.GetRadius() << endl;
		cout << setw(20) << "Diametr: " << example_sphere.GetDiameter() << endl;
		cout << setw(20) << "Volume: " << example_sphere.Volume() << endl;
		cout << setw(20) << "Surface Area: " << example_sphere.FullSurfaceArea() << endl;
		cout << endl;

		cout << setw(50) << "****************** Cylinder *******************" << endl;
		Cylinder example_cylinder("Cylinder", 3, 4);
		cout << setw(20) << "Name: " << example_cylinder.GetName() << endl;
		cout << setw(20) << "Radius: " << example_cylinder.GetRadius() << endl;
		cout << setw(20) << "Diametr: " << example_cylinder.GetDiameter() << endl;
		cout << setw(20) << "Height: " << example_cylinder.GetHeight() << endl;
		cout << setw(20) << "Volume: " << example_cylinder.Volume() << endl;
		cout << setw(20) << "Surface Area: " << example_cylinder.SurfaceArea() << endl;
		cout << setw(20) << "Base Area: " << example_cylinder.BaseArea() << endl;
		cout << setw(20) << "Full Area: " << example_cylinder.FullSurfaceArea() << endl;
		cout << endl;

		cout << setw(50) << "****************** Cone *******************" << endl;
		Cone example_cone("Cone", 3, 5);
		cout << setw(20) << "Name: " << example_cone.GetName() << endl;
		cout << setw(20) << "Radius: " << example_cone.GetRadius() << endl;
		cout << setw(20) << "Diametr: " << example_cone.GetDiameter() << endl;
		cout << setw(20) << "Height: " << example_cone.GetHeight() << endl;
		cout << setw(20) << "Generatrix: " << example_cone.GetGeneratrix() << endl;
		cout << setw(20) << "Volume: " << example_cone.Volume() << endl;
		cout << setw(20) << "Surface Area: " << example_cone.SurfaceArea() << endl;
		cout << setw(20) << "Base Area: " << example_cone.BaseArea() << endl;
		cout << setw(20) << "Full Area: " << example_cone.FullSurfaceArea() << endl;
		cout << endl;

		cout << setw(50) << "****************** Prism *******************" << endl;
		Prism example_prism("Prism", 1.6);
		cout << setw(20) << "Name: " << example_prism.GetName() << endl;
		cout << setw(20) << "Height: " << example_prism.GetHeight() << endl;
		cout << endl;

		cout << setw(50) << "****************** Parallelepiped *******************" << endl;
		Parallelepiped example_parallelepiped("Parallelepiped", 2, 3, 5);
		cout << setw(20) << "Name: " << example_parallelepiped.GetName() << endl;
		cout << setw(20) << "Height: " << example_parallelepiped.GetHeight() << endl;
		cout << setw(20) << "Width: " << example_parallelepiped.GetWidth() << endl;
		cout << setw(20) << "Length: " << example_parallelepiped.GetLength() << endl;
		cout << setw(20) << "Volume: " << example_parallelepiped.Volume() << endl;
		cout << setw(20) << "Width Side Area: " << example_parallelepiped.WidthSideArea() << endl;
		cout << setw(20) << "Length Side Area: " << example_parallelepiped.LengthSideArea() << endl;
		cout << setw(20) << "Base Area: " << example_parallelepiped.BaseArea() << endl;
		cout << endl;

		cout << setw(50) << "****************** Rhombus Base Prism *******************" << endl;
		RhombusBasePrism example_prism_2("Rhombus Base Prism", 5, 2, 4);
		cout << setw(20) << "First Diagonal: " << example_prism_2.GetDiagonal1() << endl;
		cout << setw(20) << "Second Diagonal: " << example_prism_2.GetDiagonal2() << endl;
		cout << setw(20) << "Volume: " << example_prism_2.Volume() << endl;
		cout << setw(20) << "Base Area: " << example_prism_2.BaseArea() << endl;
		cout << endl;

		
		
		
		
		
		
		
		
		
		//cout << setw(50) << "****************** Cube *******************" << endl;
		//Cube example_cube("Cube", 3);
		//cout << setw(20) << "Name: " << example_cube.GetName() << endl;
		//cout << setw(20) << "Side: " << example_cube.GetHeight() << endl;
		//cout << setw(20) << "Volume: " << example_cube.Volume() << endl;
		//cout << setw(20) << "Base Area: " << example_cube.BaseArea() << endl;
		//cout << endl;//*/

		/*Cube cube;
		cube.SetHeight(4);
		cout << cube.GetHeight() << endl;
		cout << cube.GetWidth() << endl;
		cout << cube.GetDiagonal1() << endl;
		cout << cube.LengthSideArea() << endl;
		cout << cube.Volume() << endl;//*/

		system("pause< NUL");
	}
