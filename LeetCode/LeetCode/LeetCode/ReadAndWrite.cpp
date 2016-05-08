#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int fileProcess()
{
	ifstream infile;
	ofstream outfile("d://test_back.txt");
	vector<string> content;
	infile.open("d://test.txt");
	if (!infile)
	{
		cerr << "read error" << endl;
		exit(0);
	}
	while (!infile.eof())
	{
		string s;
		//infile.getline(s, 10)
		getline(infile, s, '\n');
		content.push_back(s);
	}
	infile.close();
	for (int i = 0; i < content.size(); i++)
		outfile << content[i] << endl;
	outfile << "just for test" << endl;
	outfile.close();
	return 0;
}