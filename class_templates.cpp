#include <iostream>

/*
class Stack {
	// can only hold 512 integers
	int m_Buffer[512]; 
	int m_Top{-1}; // initialise top as -1 
public: // add functions
	void Push(int elem) {
		m_Buffer[++m_Top]=elem; 
	}
	void Pop(){
		--m_Top; 
	}
	int Top() const { // access element at top of stack 
		return m_Buffer[m_Top]; 
	}
	bool IsEmpty() {
		return m_Top == -1; 
	}
}; */

// class Stack as a template
template<typename T , int size >
class Stack { 
	T m_Buffer[size]; // array type T 
	int m_Top{-1}; // initialise top as -1 
public: // add functions
	Stack()=default; // default constructor 
	Stack(const Stack &obj){ // copy attributes manually 
		m_Top = obj.m_Top; // initialise 
		for ( int i = 0; i <= m_Top; ++i) {
			m_Buffer[i]=obj.m_Buffer[i]; 
		}
	}
	void Push(const T &elem) {
		m_Buffer[++m_Top]=elem; 
	}
	// you can declare the body outside but must follow correct syntax with templates. 
	void Pop(); 
	const T& Top() const { // access element at top of stack 
		return m_Buffer[m_Top]; 
	}
	bool IsEmpty() {
		return m_Top == -1; 
	}
	/* factory method for the stack class - this creates instances of the class. 
	 * can't define the body outside of class because it doesn't know the type of Stack. 
	 * Stack is short hand and can't be written outside the class. 
	static Stack Create() {
		return Stack<T,size>(); 
	} */
	static Stack Create(); 
};

template<typename T, int size>
void Stack<T, size>::Pop(){
	--m_Top; 
}

/* build error, Stack is unknown due to being written in short hand. 
template<typename T, int size>
Stack Stack<T, size>::Create(){
	return Stack<T,size>(); 
}  
 ---- how to fix build error , add all parameters ---- */
 template<typename T, int size>
Stack<T,size> Stack<T, size>::Create(){
	return Stack<T,size>(); 
}


/* objective of class templates - classes to be able to use different types */ 
int main () {
	/* Stack s; // create instance of the Stack 
	s.Push(3); 
	s.Push(1); 
	s.Push(6); 
	s.Push(9); */
	// must specify the type and size of array 
	Stack<float, 10> s = Stack<float,10>::Create(); ; // create instance of the Stack 
	s.Push(3); 
	s.Push(1); 
	s.Push(6); 
	s.Push(9);
	auto s2(s);  // create copy of stack 
	// print all elements which have been pushed onto the stack 
	while (!s.IsEmpty()) {
		std::cout << s.Top() << " ";
		s.Pop(); 
	}
	while (!s2.IsEmpty()) {
		std::cout << s2.Top() << " ";
		s2.Pop(); 
	}
	
	return 0; 
}
