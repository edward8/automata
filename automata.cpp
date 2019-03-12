#include <iostream>
#include <cmath>
using std::cout;
using namespace std;

const int rows = 40;
const int columns = 40;
int cell[rows][columns];

//print the grid
void printgrid (){
  std:: cout << "_______________\n";
for(int i = 1; i<=rows-1; i++){
  for(int q = 1; q<=columns-1; q++){
    if(cell[i][q] == 1)
      std:: cout << "|█";
    else
      std:: cout << "| ";
  //  std:: cout << "[" << cell[i][q] << "]";
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
for(int i = 1; i<=rows-1; i++){
  for(int q = 1; q<=columns-1; q++){
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
for(int i = 1; i<=rows; i++)
 {
  for(int q = 1; q<=columns; q++)
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
for(int i = 1; i<=rows-1; i++){
  for(int q = 1; q<=columns-1; q++){
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

    if(neighbors[i][q] == 2 || neighbors[i][q] == 3)
      cell[i][q] = 3;
    }
  if(cell[i][q] == 0)
    {
     if(neighbors[i][q] == 3)
         cell[i][q] = 3;
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
  }
}

int main(){
std:: cout << "rows:" << rows - 1 << "columns:" << columns - 1 << endl;
//clear the grid
cleargrid();

printgrid();

stepgrid(2);

return 0;
}
