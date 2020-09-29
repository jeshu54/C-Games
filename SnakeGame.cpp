#include <iostream>
#include <cmath>

using namespace std;
bool Gameover;
int x,y, fruitx, fruity, score; 
const int width=30, height=20;
enum eDirection {STOP =0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void setup() {

  Gameover = false;
  dir = STOP;
  x = width/2;
  y = height/2;
  fruitx = rand()% width;
  fruity = rand()% height;

}

void drawmap() {
  

  //system("cls");
  for(int i=0; i<= width; i++) 
  	cout << "#" ;
  	cout << endl;
  

 for(int i=0; i<= height; i++) {
  	for(int j=0; j<= width; j++) {
  	  
  	  if(j==0) 
  			cout << "#";

  	else {
     	  	cout << " "; }
     	  
  	  
  	  if(j== width-1) 
  	  	cout << "#";
  	  
 }
 cout << endl;
 } 	   

for(int i=0; i<= width; i++) 
  	cout << "#" ;
  	cout << endl;  
 }

  
void input() {


}

void  logic() {


}

int main() {
 // Functions for the game
	setup();
  drawmap();

  
  return 0;
}
