#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo) {
	return "Empty";
}

//typedef const char *(*PFN)(int);
using PFN = const char *(*)(int); // aliases of the type above, this more feel more natural 

//void ShowError(const char *(*pfn)(int)){ // looks quite complex , use a typedef
void ShowError(PFN pfn){	

} 

//typedef std::vector < std::list<std::string>> Names;
//template<typename T>
//using Names = std::vector<std::list<T>>; // aliases type 

using Names = std::vector<std::list<std::string>>;

int main() {
	//std::vector<std::list<std::string>> names; // long and we can use a typedef instead 
	
	Names names;
	Names nnames;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
