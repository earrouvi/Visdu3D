/*
* main.cpp
*
*  Created on: 3 oct. 2010
*      Author: Flo
*/

// base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

#include <osgText/Text>
#include <osgText/Font>
#include <osg/Material>
#include <osg/BlendFunc>

#include "citygml.h"

// Texture input
#include <osgDB/ReadFile>

// Position and transform
#include <osg/PositionAttitudeTransform>
#include <osg/MatrixTransform>
#include <osg/Node>
#include <osg/Transform>

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
/* CITYGML TEST*/



/* OBJECTS CREATION */

   //Creating the viewer
   osgViewer::Viewer viewer ;

   //Creating the root node
   osg::ref_ptr<osg::Group> root (new osg::Group);

   //The geode containing our shape
   osg::ref_ptr<osg::Geode> myshapegeode (new osg::Geode);
   osg::ref_ptr<osg::Geometry> geom (new osg::Geometry);

   //The geode containing our second shape
   osg::ref_ptr<osg::Geode> myshapegeode2 (new osg::Geode);

   //Our shape: a cylinder, it could have been any other geometry (a box, plane, cylinderetc.)
   osg::ref_ptr<osg::Cylinder> cyl (new osg::Cylinder(osg::Vec3f(),1,2));

   // Text accompanying the cylinder (figures for example)
   osgText::Text * cylText = new osgText::Text();
   string info = "3";
   cylText->setText(info);
   float h;
   istringstream myStream(info);
   myStream>>h;
   cyl->setHeight(h);
   cyl->setRadius(h/3);
   cyl->setCenter(osg::Vec3(cyl->getCenter().x(),cyl->getCenter().y(),cyl->getCenter().z()+cyl->getHeight()/2));
   cylText->setPosition(osg::Vec3(cyl->getCenter().x(),cyl->getCenter().y(),cyl->getCenter().z()+cyl->getHeight()/2+1));
   cylText->setCharacterSize(1);
   cylText->setAutoRotateToScreen(true);
   cylText->setFont("/Users/Renard/Library/Fonts/Arial.ttf");
   cylText->setBackdropType(osgText::Text::OUTLINE);
   cylText->setAlignment(osgText::Text::CENTER_CENTER);

   //Our shape: a box, it could have been any other geometry (a box, plane, cylinderetc.)
   //osg::ref_ptr<osg::Box> myBox (new osg::Box(osg::Vec3(10,1,1),1.0f));

   //Our shape drawable
   osg::ref_ptr<osg::ShapeDrawable> cyldraw (new osg::ShapeDrawable(cyl.get()));
   //osg::ref_ptr<osg::ShapeDrawable> boxdrawable (new osg::ShapeDrawable(myBox.get()));

   //Our text
   osgText::Text * monTexte = new osgText::Text();
   monTexte->setText("le cube");
   monTexte->setAxisAlignment(osgText::Text::SCREEN);
   //monTexte->setAutoRotateToScreen(true);
   monTexte->setAlignment(osgText::Text::CENTER_CENTER);
   monTexte->setPosition( osg::Vec3(10,-1,1) );
   monTexte->setColor(osg::Vec4(0, 1, 1, 0.2));
   monTexte->setCharacterSize(1);
   monTexte->setFont("/Users/Renard/Library/Fonts/Arial.ttf");
   monTexte->setDrawMode(osgText::Text::TEXT|osgText::Text::BOUNDINGBOX);
   monTexte->setBackdropType(osgText::Text::OUTLINE);
   monTexte->setBackdropColor(osg::Vec4(0.5, 0, 0.3, 1));

   // CityGML objects
   osg::ref_ptr<osg::MatrixTransform> citygmlScaleMat (new osg::MatrixTransform);
   osg::Matrix citygmlMatrix;
   osg::ref_ptr<osg::Node> citygmlNode (osgDB::readNodeFile("SimpleBuildings.citygml"));
   citygmlScaleMat->addChild(citygmlNode.get());
   citygmlScaleMat->setMatrix(citygmlMatrix);

   cyldraw->setColor(osg::Vec4(0.5, 0, 0.3, 0.5));
   cylText->setColor(cyldraw->getColor());

   osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
   pyramidVertices->push_back( osg::Vec3( 0, 0, 0) ); // front left
   pyramidVertices->push_back( osg::Vec3(10, 0, 0) ); // front right
   pyramidVertices->push_back( osg::Vec3(10,10, 0) ); // back right
   pyramidVertices->push_back( osg::Vec3( 0,10, 0) ); // back left
   pyramidVertices->push_back( osg::Vec3( 5, 5,10) ); // peak
   geom->setVertexArray(pyramidVertices);
   osg::DrawElementsUInt* pyramidFaceOne =
         new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
      pyramidFaceOne->push_back(0);
      pyramidFaceOne->push_back(1);
      pyramidFaceOne->push_back(4);
      geom->addPrimitiveSet(pyramidFaceOne);


   osg::DrawElementsUInt* pyramidBase =
		   new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
   pyramidBase->push_back(3);
   pyramidBase->push_back(2);
   pyramidBase->push_back(1);
   pyramidBase->push_back(0);
   geom->addPrimitiveSet(pyramidBase);


   // transparence
   osg::StateSet* state = geom->getOrCreateStateSet();
   state->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
   osg::Material* mat = new osg::Material;
   mat->setColorMode(osg::Material::SPECULAR);
   mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.1);
   mat->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0.3, 0.5));
   mat->setDiffuse( osg::Material::BACK,osg::Vec4( .2f, .9f, .9f, 1.f ) );
   mat->setSpecular(osg::Material::FRONT, osg::Vec4(1, 0.5, 0.3, 0.5));
   state->setAttributeAndModes(mat,osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

   osg::BlendFunc* bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
   state->setAttributeAndModes(bf);

   state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
   state->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

   // fin transparence

/* SCENE GRAPH*/

   // Add the shape drawable to the geode
   //myshapegeode->addDrawable(capsuledrawable.get());
   myshapegeode->addDrawable(cyldraw.get());
   myshapegeode->addDrawable(monTexte);
   myshapegeode->addDrawable(cylText);
   myshapegeode->addDrawable(geom);

   // Add the geode to the scene graph root (Group)
   root->addChild(myshapegeode.get());
   root->addChild(myshapegeode2.get());
   root->addChild(citygmlScaleMat.get());

   // Set the scene data
   viewer.setSceneData( root.get() );

   viewer.getCamera()->setClearColor(osg::Vec4(0.5, 1, 0.7, 0.2));


/* START VIEWER */

   //The viewer.run() method starts the threads and the traversals.
   return (viewer.run());
}
