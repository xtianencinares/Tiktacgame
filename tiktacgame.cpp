//TIC-TAC-TOE Game in C++/C

//Importing the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
//Structure of the Board 3*3
char Board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//STATE VARABLES FOR TURN,POSITOON MARKER
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board

void display_board(){

    //Print Game Board LAYOUT

    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<Board[0][0]<<"  | "<<Board[0][1]<<"  |  "<<Board[0][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<Board[1][0]<<"  | "<<Board[1][1]<<"  |  "<<Board[1][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<Board[2][0]<<"  | "<<Board[2][1]<<"  |  "<<Board[2][2]<<" \n";
    cout<<"\t\t\t\t     |     |     \n";
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"\ntPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\ntPlayer - 2 [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && Board[row][column] != 'X' && Board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied and change the turn
        Board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && Board[row][column] != 'X' && Board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied and change the turn
        Board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled call the function again for valid input
        cout<<"Box already filled!\n Please choose another!!\n\n";
        player_turn();
    }
    // printing the status
    display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] || Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
    return false;

    //checking the win for both diagonal

    if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] || Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(Board[i][j] != 'X' && Board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"\t\t\t\t\tWELCOME\n";
	cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    display_board();
    while(gameover()){
        
        player_turn();
       
    }
    //if someone wins then there must be a change of turn  after update 
    if(turn == 'O' && draw == false){
        cout<<"\n\nCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'X' && draw == false){
        cout<<"\n\nCongratulations!Player with 'O' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
} 

