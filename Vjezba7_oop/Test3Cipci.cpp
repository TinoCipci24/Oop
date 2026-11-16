#include <iostream>

class Racun {
	float stanje;
	int static broj_racuna;
public:
	Racun() {
		stanje = 0;
		broj_racuna++;
	}

	Racun(const Racun& other) {
		stanje = other.stanje;
		broj_racuna++;
	}

	~Racun() {
		broj_racuna--;
	}

	void uplati(float iznos) {
		stanje += iznos;
		std::cout << "Uspjesna uplata" << std::endl;
	}

	void isplati(float iznos) {
		if (iznos > stanje) {
			std::cout << "Nema dovoljno sredstava na racunu" << std::endl;
		}
		else {
			stanje -= iznos;
			std::cout << "Uspjesna isplata" << std::endl;
		}
	}

	float stanje_racuna() {
		return stanje;
	}

	int racuni_aktivni() {
		return broj_racuna;
	}

};

int Racun::broj_racuna = 0;

int main() {
	Racun r;
	r.uplati(1000.73);
	r.isplati(1200.28);
	r.isplati(20);
	Racun r2 = r;
	std::cout << "Stanje racuna: " << r.stanje_racuna() << std::endl;
	std::cout << "Stanje racuna: " << r2.stanje_racuna() << std::endl;
	return 0;
}