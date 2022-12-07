#pragma once
// wektor.h -- klasa wektor z operatorem << i prze��cznikiem trybu
#ifndef WEKTOR_H_
#define WEKTOR_H_
#include <iostream>
namespace VECTOR		//pocz�tek deklaracji przestrzeni nazw
{
	class Vector		//deklaracja klasy
	{
	private:
		double x;        // warto�� sk�adowej poziomej
		double y;        // warto�� sk�adowej pionowej
		double mag;      // d�ugo�� wektora
		double ang;      // kierunek wektora
		char mode;       // 'r' = tryb prostok�tny, 'p' = tryb biegunowy
		// prywatne metody ustawiaj�ce sk�adowe
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, char form = 'r');
		void set(double n1, double n2, char form = 'r');
		~Vector();
		double xval() const { return x; }      // zwraca warto�� sk�adowej x
		double yval() const { return y; }      // zwraca warto�� sk�adowej y
		double magval() const { return mag; }  // zwraca d�ugo��
		double angval() const { return ang; }  // zwraca k�t
		void polar_mode();    // ustawia tryb na 'p'
		void rect_mode();     // ustawia tryb na 'r'
		// metody przeci��aj�ce operatory
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// funkcje zaprzyja�nione
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
} // koniec przestrzeni nazw VECTOR
#endif

