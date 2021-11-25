#include "./Tomcat.cpp"
#include "./Safe.cpp"
#include <iostream>


int main(int argc, char *argv[])
{
 Tomcat t1(50," Tomcat nebun");
 cout << "Tomcat t1: " << endl;
 t1.ToString();
 
 // Age should be 50 but remains zero
 Tomcat t2(t1);
 cout << endl << "Tomcat t2: " << endl;
 t2.ToString();
 
 Tomcat t ( 777, "Tomcat mai nebun");
 Tomcat t3 ( 100, "Tomcat foarte nebun");
 
 // Age should become 777 but remains 100
 t3 = t;
 cout << endl << "Tomcat t3: " << endl;
 t3.ToString();


 Safe a, b, c;
 c.pData = new Data();
 c.pData2 = new Data();
 a = c = b = a = b = b = c = c = a = a = b = a = c;
    
}
