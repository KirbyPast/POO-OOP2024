#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Index invalid!";
	}
}invalidIndex;


class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
	T** List;
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator() : List(nullptr), Current(0) {};
	ArrayIterator(T** list, int current) : List(list), Current(current) {};
	ArrayIterator& operator++ (int) {
		this->Current++;
		return *this;
	}
	ArrayIterator& operator-- () {
		if (this->Current <= 0) return;
		this->Current--;
		return this;
	}
	bool operator==(ArrayIterator<T>& it) {
		if (this->Current == it.Current) return true;
		else return false;
	}
	bool operator!=(ArrayIterator<T>& it) {
		return this->Current != it.Current;
	}
	T* GetElement() {
		return this->List[this->Current];
	}
};
template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array() : List(nullptr), Capacity(0), Size(0) {} ; // Lista nu e alocata, Capacity si Size = 0
	//^MERGE
	~Array() {
		for (int i = 0; i < this->Size; i++) {
			delete this->List[i];
		}
		delete[] this->List;
	}
	//^MERGE
	// destructor
	Array(int capacity) {
		this->List = new T * [capacity];
		this->Capacity = capacity;
		this->Size = 0;
	}// Lista e alocata cu 'capacity' elemente
	//^MERGE
	Array(const Array<T>& otherArray) {
		this->List = new T * [otherArray.Capacity];
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		for (int i = 0; i < otherArray.Size; i++) {
			this->List[i] = new T(*otherArray.List[i]);
		}
	}// constructor de copiere
	//^MERGE

	T& operator[] (int index) {
		try {
			if (index<0 || index>this->Size) {
				throw invalidIndex;
			}
			return *this->List[index];
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
			throw;
		}
	}// arunca exceptie daca index este out of range
	//^MERGE

	const Array<T>& operator+=(const T& newElem) {
		this->Size++;
		if (this->List == nullptr) {
			this->Capacity = 5;
			this->List = new T * [this->Capacity];
		}
		else if (this->Size >= this->Capacity) {
			this->Capacity *= 2;
			T** buf = new T * [this->Capacity];
			for (int i = 0; i < this->Size-1; i++) {
				buf[i] = this->List[i];
			}
			delete[] this->List;
			this->List = buf;
		}
		this->List[this->Size - 1] = new T(newElem);
		return *this;
	}// adauga un element de tipul T la sfarsitul listei si returneaza this
	//^MERGE
	const Array<T>& Insert(int index, const T& newEleme) {
		T newElem = newEleme;

		if (index<0 || index>this->Size) {
			throw invalidIndex;
		}
		if (this->List == nullptr) {
			this->Capacity = 5;
			this->List = new T * [this->Capacity];
		}
		if (this->Size >= this->Capacity) {
			this->Capacity *= 2;
			T** buf = new T * [this->Capacity];
			for (int i = 0; i < this->Size; i++) {
				buf[i] = new T(*this->List[i]);
			}
			delete[] this->List;
			this->List = buf;
		}
		for (int i = this->Size - 1; i >= index; i--) {
			this->List[i + 1] = this->List[i];
		}
		this->List[index] = new T(newElem);
		this->Size++;
		return *this;

	}// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	//^MERGE, 
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		try {
			if (index < 0 || index > this->Size) {
				throw invalidIndex;
			}
			if (this->List == nullptr) {
				this->Capacity = 5;
				this->List = new T * [this->Capacity];
			}
			while (this->Size + otherArray.Size >= this->Capacity) {
				this->Capacity *= 2;
				T** buf = new T * [this->Capacity];
				for (int i = 0; i < this->Size; i++) {
					buf[i] = new T(*this->List[i]);
				}
				delete[] this->List;
				this->List = buf;
			}
			for (int i = this->Size - 1; i >= index; i--) {
				this->List[i + otherArray.Size] = this->List[i];
			}
			for (int i = 0; i < otherArray.Size; i++) {
				this->List[index + i] = new T(*otherArray.List[i]);
			}
			this->Size = this->Size + otherArray.Size;
			return *this;
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << '\n';
		}
	}// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Delete(int index) {
		/*if (index < 0 || index >= this->Size) {
			return 0;
		}*/ //Add exception
			if (index < 0 || index>this->Size) {
				throw invalidIndex;
			}
			delete this->List[index];
			for (int i = index; i < this->Size; i++) {
				this->List[i] = this->List[i + 1];
			}
			this->Size--;
			return *this;
	}// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	//^MERGE
	bool operator=(const Array<T>& otherArray) {
		for (int i = 0; i < this->Size; i++) {
			delete this->List[i];
		}
		delete[] this->List;

		this->Size = otherArray.Size;
		this->Capacity = otherArray.Capacity;

		this->List = new T * [this->Capacity];

		for (int i = 0; i < this->Size; i++) {
			this->List[i] = new T(*otherArray.List[i]);
		}

		return true;

		/*if (this->Size != otherArray.Size) return false;
		else {
			for (int i = 0; i < this->Size; i++) {
				if (this->List[i] != otherArray.List[i]) return false;
			}
		}
		return true;*/
		}
	//nu inteleg ce trebuie sa fac

	void Sort() {
		if (this->List == nullptr) {
			return;
		}
		for (int i = 0; i < this->Size-1; i++) {
			for (int j = i + 1; j < this->Size; j++) {
				if (*this->List[i] > *this->List[j]) {
					T* buf = this->List[j];
					this->List[j] = this->List[i];
					this->List[i] = buf;
				}
			}
		}
	}// sorteaza folosind comparatia intre elementele din T 
	//^MERGE
	void Sort(int(*compare)(const T&, const T&)) {
		if (this->List == nullptr) {
			return;
		}
		for (int i = 0; i < this->Size - 1; i++) {
			for (int j = i + 1; j < this->Size; j++) {
				if (compare(*this->List[i],*this->List[j]) > 0) {
					T* buf = this->List[j];
					this->List[j] = this->List[i];
					this->List[i] = buf;
				}
			}
		}
	}// sorteaza folosind o functie de comparatie 
	//^MERGE
	void Sort(Compare* comparator) {
		if (this->List == nullptr) {
			return;
		}
		for (int i = 0; i < this->Size - 1; i++) {
			for (int j = i + 1; j < this->Size; j++) {
				if (comparator->CompareElements(this->List[i],this->List[j]) > 0) {
					T* buf = this->List[j];
					this->List[j] = this->List[i];
					this->List[i] = buf;
				}
			}
		}
	}
	//^MERGE
	// sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista


	//int BinarySearch(const T& elem) {
	//	Array<T> buf = *this;
	//	buf.Sort();
	//	int st = 0;
	//	int dr = this->Size - 1;
	//	int mij = (st + dr) / 2;
	//	while (st < dr) {
	//		if (*this->List[mij] == elem) {
	//			return mij;
	//		}
	//		else if (*this->List[mij] > elem) {
	//			dr = mij-1;
	//		}
	//		else {
	//			st = mij+1;
	//		}
	//		mij = (st + dr) / 2;
	//	}
	//	return -1;
	//}// cauta un element folosind binary search in Array

	int BinarySearch(const T& elem) {
		int st = 0;
		int dr = this->Size - 1;
		int mij = (st + dr) / 2;
		while (st <= dr) {
			if (*this->List[mij] == elem) {
				return mij;
			}
			else if (*this->List[mij] > elem) {
				dr = mij - 1;
			}
			else {
				st = mij + 1;
			}
			mij = (st + dr) / 2;
		}
		return -1;
	}// cauta un element folosind binary search in Array
	//^MERGE

	//int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
	//	Array<T> buf = *this;
	//	buf.Sort();
	//	int st = 0;
	//	int dr = this->Size - 1;
	//	int mij = (st + dr) / 2;
	//	while (st < dr) {
	//		if (compare(*buf.List[mij],elem) == 0) {
	//			return mij;
	//		}
	//		else if (compare(*buf.List[mij], elem) > 0) {
	//			dr = mij-1;
	//		}
	//		else {
	//			st = mij+1;
	//		}
	//		mij = (st + dr) / 2;
	//	}
	//	return -1;
	//}// cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int st = 0;
		int dr = this->Size - 1;
		int mij = (st + dr) / 2;
		while (st <= dr) {
			if (compare(*this->List[mij], elem) == 0) {
				return mij;
			}
			else if (compare(*this->List[mij], elem) > 0) {
				dr = mij - 1;
			}
			else {
				st = mij + 1;
			}
			mij = (st + dr) / 2;
		}
		return -1;
	}
	//^MERGE

	//int BinarySearch(const T& eleme, Compare* comparator) {
	//		Array<T> buf = *this;
	//		T elem = eleme;
	//		buf.Sort();
	//		for (int i = 0; i < buf.GetSize(); i++) {
	//			cout << buf[i] << ' ';
	//		}
	//		cout << '\n';
	//		int st = 0;
	//		int dr = this->Size - 1;
	//		int mij = (st + dr) / 2;
	//		while (st < dr) {
	//			if (comparator->CompareElements(buf.List[mij],&elem) == 0) {
	//				return mij;
	//			}
	//			else if (comparator->CompareElements(buf.List[mij],&elem) > 0) {
	//				dr = mij-1;
	//			}
	//			else {
	//				st = mij+1;
	//			}
	//			mij = (st + dr) / 2;
	//		}
	//		return -1;
	//	}// cauta un element folosind binary search si un comparator

	int BinarySearch(const T& eleme, Compare* comparator) {
		T elem = eleme;
		int st = 0;
		int dr = this->Size - 1;
		int mij = (st + dr) / 2;
		while (st <= dr) {
			if (comparator->CompareElements(this->List[mij], &elem) == 0) {
				return mij;
			}
			else if (comparator->CompareElements(this->List[mij], &elem) > 0) {
				dr = mij - 1;
			}
			else {
				st = mij + 1;
			}
			mij = (st + dr) / 2;
		}
		return -1;
	}// cauta un element folosind binary search si un comparator
	//^MERGE
	int Find(const T& elem) {
			for (int i = 0; i < this->Size; i++) {
				if (*this->List[i] == elem) return i;
			}
			return -1;
		}// cauta un element in Array
	//^MERGE
	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i < this->Size; i++) {
			if (compare(elem,*this->List[i])==0) return i;
		}
		return -1;
	} // cauta un element folosind o functie de comparatie
	//^MERGE
	int Find(const T& eleme, Compare* comparator) {
		T elem = eleme;
		for (int i = 0; i < this->Size; i++) {
			if (comparator->CompareElements(&elem,this->List[i])==0) return i;
		}
		return -1;
	}// cauta un element folosind un comparator
	//^MERGE

	int GetSize() {
		return this->Size;
	}
	//^MERGE
	int GetCapacity() {
		return this->Capacity;
	}
	//^MERGE
	void Clear() {
		for (int i = 0; i < this->Size; i++) {
			delete this->List[i];
		}
		this->Size = 0;
	}
	//^MERGE
	void Print() {
		for (int i = 0; i < this->Size; i++) {
			cout << *this->List[i] << ' ';
		}
		cout << '\n';
	}

	ArrayIterator<T> GetBeginIterator() {
		ArrayIterator<T> it(this->List,0);
		return it;
	}

	ArrayIterator<T>& GetEndIterator() {
		ArrayIterator<T> it(this->List, this->Size);
		return it;
	}
};
