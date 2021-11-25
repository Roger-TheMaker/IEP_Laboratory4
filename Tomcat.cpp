#include <iostream>
#include <string>
#include "Avion.cpp"


using namespace::std;

class Tomcat : public Avion
{
 public:
 	Tomcat ( int planeId, string fuelPlane ): Avion(planeId), planefuel(fuelPlane) {}
	Tomcat ( const Tomcat& rhs ): Avion ( rhs ), planefuel(rhs.planefuel)
	{
	   // right hand side operator
	}
	
	Tomcat& operator= ( const Tomcat& rhs )
	{
		Avion::operator=(rhs);
		planefuel = rhs.planefuel;
		return *this; //item 10
	}// copy operator
	
	void ToString ( )
	{
	cout << "planeId: " << getplaneId() << "; plane Fuel: " << planefuel << endl; 
	}
	
 private:
 	string planefuel;	 
};

