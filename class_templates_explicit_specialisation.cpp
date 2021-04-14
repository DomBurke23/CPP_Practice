#include <iostream>

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

int main () {
	int data = 5; 
	float f = 8.2f; 
	PrettyPrinter<int> p1(&data); 
	p1.Print(); 
	
	PrettyPrinter<float> p2(&f); 
	p2.Print(); 
	
	char *p{"Hello World"};
	//PrettyPrinter<char*> p3(p); // build error can't convert from char* to char** 
/*	PrettyPrinter<char*> p3(&p);
	p3.Print(); 
	//char *pData = p3.GetData(); // build error 
	
	PrettyPrinter<char> p4(p);
	p4.Print(); 
	char *pData = p4.GetData(); // prints first character */
	
	// explicit specialisation
	PrettyPrinter<char*> p5(p);
	p5.Print(); 
	char *pData = p5.GetData(); // prints first character 
	
	return 0; 
}
