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
	  }
	  virtual void launchMissile()
	  {

		  std::cout << getPlaneID() << getTotalEnginePower() << " --- Fire! " << std::endl;
	  }

  };
  
  

int main(int argc, char** argv){
	std::cout << "Hello Roger" << std::endl;
	
	Avion avion1 = Avion("Alcatraz", 2);
	avion1.printDetails();
	
	Calatori avion2 = Calatori("Air700Ro", 7 , 30);
	avion2.printDetails();
	
	
	Avion avion3 = Calatori("Air700Ro2", 7 , 30);
	avion3.printDetails();
	return 0;
}



