/*
 * gipXml.cpp
 *
 *  Created on: 4 Aðu 2021
 *      Author: Selçuk
 */

#include <gipXml.h>


bool gipXml::load(std::string _fullPath) {
	fullpath = _fullPath;
	directory = getDirName(fullpath);
	path = getFileName(fullpath);
	fpath = new char[fullpath.size() + 1];
	std::strcpy(fpath, fullpath.c_str());

	int ret = (int)xmlDoc.LoadFile(fpath);

	return ret == (int)XMLError::XML_SUCCESS;
}

bool gipXml::loadXml(std::string xmlpath) {
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

std::string gipXml::getRootNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();

	return std::string(rootnode->Value());
}

std::string gipXml::getSiblingNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();

	return std::string(SiblingNode->Value());
}

std::string gipXml::getChildNode() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	return std::string(ChildNode->Value());
}

std::string gipXml::getChildElement() {

	XMLNode *rootnode = xmlDoc.FirstChild();
	XMLNode *SiblingNode = rootnode ->NextSibling();
	XMLNode *ChildNode = SiblingNode ->FirstChild();

	XMLElement *ChildElement = ChildNode->ToElement();

	return std::string(ChildElement->Value());
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
