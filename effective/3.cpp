#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
using namespace std;

int main(void){ 
	ifstream inputFile("interestingData.txt");
	inputFile.unsetf(ios::skipws);
//	cin.unsetf(ios::skipws);
//	string fileData((istream_iterator<char>(cin)),istream_iterator<char>());
	string fileData((istream_iterator<char>(inputFile)),istream_iterator<char>());
	cout<<fileData<<endl;
	
	return 0;
} 
