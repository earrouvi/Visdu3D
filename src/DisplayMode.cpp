/*
 * DisplayMode.cpp
 *
 *  Created on: 8 déc. 2010
 *      Author: Renard
 */

#include "DisplayMode.h"

#include <osg/MatrixTransform>
#include <osgDB/ReadFile>

DisplayMode::DisplayMode(DisplayType dt)
: myTextToDisplay(""),
  displayText(false)
{
	myDisplayType = dt;
}

DisplayMode::~DisplayMode() {
	// TODO Auto-generated destructor stub
}

void DisplayMode::addGeode(osg::ref_ptr<osg::Group> root, FormType formType){
	//Initializations
	osg::ref_ptr<osg::Geode> myGeode (new osg::Geode());
	osgText::Text * text = new osgText::Text();
	//Position of Objects
	myPos.set(myPos.x(), myPos.y(), myPos.z()+myHeight);
	//Text to display
	if(displayText = true && strcmp(myTextToDisplay.c_str(),"")){

		text->setText(myTextToDisplay);

		text->setPosition(osg::Vec3(myPos.x(),myPos.y(),myPos.z()+myHeight/2+text->getCharacterHeight()));
		text->setAutoRotateToScreen(true);
		text->setAlignment(osgText::Text::CENTER_CENTER);
		text->setColor(osg::Vec4(1, 0, 0, 1));
		text->setCharacterSize(root->getBound().radius()*0.15);
	}
	//If type is SHAPE_3D we add the shape to the geode, here Sphere
	if(myDisplayType == SHAPE_3D && formType == SPHERE){
		osg::ref_ptr<osg::Sphere> sph (new osg::Sphere(myPos,myRadius * 0.5));
		osg::ref_ptr<osg::ShapeDrawable> sphD (new osg::ShapeDrawable(sph.get()));
		//Apply RED color to the sphere
		osg::StateSet* stateSphere = sphD->getOrCreateStateSet();
		stateSphere->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
		stateSphere->setAttributeAndModes((new osg::Material(*getRedMaterial())), osg::StateAttribute::OVERRIDE);
		//Add the Sphere to the geode
		myGeode->addDrawable(sphD.get());
	}
	//If type is SHAPE_3D we add the shape to the geode, here Sphere
	if(myDisplayType == SHAPE_3D && formType == CYLINDER){
		//Adjust height and myPosition
		myPos.set(myPos.x(), myPos.y(), myHeight/2);
		//Creates cylinder and drawable
		osg::ref_ptr<osg::Cylinder> cyl (new osg::Cylinder(myPos, myRadius*0.5, myHeight));
		osg::ref_ptr<osg::ShapeDrawable> cylD (new osg::ShapeDrawable(cyl.get()));
		text->setPosition(osg::Vec3(myPos.x(),myPos.y(),myPos.z()+myHeight/2+text->getCharacterHeight()));
		//Apply RED color to the cylinder
		osg::StateSet* stateCyl = cylD->getOrCreateStateSet();
		stateCyl->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
		stateCyl->setAttributeAndModes((new osg::Material(*getRedMaterial())), osg::StateAttribute::OVERRIDE);
		//Add the cylinder to the geode
		myGeode->addDrawable(cylD.get());
	}
	//If type is SHAPE_3D we add the shape to the geode, here SMARTIES
	if(myDisplayType == SHAPE_3D_SMARTIES && formType == SMARTIES){
		//Our shape: a sphere, transformed by scaling to a smarties.
		osg::ref_ptr<osg::Geode> myShapeGeodeSmarties (new osg::Geode());
		//The sphere is created relatively to the size of the buildings
		osg::ref_ptr<osg::Sphere> mySmarties (new osg::Sphere(osg::Vec3f(0.f,0.f,0.f),myRadius));
		//Place the sphere upon the building
		mySmarties->setCenter(osg::Vec3(myPos.x(),myPos.y(),myHeight));
		//The future Smarties' shape drawable
		osg::ref_ptr<osg::ShapeDrawable> smartiesDrawable (new osg::ShapeDrawable(mySmarties.get()));
		// Add the shape drawable to the geode
		myShapeGeodeSmarties->addDrawable(smartiesDrawable.get());
		//Getting the state set of the geode
		osg::ref_ptr<osg::StateSet> nodesscapsule (myShapeGeodeSmarties->getOrCreateStateSet());
		//Loads the image for texturing the smarties
		osg::ref_ptr<osg::Image> image (osgDB::readImageFile("Smiley.png"));
		//Bind the image to a 2D texture object
		osg::ref_ptr<osg::Texture2D> tex (new osg::Texture2D);
		tex->setImage(image.get());
		//Applying texture on the smarties (but sphere) object
		nodesscapsule->setTextureAttributeAndModes(0,tex.get(),osg::StateAttribute::ON);
		//Dealing with matrix for transforming the sphere into a smarties
		osg::ref_ptr<osg::MatrixTransform> sphereToSmartiesScaleMAT = new osg::MatrixTransform;
		//If we don't translate the sphere at the center of scene before scaling it,
		// the resulted scaled object would be translated
		osg::Matrix tranlateToOrigin = osg::Matrix::translate(-myPos.x(),-myPos.y(),0.f);
		osg::Matrix scaleToASmarties = osg::Matrix::scale(1.f,0.1f,1.f);
		osg::Matrix translateToBuildingPos = osg::Matrix::translate(myPos.x(),myPos.y(),0.f);
		//Osg uses prefix matrix multiplication
		osg::Matrix transformToASmarties = tranlateToOrigin * scaleToASmarties * translateToBuildingPos;
		// Set the matrix transform
		sphereToSmartiesScaleMAT->addChild(myShapeGeodeSmarties.get());
		sphereToSmartiesScaleMAT->setMatrix(transformToASmarties);
		// We will now add a 3D indicator to the building
		//The geode containing our  information shape
		osg::ref_ptr<osg::Geode> myIndicatorCapsuleGeode (new osg::Geode);
		//The indicator is also created relatively to the size of the buildings
		osg::ref_ptr<osg::Capsule> myIndicatorCapsule (new osg::Capsule(osg::Vec3f(),myRadius * 0.05f, myHeight));
		//Place the sphere upon the building
		myIndicatorCapsule->setCenter(osg::Vec3f(myPos.x(),myPos.y(),myHeight*0.5));
		//The future Smarties' shape drawable
		osg::ref_ptr<osg::ShapeDrawable> myIndicatorCapsuleDrawable (new osg::ShapeDrawable(myIndicatorCapsule.get()));
		// Add the shape drawable to the geode ///myIndicatorCapsuleGeode->addDrawable(myIndicatorCapsuleDrawable.get());
		myGeode->addDrawable(myIndicatorCapsuleDrawable.get());
		// I don'get why if th following is missing, objects are not in the same place
		osg::ref_ptr<osg::MatrixTransform> myIndicatorCapsuleScaleMAT = new osg::MatrixTransform;

		//Add the applaned spher called smarties to the scene
		root->addChild(sphereToSmartiesScaleMAT.get());
	}
	if(displayText = true){
		myGeode->addDrawable(text);
	}
	//Add the Geode to global scene
	root->addChild(myGeode.get());
}


