#include <string>
#include <iostream>

class Avion
{
  private:
  std::string planeId;
  int totalEnginePower;

  public:
  Avion(const std::string &id, int eng)
  {
	  planeId = id;
	  totalEnginePower = eng;
	  std::cout << "calling the class Avion constructor" << std::endl;
  }

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
	  std::cout << getPlaneID() << " " << getTotalEnginePower() << std::endl;
  }
};




class Calatori : public Avion
{

  private:
	  int maxPassengers;

  public:
	  Calatori(const std::string &id, int eng, int maxPassengers) : Avion(id,eng)
	  {
		  this->maxPassengers = maxPassengers;
		  std::cout << "calling the class Calatori constructor" << std::endl;
	  }

	  virtual int getMaxPassengers()
	  {
		  return this->maxPassengers;
	  }

	 virtual void printDetails()
  {
	  std::cout << getPlaneID() << " " << getTotalEnginePower() << " " << getMaxPassengers() << std::endl;
  }
};



  class Lupta : public Avion
  {

  public:
	  Lupta(const std::string &id, int eng) : Avion(id, eng)
	  {
	 	 std::cout << "calling the class Lupta constructor" << std::endl;
	  }
	  virtual void launchMissile()
	  {

		  std::cout << getPlaneID() << getTotalEnginePower() << " Prepare missile --- Fire! " << std::endl;
	  }

  };
  
  
 
class AvionUnic
{
    private:
        /* Here will be the instance stored. */
        static AvionUnic* instance;

        /* Private constructor to prevent instancing. */
        AvionUnic();

    public:
        /* Static access method. */
        static AvionUnic* getInstance();
};

/* Null instance, because it will be initialized on demand. */

AvionUnic* AvionUnic::instance = 0; //declararea unui atribut

AvionUnic* AvionUnic::getInstance() //declararea unei metode
{
    if (instance == 0)
    {
        instance = new AvionUnic();
        std::cout << "first and only instantion of the class AvionUnic"  << std::endl;
        
    }

    return instance;
}

AvionUnic::AvionUnic() // definirea constructorului
{
	std::cout << "calling the constructor of AvionUnic"  << std::endl;
}


  

int main(int argc, char** argv){
	std::cout << "Hello Roger" << std::endl;
	
	Avion avion7("Roger's Plane ", 2);
	avion7.printDetails();
	
	Avion avion1 = Avion("Alcatraz", 2);
	avion1.printDetails();
	
	Calatori avion2 = Calatori("Air700Ro", 7 , 30);
	avion2.printDetails();
	
	Avion avion3 = Calatori("Air700Ro2", 7 , 30);
	avion3.printDetails();
	
	Lupta avion4 = Lupta("Air700Ro2", 7);
	avion4.launchMissile();
	
	Avion avion5 = Lupta("Air700Ro2", 7);
	//avion5.launchMissile();
	
	AvionUnic* z = AvionUnic::getInstance();
	std::cout << "Hascode: "   <<  z  << std::endl;
	
	AvionUnic* w = AvionUnic::getInstance();
	std::cout << "Hascode: "   <<  w  << std::endl;
	
	return 0;
}



