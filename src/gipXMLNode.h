/*
 * gipXmlNode.h
 *
 *  Created on: 24 Aug 2021
 *      Author: Selcuk
 */

#ifndef SRC_GIPXMLNODE_H_
#define SRC_GIPXMLNODE_H_

#include "gBasePlugin.h"
#include "tinyxml2.h"

using namespace tinyxml2;

class gipXmlNode: public gBasePlugin {
public:
	gipXmlNode();
	virtual ~gipXmlNode();

	void setNode(XMLNode* outnode);

	std::string getTag();
	gipXmlNode* getSiblingNode();
	gipXmlNode* getChildNode();
	std::string getAttribute(std::string attribute);

private:
	XMLNode* node;
	XMLElement* element;
	std::string tagname;
};

#endif /* SRC_GIPXMLNODE_H_ */
