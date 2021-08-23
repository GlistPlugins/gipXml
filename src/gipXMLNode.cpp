/*
 * gipXMLNode.cpp
 *
 *  Created on: 23 Aðu 2021
 *      Author: ROG_D
 */

#include "gipXMLNode.h"

XMLNode* gipXMLNode::_rootNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();

	return rootnode;
}

XMLNode* gipXMLNode::_SiblingNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();

	return SiblingNode;
}

XMLNode* gipXMLNode::_ChildNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	return ChildNode;
}

