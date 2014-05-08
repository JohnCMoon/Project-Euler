#include <iostream>
#include <iomanip>

int main() {

	using namespace std;
	
	double sumOfSquares = 0;
	double squareOfSum = 0;
	double diff;
	double sum = 0;
	
	int i = 1;
	while (i <= 100) {
		sumOfSquares = i*i + sumOfSquares;
		sum = i + sum;
		if (i == 100)
			squareOfSum = sum*sum;
		i++;
	}
	diff = squareOfSum - sumOfSquares;
	cout << fixed << setprecision(0) << diff << endl;
	return 0;
}
