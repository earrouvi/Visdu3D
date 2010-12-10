/*
 * main.cpp
 *
 * Created on: 9 dec. 2010
 * Author: Robin
 */

#include <iostream>
#include <string>

using namespace std;

// 
int main( int argc, const char* argv[])
{

	//  Checking CityGML File
	string cityGMLFile = argv[1];
	if(CityGMLFile.substr(CityGMLFile.find_last_of(".") + 1) != "citygml")
	{
		cout << "error: Not a correct Citygml file, put it in \".citygml\" format." << endl;
	}


	// Checking ShapeFile File
	string shapeFile = argv[2];

	
}
