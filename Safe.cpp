#include <utility>

// item 11
typedef int Data;

class Safe {
public:
	Data *p1, *p2, p3;
	
	void swap(Safe &&obj) noexcept {
		
		std::swap(p1, obj.p1);
		std::swap(p2, obj.p2);
		
		p3 = std::move(obj.p3);
	}
	
	
	Safe& operator=(const Safe& obj) {
		Safe copy(obj);
		swap(std::move(copy));
		return *this;
	}
};

