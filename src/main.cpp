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
	//Verification du fichier CityGML
	string cityGMLFile = argv[1];
	if(CityGMLFile.substr(CityGMLFile.find_last_of(".") + 1) != "citygml")
	{
		cout << "erreur: Le fichier citygml n'est pas valable" << endl;
	}

	//Verification du fichier ShapeFile
	string shapeFile = argv[2];

	
}
