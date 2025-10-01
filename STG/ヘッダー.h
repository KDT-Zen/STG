#pragma once


#include <vector>






template <typename T>



class ObjectPool {

	std::vector<std::unique_ptr<T>> pool;
	std::vector<std::unique_ptr<bool>>inUse;


public:

	ObjectPool(size_t size) {
		pool.reserve(size);
		inUse.resize(size, false);
		for (size_t i = 0; i < size; ++i) {

			pool.push_back(new T());
		}
	}

	~ObjectPool() {
		for (T* obj : pool) {
			delete obj;
		}

	}

};