#pragma once
#include<string.h>
#include<iostream>

#define VOLUMETRIC_FIGURES_H

#include "Prism.h"
namespace Vol_Figures{

	class RhombusBasePrism : virtual protected Prism, private RotationFigure {

	protected:
		double diagonal1;
		double diagonal2;

	public:
		RhombusBasePrism() : diagonal1(0), diagonal2(0) {}

		RhombusBasePrism(const char* name, const double height, const double diagonal1, const double diagonal2) : Prism(name, height), diagonal1(diagonal1), diagonal2(diagonal2) {}

		void SetDiagonal1(const double diagonal1) {
			this->diagonal1 = diagonal1;
		}

		double GetDiagonal1() {
			return diagonal1;
		}

		void SetDiagonal2(const double diagonal2) {
			this->diagonal2 = diagonal2;
		}

		double GetDiagonal2() {
			return diagonal2;
		}

		double Volume() {
			return height * BaseArea();
		}

		double BaseArea() {
			return diagonal1 * diagonal2 / 2;
		}
	};
	}
#include "Parallelepiped.h"
