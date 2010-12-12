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

#include <iostream>
#include <string>

// osg includes
#include <osgViewer/Viewer>
// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

// others
#include "CityGMLObject.h"
#include "DisplayMode.h"

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
		cout << "Parsing OK... " << endl;
	}

	// Checking ShapeFile File
	//string shapeFile = argv[2];

	cout << "Parsing OK... " << endl;

	/* CREATION OF THE SCENE */
	cout << "Creating the scene... " << endl;
	//Creating the viewer
	osgViewer::Viewer viewer ;
	//Creating the root node
	osg::ref_ptr<osg::Group> root (new osg::Group);
	// Scene Created
	cout << "Scene creation OK... " << endl;


	/* OPENING THE FILES */
	cout << "Loading files... " << endl;
	//Loading the CityGML file
	cout << "Loading CityGML file... " << endl;
	CityGMLObject * cityGMLObject = new CityGMLObject(cityGMLFile);
	// Add the nodes to the scene graph root (Group)
	root->addChild(cityGMLObject->getCityGMLScaleMAT());
	cout << "CityGML file loaded... " << endl;
	//Loading the Shapefile
	cout << "Loading Shapefile file... " << endl;
	// Insert commands here.
	cout << "Shapefile loaded... " << endl;

	/* KEYBOARD INPUT*/
	cout << "Managing Keyboard Inputs... " << endl;
	//Stats Event Handler (s key)
	viewer.addEventHandler(new osgViewer::StatsHandler);
	//Windows size handler (f key)
	viewer.addEventHandler(new osgViewer::WindowSizeHandler);
	// add the state manipulator
	viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );

/* creation d'informations et affichage */

	osg::ref_ptr<osg::Node> citygmlNode = cityGMLObject->getCityGMLNode();
	osg::ref_ptr<osg::Group> myOSGGroup = (osg::Group*) citygmlNode.get();
	QualitativeInfo * info = new QualitativeInfo("mon texte ici");
	DisplayType dt = TEXT_DISPLAY;
	DisplayMode * mode = new DisplayMode(dt);
	info->display(mode, citygmlNode);

/* fin de la creation d'informations */

	/* START VIEWER */
	cout << "Starting the viewer... " << endl;
	// Set the scene data
	viewer.setSceneData( root.get() );
	//The viewer.run() method starts the threads and the traversals.
	return (viewer.run());

}

/* REMOVE Parcours des nodes et changements d'apparence


	//Use this to verify whether a node is a group or not.
	//std::cout << citygmlnode->className() << std::endl;


	//Cast our OSG Node to an OSG Group so we have access to grouping methods
	//(do this ONLY after verifying this OSG Node is, in fact, a Node of type OSG Group)

	osg::ref_ptr<osg::Group> myOSGGroup;
	osg::ref_ptr<osg::Group> anotherOSGGroup;
	osg::ref_ptr<osg::Group> thirdOSGGroup;
	osg::ref_ptr<osg::Group> fourthOSGGroup;
	myOSGGroup = (osg::Group*) citygmlnode.get();


	for (unsigned int i = 0; i < myOSGGroup->getNumChildren()/2; i++) {
	   cout << "\t" << myOSGGroup->getChild(i)->className() << endl;
	   anotherOSGGroup = (osg::Group *) myOSGGroup->getChild(i);

	   for (unsigned int j = 0; j < anotherOSGGroup->getNumChildren(); j++) {
	      cout << "\t\t" << anotherOSGGroup->getChild(j)->className() << endl;
	      osg::Geode* ceBatiment = (osg::Geode*) anotherOSGGroup->getChild(j);
	      for(unsigned int m = 0; m < ceBatiment->getNumDrawables(); m++){
	    	  cout << "\t\t" << ceBatiment->getDrawable(m)->className() << endl;
	    	  osg::Geometry * geom = ceBatiment->getDrawable(m)->asGeometry();
	    	  osg::StateSet* state = geom->getOrCreateStateSet();
	    	  	   state->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
	    	  	   osg::Material* mat = new osg::Material;
	    	  	   mat->setColorMode(osg::Material::AMBIENT); // SPECULAR ou EMISSION ou AMBIENT ou DIFFUSE...
	    	  	   mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.1);
	    	  	   // on set les differents types de couleur : (voir cours d'eImage sur lumiere ambiante, diffuse, speculaire, ...)
	    	  	   mat->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0.3, 0.5));
	    	  	   mat->setDiffuse( osg::Material::BACK,osg::Vec4( .2f, .9f, .9f, 1.f ) );
	    	  	   mat->setSpecular(osg::Material::FRONT, osg::Vec4(1, 0.5, 0.3, 0.5));
	    	  	   state->setAttributeAndModes(mat, osg::StateAttribute::ON);
	      }
	      thirdOSGGroup = (osg::Group *) anotherOSGGroup->getChild(j);
	      for (unsigned int k = 0; k < thirdOSGGroup->getNumChildren(); k++) {
	         cout << "\t\t\t" << thirdOSGGroup->getChild(k)->className() << endl;

	         fourthOSGGroup = (osg::Group *) thirdOSGGroup->getChild(k);
	         for (unsigned int l = 0; l < fourthOSGGroup->getNumChildren(); l++) {
	            cout << "\t\t\t\t" << fourthOSGGroup->getChild(l)->className() << endl;
	         }
	      }
	   }
	}



 */
