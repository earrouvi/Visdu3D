/*
 * main.cpp
 *
 *  Created on: Dec. 2010
 *      Author: Visdu3D, Group project working on cityGML and ESRI formats co-visualization.
 *      Elsa Arrou-Vignod
 *      Florent Buisson
 *      Robin Kervadec
 *      Alice Lan
 *      Michael Lumbroso
 *      Toinon Vigier
 */

// Comment/Uncomment this line if osgGIS is not installed on your platform
// You will not be able to display a shapefile nor to extract information from it.
#define OSGGIS_NOT_INSTALLED
// DO THE SAME in ShapefileObject and DilplayableField Files (.h and .cpp)

#include <iostream>
#include <string>

// osg includes
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

// others
#include "CityGMLObject.h"
#include "KeyBoardHandler.h"
#ifndef OSGGIS_NOT_INSTALLED
#include "ShapefileObject.h"
#endif/*OSGGIS_NOT_INSTALLED*/



using namespace std;

// 
int main( int argc, const char* argv[])
{
	/* Parsing the program arguments */
	cout << "Parsing arguments..." << endl;
	//  Checking CityGML File
	string cityGMLFile = argv[1];
	if(cityGMLFile.substr(cityGMLFile.find_last_of(".") + 1) != "citygml")
	{
		cout << "error: Not a correct CityGML file, put it in \".citygml\" format." << endl;
	} else {
		cout << "CityGML argument parsing OK... " << endl;
	}
#ifndef OSGGIS_NOT_INSTALLED
	// Checking ShapeFile File // example"/home/toinon/OrbisGIS/data_seance_5/Girona/Rivers/rius.shp"
	string shapeFile = argv[2];
	if(shapeFile.substr(shapeFile.find_last_of(".") + 1) != "shp")
		{
			cout << "error: Not a correct ShapeFile file, put it in \".shp\" format." << endl;
		} else {
			cout << "ShapeFile argument parsing OK... " << endl;
		}
#endif/*OSGGIS_NOT_INSTALLED*/

	cout << "Parsing OK... " << endl;

	/* CREATION OF THE SCENE */
	cout << "Creating the scene... " << endl;
	//Creating the viewer
	osgViewer::Viewer viewer ;
	//Creating the root node
	osg::ref_ptr<osg::Group> root (new osg::Group);
	// Scene Created
	cout << "Scene creation OK... " << endl;
	/*osg::ref_ptr<osg::MatrixTransform> shapeFileScaleMAT (new osg::MatrixTransform);
	osg::Matrix shapeFileScaleMatrix;
	osg::ref_ptr<osg::Node> shapeFileNode (osgDB::readNodeFile("/User/Flo/Dev/OpenSceneGraph-Data/Data_Toinon/Bati_ile_nantes_l2e/bati_ile_nantes.shp"));
	shapeFileScaleMAT->addChild(shapeFileNode.get());
	shapeFileScaleMAT->setMatrix(shapeFileScaleMatrix);
	root->addChild(shapeFileScaleMAT.get());*/

	/* OPENING THE FILES */
		/*CITYGML*/
			cout << "Loading files... " << endl;
			//Loading the CityGML file
			cout << "Loading CityGML file... " << endl;
			CityGMLObject * cityGMLObject = new CityGMLObject(cityGMLFile);
			// Add the nodes to the scene graph root (Group)
			root->addChild(cityGMLObject->getCityGMLScaleMAT());
			cout << "CityGML file loaded... " << endl;

			cout << "Loading Shapefile file... " << endl;
			// Insert commands here.
			cout << "Shapefile loaded... " << endl;
#ifndef OSGGIS_NOT_INSTALLED
		/*SHAPEFILE*/
			//Loading the Shapefile
			ShapefileObject* shapeFileObject = new ShapefileObject(shapeFile);
			//Write the different type of information included in the ShapeFile
			//With this you can choose which type of information you get.
			shapeFileObject->printFieldsName();
			// Sets the color of the shapeFile Object
			shapeFileObject->setColor("green");
			osg::ref_ptr<osg::Node> shapeFileNode = shapeFileObject->transformShapefile();
			// Add the nodes to the scene graph root (Group)
			root->addChild(shapeFileNode.get());
			//Extracts a type of information from the shapeFile
			std::vector<DisplayableField> fieldList = shapeFileObject->ListFeaturesForField(4);
			//Create 3D visualization for these information
			//Sets a visualization mode
			DisplayMode * shapeFileVisualizationMode = new DisplayMode();
			shapeFileVisualizationMode->set...
			shapeFileObject->createShapeFileInformation(shapeFileVisualizationMode, fieldList);
			//Adds the information to the scene
			shapeFileVisualizationMode->addGeode(root);
			root->addChild(shapeInformation.get());
#endif/*OSGGIS_NOT_INSTALLED*/


	/* Information creation and display */

	osg::ref_ptr<osg::Group> myOSGGroup = (osg::Group*) cityGMLObject->asGroup()->getChild(0);

	for (int i=0;i<4;i++) {
		QualitativeInfo * info = new QualitativeInfo("i*40");
		cityGMLObject->addInfo(*info);
		info->setChildIndex(i);
		cityGMLObject->displayInfo(*info, 0, root);
	}


	/* fin de la creation d'informations */

	/* KEYBOARD INPUT*/
	cout << "Managing Keyboard Inputs... " << endl;
	//Stats Event Handler (s key)
	viewer.addEventHandler(new osgViewer::StatsHandler);
	//Windows size handler (f key)
	viewer.addEventHandler(new osgViewer::WindowSizeHandler);
	// add the state manipulator
	viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );
	// Create new Keybord handler
	KeyboardEventHandler* keh = new KeyboardEventHandler(cityGMLObject);
	viewer.getEventHandlers().push_front(keh);

	/* START VIEWER */
	cout << "Starting the viewer... " << endl;
	// Set the scene data
	viewer.setSceneData( root.get() );
	//The viewer.run() method starts the threads and the traversals.
	return (viewer.run());

}

