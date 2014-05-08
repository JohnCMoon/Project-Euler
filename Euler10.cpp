#include <iostream>
#include <math.h>
#include <iomanip>

int isPrime(double num);

int main() {

	using namespace std;
	
	double sum = 2;
	long int i;
	for (i = 3; i <= 2000000; i = i + 2) { // 2 million is the number below which to sum up the primes.
		if (isPrime(i))
			sum = sum + i;
	}

	cout << fixed << setprecision(0) << sum << endl;

	return 0;
}


int isPrime(double num) {
	if (num == 2 )
		return 1;
	if (num < 2)
		return 0;
	if (num > 2 && fmod(num,2) == 0)
		return 0;
	
	int i;
	for (i = 3; i < sqrt(num) + 1; i = i + 2) {
		if (fmod(num,i) == 0)
			return 0;
	}
	return 1;
}	
