#pragma once

template <typename T>
class Array {
	private:
		T* _array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		T& operator[](unsigned int index);
		unsigned int size();
};

template<typename T>
Array<T>::Array () {
	this->_array = nullptr;
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	this->_array = new T[n]();
	this->_size = n;
}

template<typename T>
Array<T>::Array(const Array<T>& other){

	this->_size = other.size();
	this->_array = new T[this->_size];
	for (size_t i = 0; i < _size; ++i)
	{
		_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != other)
	{
		this->_size = other.size();
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++)
			_array[i] = other[i];
	}
	return *this;
}

