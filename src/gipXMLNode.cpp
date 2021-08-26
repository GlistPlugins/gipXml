/*
 * gipXmlNode.cpp
 *
 *  Created on: 24 Aug 2021
 *      Author: Selcuk
 */

#include "gipXmlNode.h"

gipXmlNode::gipXmlNode() {

}

gipXmlNode::~gipXmlNode() {
	// TODO Auto-generated destructor stub
}

void gipXmlNode::setNode(XMLNode* outnode) {
	if (outnode->ToElement() == nullptr)
		outnode = outnode->NextSibling();
	node = outnode;

	element = node->ToElement();
	tagname = element->Name();
}

std::string gipXmlNode::getTag() {
	return tagname;
}

gipXmlNode* gipXmlNode::getSiblingNode() {
	gipXmlNode* siblingXml = new gipXmlNode;
	if(node->NextSibling()){
		siblingXml->setNode(node->NextSibling());
		return siblingXml;
	}

	gLogi("gipXmlNode") << "Sibling doesn't exist...";
	return this;
}

gipXmlNode* gipXmlNode::getChildNode() {
	gipXmlNode* childXml = new gipXmlNode;
	if(node->FirstChild()) {
		childXml->setNode(node->FirstChild());
		return childXml;
	}
	gLogi("gipXmlNode") << "Child doesn't exist...";
	return this;
}

std::string gipXmlNode::getAttribute(std::string attribute){
	if (element->Attribute(attribute.c_str()))
	return element->Attribute(attribute.c_str());

	return "Attribute doesn't exist...";
}
