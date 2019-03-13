#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
using std::cout;
using namespace std;

const int rows = 50;
const int columns = 50;
int cell[rows][columns];

//print the grid
void printgrid (){
  for(int i = -3; i<=columns; i++){
    std:: cout << "_";
  }
  std:: cout << "\n";
for(int q = rows; q>=1; q--){
  for(int i = 1; i<=columns-1; i++){
    if(cell[i][q] == 1)
      std:: cout << "|█";
    else
      std:: cout << "| ";
  //  std:: cout << "[" << cell[i][q] << "]";
    if(i==columns-1)
      std:: cout << "|";
    fflush(stdout);
    //enable for exact location printing
    //std:: cout << q << "," << i;
  }
  std:: cout << endl ;
  //enable for row by row
  //getchar();
 }
}

//2 means 0->0 3 means 1->1 4 means 0->1 5 means 1->0
/*
void bakegrid (){
for(int q = 1; q<=rows-1; q++){
  for(int i = 1; i<=columns-1; i++){
    //2 = 0, 3 = 1
        if(cell[i][q] == 2 || cell[i][q] == 4){
          cell[i][q] = 0;
        }
        if(cell[i][q] == 3 || cell[i][q] == 5){
          cell[i][q] = 1;
        }
  }
 }
}
*/

//clear the grid
void cleargrid (){
for(int q = 1; q<=rows; q++)
 {
  for(int i = 1; i<=columns; i++)
  {
    cell[i][q] = 0;
  }
 }
}

int neighbors[rows][columns];
//update the grid (i=row, q=column)
//left unoccupied? ([i-1][q] == 0) (up:[i][q+1]) 2 = 0 3 = 1
/* if(cell[i+1][q+1] == 0) then cell[i+1][q] = 3;*/
void updategrid1 (){
for(int q = 1; q<=rows-1; q++){
  for(int i = 1; i<=columns-1; i++){
    neighbors[i][q] = 0;
//dudes above me
    if(cell[i-1][q+1] == 1 || cell[i-1][q+1] == 4)
      neighbors[i][q]++;
    if(cell[i][q+1] == 1 || cell[i][q+1] == 4)
      neighbors[i][q]++;
    if(cell[i+1][q+1] == 1 || cell[i+1][q+1] == 4)
      neighbors[i][q]++;
//dudes to my left and right
    if(cell[i-1][q] == 1 || cell[i-1][q] == 4)
      neighbors[i][q]++;
//  if(cell[i][q] == 1)
//    neighbors[i][q]++;
    if(cell[i+1][q] == 1 || cell[i+1][q] == 4)
      neighbors[i][q]++;
//dudes below me
    if(cell[i-1][q-1] == 1 || cell[i-1][q-1] == 4)
      neighbors[i][q]++;
    if(cell[i][q-1] == 1 || cell[i][q-1] == 4)
      neighbors[i][q]++;
    if(cell[i+1][q-1] == 1 || cell[i+1][q-1] == 4)
      neighbors[i][q]++;
//2 means 0->0 3 means 1->1 4 means 0->1 5 means 1->0
 if(cell[i][q] == 1)
   {
    if(neighbors[i][q] < 2)
      cell[i][q] = 5;

    if(neighbors[i][q] > 3)
      cell[i][q] = 5;

    if(neighbors[i][q] == 2 || neighbors[i][q] > 2)
      cell[i][q] = 3;
    }
  if(cell[i][q] != 1)
    {
     if(neighbors[i][q] == 3)
         cell[i][q] = 4;
     }
  }
  //visualize updating
  //std:: cout << endl;
  //getchar();
 }
}

//2 means 0->0 3 means 1->1 4 means 0->1 5 means 1->0
void updategrid2 (){
  for(int q = 1; q<=rows; q++)
   {
    for(int i = 1; i<=columns; i++)
    {
      if(cell[i][q] == 2 || cell[i][q] == 5)
        cell[i][q] = 0;
      if(cell[i][q] == 3 || cell[i][q] == 4)
        cell[i][q] = 1;
    }
   }
}


int stepgrid (int iterations){
  for(int c=0; c<iterations; c++){
    updategrid1();
    updategrid2();
    //bakegrid();
    printgrid();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

int main(){
std:: cout << "rows:" << rows << "columns:" << columns-1 << endl;
//clear the grid
cleargrid();

cell[15][25] = 1;
cell[16][25] = 1;
cell[17][25] = 1;
cell[18][25] = 1;
cell[19][25] = 1;
cell[20][25] = 1;
cell[21][25] = 1;
cell[22][25] = 1;
cell[23][25] = 1;
cell[24][25] = 1;

std::this_thread::sleep_for(std::chrono::milliseconds(100));


printgrid();

stepgrid(200);

return 0;
}
