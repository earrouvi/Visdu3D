/*
 * GeodeFinder.cpp
 *
 *  Created on: Dec. 2010
 *      Author: Visdu3D, Group project working on cityGML and ESRI formats co-visualization.
 *      Elsa Arrou-Vignod
 *      Florent Buisson
 *      Robin Kervadec
 *      Alice Lan
 *      Michael Lumbroso
 *      Toinon Vigier
 *
 *      This file is taken from an OSG project tutorial:
 *      http://sourceforge.net/apps/mediawiki/delta3d/index.php?title=Accessing_Underlying_OpenSceneGraph_Geometry
 */

#include "GeodeFinder.h"
#include <string.h>

GeodeFinder::GeodeFinder ()
   : NodeVisitor (osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) {}

void GeodeFinder::apply (osg::Node &searchNode) {
   if (! strcmp (searchNode.className(), "Geode")) {
      foundGeodes.push_back ((osg::Geode*) &searchNode);
   }

   traverse (searchNode);
}

osg::Geode* GeodeFinder::getFirst () {
   if (foundGeodes.size() > 0)
      return foundGeodes.at(0);
   else
      return NULL;
}

std::vector<osg::Geode*> GeodeFinder::getNodeList() {
   return foundGeodes;
}
