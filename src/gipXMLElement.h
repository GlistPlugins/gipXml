/*
 * gipXMLElement.h
 *
 *  Created on: 23 Aðu 2021
 *      Author: ROG_D
 */

#ifndef SRC_GIPXMLELEMENT_H_
#define SRC_GIPXMLELEMENT_H_

#include "gBasePlugin.h"
#include "tinyxml2.h"
using namespace tinyxml2;

class gipXMLElement {

public:

	XMLElement* _ChildElement();
	std::string _TagName();
	std::string _Attribute(std::string attributeName);


private:
	XMLDocument xmlDoc;
	XMLNode *rootnode, *SiblingNode, *ChildNode;
	XMLElement *ChildElement;
	const char *strTagName, *strAttribute;
};

#endif /* SRC_GIPXMLELEMENT_H_ */
