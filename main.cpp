#include "./Tomcat.cpp"
#include "./Safe.cpp"
#include <iostream>


int main(int argc, char *argv[])
{
 Tomcat t1(50," Tomcat nebun");
 cout << "Tomcat t1: " << endl;
 t1.ToString();
 
 Tomcat t2(t1);
 cout << endl << "Tomcat t2: " << endl;
 t2.ToString();
 
 

 Safe a, b, c;
 c.p1 = new Data();
 c.p2 = new Data();
 a = c = b = a = b = b = c = c = a = a = b = a = c;
    
}
