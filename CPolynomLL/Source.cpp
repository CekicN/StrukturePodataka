#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "CPolynomLL.h"

double randomDouble(double lower_bound, double upper_bound) {
	double f = (double)rand() / RAND_MAX;
	return lower_bound + f * (upper_bound - lower_bound);
}

int main() {

	srand(time(NULL));

	CPolynomLL polinom1, polinom2;

	polinom1.Coef(5, randomDouble(10., 50.));
	polinom1.Coef(5, randomDouble(10., 50.));
	polinom2.Coef(5, randomDouble(10., 50.));
	polinom1.Coef(3, randomDouble(10., 50.));
	polinom2.Coef(3, randomDouble(10., 50.));
	polinom1.Coef(2, randomDouble(10., 50.));
	polinom2.Coef(1, randomDouble(10., 50.));

	CPolynomLL* zbir = polinom1.Add(polinom1, polinom2);
	//CPolynomLL* proizvod = Mul(polinom1, polinom2);

	polinom1.stampaj();
	cout << endl;
	polinom2.stampaj();
	cout << endl;
	zbir->stampaj();

	//proizvod->print(std::cout) << '\n';

	return 0;
}