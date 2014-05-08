// Find the 10,001st prime number.

#include <iostream>
#include <iomanip>
int isPrime(int num);

int main() {

	using namespace std;
	
	int num = 0;
	int count = 0;
	while (1) {
		if (isPrime(num))
			count++;
		if ( count == 10001 ) {
			cout << num << endl;
			break;
		}
		num++;
	}
	return 0;
}

int isPrime (int num) {
	if (num == 2 )
		return 1;
	if (num == 0 || num == 1)
		return 0;
	if (num % 2 == 0)
		return 0;
	
	int i;
	for (i = 3; i < num; i = i + 2) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}	
