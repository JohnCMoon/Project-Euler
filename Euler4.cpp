#include <iostream>
#include <math.h>

int main() {

	using namespace std;
	
	double x,y,z[6],t,largest = 0;
	
	for (x = 100; x < 1000; x++) {
		for (y = 100; y < 1000; y++) {
		
			t = x * y;
			z[5] = fmod(t,10); // 1's place
			z[4] = (fmod(t,100) - z[5]) / 10; // 10's place
			z[3] = (fmod(t,1000) - z[4]*10 - z[5]) / 100; // 100's place
			z[2] = (fmod(t,10000) - z[3]*100 - z[4]*10 - z[5]) / 1000; // 1000's place
			z[1] = (fmod(t,100000) - z[2]*1000 - z[3]*100 - z[4]*10 - z[5]) / 10000; // 10000's place
			z[0] = (fmod(t,1000000) - z[1]*10000 - z[2]*1000 - z[3]*100 - z[4]*10 - z[5]) / 100000; // 100000's place
			
			if (z[0] == z[5] && z[4] == z[1] && z[3] == z[2]) {
				if (t > largest) 
					largest = t;
			}
		}
	}
	
	cout << largest << endl;
		
		
return 0;
}
