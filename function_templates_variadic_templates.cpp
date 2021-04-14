#include <iostream>
#include <typeinfo>
#include <string.h> 
#include <stdio.h>
#include "Integer.h"
using namespace std;

/* template<typename T>
void Print(std::initializer_list<T> args){
	for ( const auto &x : args){
		std::cout<<x<<" "; 
	}
} */

// base case to stop recursion
void Print(){
	std::cout<<std::endl; 
}

// syntax for variadic is the 3 dots (ellipsis) 
template<typename T, typename... Params> // template parameter pack 
//void Print(T a, Params... args){ // function parameter pack  
//void Print(const T &a, const Params&... args){ // another way 
void Print(T &&a, const Params&&... args){ // another way 
	/* std::cout<<sizeof...(args)<<std::endl; // find out the number of elements in the parameter pack. 
	std::cout<<sizeof...(Params)<<std::endl;
	std::cout<<a<<","; // this prints a , after the last element which isn't needed */
	if (sizeof...(args)!=0){
		std::cout<<a<<",";
	}
	// use recursion to access parameters. 
	//Print(args...); // can be used for the 1st two Print()
	Print(std::forward<Params>(args...); 
}

int main () {
	//Print({1,2,3,4}); // goes with the first print() 
	//Print({1,2.2,3,4}); // fails argument type deduction so use variadic templates so you can pass multiple arguments with different types. 
	Print(1,2.2,3,"4"); 
	
	Integer val{ 1 };
	Print(0, val, Integer{ 2 });
	
	return 0; 
}