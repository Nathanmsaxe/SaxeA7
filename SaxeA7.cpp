#include <iostream>
#include "Container.h"
#include "Container.cpp"
using namespace std;



int main() {
	bool b;
	Container<int, string> c(5);

	int keyValue=111;
	string dataValue="aaa";
	c.push_back(keyValue, dataValue);
	keyValue=222;
	dataValue="bbb";
	c.push_back(keyValue, dataValue);
	keyValue=333;
	dataValue="ccc";
	c.push_back(keyValue, dataValue);
	cout << "size of c after three pushes " << c.size() << endl;
	keyValue=444;
	dataValue="ddd";
	c.push_back(keyValue, dataValue);
	keyValue=555;
	dataValue="eee";
	c.push_back(keyValue, dataValue);

	cout << "max size of c " << c.max_size() << endl;

	int m;
	string n;
	m = c.key(0);
	n = c.data(0);
	cout << "retrieval of element [0] -->" << m << "-->" << n << endl;

	m = c.key(4);
	n = c.data(4);
	cout << "retrieval of element [4] -->" << m << "-->" << n << endl;

	cout << "before attempted retrieval of element [5]" << endl;
	try {
	m = c.key(5);
	}
	catch (string&) {
		cout << "   successfully threw exception" << endl;
	}
	m = 333;
	b = c.retrieve_by_key (m, n);
	cout << "retrieve_by_key=333, returned data -->" << n << endl;

	m = 334;
	b = c.retrieve_by_key (m, n);
	if (!b)
	{
		cout << "successfully returned not found when looking for key 334" << endl;
	}

	n = c[2];
	cout << "return from first c[2]  -->" << n << endl;
	c[2] = "zzz";
	n = c[2];
	cout << "return from second c[2] -->" << n << endl;

	keyValue=666;
	dataValue="fff";
	b = c.push_back(keyValue, dataValue);
	if (!b)
	{
		cout << "successfully returned container full" << endl;
	}
	return 0;
}
