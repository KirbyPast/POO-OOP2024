#pragma once
#include <iostream>
#include <tuple>
template <typename K, typename V>
class Map
{
	class Node {
	public:
		int index;
		K key;
		V value;

		Node() : index(0), key(0), value(0) {};
		Node(int index, K key, V value) : index(index), key(key), value(value) {};

		void operator=(V value) {
			this->value = value;
		};
	};

	struct Iterator {
		Node** data;
		int index;
		Iterator& operator++(){
			this->index++;
			return *this;
		}

		bool operator!=(const Iterator& it) {
			return it.index != this->index;
		}

		Node& operator*() {
			return *this->data[this->index];
		}
	};

public:
	Node** data;
	int size;
	int capacity;

	Map() : size(0), capacity(5){
		this->data = new Node*[capacity];
	}

	~Map() {
		delete[] this->data;
	}

	Node& operator[](K key) {
		//if key is already in map
		for (int i = 0; i < size; i++) {
			if (key == this->data[i]->key) {
				return *this->data[i];
			}
		}
		//if key is new
		this->size++;
		if (size > capacity) {
			Node** temp = new Node*[this->capacity * 2];
			this->capacity *= 2;
			for (int i = 0; i < size; i++) {
				/*temp[i]->key = this->data[i]->key;
				temp[i]->value = this->data[i]->value;*/
				temp[i] = new Node(i,this->data[i]->key, this->data[i]->value);
			}
			delete[] this->data;
			this->data = temp;
			//delete[] temp;
		}
		this->data[size-1] = new Node(size-1,key,0);
		return *this->data[size-1];
	};

	bool Set(V value, K key) {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i]->key == key) {
				this->data[i]->value = value;
				return true;
			}
		}
		return false;
	}

	bool Get(const K& key, V& value) {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i]->key == key) {
				value = this->data[i]->value;
				return true;
			}
		}
		return false;
	}

	int Count() {
		return this->size;
	}

	void Clear() {
		delete[] this->data;
		this->size = 0;
		this->data = new Node * [this->capacity];
	}

	bool Delete(const K& key) {
		int to_delete = -1;
		for (int i = 0; i < this->size; i++) {
			if (this->data[i]->key == key) {
				to_delete = i;
			}
		}
		for (int i = to_delete; i < this->size-1; i++) {
			this->data[i]->key = this->data[i + 1]->key;
			this->data[i]->value = this->data[i + 1]->value;
		}
		if (to_delete != -1) {
			delete this->data[this->size - 1];
			this->size--;
			return true;
		}
		return false;
	}

	bool Includes(const Map<K, V>& map) {
		if (this->size > map->size) return false;
		else {
			for (int i = 0; i < this->size; i++) {
				int ok = 0;
				for (int j = 0; j < map->size; j++) {
					if (this->data[i]->key == map->data[j]->key) ok = 1;
				}
				if (!ok) return false;
			}
		}
		return true;
	}

	Iterator begin() {
		return { this->data, 0 };
	}

	Iterator end() {
		return {this->data, this->size};
	}
};

