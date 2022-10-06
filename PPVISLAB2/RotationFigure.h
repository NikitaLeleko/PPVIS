#pragma once
#include<string.h>
#include<iostream>
#define VOLUMETRIC_FIGURES_H

#include "Figure.h"

namespace Vol_Figures {
	class RotationFigure : public Figure {

	protected:
		double radius;

	public:
		RotationFigure() {
			radius = 0.0;
		}

		RotationFigure(const char* name, const double radius) :Figure(name) {
			this->radius = (double)radius;
		}

		void SetRadius(const double radius) {
			this->radius = (double)radius;
		}

		double GetRadius() {
			return radius;
		}

		double GetDiameter() {
			return 2 * radius;
		}
	};
}
#include "RotationFigure.h"

