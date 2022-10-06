#pragma once
#include<string.h>
#include<iostream>

#define VOLUMETRIC_FIGURES_H

#include "RotationFigure.h"
namespace Vol_Figures {

	class Cylinder final : public RotationFigure {

	private:
		double height;

	public:
		const double pi = 3.14159265358979323;

		Cylinder() {
			height = 0;
		}

		Cylinder(const char* name, const double radius, const double height) :RotationFigure(name, radius) {
			this->height = height;
		}

		void SetHeight(const double height) {
			this->height = height;
		}

		double GetHeight() {
			return height;
		}

		double Volume() {
			return BaseArea() * height;
		}

		double SurfaceArea() {
			return 2 * pi * radius * height;
		}

		double BaseArea() {
			return pi * pow(radius, 2);
		}

		double FullSurfaceArea() {
			return BaseArea() + SurfaceArea();
		}

	};
}

#include "Prism.h"