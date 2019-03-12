#include <iostream>
#include <cmath>
using std::cout;
using namespace std;

//print a grid lmao

//
const int rows = 5;
const int columns = 5;
int cell[rows][columns];
int sizex;
int sizey;
int sizetotal;

//print the grid
void printgrid ()
{
  std:: cout << "_______________\n";
for(int i = 1; i<=rows; i++)
 {
  for(int q = 1; q<=columns; q++)
  {
    std:: cout << "[" << cell[i][q] << "]";
    fflush(stdout);
    //enable for exact location printing
    //std:: cout << q << "," << i;
  }
  std:: cout << endl ;
  //enable for row by row
  //getchar();
 }
}


void bakegrid ()
{
for(int i = 1; i<=rows; i++)
 {
  for(int q = 1; q<=columns; q++)
  {
    //2 = 0, 3 = 1
        if(cell[i][q] == 2)
        {
          cell[i][q] = 0;
        }

        if(cell[i][q] == 3)
        {
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
for(int i = 1; i<=rows; i++)
 {
  for(int q = 1; q<=columns; q++)
  {
    if(cell[i][q] == 0)
    {
      cell[i][q] = 3;
    }

    if(cell[i][q] == 1)
    {
      cell[i][q] = 2;
    }

    //is t
    //is there an unoccupied cell to my left?
    /*
    if(cell[i][q-1] == 0)
    {
    cell[i][q] = 1;
    std::cout << "X";
    }
    */

    /*
    //is there an unoccupied cell above me?
    if(cell[i-1][q] == 0)
    {
    cell[i][q] = 1;
    std::cout << "Y";
    }
    */

    //visualize updating
    //std:: cout << cell[i][q];
  }
  //visualize updating
  //std:: cout << endl;
  //getchar();
 }
}


int stepgrid (int iterations)
{
  for(int c=0; c<iterations; c++)
  {
    updategrid();
    bakegrid();
    printgrid();
  }
}

int main()
{
//calculate sizes and say them
sizex = sizeof(cell)/sizeof(cell[0]);
sizey = sizex;
sizetotal= pow(sizex, 2);
std:: cout << "X:" << sizex << endl;
std:: cout << "Y:" << sizey << endl;
std:: cout << "Total:" << sizetotal << endl;

//clear the grid
cleargrid();

printgrid();

stepgrid(2);

return 0;
}
