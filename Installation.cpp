#include "Installation.h"

using namespace std;

class Installation {
	

	Installation::Installation(string family, string product, string edition, string version)
	{
		this->family = family;
		this->product = product;
		this->edition = edition;
		this->version = version;
		this->hasEdition = !(edition = "");
		this->isChargeable = true;
	}

	Installation::~Installation() {

	}

};