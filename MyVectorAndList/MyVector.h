#pragma once

template<typename T>
class MyVector
{
private:
	T* data = nullptr;
	size_t length = 0;
	size_t capacity = 0;

public:

	MyVector() = default;
	MyVector(size_t newCapacity) : length(0), capacity(newCapacity)
	{
		data = new T[capacity];
	}
	MyVector(const MyVector& otherVector) : length(otherVector.length), capacity(otherVector.capacity)
	{
		data = new T[otherVector.capacity];
		for (size_t i = 0; i < length; ++i)
		{
			data[i] = otherVector.data[i];
		}
	}


	~MyVector()
	{
		delete[] data;
	}

	MyVector& operator= (const MyVector& otherVector)
	{
		if (this == &otherVector) return *this;

		if (data && otherVector.data)
		{
			delete[] data;
			/*
			data = new T[otherVector.capacity];
			length = otherVector.length;
			capacity = otherVector.capacity;
			for (size_t i = 0; i < length; i++)
			{
				data[i] = otherVector.data[i];
			}
			*/

			length = otherVector.length;
			capacity = otherVector.capacity;
			if (length > capacity) capacity = length;

			data = new T[capacity];
			for (size_t i = 0; i < length; i++)
			{
				data[i] = otherVector.data[i];
			}


		}
		return *this;
	}

	int operator[] (size_t index)
	{
		return data[index];
	}

	MyVector operator+(const MyVector& otherVector)
	{
		MyVector resultVector(length + otherVector.length);
		for (size_t i = 0; i < length; ++i)
		{
			resultVector.data[i] = data[i];
		}

		for (size_t i = 0; i < otherVector.length; i++)
		{
			resultVector.data[length + i] = otherVector.data[i];
		}
		resultVector.length = length + otherVector.length;
		return resultVector;
	}

	void push_back(const T item)
	{
		if (length == capacity)
		{
			std::cout << "Vector is full" << std::endl;
			return;
		}
		data[length++] = item;
	}

	size_t getLength() const
	{
		return length;
	}

	size_t getCapacity() const
	{
		return capacity;
	}

	void printData() const
	{
		for (size_t i = 0; i < length; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}

};