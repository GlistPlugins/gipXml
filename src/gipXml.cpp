/*
 * gipXml.cpp
 *
 *  Created on: 4 Aðu 2021
 *      Author: Selçuk
 */

#include <gipXml.h>


XMLError gipXml::load(std::string _fullPath) {
	fullpath = _fullPath;
	directory = getDirName(fullpath);
	path = getFileName(fullpath);
	fpath = new char[fullpath.size() + 1];
	std::strcpy(fpath, fullpath.c_str());

	xmlDoc.LoadFile(fpath);

	return xmlDoc.LoadFile(fpath);
}

int gipXml::loadXml(std::string xmlpath) {
	return load(gGetFilesDir() + xmlpath);
}

std::string gipXml::getDirName(const std::string& fname) {
     size_t pos = fname.find_last_of("\\/");
     return (std::string::npos == pos)
         ? ""
         : fname.substr(0, pos);
}

std::string gipXml::getFileName(const std::string& fname) {
     size_t pos = fname.find_last_of("\\/");
     return (std::string::npos == pos)
         ? ""
         : fname.substr(pos + 1, fname.size());
}

void gipXml::parseXml() {

	xmlDoc.Parse(fpath);
}

XMLNode* gipXml::getRootNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();

	return rootnode;
}

XMLNode* gipXml::getSiblingNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();

	return SiblingNode;
}

XMLNode* gipXml::getChildNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	std::string strChildName = ChildElement ->Name();

	return ChildNode;
}

XMLElement* gipXml::getChildElement() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	return ChildElement;
}

std::string gipXml::getTagName() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	std::string strTagName = ChildElement ->Name();

	return strTagName;
}

std::string gipXml::getAttribute(std::string attributeName) {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	std::string strAttribute = ChildElement ->Attribute(attributeName.c_str());

	return strAttribute;

}