osg::Material * DisplayMode::getRedMaterial(){
	osg::Material* mat = new osg::Material;
	mat->setColorMode(osg::Material::AMBIENT); // SPECULAR or EMISSION or AMBIENT or DIFFUSE or AMBIENT_AND_DIFFUSE
	mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.6);
	// let's set the different lights and colors : RED
	mat->setAmbient (osg::Material::FRONT, osg::Vec4(1, 0, 0, 1));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(0.4, 0, 0, 1));
	return mat;
}
osg::Material * DisplayMode::getCoefColorMaterial(int figure){
	osg::Material* mat = new osg::Material;
	mat->setAlpha(osg::Material::FRONT_AND_BACK, 1);
	// let's set the different lights and colors :
	mat->setAmbient(osg::Material::FRONT, osg::Vec4(0, 0, 0, 1));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(figure/900, 0, 1-figure/900, 0.5)); // change values but be sure to normalize figure
	return mat;
}

osg::Material * DisplayMode::getOpacityMaterial(){
	osg::Material* mat = new osg::Material;
	mat->setAlpha(osg::Material::FRONT_AND_BACK, 0.5);
	// let's set the different lights and colors :
	mat->setAmbient(osg::Material::FRONT, osg::Vec4(1, 0, 0, 1));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(0, 0.5, 0, 0.5));
	return mat;
}

osg::Material * DisplayMode::getCoefOpacityMaterial(int figure){
	osg::Material* mat = new osg::Material;
	mat->setAlpha(osg::Material::FRONT_AND_BACK, figure/900);// change values but be sure to normalize getMyFigure()
	// let's set the different lights and colors :
	mat->setAmbient(osg::Material::FRONT, osg::Vec4(0, 0, 0, 1));
	mat->setSpecular(osg::Material::FRONT, osg::Vec4(0, 0.5, 0, 0.5));
	return mat;
}
