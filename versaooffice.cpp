// reading a text file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
	static const size_t npos = -1;
  string line, line2;
  string entrada = "Microsoft Office";
  //string line3, entrada_c;
  
  ofstream saida;
  saida.open ("saida.txt");
  
  //cout << "Entrada:" << endl;
  //cin >> entrada;
  //entrada = "Microsoft Office";
  
	ifstream myfilenames ("nomes_maq.txt");
  if(myfilenames.is_open()) {
  
  while (getline (myfilenames,line2)) {
  	
  	//cout << line2.c_str();
  ifstream myfile (line2.c_str());
  if (myfile.is_open())
  {
    while (getline (myfile,line) )
    {
    	//cout << line << endl;
    	//for (int i=0; i < line.size(); i++) line3[i] = tolower(line[i]);
    	//cout << line3;
    	//line3 = tolower(line);
    	//entrada_c = tolower(entrada);
    	//for (int i=0; i < entrada.size(); i++) entrada_c[i] = tolower(entrada[i]);
    	//cout << entrada_c;
    	if (line.find(entrada) != npos) {
    		saida << line2 << "," << line << endl;
    		break;
		}
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
  
}
myfilenames.close();
saida.close();
}
else cout << "Unable to open filenames";
  return 0;
}
