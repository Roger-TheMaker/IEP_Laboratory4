#include <utility>

// item 11

typedef int Data;

class Safe {
public:
	Data *pData, *pData2, data3;
	
	void swap(Safe &&obj) noexcept {
		// &&
		std::swap(pData, obj.pData);
		std::swap(pData2, obj.pData2);
		
		data3 = std::move(obj.data3);
	}
	
	
	Safe& operator=(const Safe& obj) {
		Safe copy(obj);
		// std::swap(*this, copy);  // BAD!! Infinite loop occurs!
		swap(std::move(copy));
		return *this;
	}
};

