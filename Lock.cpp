#include<iostream>
#include<mutex>
using namespace std;


class Lock{
public:
	explicit Lock(mutex* pm) : mutexPtr_(pm){
		if(mutexPtr_->try_lock()){
			cout << "Locked" << endl;
		}else{
			cout << "Locking Failed" << endl;
		}
	}
	~Lock(){
		mutexPtr_->unlock();
		cout << "Unlocked" << endl;
	}
private:
	mutex * mutexPtr_;
};
