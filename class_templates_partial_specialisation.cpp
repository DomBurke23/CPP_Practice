#include <iostream>
#include <vector> 
// only some of the template parameters are specialised. 

template<typename T, int columns>
class PrettyPrinter {
	T *m_pData;
	public:
		PrettyPrinter(T *data) : m_pData(data){
			
		}
		void Print() {
			std::cout<<"Columns:"<<columns<<std::endl; 
			std::cout<<"{"<<*m_pData<<"}"<<std::endl;
		}
		T * GetData() {
			return m_pData;
		}
};

template<typename T>
class PrettyPrinter<T,80> {
	T *m_pData;
	public:
		PrettyPrinter(T *data) : m_pData(data){
			
		}
		void Print() {
			std::cout<<"Using 80 Columns"<<std::endl; 
			std::cout<<"{"<<*m_pData<<"}"<<std::endl;
		}
		T * GetData() {
			return m_pData;
		}
};

template<typename T>
class SmartPointer {
	T *m_ptr;
	public:
		SmartPointer(T *ptr):m_ptr(ptr){
			
		}
		//operators 
		T * operator ->(){
			return m_ptr;
		}
		T & operator *(){
			return *m_ptr;
		}
		//destructors to free
		~SmartPointer(){
			delete m_ptr;
		}
};

//specialise for array types 
template<typename T>
class SmartPointer<T[]> {
	T *m_ptr;
	public:
		SmartPointer(T *ptr):m_ptr(ptr){
			
		}
		T & operator[](int index){
			return m_ptr[index];
		}
		//destructors to free
		~SmartPointer(){
			delete[] m_ptr;
		}
};

int main() {
	int data = 80;
	PrettyPrinter<int,40>p{&data};
	p.Print(); 
	/*SmartPointer<int>s1{new int(3)}; 
	std::cout<<*s1<<std::endl; */
	SmartPointer<int[]>s1{new int[5]}; // integer array 
	s1[0]=5;
	std::cout<<s1[0]<<std::endl; 
	return 0;
}