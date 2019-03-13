#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
using std::cout;
using namespace std;

const int rows = 20;
const int columns = 20;
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


void bakegrid (){
for(int q = 1; q<=rows-1; q++){
  for(int i = 1; i<=columns-1; i++){
    //2 = 0, 3 = 1
        if(cell[i][q] == 2){
          cell[i][q] = 0;
        }
        if(cell[i][q] == 3){
          cell[i][q] = 1;
        }
  }
 }
}

//clear the grid
void cleargrid ()
{
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
void updategrid ()
{
for(int q = 1; q<=rows-1; q++){
  for(int i = 1; i<=columns-1; i++){
    neighbors[i][q] = 0;
//dudes above me
    if(cell[i-1][q+1] == 1)
      neighbors[i][q]++;
    if(cell[i][q+1] == 1)
      neighbors[i][q]++;
    if(cell[i+1][q+1] == 1)
      neighbors[i][q]++;
//dudes to my left and right
    if(cell[i-1][q] == 1)
      neighbors[i][q]++;
//  if(cell[i][q] == 1)
//    neighbors[i][q]++;
    if(cell[i+1][q] == 1)
      neighbors[i][q]++;
//dudes below me
    if(cell[i-1][q-1] == 1)
      neighbors[i][q]++;
    if(cell[i][q-1] == 1)
      neighbors[i][q]++;
    if(cell[i+1][q-1] == 1)
      neighbors[i][q]++;

 if(cell[i][q] == 1)
   {
    if(neighbors[i][q] < 2)
      cell[i][q] = 2;

    if(neighbors[i][q] > 3)
      cell[i][q] = 2;

    if(neighbors[i][q] == 2 || neighbors[i][q] > 2)
      cell[i][q] = 3;
    }
  if(cell[i][q] != 1)
    {
     if(neighbors[i][q] == 2)
         cell[i][q] = 1;
     }
  }
  //visualize updating
  //std:: cout << endl;
  //getchar();
 }
}


int stepgrid (int iterations){
  for(int c=0; c<iterations; c++){
    updategrid();
    bakegrid();
    printgrid();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

int main(){
std:: cout << "rows:" << rows << "columns:" << columns-1 << endl;
//clear the grid
cleargrid();

/*
cell[19][19] = 1;
cell[20][18] = 1;
cell[18][17] = 1;
cell[19][17] = 1;
cell[20][17] = 1;
cell[20][20] = 1;
cell[21][21] = 1;
cell[17][17] = 1;
*/
cell[1][1] = 1;
cell[2][1] = 1;
cell[3][1] = 1;
cell[4][2] = 1;
std::this_thread::sleep_for(std::chrono::milliseconds(1000));


printgrid();

stepgrid(0);

return 0;
}
