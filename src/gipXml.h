/*
 * gipXml.h
 *
 *  Created on: 4 aug 2021
 *      Author: Selçuk
 */

#ifndef SRC_GIPEMPTY_H_
#define SRC_GIPEMPTY_H_

#include "gBaseComponent.h"
#include "gipXmlNode.h"
using namespace tinyxml2;

class gipXml : public gBaseComponent {
public:

	/*
	 * Loads the XML from fullpath.
	 */
	bool load(std::string fullpath);

	/*
	 * Loads the XML from file path.
	 */
	bool loadXml(std::string xmlpath);

	/*
	 * Parsing for string that contains XML.
	 */
	void parseXml();

	/*
	 * Gets the root node by calling FirstChild function of XMLDocument. It will return a pointer to the XMLNode class.
	 */
	gipXmlNode* getRootNode();

	/*
	 * Iterates the node by calling NextSibling() function of XMLNode.
	 */
	gipXmlNode* getSiblingNode(gipXmlNode* xmlNode);

	/*
	 * Gets the child level node of the current node by calling FirstChild() function of XMLNode.
	 */
	gipXmlNode* getChildNode(gipXmlNode* xmlNode);

	/*
	 * Gets the Tag name of the Node using Name() function of XMLElement class.
	 */
	std::string getTagName(gipXmlNode* xmlNode);

	/*
	 * Gets the values of the attributes of elements using the Attribute() function by giving the attribute name as parameter.
	 */
	std::string getAttribute(gipXmlNode* xmlNode, std::string attributeName);

private:
	std::string fullpath, directory, path;
	std::string getDirName(const std::string& fname);
	std::string getFileName(const std::string& fname);
	char *fpath;
	XMLDocument xmlDoc;
	gipXmlNode *rootnode;
};

#endif /* SRC_GIPEMPTY_H_ */
