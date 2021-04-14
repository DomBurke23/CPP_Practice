#include <iostream>
#include <vector>

template<typename T>
class PrettyPrinter {
	T *m_pData;
	public:
		PrettyPrinter(T *data) :m_pData(data){
			
		}
		void Print(){
			std::cout<<"{"<<*m_pData<<"}"<<std::endl; 
		}
		T * GetData(){
			return m_pData; 
		}
};

// create an explicit specialisation 
template<> // template list must be empty 
class PrettyPrinter<char*> { // specify type here 
	char *m_pData;
	public:
		PrettyPrinter(char *data) :m_pData(data){
			
		}
		void Print(){
			std::cout<<"{"<<m_pData<<"}"<<std::endl; 
		}
		char * GetData(){
			return m_pData; 
		}
};

// create an explicit specialisation 
template<>
class PrettyPrinter<std::vector<int>>{
	std::vector<int>*m_pData;
	public:
		PrettyPrinter(std::vector<int>*data):m_pData(data){
			
		}
		void Print(){
			std::cout<<"{";
			for ( const auto &x:*m_pData){
				std::cout<<x;
			}
			std::cout<<"}"<<std::endl;
		}
		std::vector<int> * GetData(){
			return m_pData;
		}
};

int main () {
	int data = 5; 
	float f = 8.2f; 
	PrettyPrinter<int> p1(&data); 
	p1.Print(); 
	
	PrettyPrinter<float> p2(&f); 
	p2.Print(); 
	
	char *p{"Hello World"};	
	// explicit specialisation
	PrettyPrinter<char*> p5(p);
	p5.Print(); 
	char *pData = p5.GetData(); // prints first character 
	
	//create vector of integers and print data 
	std::vector<int> v{1,2,3,4,5}; 	
	PrettyPrinter<std::vector<int>>pv(&v);
	pv.Print(); 
	
	return 0; 
}
