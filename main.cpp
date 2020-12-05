// DesktopLicensing.cpp : Defines the entry point for the console application.
//
#include "Installation.h"
#include "Device.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

// Fonction split
vector<string> split(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}


int main()
{
	//Constantes Catalogue
	int const CAT_PACKAGE = 0;
	int const CAT_EDITION = 1;
	int const CAT_VERSION = 2;
	int const CAT_RANK = 3;
	int const CAT_PRODUCT = 4;

	//Constates Installations
	int const DEVICE_NAME = 0;
	int const REGION = 1;
	int const TYPE = 2;
	int const FAMILY = 3;
	int const PRODUCT = 4;
	int const EDITION = 5;
	int const VERSION = 6;


	// 1. Lecture catalogue
	string catalogueFile("Catalog.csv");
	string line;
	vector<vector<string> > catalogue;
	ifstream fCatalogue(catalogueFile.c_str());

	if (fCatalogue)
	{
		bool notEntitles=false;
		while (getline(fCatalogue, line))
		{
			if (notEntitles)
			{
				catalogue.push_back(split(line,','));
				for (int i=0; i<catalogue[catalogue.size()-1].size();  i++) {
					cout << catalogue[catalogue.size() - 1][i] << "\t";
				cout << endl;
				}

			}
			else
			{
				notEntitles = true;
			}
		}
	}
	else
	{
		cout << "> Opening catalog is impossible." << endl;
	}

	// 2. Insertion Devices et Installations
	map<string, Device*> Devices;
	string installsFile("Deployments.csv");
	line="";
	ifstream fInstallas(catalogueFile.c_str());

	if (fInstallas)
	{
		bool notEntitles = false;
		while (getline(fInstallas, line))
		{
			if (notEntitles)
			{
				vector<string> splitLine = split(line, ',');
				if (Devices.count(splitLine[DEVICE_NAME]) == 0) {
                   //Device *pt;
					cout << new Device(splitLine[DEVICE_NAME], splitLine[REGION]);
					//Devices[splitLine[DEVICE_NAME]] = pt;
				}

				/*Devices[splitLine[DEVICE_NAME]]->addInstallation(splitLine[FAMILY],
					splitLine[PRODUCT],
					splitLine[EDITION],
					splitLine[VERSION]);*/
			}
			else
			{
				notEntitles = true;
			}
		}
	}
	else
	{
		cout << "> Opening deployments is impossible." << endl;
	}
	while (true);
    return 0;
}
