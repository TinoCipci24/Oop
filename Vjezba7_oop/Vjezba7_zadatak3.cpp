#include <iostream>
#include <cassert>
#include <utility>

class IntStack
{
	int* data;
	int broj_elemenata;
	int kapacitet;

public:
	IntStack() : data(new int[2]), broj_elemenata(0), kapacitet(2) {}

	IntStack(const IntStack& other) : data(new int[other.kapacitet]), broj_elemenata(other.broj_elemenata), kapacitet(other.kapacitet)
	{
		std::cout << "copy konstruktor\n";
		for (int i = 0; i < broj_elemenata; ++i) {
			data[i] = other.data[i];
		}
	}

	~IntStack() {
		delete[] data;
	}

	IntStack& operator=(const IntStack& other) {
		std::cout << "copy assignment\n";
		if (this != &other) {
			int* novi = new int[other.kapacitet];
			for (int i = 0; i < other.broj_elemenata; ++i) {
				novi[i] = other.data[i];
			}
			delete[] data;
			data = novi;
			broj_elemenata = other.broj_elemenata;
			kapacitet = other.kapacitet;
		}
		return *this;
	}

	IntStack(IntStack&& other) noexcept : data(other.data),broj_elemenata(other.broj_elemenata),kapacitet(other.kapacitet)
	{
		std::cout << "move konstruktor\n";
		other.data = nullptr;
		other.broj_elemenata = 0;
		other.kapacitet = 0;
	}

	IntStack& operator=(IntStack&& other) noexcept {
		std::cout << "move assignment\n";
		if (this != &other) {
			delete[] data;
			data = other.data;
			broj_elemenata = other.broj_elemenata;
			kapacitet = other.kapacitet;
			other.data = nullptr;
			other.broj_elemenata = 0;
			other.kapacitet = 0;
		}

		return *this;
	}

	void push(int x) {
		if (broj_elemenata == kapacitet) {
			int* veci = new int[kapacitet * 2];
			for (int i = 0; i < broj_elemenata; ++i) {
				veci[i] = data[i];
			}
			delete[] data;
			data = veci;
			kapacitet *= 2;
		}
		data[broj_elemenata] = x;
		broj_elemenata++;
	}

	void pop() {
		if (!empty()) {
			broj_elemenata--;
		}
	}

	int top() {
		assert(!empty());
		return data[broj_elemenata - 1];
	}

	bool empty() {
		return broj_elemenata == 0;
	}

	int size() {
		return broj_elemenata;
	}

	int capacity() {
		return kapacitet;
	}
};


int main()
{
	IntStack a;
	a.push(10);
	a.push(20);
	a.push(30);

	IntStack b = a;              // ispis: copy konstruktor
	b = a;                       // ispis: copy assignment
	IntStack c = std::move(a);   // ispis: move konstruktor
	b = std::move(c);            // ispis: move assignment

	std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	copy konstruktor
	copy assignment
	move konstruktor
	move assignment
	0 0 3 30
*/
