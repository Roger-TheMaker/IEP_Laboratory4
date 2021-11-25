#include <string>
#include <iostream>

using namespace::std;


class Avion
{
  protected:
  	 
  	 Avion (int planeId): planeid (planeId) {};
 	 Avion (const Avion& rhs ): planeid  ( rhs.planeid ) {}; //copy constructor
 	 
	 Avion& operator = ( const Avion& rhs )  //copy operator
   	 {
   	 	planeid  = rhs.planeid ;
   		return *this;
    	}
    	
	int getplaneId ( ) {return planeid;}

  private:
    	int planeid;
};







