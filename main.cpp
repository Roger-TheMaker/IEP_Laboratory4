#include "./Investment.cpp"
#include "./Lock.cpp"

#include <iostream>
#include<memory>

using namespace std;


void doSomething(){
	mutex m;
	Lock lock(&m);


	Lock lock1(lock);
}

void f(){

	/*
	pointerii smart sunt ca niste templateuri
	la unique pointers poti doar sa muti zona de memorie sa fie referita de catre 
	alt pointer, dar aceeasi zona aceasta de memorie nu poate fi referita de catre 		mai multi pointeri simultan, acest lucru se face prin std::move
	
	Acesti pointeri au niste functii speciale, precum delete ul cred, care se
	apeleaza cand este nevoie ...
	*/
	
	
	std::unique_ptr<Investment> pInv(new Investment);
	//std::unique_ptr<Investment> pInv_beta = pInv;
	
	std::unique_ptr<Investment> pInv_beta = std::move(pInv); 

	//std::unique_ptr<Investment> pInv1(pInv);
	/*error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr etc
	unique_ptr(const unique_ptr&) = delete;  */

	
	//unique_ptr<Investment> pInv2(NULL);
	//call of overloaded ‘unique_ptr(NULL)’ is ambiguous
	
	//pInv2 = pInv1;


	shared_ptr<Investment> sInv(new Investment);
	shared_ptr<Investment> sInv1 = sInv;
	shared_ptr<Investment> sInv2(NULL);
	sInv2 = sInv1;

}

unique_ptr<Investment> MyFunction() {

    unique_ptr<Investment> myPtr;

    /* ... */

    return myPtr;
}



/*

Teorie


This idiom means "I'm returning a managed resource to you. If you don't explicitly capture the return value, then the resource will be cleaned up. If you do, then 
you now have exclusive ownership of that resource." In this way, you can think of unique_ptr as a safer, better replacement for auto_ptr.

shared_ptr, on the other hand, allows for multiple pointers to point at a given resource. When the very last shared_ptr to a resource is destroyed, the resource will be deallocated.


It's a type whose values can be used like pointers, but which provides the additional feature of automatic memory management: When a smart pointer is no longer in use, the memory it points to is deallocated


Use std::unique_ptr when you want your object to live just as long as a single owning reference to it lives. For example, use it for a pointer to memory which gets allocated on entering some scope and de-allocated on exiting the scope.

Use std::shared_ptr when you do want to refer to your object from multiple places - and do not want your object to be de-allocated until all these references are themselves gone.

Perfect
*/


int main(int argc, char *argv[])
{


	doSomething();



    f();
    
    //Exemple
    
	std::unique_ptr<int> p1(new int(5));
	//std::unique_ptr<int> p2 = p1;  // Compile error.
	std::unique_ptr<int> p3 = std::move(p1);  // Transfers ownership. p3 now owns the memory and p1 is set to nullptr.


	std::shared_ptr<int> p5(new int(5));  // Valid, allocates 1 integer and initialize it with value 5.
	std::shared_ptr<int[]> p6(new int[5]);  // Valid, allocates 5 integers.
	std::shared_ptr<int[]> p7 = p6;  // Both now own the memory.

	p6.reset();  // Memory still exists, due to p2.
	p7.reset();  // Frees the memory, since no one else owns the memory.




	return 0;

    
}

