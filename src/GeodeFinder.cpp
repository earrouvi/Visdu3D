/*
 * GeodeFinder.cpp
 *
 *  Created on: 10 dŽc. 2010
 *      Author: Flo
 */

#include "GeodeFinder.h"

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
