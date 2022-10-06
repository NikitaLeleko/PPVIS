#ifndef VOLUMETRIC_FIGURES_H
#define VOLUMETRIC_FIGURES_H

#include<string.h>
#include<iostream>

namespace Vol_Figures {
	const double pi = 3.14159265358979323;
	using namespace std;
	// Объмные фигуры
	class Figure {

	protected:
		char name[21];

	public:

		Figure() {
			strcpy_s(name, "Figure");
		}

		Figure(const char* name) {
			strcpy_s(this->name, name);
		}

		void SetName(const char* name) {
			strcpy_s(this->name, name);
		}

		char* GetName() {
			//cout << name << endl;
			return name;
		}

	};
}
#include "Figure.h"

#endif // !VOLUMETRIC_FIGURES_H


