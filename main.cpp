#include <string> //necesar pentru citire sau scriere la iesirea/intrarea standard
#include <iostream>

class Avion
{
  protected:
  std::string planeId = "";
//std este un namespace care inseamna o regiune declararativa pentru nume de topuri, functii si variabile
// :: este un operator numit "scope" care precizeaza compilatorului dupa ce nume sa se uite in lista de identificatori
  int totalEnginePower = 0;

  public:
  Avion(const std::string &id, int eng): planeId(id), totalEnginePower(eng)
  {  	  //Atribuirea proprietatilor constructorului folosind Lista de Initializare
	  
	  std::cout << "calling the constructor of class Avion" << std::endl;
  }
  
  
  /*
  or
  
  Avion(const std::string &id, int eng)
  {  	  
	  this->planeId = id;
	  this->totalEnginePower = eng;
	  std::cout << "calling the constructor of class Avion" << std::endl;
  }

  */

  virtual std::string getPlaneID()
  {

	  return this->planeId;
  }

  virtual int getTotalEnginePower()
  {

	  return this->totalEnginePower;
  }


  virtual void printDetails()
  {
	  std::cout << "Plane ID: " << getPlaneID() << " | TotalEnginePower: " << getTotalEnginePower() << std::endl;
  }
};




class Calatori : public Avion
{

  protected:
	  int maxPassengers;

  public:
	  Calatori(const std::string &id, int eng, int maxPassengers) : Avion(id,eng)
	  {
		  this->maxPassengers = maxPassengers;
		  std::cout << "calling the constructor of class Calatori" << std::endl;
	  }

	  virtual int getMaxPassengers()
	  {
		  return this->maxPassengers;
	  }

	 virtual void printDetails() override
  		{
		   std::cout << "Plane ID: " << getPlaneID() << " | TotalEnginePower: " << getTotalEnginePower() << " | MaxNumberOfPassengers: " << getMaxPassengers() << std::endl;
  		}
};



  class Lupta : public Avion
  {

  public:
	  Lupta(const std::string &id, int eng) : Avion(id, eng)
	  {
	 	 std::cout << "calling the constructor of class Lupta" << std::endl;
	  }
	  virtual void launchMissile()
	  {

		std::cout << "Plane ID: " << getPlaneID() << " | TotalEnginePower: " << getTotalEnginePower() <<  " | Prepare missile --- Fire! "  << std::endl;
	  }

  };
  
  
  
  
  class Avion_Testare : public Avion
  {

  public:
	  Avion_Testare(const std::string &id, int eng) : Avion(id, eng)
	  {
	 	 std::cout << "calling the constructor of class Avion_Testare" << std::endl;
	  }
	  
	virtual void printDetails() override
  	  {
	 	 std::cout << getPlaneID() << " " << getTotalEnginePower() << std::endl;
          }

  };
  
  
  
  
 
class AvionPrivat
{
    private:
        /* Here will be the instance stored. */
        static AvionPrivat* instance;

        /* Private constructor to prevent instancing. */
        AvionPrivat();

    public:
        /* Static access method. */
        static AvionPrivat* getInstance();
        
        virtual void print()  // simple method
  	  {
	 	 std::cout << "Just For VIPS" << std::endl;
          }
};



AvionPrivat* AvionPrivat::instance = 0;
/* Null instance, because it will be initialized on demand. */

AvionPrivat* AvionPrivat::getInstance()
{
    if (instance == 0)
    {
        instance = new AvionPrivat();
        std::cout << "first and only instantion of the class AvionPrivat"  << std::endl;
        
    }

    return instance;
}

AvionPrivat::AvionPrivat() // definirea constructorului
{
	std::cout << "calling the constructor of AvionPrivat"  << std::endl;
}


  

int main(int argc, char** argv){
	std::cout << "Welcome to the Plane Management System" << std::endl;
	

	Avion avion1 = Avion("Alcatraz", 2);
	avion1.printDetails();
	
	Calatori avion2 = Calatori("Air700Ro", 7 , 30);
	avion2.printDetails();
	
	Avion avion3 = Calatori("Air700Ro2", 7 , 30);
	avion3.printDetails();
	
	Lupta avion4 = Lupta("rUSSIA", 7);
	avion4.launchMissile();
	avion4.printDetails();
	
	
	
	AvionPrivat* z = AvionPrivat::getInstance();
	std::cout << "Hascode: "   <<  z  << std::endl;
	
	AvionPrivat* w = AvionPrivat::getInstance();
	std::cout << "Hascode: "   <<  w  << std::endl;
	z->print();
	
	
	Avion_Testare * avion_testare = new Avion_Testare("Avion de Testare", 20);
	avion_testare->printDetails(); // MERGE SI ASA
	
	Avion * avion10 = new Lupta("Americano", 2);
	//avion10->launchMissile(); Este corect ca nu merge
	
	return 0;
}



