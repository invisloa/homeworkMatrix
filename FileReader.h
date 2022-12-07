#pragma once
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

using namespace std;
using VECTOR::Vector;

class FileReader
{
public:
	string filename;
	ifstream inFile;        // obiekt obsługujący odczyt z pliku
	double valuesArray[4];

	VECTOR::Matrix readMatrixFromFile();
};

