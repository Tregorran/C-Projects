/*
* indicates live cells
. indicates dead cells
example 1 input:
4 8
........
....*...
...**...
.....*..

example 1 output:
4 8
........
...**...
...***..
....*...


example 2 input:
5 8
........
...**...
.*****..
........
........

example 2 output:
5 8
........
.....*..
..*..*..
..***...
........
*/

#include <iostream>
using namespace std;

// change row and column value to set the canvas size
const int row = 5;
const int col = 8;


int numAliveNeighbours(char before[row][col], int r, int c){
    //count in a square around the cell
    int count = 0;
    for(int i = r - 1; i <= r + 1; i++){
        for(int j = c - 1; j <= c + 1; j++){
            //if ((i >= 0 && j >= 0) && (i < row && j < col) && (i != r && j != c)){
            if ((i >= 0 && j >= 0) && (i < row && j < col) && (i != r || j != c)){
                //cout << i << ":" << j << "\n";
                if (before[i][j] == '*'){
                    count += 1;
                }
            }
        }
    }
    return count;
}


int main(){
    char before[row][col];
    char after[row][col];

    //example1
    /*........
      ....*...
      ...**...
      .....*..
    */
    /*
    before[0][0] = '.';
    before[0][1] = '.';
    before[0][2] = '.';
    before[0][3] = '.';
    before[0][4] = '.';
    before[0][5] = '.';
    before[0][6] = '.';
    before[0][7] = '.';

    before[1][0] = '.';
    before[1][1] = '.';
    before[1][2] = '.';
    before[1][3] = '.';
    before[1][4] = '*';
    before[1][5] = '.';
    before[1][6] = '.';
    before[1][7] = '.';

    before[2][0] = '.';
    before[2][1] = '.';
    before[2][2] = '.';
    before[2][3] = '*';
    before[2][4] = '*';
    before[2][5] = '.';
    before[2][6] = '.';
    before[2][7] = '.';

    before[3][0] = '.';
    before[3][1] = '.';
    before[3][2] = '.';
    before[3][3] = '.';
    before[3][4] = '.';
    before[3][5] = '*';
    before[3][6] = '.';
    before[3][7] = '.';
    */
    /*
    ........
    ...**...
    .*****..
    ........
    ........
    */
    before[0][0] = '.';
    before[0][1] = '.';
    before[0][2] = '.';
    before[0][3] = '.';
    before[0][4] = '.';
    before[0][5] = '.';
    before[0][6] = '.';
    before[0][7] = '.';

    before[1][0] = '.';
    before[1][1] = '.';
    before[1][2] = '.';
    before[1][3] = '*';
    before[1][4] = '*';
    before[1][5] = '.';
    before[1][6] = '.';
    before[1][7] = '.';

    before[2][0] = '.';
    before[2][1] = '*';
    before[2][2] = '*';
    before[2][3] = '*';
    before[2][4] = '*';
    before[2][5] = '*';
    before[2][6] = '.';
    before[2][7] = '.';

    before[3][0] = '.';
    before[3][1] = '.';
    before[3][2] = '.';
    before[3][3] = '.';
    before[3][4] = '.';
    before[3][5] = '.';
    before[3][6] = '.';
    before[3][7] = '.';

    before[4][0] = '.';
    before[4][1] = '.';
    before[4][2] = '.';
    before[4][3] = '.';
    before[4][4] = '.';
    before[4][5] = '.';
    before[4][6] = '.';
    before[4][7] = '.';


    //print before
    cout << "Initial matrix: \n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << before[i][j];
        }
        cout << "\n";
    }

    /*Your task is to write a program to calculate the next generation of Conway's game of life, given any starting position.

    You start with a two dimensional grid of cells, where each cell is either alive or dead.
    The grid is finite, and no life can exist off the edges.
    When calculating the next generation of the grid, follow these four rules:

    1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
    2. Any live cell with more than three live neighbours dies, as if by overcrowding.
    3. Any live cell with two or three live neighbours lives on to the next generation.
    4. Any dead cell with exactly three live neighbours becomes a live cell.

    1. < 2 dies
    2. >= 4 dies
    3. 2 or 3 lives
    4. ded 3 becomes alive

    example 1 input:
    ........
    ....*...
    ...**...
    .....*..

    example 1 output:
    ........
    ...**...
    ...***..
    ....*...

    .*/

    //int num = numAliveNeighbours(before, 1, 4);
    //cout << num;
    //cout << "\n";
    int num = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            num = numAliveNeighbours(before, i, j);
            if (before[i][j] == '.'){
                if (num == 3){
                    after[i][j] = '*';
                } else {
                    after[i][j] = '.';
                }
            }
            else if (before[i][j] == '*'){
                if (num < 2){
                    after[i][j] = '.';
                } else if (num >= 4){
                    after[i][j] = '.';
                } else{
                    after[i][j] = '*';
                }
            } else {
             cout << "Error! in matrix";
            }
        }
    }

    cout << "Completed matrix: \n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << after[i][j];
        }
        cout << "\n";
    }
}

//1 hour
