/*Given a letter print a diamond starting with 'A' with the supplied letter at the widest point.

This is the print diamond for 'E'.

....A....
...B.B...
..C...C..
.D.....D.
E.......E
.D.....D.
..C...C..
...B.B...
....A....


This is the print diamond for 'C'.

..A..
.B.B.
C...C
.B.B.
..A..

This is the print diamond for 'A'.

A

Note: These examples use dots in place of spaces only for readability.
Your diamond must contain spaces where there are dots.
*/

#include <iostream>
using namespace std;

int main(){
    char useLetter = 'E';
    int letterIndex = 0;
    char letters[] = {'A','B','C','D','E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z'};

    cout << "Hello World!";
    char diamond[52];

    //Get index of chosen letter
    for(int i = 0; i < sizeof(letters)/sizeof(char); i++){
        if (letters[i] == useLetter){
            letterIndex = i;
            break;
        }
    }
//    printf("%d\n", letterIndex);

    for(int i = 0; i <= letterIndex; i++){

        //print initial spaces
        int numSpaces = (letterIndex - i);
        for (int j = 0; j < numSpaces; j++){
            printf(".");
        }
        //PrintSpaces(numSpaces);

        printf("%c",letters[i]);
        diamond[i] = i;

        if (letters[i] != 'A')
        {
            //print middle spaces
            for(int j = 0; j < (i*2)-1; j++){
                printf(".");
            }
            printf("%c",letters[i]);
        }

        //print post spaces
        //PrintSpaces(numSpaces);
        for (int j = 0; j < numSpaces; j++){
            printf(".");
        }
        printf("\n");
    }
}

void PrintSpaces(int i){
    for (int j = 0; j < i; j++){
        printf(".");
    }
}


