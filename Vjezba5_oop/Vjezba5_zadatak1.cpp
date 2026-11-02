// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Volume
{
	int glasnoca;
	int prije;

	static int ogranici(int l) {
		if (l < 0) {
			l = 0;
		}
		else if (l > 100) {
			l = 100;
		}
		return l;
	}

public:
	int get() {
		return glasnoca;
	}

	Volume(int l){
		glasnoca=l;
		if (glasnoca < 0) {
			glasnoca = 0;
		}
		else if (glasnoca>100) {
			glasnoca = 100;
		}
	};

	Volume() : Volume(50) {};
	
	void up(int step=10) {
		glasnoca = ogranici(glasnoca + step);
		assert(valid());
	}

	void down(int step = 10) {
		glasnoca = ogranici(glasnoca - step);
		assert(valid());
	}

	void mute() {
		prije = glasnoca;
		glasnoca = 0;
		assert(valid());
	}

	void unmute() {
		glasnoca = prije;
		assert(valid());
	}

private:
	bool valid() const { return glasnoca >= 0 && glasnoca <= 100; }
};

// ovdje napisite klasu Volume

int main()
{
	Volume v;
	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	50
	100
	0
	100
	0
*/
