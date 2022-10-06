#pragma once
#include<string.h>
#include<iostream>
#define VOLUMETRIC_FIGURES_H

#include "RotationFigure.h"
namespace Vol_Figures {

	class Cone final : public RotationFigure {

	private:
		double generatrix;

	public:
		const double pi = 3.14159265358979323;
		Cone() {
			generatrix = 0;
		}

		Cone(const char* name, const double radius, const double generatrix) :RotationFigure(name, radius) {
			this->generatrix = generatrix;
		}

		void SetGeneratrix(const double generatrix) {
			this->generatrix = generatrix;
		}

		double GetHeight() {
			return sqrt(pow(generatrix, 2) - pow(radius, 2));
		}

		double GetGeneratrix() {
			return generatrix;
		}

		double Volume() {
			return BaseArea() * GetHeight() / 3;
		}

		double SurfaceArea() {
			return pi * radius * generatrix;
		}

		double BaseArea() {
			return pi * pow(radius, 2);
		}

		double FullSurfaceArea() {
			return BaseArea() + SurfaceArea();
		}
	};
}
