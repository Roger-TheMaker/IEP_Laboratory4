#include<iostream>
#include<memory>
using namespace std;


class Investment{
public:
	Investment(){
	cout << "Constructing Investment ..." << endl;
}
	~Investment(){
		cout << "Destructing Investment ..." << endl;
	}

};
