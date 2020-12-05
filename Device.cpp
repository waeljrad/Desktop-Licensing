#include "Device.h"

using namespace std;

class Device {

	Device::Device(string name,  string region) {
		this->name = name;
		this->region = region;
		return this;
	}

	Device::~Device() {
		for (int i = 0; i < this.Installs.size(); i++)
			delete this->Installs[i];
	}
	
	void Device::addInstallation(string family, string product, string edition, string version) {
		this->Installs.push_back(*(new Installation(family, product, edition, version)));
	}

};