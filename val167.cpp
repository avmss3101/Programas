#include <iostream>
#include <stdlib.h>
using namespace std;
 
int main() {
	int k, cont, sum, tsum;
	cont = 0;
	sum = 0;
 
	cin >> k;
	int* board = (int*) malloc(64*k*sizeof(int));
	int* queens = (int*) malloc(8*sizeof(int));
 
	while (k--) {
		cin >> *(board + cont);
		cont++;
	}
 
	for(int i = 0; i++; i < 8) {
 
		if (sum < tsum)
			sum = tsum;
	}
 
	return 0;
}
