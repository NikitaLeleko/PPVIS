#pragma once
#include<string.h>
#include<iostream>

#define VOLUMETRIC_FIGURES_H

#include "RotationFigure.h"

namespace Vol_Figures {

	class Sphere final : public RotationFigure {

	public:

		const double pi = 3.14159265358979323;
		Sphere() {}

		Sphere(const char* name, const double radius) :RotationFigure(name, radius) {}

		double Volume() {
			return (pi * pow(radius, 3) * 4 / 3);
		}

		double FullSurfaceArea() {

			return 4 * pow(radius, 2) * pi;
		}
	};
}




