#include <iostream>
#include <string>
#include "Avion.cpp"


using namespace::std;

class Tomcat : public Avion
{
 public:
 	Tomcat ( int planeId, string planeName ): Avion(planeId), planename(planeName) {}
	Tomcat ( const Tomcat& rhs ): Avion ( rhs ), planename(rhs.planename){}
	
	Tomcat& operator= ( const Tomcat& rhs ) // item 12
	{
		Avion::operator=(rhs); // item 12
		planename = rhs.planename;
		return *this;
	}
	
	void ToString ( )
	{
	cout << "planeId: " << getplaneId() << "; plane Name: " << planename << endl; 
	}
	
 protected:
 	string planename;	 
};

