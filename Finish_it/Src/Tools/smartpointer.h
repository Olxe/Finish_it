#pragma once
#include <iostream>
template<class T>
class SmartPointer
{
public:
	SmartPointer(T** ptr);
	~SmartPointer() {}
	T** operator->() const { return m_ptr; }
	T** GetPtr() const { return m_ptr; }

private:
	T** m_ptr;

};

template<class T>
SmartPointer<T>::SmartPointer(T** ptr)
{
	std::cout << "test" << std::endl;
	m_ptr = ptr;
}