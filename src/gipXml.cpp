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

	XMLError error = xmlDoc.LoadFile(fpath);
	if(error != 0) {
		if(error == 3) gLogi("gipXml") << "Dosya bulunamadi ";
		return false;
	}
	rootnode = new gipXmlNode();
	if(xmlDoc.FirstChild())
		rootnode->setNode(xmlDoc.FirstChild());
	return true;
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

gipXmlNode* gipXml::getRootNode() {
	return rootnode;
}

gipXmlNode* gipXml::getSiblingNode(gipXmlNode* xmlNode) {
	return xmlNode->getSiblingNode();
}

gipXmlNode* gipXml::getChildNode(gipXmlNode* xmlNode) {
	return xmlNode->getChildNode();
}

std::string gipXml::getAttribute(gipXmlNode* xmlNode, std::string attributeName) {
	return xmlNode->getAttribute(attributeName);

}
