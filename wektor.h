#pragma once
// wektor.h -- klasa wektor z operatorem << i prze³¹cznikiem trybu
#ifndef WEKTOR_H_
#define WEKTOR_H_
#include <iostream>
namespace VECTOR		//pocz¹tek deklaracji przestrzeni nazw
{
	class Vector		//deklaracja klasy
	{
	private:
		double x;        // wartoœæ sk³adowej poziomej
		double y;        // wartoœæ sk³adowej pionowej
		double mag;      // d³ugoœæ wektora
		double ang;      // kierunek wektora
		char mode;       // 'r' = tryb prostok¹tny, 'p' = tryb biegunowy
		// prywatne metody ustawiaj¹ce sk³adowe
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, char form = 'r');
		void set(double n1, double n2, char form = 'r');
		~Vector();
		double xval() const { return x; }      // zwraca wartoœæ sk³adowej x
		double yval() const { return y; }      // zwraca wartoœæ sk³adowej y
		double magval() const { return mag; }  // zwraca d³ugoœæ
		double angval() const { return ang; }  // zwraca k¹t
		void polar_mode();    // ustawia tryb na 'p'
		void rect_mode();     // ustawia tryb na 'r'
		// metody przeci¹¿aj¹ce operatory
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// funkcje zaprzyjaŸnione
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
} // koniec przestrzeni nazw VECTOR
#endif

