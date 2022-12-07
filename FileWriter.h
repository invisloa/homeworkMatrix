#pragma once
#include <iostream>
#include <fstream>                  // plikowe wejście-wyjście
#include <string>        
#include "matrix.h"

using namespace std;

static class FileWriter
{
public:
	static string fileName;
	static string filePath;
	static void WriteToFile(double r1c1, double r1c2, double r2c1, double r2c2);
};

