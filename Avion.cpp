#include <string>
#include <iostream>

using namespace::std;


class Avion
{
  public:
  	 
  	 Avion (int planeId): planeid (planeId) {};
 	 Avion (const Avion& rhs ): planeid  ( rhs.planeid ) {}; // copy constructor
 	 
	 Avion& operator = ( const Avion& rhs ) 
	 // supraincarcarea operatorului de assignment
	 // tipul returnat este o referinta la clasa curenta
   	 {
   	 	planeid  = rhs.planeid ;
   		return *this; //returnarea obiectului left-handed
    	}
    	
	int getplaneId ( ) {return planeid;}

  protected:
    	int planeid;
};







