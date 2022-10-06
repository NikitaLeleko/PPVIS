#pragma once
#include<string.h>
#include<iostream>
#define VOLUMETRIC_FIGURES_H

#include "Figure.h"
namespace Vol_Figures{

	class Prism : public Figure {

		
	protected:
		double height;

	public:

		Prism() {
			height = 0;
		}

		Prism(const char* name, const double height) :Figure(name), height(height) {}

		double GetHeight() {
			return height;
		}

		void SetHeight(const double height) {
			this->height = height;
		}
	};

}
#include "Prism.h"
