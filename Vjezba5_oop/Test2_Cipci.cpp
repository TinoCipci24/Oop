#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void ispis(std::vector<std::string> v) {
	for (auto it = v.begin(); it != v.end();it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void procesiraj(std::vector<std::string>& v) {
	auto it = std::max_element(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
		return a.size() < b.size();
	});
	
	auto najveci = *it;

	v.erase(std::remove(v.begin(), v.end(), najveci), v.end());

}

int main() {
	std::vector<std::string> rijeci = { "asdds","ksadsadsada","asdkj","ksdja","ksadsadsada" };

	std::cout << "Originalni vektor: ";
	ispis(rijeci);

	procesiraj(rijeci);
	std::cout << "Nakon procesiranja vektora: ";
	ispis(rijeci);

	return 0;
}