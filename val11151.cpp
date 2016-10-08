#include<iostream>
#include <string.h>
using namespace std;

int n, m, TM[12345][12345];
char A[1001], B[1001], C[1001];

void SMC(){
	n = strlen(A);
	m = strlen(B);
    for( int i=1; i<=n; i++ ) TM[i][0]=0;
    for( int j=1; j<=m; j++ ) TM[0][j]=0;    
	for( int i=1; i<=n; i++ ) {
		for( int j=1; j<=m; j++ ) {
			if( A[i-1] == B[j-1] )
				TM[i][j] = TM[i-1][j-1]+1;
			else
				TM[i][j] = max(TM[i-1][j], TM[i][j-1]);
		}
	}
}

void GeraSMC(int i, int j, int k){
	if( k > 0 ) {
		if( A[i-1] == B[j-1] ) {
			 k--; i--; j--;
			 C[k] = A[i];
        }
		else if( TM[i-1][j] == k )
			i--;
		else
			j--;
		GeraSMC(i, j, k);
    }
}

int main() {
	
	int N;
	
	cin >> N;
	
	while(N > 0) {
		cin >> A;
		//for (int i = 1; i <= strlen(A); i++)
			//B[i] = A[i];
		//B = strrev(A);
		//strcpy(B, A);
		B = strrev(A);
			
		SMC();
		GeraSMC( n, m, TM[n][m]);
		cout << TM[n][m] << endl;
		N--;
	}
	
	return 0;
}
