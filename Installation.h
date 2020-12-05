#ifndef DEF_INSTALLATION
#define DEF_INSTALLATION

#include <string>

class Installation {

public:
	Installation(std::string family, std::string product, std::string edition, std::string version);
	~Installation();

private:
	std::string family;
	std::string product;
	std::string edition;
	std::string version;
	bool hasEdition;
	bool isChargeable;
}; 


#endif
