#pragma once
#include <iostream>
#include <string>
#include "wektor.h"

namespace VECTOR
{

	class Matrix
	{
	public:
		Vector row1Vect;        // wiersz 1
		Vector row2Vect;        // wiersz 2

		Matrix();
		Matrix(double r1c1, double r1c2, double r2c1, double r2c2);
		Matrix(Vector v1, Vector v2);
		void set(Vector n1, Matrix n2);
		~Matrix();
		Vector row1() const { return row1Vect; }      // zwraca  wiersz 1
		Vector row2() const { return row2Vect; }      // zwraca  wiersz 2

		Matrix operator+(const Matrix& b) const;
		Matrix operator+=(const Matrix& b);
		Matrix operator-(const Matrix& b) const;
		Matrix operator-=(const Matrix& b);
		Matrix operator*(const Matrix& b) const;
		Matrix operator *=(double n);


		Matrix operator-() const;
		Matrix operator*(double n) const;
		// funkcje zaprzyjaünione
		friend Matrix operator*(double n, const Matrix& a);
		friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
		Matrix getMatrixValues();
	};
}

