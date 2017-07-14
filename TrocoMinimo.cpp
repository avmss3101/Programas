#include <iostream>
#include <vector>
using namespace std;
 
int TrocoMinimo(int, vector<int>);
 
int main() {
	int Troco;
 
	//cin >> N;
 
	vector<int> M(6);
	M[0] = 1;
	M[1] = 2;
	M[2] = 6;
	M[3] = 9;
	M[4] = 15;
	M[5] = 50;
	//for (int i = 0; i < 6; i++)
	//	Moedas[i] = rand()%100;
 
	int resultado;
	while (cin >> Troco) {
		resultado = TrocoMinimo(Troco, M);
		cout << resultado << endl;
	}
 
	return 0;
}
 
int TrocoMinimo(int Troco, vector<int> M) {
	vector<int> TM(Troco);
	TM[0] = 0;
	for (int i = 1; i <= Troco; i++) {
		TM[i] = 1000;
		for (int j = 0; M[j] <= i; j++)
			if (1 + TM[i - M[j]] < TM[i])
				TM[i] = 1 + TM[i - M[j]];
	}
	return TM[Troco];
}
