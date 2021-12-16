#include<iostream>
#include<memory>
using namespace std;


class Investment{
public:
	Investment(){
	cout << "Constructor Investment" << endl;
}
	~Investment(){
		cout << "Destructor Investment" << endl;
	}

};
