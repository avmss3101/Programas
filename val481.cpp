#include <iostream>
#include <algorithm>
using namespace std;

int T[1234567], S[1234567], O[1234567], n, kscm;

int SCM() {
    int j, k = 1;
	T[1] = S[1];   O[1] = 1; 	
	for( int i = 2; i <= n; i++ ) {
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

void ImprimeSCM( int i, int j, int m ) {
     if( j > 0 ) {
         if( ( O[i] == j ) && ( S[i] < m ) ) {
             ImprimeSCM( i-1, j-1, S[i] );
             cout << S[i] << endl;
         }
         else ImprimeSCM( i-1, j, m );
     }
}

int main() {
	
	int N;
	int i = 1;
	int tam = 0;
	
	
	while (cin >> S[i]) {
		i++;
		tam++;
	}
	
	n = tam;
	kscm = SCM();
	cout << kscm << endl << "-" << endl;
	ImprimeSCM( n, kscm, 2000000000 );

	
	return 0;
}
