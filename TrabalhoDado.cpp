    #include <iostream>
    #include <string>
    #include <vector>
     
    #define MAX 20
     
    using namespace std;
     
    char tabuleiro[MAX][MAX];
    //char linha[100];
    char dado[6];
    char frentetopo[7][7];
     
    int terminou = false;
     
    int prox_pos(int[], char, char, int[], vector<int>, bool);
     
    int main() {
    	string linha; //auxiliar para passar os valores da linha para a matriz
    	string sujeira;
    	int pos_ini[2]; //posicao inicial
    	int pos[2];
    	char topo_ini;
    	vector<int> solucao(100, -1);
     
    	dado[0] = '1'; //os indices pares sao de uma face e 	
    	dado[1] = '6'; //os impares sao da face oposta (diferenca de uma unidade)
    	dado[2] = '2';
    	dado[3] = '5';
    	dado[4] = '3';
    	dado[5] = '4';
     
    	// frentetopo[frente][topo] = direita do dado
        frentetopo[1][2] = '4'; 
        frentetopo[1][3] = '2';
        frentetopo[1][4] = '5';
        frentetopo[1][5] = '3';
        frentetopo[2][1] = '3'; 
        frentetopo[2][3] = '6'; 
        frentetopo[2][4] = '1';
        frentetopo[2][6] = '4';
        frentetopo[3][1] = '5'; 
        frentetopo[3][2] = '1';
        frentetopo[3][5] = '6';
        frentetopo[3][6] = '2';
        frentetopo[4][1] = '2';
        frentetopo[4][2] = '6';
        frentetopo[4][5] = '1';
        frentetopo[4][6] = '5';
        frentetopo[5][1] = '4';
        frentetopo[5][3] = '1';
        frentetopo[5][4] = '6';
        frentetopo[5][6] = '3';
        frentetopo[6][2] = '3';
        frentetopo[6][3] = '5';
        frentetopo[6][4] = '2';
        frentetopo[6][5] = '4';
     
    	int taml;
    	int tamc;
    	cin >> taml;
    	cin >> tamc;
    	cin >> pos_ini[0] >> pos_ini[1];//linha, coluna
    	pos[0] = pos_ini[0];
    	pos[1] = pos_ini[1];
    	solucao[0] = 1;
    	solucao[1] = pos_ini[0];
    	solucao[2] = pos_ini[1];
    	cin >> topo_ini;
    	char frente_ini;
    	cin >> frente_ini;
     
    	for (int i = 0; i < taml+2; i++)
    		for (int j = 0; j < tamc+2; j++)
    			tabuleiro[i][j] = '0';
     
    	//preenchendo o tabuleiro
    	int auxcol = 1;
    	int auxlin = 1;
    	getline(cin, sujeira);
    	while (getline(cin, linha)) {
    		int tam = linha.length();
    		for (int i = 0; i < tam; i++) {// primeira posicao = (1,1)
    			if (linha[i] != '-') {
    				if (linha[i] != ' ') {
    					tabuleiro[auxlin][auxcol] = linha[i];
    					auxcol++;
    				}
    			}	else {
    					tabuleiro[auxlin][auxcol] = '*';
    					auxcol++;
    					i++;
    				}
    		}
     
    		auxlin++;
    		auxcol = 1;
    	}
     
    	int resultado;
    	resultado = prox_pos(pos, topo_ini, frente_ini, pos_ini, solucao, true);
    	if (terminou == false) 
    		cout << 0 << endl;
    	return 0;
    }
     
    int prox_pos(int pos[], char topo, char frente, int pos_ini[], vector<int> solucao, bool primeira_vez) {
     
    	int foi;
    	if ((topo == tabuleiro[pos[0] + 1][pos[1]] || tabuleiro[pos[0] + 1][pos[1]] == '*' ||
    		topo == tabuleiro[pos[0]][pos[1] + 1] || tabuleiro[pos[0]][pos[1] + 1] == '*' ||
    		topo == tabuleiro[pos[0] - 1][pos[1]] || tabuleiro[pos[0] - 1][pos[1]] == '*' ||
    		topo == tabuleiro[pos[0]][pos[1] - 1] || tabuleiro[pos[0]][pos[1] - 1] == '*') &&
    		!(solucao[solucao[0]*2-3] == solucao[solucao[0]*2-7] && solucao[solucao[0]*2-2] == solucao[solucao[0]*2-6]) && 
    		terminou == false) {
     
    			if (pos_ini[0] == pos[0] && pos_ini[1] == pos[1] && !(primeira_vez)) {
    				cout << solucao[0] << " ";
    				for (int i = 1; i <= solucao[0]*2; i = i + 2)
    					cout << "(" << solucao[i] << "," << solucao[i+1] << ") ";
    				cout << endl;
    				terminou = true;
    				return 1;
    			}
    			else {
    					if (topo == tabuleiro[pos[0] + 1][pos[1]] || tabuleiro[pos[0] + 1][pos[1]] == '*') {
    						//se andar pra frente(baixo)
    						char aux;//recebera o valor do proximo topo
    						for (int i = 0; i < 6; i++)
    							if (dado[i] == frente) {
    								if (i % 2 == 0)
    									aux = dado[i+1];
    									else
    										aux = dado[i-1];
    							}
    						pos[0]++;
    						solucao[solucao[0]*2+1] = pos[0];
    						solucao[solucao[0]*2+2] = pos[1];
    						solucao[0]++;
    						foi = prox_pos(pos, aux, topo, pos_ini, solucao, false);
    						pos[0]--;
    						solucao[0]--;
    						solucao[solucao[0]*2+1] = -1;
    						solucao[solucao[0]*2+2] = -1;
    					}
    					if (topo == tabuleiro[pos[0]][pos[1] + 1] || tabuleiro[pos[0]][pos[1] + 1] == '*') {
    						//se andar para direita
    						int f = frente - '0';
    						int t = topo - '0';
    						vector<bool> arr(6,true);
    						//qual face sera o topo?
    						for (int i = 0; i < 6; i++) {
    							if (dado[i] == topo) {
    								arr[i] = false;
    								if (i%2==0)
    									arr[i+1] = false;
    								else
    									arr[i-1] = false;
    							}
    							if (dado[i] == frente) {
    								arr[i] = false;
    								if (i%2==0)
    									arr[i+1] = false;
    								else
    									arr[i-1] = false;
    							}
    						}
    						for (int  i = 0; i < 6; i++) {
    							if (arr[i] == true && frentetopo[f][t] != dado[i]) {
    								pos[1]++;
    								solucao[solucao[0]*2+1] = pos[0];
    								solucao[solucao[0]*2+2] = pos[1];
    								solucao[0]++;
    								foi = prox_pos(pos, dado[i], frente, pos_ini, solucao, false);
    								pos[1]--;
    								solucao[0]--;
    								solucao[solucao[0]*2+1] = -1;
    								solucao[solucao[0]*2+2] = -1;
    							}
    						}
    					}
    				if (topo == tabuleiro[pos[0] - 1][pos[1]] || tabuleiro[pos[0] - 1][pos[1]] == '*') {
    					//se  andar para tras(cima)
    					int aux;//recebera o valor do proximo frente
    					for (int i = 0; i < 6; i++)
    							if (dado[i] == topo) {
    								if (i % 2 == 0)
    									aux = dado[i+1];
    									else
    										aux = dado[i-1];
    							}
    					pos[0]--;
    					solucao[solucao[0]*2+1] = pos[0];
    					solucao[solucao[0]*2+2] = pos[1];
    					solucao[0]++;
    					foi = prox_pos(pos, frente, aux, pos_ini, solucao, false);
    					pos[0]++;
    					solucao[0]--;
    					solucao[solucao[0]*2+1] = -1;
    					solucao[solucao[0]*2+2] = -1;
    				}
    				if (topo == tabuleiro[pos[0]][pos[1] - 1] || tabuleiro[pos[0]][pos[1] - 1] == '*') {
    					//se andar para esquerda
    					int f = frente - '0';
    					int t = topo - '0';
    					vector<bool> arr(6,true);
    						//qual face sera o topo?
    						for (int i = 0; i < 6; i++) {
    							if (dado[i] == topo) {
    								arr[i] = false;
    								if (i%2==0)
    									arr[i+1] = false;
    								else
    									arr[i-1] = false;
    							}
    							if (dado[i] == frente) {
    								arr[i] = false;
    								if (i%2==0)
    									arr[i+1] = false;
    								else
    									arr[i-1] = false;
    							}
    						}
    						for (int  i = 0; i < 6; i++) {
    							if (arr[i] == true && frentetopo[f][t] == dado[i]) {
    								pos[1]--;
    								solucao[solucao[0]*2+1] = pos[0];
    								solucao[solucao[0]*2+2] = pos[1];
    								solucao[0]++;
    								foi = prox_pos(pos, dado[i], frente, pos_ini, solucao, false);
    								pos[1]++;
    								solucao[0]--;
    								solucao[solucao[0]*2+1] = -1;
    								solucao[solucao[0]*2+2] = -1;
    							}
    						}
    				}
    			}
    	}
    	return 2;
    }
