#include <iostream>
#include <cassert>

class IntStack
{
	int* data;
	int broj_elemenata;
	int kapacitet;

public:
	IntStack(): data(new int[2]), broj_elemenata(0), kapacitet(2) {}

	IntStack(const IntStack& other): data(new int[other.kapacitet]),broj_elemenata(other.broj_elemenata),kapacitet(other.kapacitet)
	{
		for (int i = 0; i < broj_elemenata; ++i) {
			data[i] = other.data[i];
		}
	}

	~IntStack() {
		delete[] data;
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
		return data[broj_elemenata-1];
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
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' '<< s.capacity() << ' '<< s.top() << '\n';
	IntStack c = s;
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';

	return 0;
}
