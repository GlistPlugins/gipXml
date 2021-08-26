/*
 * gipXml.h
 *
 *  Created on: 4 Aðu 2021
 *      Author: Selçuk
 */

#ifndef SRC_GIPEMPTY_H_
#define SRC_GIPEMPTY_H_

#include "gBasePlugin.h"
#include "gipXmlNode.h"
using namespace tinyxml2;

class gipXml : public gBasePlugin{
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
	 * Iterates the nodes by calling NextSibling() function of XMLNode.
	 */
	gipXmlNode* getSiblingNode(gipXmlNode* xmlNode);

	/*
	 * Gets the child level nodes of the current node by calling FirstChild() function of XMLNode.
	 */
	gipXmlNode* getChildNode(gipXmlNode* xmlNode);

	/*
	 *Gets data from node by using XML Node class ToElement() function.
	 */
	//Child Elemnt

	/*
	 * Gets the Tag name of the Node using Name() function of XMLElement class.
	 */
	//TAG NAME

	/*
	 * Gets the values of the attributes of elements using the Attribute() function by giving the attribute name as parameter.
	 *
	 * Use it if your xml has attributes in it you can also use it to check if the xml file has attributes or not as well.
	 *
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
