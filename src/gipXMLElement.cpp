/*
 * gipXMLElement.cpp
 *
 *  Created on: 23 Aðu 2021
 *      Author: ROG_D
 */

#include "gipXMLElement.h"

XMLElement* gipXMLElement::_ChildElement() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	return ChildElement;
}

std::string gipXMLElement::_TagName() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	std::string strTagName = ChildElement ->Name();

	return strTagName;
}

std::string gipXMLElement::_Attribute(std::string attributeName) {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	std::string strAttribute = ChildElement ->Attribute(attributeName.c_str());

	return strAttribute;
}

