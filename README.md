# gipXml
Xml component for [GlistEngine](https://github.com/GlistEngine/GlistEngine).
### Requirements
- [GlistEngine](https://github.com/GlistEngine/GlistEngine).
- Any program that can read/write XML file type.
- Windows, Linux, or MacOS operating system.

## Installation
### 1. Open file explorer and create necessary folders:
- On Windows:
  - C:\dev\glist\glistplugins
- On macOS
  - ~/dev/glist/glistplugins
- On Linux
  - ~/dev/glist/glistplugins
### 2. Clone Plugin :
 First of all fork this repo at right up corner.  
   
Open command line(cmd.exe or bash) and go to the glistplugins folder by the command.
- On Windows:
  > cd C:\dev\glist\glistplugins
- On macOS:
  > cd ~/dev/glist/glistplugins
- On macOS:
  > cd ~/dev/glist/glistplugins
  
 Clone the gipXml repo by writing this commands on command line:
 > git clone https://github.com/yourgithubusername/gipXml.git

### 3. Set Up Plugin
 Add "gipXml" in GlistApp's CMakelists.txt's line where it write "set(PLUGINS)" (Like "set(PLUGINS gipXml)").
## How to Use
Only requirement to use the plugin is to include the header file of "gipXml" plugin.
### Functions
- bool load(std::string fullpath) :
  > Loads the XML from fullpath.
- bool loadXml(std::string xmlpath) :
  > Loads the XML from file path.
- void parseXml() :
  > Parsing for string that contains XML.
- gipXmlNode* getRootNode() :
  > Gets the root node by calling FirstChild function of XMLDocument. It will return a pointer to the XMLNode class.
- gipXmlNode* getSiblingNode(gipXmlNode* xmlNode) :
  > Iterates the node by calling NextSibling() function of XMLNode.
- gipXmlNode* getChildNode(gipXmlNode* xmlNode) :
  > Gets the child level node of the current node by calling FirstChild() function of XMLNode.
- std::string getTagName(gipXmlNode* xmlNode) :
  > Gets the Tag name of the Node using Name() function of XMLElement class.
- std::string getAttribute(gipXmlNode* xmlNode, std::string attributeName) :
  > Gets the values of the attributes of elements using the Attribute() function by giving the attribute name as parameter.
