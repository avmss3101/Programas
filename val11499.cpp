#include <iostream>
#include <algorithm>
using namespace std;

int T[1234567], S[1234567], O[1234567], nl, nc, kscm;

int SCM() {
    int j, k = 1;
	T[1] = S[1];   O[1] = 1; 	
	for( int i = 2; i <= nc; i++ ) {
        if( S[i] > T[k] ) {
            T[++k] = S[i];    O[i] = k;
        } else {
			j = lower_bound( T, T + k, S[i] ) - T;           
            if( S[i] > T[j] )  j++;           
            T[j] = S[i];  O[i] = j;
        }
    }
 
    return k;
}

int main() {
	
	
	
	return 0;
}
