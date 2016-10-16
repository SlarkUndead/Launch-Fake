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

LPCTSTR getExecPath()
{
	DWORD len = 64;
	for (;;) {
		LPTSTR fileName = new TCHAR[len];
		if (len == ::GetModuleFileName(NULL, fileName, len)) {
			delete fileName;
			len *= 2;
		}
		else {
			return fileName;
		}
	}
}

/*
 * Get client version
 */
string getClientVersion() {

	std::ifstream vfile("(version)");
	if (!vfile) {
		throw std::invalid_argument("File (version) not found");
		return NULL;
	}
	if (vfile.peek() == std::ifstream::traits_type::eof()) {
		throw std::invalid_argument("File (version) is empty");
		return NULL;
	}
	std::string fline;
	std::getline(vfile, fline);// Get first line content
	auto v = explode(fline, '|');

	return v[0];
}

/*
* Get Launch Settings
*/
string getINIsettings(string setting, string df="") {

	INIReader reader("Launch.ini");

	if (reader.ParseError() < 0) {
		throw std::invalid_argument("Can't load .ini");
		return NULL;
	}

	return reader.Get("Launch", setting, df);

}

/*
* Update Patch folder
*/
int updatePatchFolder() {
	cout << getINIsettings("ChoiceURL") << endl;
	//system(".\\Bin\\Game.exe -fl");
	return 0;
}

int main()
{
	try {

		updatePatchFolder();

	} catch (invalid_argument& e) {
		cerr << e.what() << endl;
	}
	//system("pause");
	return 0;
}