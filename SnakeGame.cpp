#include <iostream>
#include <cmath>
#include <ncurses.h>
#include <cstdlib>
#include <curses.h>

using namespace std;
bool Gameover;
int x,y, fruitx, fruity, score; 
const int width=30, height=20;
enum eDirection {STOP =0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int tail_x[100];
int tail_y[100];
int ntail =0;


void setup() {
  //initscr();
  //clear();
 // noecho();
  //cbreak();
  //curs_set(0);

  Gameover = false;
  dir = STOP;
  x = width/2;
  y = height/2;
  fruitx = rand()% width;
  fruity = rand()% height;
  score =0;

}

void drawmap() {
  

  //clear();

  for(int i=0; i<= width; i++) 
  	cout << "#" ;
  	cout << endl;
  

  for(int i=0; i<= height; i++) {
  	for(int j=0; j<= width; j++) {
  	  
  	  if (j==0) 
  			cout << "#";
      if (i==y && j==x) 
        cout << "0";
      
      else if (i==fruitx && j== fruity) 

        cout << "F";
      
      else 
        for (int k = 0; k <ntail; k++) {
          if (tail_x[k] == j && tail_y[k] == i)
            cout << "o";
        }

      
     
      
     	  
  	  
  	  if (j == width - 1) {
  	  	cout << "#";
      }
       else 
        cout << " ";
  	  
 }
 cout << endl;
 //refresh();
 //getch();
 //endwin();
 } 	   

 for(int i=0; i<= width; i++) 
  	cout << "#" ;
  	cout << endl;  
 }

  
void input() {
  //keypad(stdscr, TRUE);
  //halfdelay(1);
  int c ;

    switch (c) {
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'w':
        dir = UP;
        break;
      case 'x':
        Gameover = TRUE; 
        break;
    }
  }



void  logic() {
  int prevx = tail_x[0];
  int prevy = tail_y[0];
  int prev2x, prev2y;
  tail_x[0] = x;
  tail_y[0] = y;

  for (int i=1; i < ntail; i++) {

    prev2x = tail_x[i];
    prev2y = tail_y[i];
    tail_x[i] = prevx;
    tail_y[i] = prevy;
    prevx = prev2x;
    prevy = prev2y;
    
  }


  switch (dir) {
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case DOWN:
      y--;
      break;
    case UP:
      y++;
      break;
    default:
      break;
  }
  if (x > width || x < 1 || y < 1|| y> height)
    Gameover = TRUE;

  if (x == fruitx && y == fruity) {

    score++;
    fruitx = rand()% width;
    fruity = rand()% height;

  }

  for (int i = 0; i < ntail; i++) {
    if(tail_x[i] == x && tail_y[i] == y) {
      Gameover = TRUE;
    }

  }

}

int main() {
 // Functions for the game
	setup();
  while (!Gameover) {
    drawmap();
    input();
    logic();

  }
  //getch();
  //endwin();
  
  return 0;
}
