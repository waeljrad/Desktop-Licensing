#ifndef DEF_DEVICE
#define DEF_DEVICE

#include <string>
#include <vector>

#include "Installation.h"


class Device {

public:
	Device(std::string name, std::string region);
	~Device();
	void addInstallation(std::string family, std::string product, std::string edition, std::string version);

private:
	std::string name;
	std::string region;
	std::vector<Installation*> Installs;
}; 
#endif