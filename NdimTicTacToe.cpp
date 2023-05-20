#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;



//lets define a block to be a struct, this is only being done to make it easier to visualise, if ever needed
//as it would be a simple task to give each block some visual property or correlate it to one

//this is the singular unit the lowest dimension gameboard
struct Block{
    int state; // state can be 0 for O 
               // 1 for X
               // -1 for empty or unassigned
};
typedef struct Block Block;


// we can treat the final gameboard as a collection of gameboards
 
struct GameBoard{
    int dimension;
    Block **subGameBoard;


    
    
};
typedef struct GameBoard GameBoard;

//  initialisation (or) creation functions

Block * initBlock(){
    Block * newBlock = (Block *)malloc(sizeof(Block));
    newBlock->state = -1; //block initialise with -1 always
    return newBlock;
}

GameBoard * initGB(int dimension){

    //the lowest acceptable dimension is 1 which has 3 blocks
    //2D can be represented as (1D) x (1D) which is well, 3 x 3 = 9 blocks
    //in general we can represent it as 3^N, which means we need to allocate 3^N blocks of memory


    GameBoard* newBoard = (GameBoard*)malloc(sizeof(GameBoard));

    newBoard->dimension = dimension;

    //allocating 3^N memory blocks to subGameBoard

    Block** temp;
    temp = (Block**)malloc((int)(pow(3, dimension))*sizeof(Block*));
    
    newBoard->subGameBoard = temp;

    //initialising all the blocks
    for(int i = 0; i<(int)pow(3,dimension);i++){
        temp[i] = initBlock();
    }




    return newBoard;
}


void display(GameBoard* board, int dimension){

    for(int i = 0; i < (int)pow(3, dimension);i++){
        if(i%3 == 0){
            printf("\n");
        }

        Block **temp = board->subGameBoard;

        printf("%d", temp[i]->state);
    }

}




int main(){

    cout << "Enter the dimension the game takes place in : ";

    //we are assuming the size of the board is of constant 3 units in each dimension.
    int dimension;
    cin >> dimension;

    GameBoard * board1 = initGB(dimension);

    display(board1, board1->dimension);

    //ignoring the low dimensions of 0,1,2 for now
    
    //for dimension 1, we could have a line of 3 blocks
    //in dimension 2 we achieve the traditional 3x3 gameboard with 9 blocks
    //extending this into the 3rd dimension, we would have a cube, 3x3x3,
    // or we could look at it as, 3 x (2 dimensional tictactoe boards)
    //for a 4th dimensional board, we would have a hypercube but we could still intepret it as 3x3x3x3

    //in essence, 3^N would be the hyper volume of the hypercube of N dimensions
    //in this case the volume would be proportional to the amount of memory being allocated.

    //Creating the gameboard

    


}



