/*
 * gipXml.cpp
 *
 *  Created on: 4 Aðu 2021
 *      Author: Selçuk
 */

#include "gipXml.h"


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

	return std::string(xmlNode._rootNode()->Value());
}

std::string gipXml::getSiblingNode() {

	return std::string(xmlNode._SiblingNode()->Value());
}

std::string gipXml::getChildNode() {

	return std::string(xmlNode._ChildNode()->Value());
}

std::string gipXml::getChildElement() {

	return std::string(xmlElement._ChildElement()->Value());
}

std::string gipXml::getTagName() {

	return xmlElement._TagName();
}

std::string gipXml::getAttribute(std::string attributeName) {

	return xmlElement._Attribute(attributeName);

}
