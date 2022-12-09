#include "pch.h"
#include "wektor.h"
#include "matrix.h"
#include <iostream>
#include <cstdlib>   
#include <iomanip>
#include <fstream>   
#include "wektor.h"
#include "matrix.h"
#include "FileWriter.h"
#include "FileReader.h"



int main()
{
	FileReader _fileReader;
	VECTOR::Matrix Matrix1 = _fileReader.readMatrixFromFile();
	VECTOR::Matrix Matrix3;

	cout << "Pobrana macierz: " << endl;
	cout << Matrix1;
	cout << "Podaj jaka operacje chcesz wykonac na macierzach" << endl;
	cout << "(D)-dodawanie, (O)-odejmowanie, (X)-mnozenie dwoch macierzy, (M)-mnozenie przez liczbe" << endl;
	char dzialanie;
	cin >> dzialanie;
	cout << "Podaj wartosci drugiej macierzy" << endl;
	if (toupper(dzialanie) != 'M')
	{
		VECTOR::Matrix Matrix2 = Matrix2.getMatrixValues();

		if (toupper(dzialanie) == 'D')
		{
			cout << "Suma dodawania dwoch macierzy to:" << endl;
			Matrix3 = Matrix1 + Matrix2;
			cout << Matrix3 << endl;
		}
		else if (toupper(dzialanie) == 'O')
		{
			cout << "Iloczyn odejmowania dwoch macierzy to:" << endl;
			Matrix3 = Matrix1 - Matrix2;
			cout << Matrix3 << endl;
		}
		else if (toupper(dzialanie) == 'X')
		{
			cout << "Iloraz macierzy to:" << endl;
			Matrix3 = Matrix1 * Matrix2;
			cout << Matrix3 << endl;
		}
	}
	if (toupper(dzialanie) == 'M')
	{
		cout << "Przez jaka liczbe ma byc pomnozona macierz" << endl;
		int przezCoMnozymy;
		cin >> przezCoMnozymy;
		cout << "Iloraz mnozenia macierzy to: " << endl;
		Matrix3 = Matrix1 * przezCoMnozymy;
		cout << Matrix3 << endl;
	}
	cout << "Pod jaka nazwa chcesz zapisac plik?" << endl;
	cin >> FileWriter::fileName;
	cout << "Zapisz plik w lokalizacji domyslnej- (dowolny przycisk) lub wlasnej (W)" << endl;
	char chooseSaveMethod;
	cin.ignore();
	if (toupper(cin.get()) == 'W')
	{
		cout << "Podaj sciezke zapisu pliku?" << endl;
		string saveFilePath;
		cin >> saveFilePath;
		FileWriter::filePath = saveFilePath;
	}
	FileWriter::WriteToFile(Matrix3.row1Vect.xval(), Matrix3.row1Vect.yval(), Matrix3.row2Vect.xval(), Matrix3.row2Vect.yval());
	return 0;
}

