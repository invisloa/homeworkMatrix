#include "pch.h"
#include "FileWriter.h"
#include "matrix.h"

string FileWriter::fileName = "wartosci";
string FileWriter::filePath = "";

void FileWriter::WriteToFile(double r1c1, double r1c2, double r2c1, double r2c2)
{
		VECTOR::Matrix matrixToWrite(r1c1, r1c2, r2c1, r2c2);
		ofstream outFileValuesOnly;
		ofstream outFileAll;
		outFileAll.open("macierz.txt");
		outFileValuesOnly.open(filePath + fileName + ".txt");
		// powiązanie obiektu z plikiem
		// dokładnie to samo robimy z outFile zamiast cout
		outFileAll << "Wartosci macierzy:" << endl;;
		outFileAll << right << setw(30) << "Kolumna 1";
		outFileAll << right << setw(20) << "Kolumna 2" << endl;
		outFileAll << endl;
		outFileAll << "Wiersz 1";
		outFileAll << right << setw(22) << matrixToWrite.row1Vect.xval();
		outFileAll << right << setw(20) << matrixToWrite.row1Vect.yval() << endl;
		outFileValuesOnly << matrixToWrite.row1Vect.xval() << " ";
		outFileValuesOnly << matrixToWrite.row1Vect.yval() << " ";
		outFileAll << "Wiersz 2";
		outFileAll << right << setw(22) << matrixToWrite.row2Vect.xval();
		outFileAll << right << setw(20) << matrixToWrite.row2Vect.yval() << endl;
		outFileValuesOnly << matrixToWrite.row2Vect.xval() << " ";
		outFileValuesOnly << matrixToWrite.row2Vect.yval();
		outFileAll.close();
}
