/*#pragma once
#include<string.h>
#include<iostream>
#define VOLUMETRIC_FIGURES_H


namespace Vol_Figures{
	class Cube final : public Parallelepiped, private RhombusBasePrism {

	public:
	    Cube() {}
		Cube(const char* name, const double height) : Prism(name, height) {
			width = height;
			length = height;
			diagonal1 = pow(2, 0.5) * height;
			diagonal2 = diagonal1;
		}

		double Volume() {
			return pow(height, 3);
		}

		double BaseArea() {
			return pow(height, 2);
		}

		void SetHeight(const double height) {
			this->height = height;
			width = height;
			length = height;
			diagonal1 = pow(2, 0.5) * height;
			diagonal2 = diagonal1;
		}

		void SetWidth(const double width) {
			this->width = width;
			height = width;
			length = width;
			diagonal1 = pow(2, 0.5) * height;
			diagonal2 = diagonal1;
		}

		void SetLength(const double length) {
			this->length = length;
			height = length;
			width = height;
			diagonal1 = pow(2, 0.5) * height;
			diagonal2 = diagonal1;
		}

	};
	}


*/