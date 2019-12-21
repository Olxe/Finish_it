#ifndef __UTILITY__
#define __UTILITY__

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <iostream>

template<class T>
inline void clearVector(std::vector< T* >& v)
{
	/*for (size_t i = 0; i < v.size(); i++) {
		if (v[i]) {
			delete v[i];
			v[i] = nullptr;
		}

	}
	v.clear();*/

	while(!v.empty()){
		if (v.back()) {
			delete v.back();
			v.back() = NULL;
		}
		
		v.pop_back();
	}
}

template<class T>
inline void clearPtr(T*& v)
{
	if(v){
		delete v;
		v = nullptr;
	}
}

inline void displayVec(sf::Vector2f v)
{
	std::cout << v.x << " | " << v.y << std::endl;
}

inline void displayVec(sf::Vector2i v)
{
	std::cout << v.x << " | " << v.y << std::endl;
}

template<class T>
inline void display(T v)
{
	std::cout << v << std::endl;
}

inline bool isStrOnlyDigit(const std::string& str)
{
	for(auto it = str.begin(); it != str.end(); ++it){
		if(!isdigit(*it)) return false;
	}

	return true;
}

#endif