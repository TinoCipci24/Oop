
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class Money {
	int centi;

public:
	Money(int euros = 0, int cents = 0) {
		centi = euros * 100 + cents;
	}

	Money& operator+=(const Money& other) {
		centi += other.centi;
		return *this;
	}

	friend bool operator<(const Money& a, const Money& b);
	friend std::ostream& operator<<(std::ostream& os, const Money& a);
	friend std::istream& operator>>(std::istream& is, Money& a);
};

Money operator+(Money a, const Money& b) {
	a += b;
	return a;
}

bool operator<(const Money& a, const Money& b) {
	return a.centi < b.centi;
}

std::ostream& operator<<(std::ostream& os, const Money& a) {
	os << a.centi / 100 << '.'<< std::setw(2) << std::setfill('0')<< a.centi % 100;

	return os;
}

std::istream& operator>>(std::istream& is, Money& a) {
	int euros, cents;
	char separator;
	if (is >> euros >> separator >> cents && separator == '.' && euros >= 0 && cents >= 0 && cents < 100) {

		a = Money(euros, cents);
	}
	else {
		is.setstate(std::ios::failbit);
	}

	return is;
}

int main()
{
	Money a(1, 5);
	Money b(0, 95);
	std::cout << a << " + " << b << " = " << a + b << '\n';

	std::ifstream in("racun.txt");
	if (!in) {
		std::cout << "Datoteka racun.txt ne postoji\n";
		return 1;
	}

	std::string item;
	Money price;
	Money total;
	Money max_price;
	std::string max_item;
	int count = 0;
	while (in >> item >> price) {
		total += price;
		if (max_price < price) {
			max_price = price;
			max_item = item;
		}
		++count;
	}
	if (!in.eof())
		std::cout << "Neispravan zapis: " << item << '\n';

	std::cout << "Stavki: " << count << '\n';
	std::cout << "Ukupno: " << total << '\n';
	std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
	return 0;
}


/*
Ocekivani ispis:

	1.05 EUR + 0.95 EUR = 2.00 EUR
	Neispravan zapis: Sok
	Stavki: 5
	Ukupno: 17.23 EUR
	Najskuplje: Kava 7.99 EUR
*/
