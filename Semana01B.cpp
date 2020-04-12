#include <iostream>
#include <cassert>
#include <string>
#include "linkedList.h"

using namespace std;

int main() {

	utec::linked_list_t ll;


	// Probar el metodo push_front;
	for (int i = 0; i < 10; ++i) {
		ll.push_front(i);
	}
	
	// Verifico el tamano
	assert(ll.size() == 10);
	
	string result;

	for (int i = 0; i < ll.size(); ++i) {
		result += to_string(ll.item(i)) + " ";
	}
	assert(result == "9 8 7 6 5 4 3 2 1 0 ");

	// Probar el push_back
	for (int i = 0; i < 5; ++i) {
		ll.push_back(i);
	}

	assert(ll.size() == 15);
	
	result = "";
	
	for (int i = 0; i < ll.size(); ++i) {
		result += to_string(ll.item(i)) + " ";
	}
	assert(result == "9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 ");

	

	// Probar el metodo pop_front;
	for (int i = 0; i < 5; ++i) {
		ll.pop_front();
	}

	result = "";

	for (int i = 0; i < ll.size(); ++i) {
		result += to_string(ll.item(i)) + " ";
	}
	assert(result == "4 3 2 1 0 0 1 2 3 4 ");

	// Verifico el tamano
	assert(ll.size() == 10);


	// Probar el metodo pop_back;
	for (int i = 0; i < 5; ++i) {
		ll.pop_back();
	}

	result = "";

	for (int i = 0; i < ll.size(); ++i) {
		result += to_string(ll.item(i)) + " ";
	}
	assert(result == "4 3 2 1 0 ");

	// Verifico el tamano
	assert(ll.size() == 5);

	//Probar erase
	ll.erase(2);

	result = "";

	for (int i = 0; i < ll.size(); ++i) {
		result += to_string(ll.item(i)) + " ";
	}
	assert(result == "4 3 1 0 ");

	// Verifico el tamano
	assert(ll.size() == 4);

	//Probar insert
	ll.insert(2, 100);

	result = "";

	for (int i = 0; i < ll.size(); ++i) {
		result += to_string(ll.item(i)) + " ";
	}
	assert(result == "4 3 100 1 0 ");

	// Verifico el tamano
	assert(ll.size() == 5);



	
	



	std::cout << "Ejecucion exitosa!!" << std::endl;
	return 0;
}
