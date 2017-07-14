    #include <iostream>
    using namespace std;
     
    int TrocoMinimo(int, int);
    int max(int[], int, int);
    int moedas[6];
     
    int main() {
    	int n, tam;
     
    	moedas[0] = 1;
    	moedas[1] = 5;
    	moedas[2] = 10;
    	moedas[3] = 25;
    	moedas[4] = 50;
    	moedas[5] = 100;
    	tam = 6;
     
    	while(cin >> n)
    		cout << TrocoMinimo(n, tam) << endl;
     
    	return 0;
    }
     
    int max(int troco, int tam) {
    	int maior = 0;
     
    	for (int i = 0; i < tam; i++)
    		if (moedas[i] > maior && troco >= moedas[i])
    			maior = moedas[i];
    	return maior;
    }
     
    int TrocoMinimo(int troco, int tam) {
    	int moeda;
     
    	if (troco == 0)
    		return 0;
    	else {
    		moeda = max(troco, tam);
    		cout <<  "moeda: " << moeda << endl;
    		return 1 + TrocoMinimo(troco - moeda, tam);
    	}
    }
