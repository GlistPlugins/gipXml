/*
 * gipXMLNode.h
 *
 *  Created on: 23 Aðu 2021
 *      Author: ROG_D
 */

#ifndef SRC_GIPXMLNODE_H_
#define SRC_GIPXMLNODE_H_

#include "tinyxml2.h"
using namespace tinyxml2;

class gipXMLNode {


public:

	XMLNode* _rootNode();
	XMLNode* _SiblingNode();
	XMLNode* _ChildNode();


private:

	XMLDocument xmlDoc;
	XMLNode *rootnode, *SiblingNode, *ChildNode;
};
#endif /* SRC_GIPXMLNODE_H_ */
