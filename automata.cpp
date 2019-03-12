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

//update the grid (i=row, q=column)
void updategrid ()
{
for(int i = 1; i<=rows-1; i++){
  for(int q = 1; q<=columns-1; q++){
    //left unoccupied? ([i-1][q] == 0) (up:[i][q+1]) 2 = 0 3 = 1
    if(cell[i-1][q] == 0)
      cell[i][q-1] = 3;
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
