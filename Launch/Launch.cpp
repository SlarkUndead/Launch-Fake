// Launch.cpp : Main of the Launch Fake

/*
*
* Code by Dark.Hades
* Start 15.10.2016
* MS VS 2016
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getClientVersion() {
	string file;
	file = "(version)";

	char data[100];

	ifstream v;
	v.open(file);
	v >> data;
	//cout << data;
	v.close();

	return file;
}
int main()
{
	ofstream myfile("(version)");
	if (myfile.is_open())
	{
		cout << "fsf";
		myfile.close();
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}