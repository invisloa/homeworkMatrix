#include "pch.h"

// vect.cpp -- implementacje metod klasy Vector
#include <cmath>
#include "wektor.h"        // włącza plik nagłówkowy <iostream>
#include <iomanip>
#include <string>

using namespace std;
using std::cout;
const int maxStrLength = 60;
namespace VECTOR
{

	// metody publiczne
	Matrix::Matrix()          // konstruktor domyślny
	{
	}
	Matrix::Matrix(Vector vect1, Vector vect2)          // konstruktor 
	{
		row1Vect = vect1;
		row2Vect = vect2;
	}
	Matrix::Matrix(double r1c1, double r1c2, double r2c1, double r2c2)          // konstruktor 
	{
		Vector vector1 = Vector(r1c1, r1c2);
		Vector vector2 = Vector(r2c1, r2c2);
		row1Vect = vector1;
		row2Vect = vector2;
	}
	Matrix::~Matrix()   // destruktor
	{
	}


	Matrix Matrix::operator+(const Matrix& b) const
	{
		return Matrix(row1Vect + b.row1Vect, row2Vect + b.row2Vect);
	}
	Matrix Matrix::operator+=(const Matrix& b)
	{
		this->row1Vect = (this->row1Vect + b.row1Vect);
		this->row2Vect = (this->row1Vect + b.row2Vect);
		return *this;
	}
	Matrix Matrix::operator-(const Matrix& b) const
	{
		return Matrix(row1Vect - b.row1Vect, row2Vect - b.row2Vect);

	}
	Matrix Matrix::operator-=(const Matrix& b)
	{
		this->row1Vect = (this->row1Vect - b.row1Vect);
		this->row2Vect = (this->row2Vect - b.row2Vect);
		return *this;
	}
	Matrix Matrix::operator*(const Matrix& b)  const
	{
		double r1c1 = row1Vect.xval() * b.row1Vect.xval() + row1Vect.yval() * b.row2Vect.xval();
		double r1c2 = row1Vect.xval() * b.row1Vect.yval() + row1Vect.yval() * b.row2Vect.yval();
		double r2c1 = row2Vect.xval() * b.row1Vect.xval() + row2Vect.yval() * b.row2Vect.xval();
		double r2c2 = row2Vect.xval() * b.row1Vect.yval() + row2Vect.yval() * b.row2Vect.yval();

		return Matrix(r1c1, r1c2, r2c1, r2c2);
	}
	// zmienia znak wektora
	Matrix Matrix::operator-() const
	{
		//Matrix x;
		//x.row1Vect = -this->row1Vect;
		//x.row2Vect = -this->row2Vect;

		return Matrix(-row1Vect, -row2Vect);
	}
	// mnoży wektor wywołujący przez n
	Matrix Matrix::operator*(double n) const
	{
		return Matrix(row1Vect * n, row2Vect * n);
	}
	Matrix Matrix::operator *=(double n)
	{
		this->row1Vect = (this->row1Vect * n);
		this->row2Vect = (this->row2Vect * n);
		return *this;
	}


	VECTOR::Matrix Matrix::getMatrixValues()
	{
		cout << "Podaj wartosci macierzy" << endl << "wiersz 1, kolumna 1: ";
		int w1c1;
		cin >> w1c1;
		cout << "Podaj wartosci macierzy" << endl << "wiersz 1, kolumna 2: ";
		int w1c2;
		cin >> w1c2;
		cout << "Podaj wartosci macierzy" << endl << "wiersz 2, kolumna 1: ";
		int w2c1;
		cin >> w2c1;
		cout << "Podaj wartosci macierzy" << endl << "wiersz 2, kolumna 2: ";
		int w2c2;
		cin >> w2c2;

		return VECTOR::Matrix(w1c1, w1c2, w2c1, w2c2);
	}



	std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
	{
		os << "Wartosci macierzy:" << endl;;

		os << right << setw(30) << "Kolumna 1";
		os << right << setw(20) << "Kolumna 2" << endl;
		os << endl;
		os << "Wiersz 1";
		os << right << setw(22) << matrix.row1Vect.xval();
		os << right << setw(20) << matrix.row1Vect.yval() << endl;

		os << "Wiersz 2";
		os << right << setw(22) << matrix.row2Vect.xval();
		os << right << setw(20) << matrix.row2Vect.yval() << endl;

		//os << "Matryca o nastepujacych wartosciach: \n" << "\twiersz 1 kolumna 1: = " << m.r1c1 << ", kolumna 2 : " << m.r1c2 << "\n"
		//	<< "\twiersz 2 kolumna 1: = " << m.r2c1 << ", kolumna 2: " << m.r2c2 << "\n";
		return os;
	}

	// wyświetla współrzędne wektora (prostokątne w trybie 'r',
	// biegunowe w trybie 'p'
} // koniec przestrzeni nazw VECTOR

