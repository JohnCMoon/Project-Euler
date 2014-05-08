#include <iostream>
#include <math.h>

int main() {

	using namespace std;
	
	int a, b, x;
	float c;
	for (a = 1; a < 1000; a++) {
		for (b = 1; b < 1000; b++) {
			c = sqrt(a*a + b*b);
			if (a + b + c == 1000 && b > a && c > b) {
				x = a*b*c;
				cout << x << endl;
			}
		}
	}
	return 0;
}
