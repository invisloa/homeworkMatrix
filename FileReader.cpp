#include "pch.h"
#include "FileReader.h"

VECTOR::Matrix FileReader::readMatrixFromFile()
{
	cout << "Podaj nazwę pliku z wartosciami pierwszej macierzy: ";
	cin >> filename;
	inFile.open(filename + ".txt");  // połączenie inFile z plikiem
	if (!inFile.is_open())  // nieudana próba otwarcia pliku
	{
		cout << "Otwarcie pliku " << filename << " nie powiodło się.\n";
		cout << "Program zostanie zakończony.\n";
		exit(EXIT_FAILURE);
	}
	int count = 0;          // liczba elementów do odczytu

	for (int i = 0; i < 4; i++)
	{
		++count;
		inFile >> valuesArray[i];
	}

	if (inFile.eof())
		cout << "Dane pobrane z pliku:\n";
	else if (inFile.fail())
		cout << "Wczytywanie danych przerwane - błąd.\n";
	else
		cout << "Wczytywanie danych przerwane, przyczyna nieznana.\n";
	if (count == 0)
		cout << "Nie przetworzono żadnych danych.\n";
	inFile.close();         // plik już niepotrzebny

	return VECTOR::Matrix(valuesArray[0], valuesArray[1], valuesArray[2], valuesArray[3]);
}
