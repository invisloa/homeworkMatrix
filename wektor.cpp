#include "pch.h"
#include "wektor.h"        // włącza plik nagłówkowy <iostream>
#include <cmath>
using std::cout;
namespace VECTOR
{
	const double Rad_to_deg = 57.2957795130823;	//przelicznik radianów na stopnie
	// metody prywatne
	// oblicza długość wektora ze składowych x i y
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);	//obliczenie długości wektora z jego składowych arytmetycznych
	}

	void Vector::set_ang()		//ustawienie kąta wektora
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	// oblicza składową x ze współrzędnych biegunowych
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	// oblicza składową y ze współrzędnych biegunowych
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	// metody publiczne
	Vector::Vector()          // konstruktor domyślny
	{
		x = y = mag = ang = 0.0;
		mode = 'r';
	}
	// konstruuje wektor o zadanych współrzędnych biegunowych (w trybie 'p')
	// bądź prostokątnych (w domyślnym trybie 'r')
	Vector::Vector(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r')
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == 'p')
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Niepoprawna wartość trzeciego argumentu Vector() -- ";
			cout << "zeruję wektor\n";
			x = y = mag = ang = 0.0;
			mode = 'r';
		}
	}
	// ustawia wartości wektora dla zadanych współrzędnych biegunowych ('p')
	// lub prostokątnych ('r' -- ryb domyślny)
	void Vector::set(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r')
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == 'p')
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Niepoprawny trzeci argument set() -- ";
			cout << "zeruję wektor\n";
			x = y = mag = ang = 0.0;
			mode = 'r';
		}
	}
	Vector::~Vector()   // destruktor
	{
	}
	void Vector::polar_mode()  // przełącza do reprezentacji biegunowej
	{
		mode = 'p';
	}
	void Vector::rect_mode()   // przełącza do reprezentacji kartezjańskiej
	{
		mode = 'r';
	}
	// przeciążone operatory
	// dodawanie dwóch wektorów
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	// odejmowanie wektora b od wektora a
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	// zmienia znak wektora
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	// mnoży wektor wywołujący przez n
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}
	// funkcje zaprzyjaźnione
	// mnoży n przez wektor a
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	// wyświetla współrzędne wektora (prostokątne w trybie 'r',
	// biegunowe w trybie 'p'
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == 'r')
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == 'p')
		{
			os << "(m,a) = (" << v.mag << ", "
				<< v.ang * Rad_to_deg << ")";
		}
		else
			os << "Niepoprawny tryb reprezentacji obiektu wektora";
		return os;
	}
} // koniec przestrzeni nazw VECTOR

