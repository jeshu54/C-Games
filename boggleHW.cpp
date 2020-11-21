
#include <cstring> 
#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; 
#define M 4 
#define N 4 

class Boggle{
  private:
  	string filename;
  	string color;
	char a,b,c,d;
	vector<char> e,f,g,h;
	char boggle[M][N];
  public:
  	Boggle(string filename): filename(filename) {
  	ifstream in(filename);
 
  	 if(in.is_open()) {
  	while(getline(in,color) && color.length() !=0) {
  		stringstream sso(color);
  		if(color[0] == '4') {
  			continue;
  		}
  		
  		else {
  		 sso >> a >> b >> c >> d ;
  		 e.push_back(a);
  		 f.push_back(b);
  		 g.push_back(c);
  		 h.push_back(d);
  		 for(int i=0; i< N; i++){
  		 		boggle[i][0] = e[i]; 
  		 		boggle[i][1] = f[i];
  		 		boggle[i][2] = g[i];
  		 		boggle[i][3] = h[i]; 
  		 		
  	  }
  	}
  }
}
  
  else {
    cout << "file is not open" << endl;
  }
}
  void printboggle(){
  for(int i=0; i< M; i++) {
  		 	for (int j=0; j< N; j++){
  		// 	 boggle[i][j] = boggle[j][i];
  		 	 cout << boggle[i][j];
  		 		}
  		 	}

}
}
;



int main() {

Boggle s("boggle.dat");

s.printboggle();

}