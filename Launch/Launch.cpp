// Launch.cpp : Main of the Launch Fake

/*
*
* Code by Dark.Hades
* Start 15.10.2016
* MS VS 2016
*/

#include "stdafx.h"

std::vector<std::string> explode(std::string const & s, char delim) // Function explode
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}

	return result;
}

string getClientVersion() { // Get client version
	
	std::ifstream vfile("(version)");
	std::string fline;
	std::getline(vfile, fline);// Get first line content
	auto v = explode(fline, '|');
	return v[0];
}

/*
auto getINIsettings() {
TCHAR szExeFileName[MAX_PATH];
string fname;
fname = GetModuleFileName(NULL, szExeFileName, MAX_PATH);
}
*/

int main()
{

	cout << getClientVersion() << endl;

	system("pause");
	return 0;
}