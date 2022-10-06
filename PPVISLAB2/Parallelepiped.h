#pragma once
#include<string.h>
#include<iostream>
#define VOLUMETRIC_FIGURES_H

#include "Prism.h"
namespace Vol_Figures{

	class Parallelepiped : virtual public Prism {

		public:
		double width;
		double length;

	public:

		Parallelepiped() :width(0), length(0) {}

		Parallelepiped(const char* name, const double height, const double width, const double length) : Prism(name, height), width(width), length(length) {}

		double SetWidth(const double width) {
			this->width = width;
		}

		double GetWidth() {
			return width;
		}

		void SetLength(const double length) {
			this->length = length;
		}

		double GetLength() {
			return length;
		}

		double Volume() {
			return height * BaseArea();
		}

		double WidthSideArea() {
			return width * height;
		}

		double LengthSideArea() {
			return length * height;
		}

		double BaseArea() {
			return length * width;
		}
	};

	}
#include "Prism.h"
#include "Parallelepiped.h"

