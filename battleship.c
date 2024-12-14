/*
 * battleship.c
 *
 *  Created on: Mar 14, 2018
 *      Author: Aaron
 */

#include "system.h"
#include "random_int.h"
#include "stddef.h"
#include "strings.h"
#include "game.h"
#include "timing.h"
#include "task.h"
#include "terminal.h"
#include "random_int.h"

#define PLAYER_MAP_MIN_X 2
#define PLAYER_MAP_MIN_Y 3
#define PLAYER_MAP_MAX_X 22
#define PLAYER_MAP_MAX_Y 23
#define OPPONENT_MAP_MIN_X 25
#define OPPONENT_MAP_MIN_Y 3
#define OPPONENT_MAP_MAX_X 45
#define OPPONENT_MAP_MAX_Y 23

//Game Structure
struct battleship_t {
    uint8_t id; //ID of game
};

typedef struct coordinate_t {
   char x;
   char y;
} coordinate_t;

struct ships_t {
    coordinate_t carrierStart,       //Starting coordinate of the aircraft carrier
                 battleshipStart,    //Starting coordinate of the battleship
                 submarineStart,     //Starting coordinate of the submarine
                 cruiserStart,       //Starting coordinate of the cruiser
                 destroyerStart;     //Starting coordinate of the destroyer
    uint8_t carrierLength,     //Length of the aircraft carrier
            battleshipLength,   //Length of the battleship
            submarineLength,    //Length of the submarine
            cruiserLength,      //Length of the cruiser
            destroyerLength;    //Length of the destroyer
};

static void Receiver(uint8_t c);
static void ReceiveXCoordinate(uint8_t c);
static void ReceiveYCoordinate(uint8_t c);
static void ReceiveCoordinates(uint8_t c);
static void Play(void);
static void Help(void);
static void PlaceShip(char direction, char startX, char startY, uint8_t length);
static void BuildField();
static void PromptForShipPlacement();
static void ShipPromptReceiver(uint8_t c);

static struct battleship_t game;
static struct ships_t ships = { .carrierLength = 5, .battleshipLength = 4, .submarineLength = 3, .cruiserLength = 3, .destroyerLength = 2};
coordinate_t *shipCoordinate;

Battleship_Init(void) {
    // Register the module with the game system and give it the name "MUH3"
    game.id = Game_Register("Battleship", "A sea battle guessing game.", Play, Help);
}

void Help(void) {
    Game_Printf("Choose the started coordinates and direction for each of your ships, then guess which coordinates at which you think your "
                "opponent placed ships.");
}

void Play(void) {
    //Clear screen
    Game_ClearScreen();

    //Build playing field
    BuildField();

    //Prompt user for ship positions
    PromptForShipPlacement();

    //Game_RegisterPlayer1Receiver(Receiver);

}

void Receiver(uint8_t c) {

}

void PromptForShipPlacement() {
    Game_Printf("Time to place your ships!\n\r");
    Game_Printf("Enter X Coordinate for your Aircraft Carrier: ");
    shipCoordinate = &ships.carrierStart;




    /*Game_Printf("Time to place your ships!\n\r"
                "Choose which ship you'd like to place: \n\r"
                "   1. Aircraft Carrier (%d)\n\r"
                "   2. Battleship (%d)\n\r"
                "   3. Submarine (%d)\n\r"
                "   4. Cruiser (%d)\n\r"
                "   5. Destroyer (%d)\n\r"
                "   0. Done \n\r",
                ships.carrierLength,
                ships.battleshipLength,
                ships.submarineLength,
                ships.cruiserLength,
                ships.destroyerLength);

    Game_Printf("Which ship would you like to place? ");
    Game_RegisterPlayer1Receiver(ShipPromptReceiver);*/
}

void ShipPromptReceiver(uint8_t c) {
    Game_Printf("\n\r");
    switch(c) {
        case '1':
            Game_Printf("Place Aircraft Carrier: \n\r");
            shipCoordinate = &ships.carrierStart;
            Game_Printf("X: ");
            //Game_UnregisterPlayer1Receiver(ShipPromptReceiver);
            shipCoordinate->x = 100;
            Game_RegisterPlayer1Receiver(ReceiveCoordinates);
            break;
        case '2':
            Game_Printf("Place Battleship: ");
            shipCoordinate = &ships.battleshipStart;
            break;
        case '3':
            Game_Printf("Place Submarine: ");
            shipCoordinate = &ships.submarineStart;
            break;
        case '4':
            Game_Printf("Place Cruiser: ");
            shipCoordinate = &ships.cruiserStart;
            break;
        case '5':
            Game_Printf("Place Destroyer: ");
            shipCoordinate = &ships.destroyerStart;
            break;
    }
}

void ReceiveString(char * receiveStr){
    uint8_t indexChar = 0, indexCharOld = 0;

    do{
        while(indexChar == indexCharOld){

        }
    }while()
}

void PlaceShip(char direction, char startX, char startY, uint8_t length) {
    //for
}

void ReceiveXCoordinate(uint8_t c) {
    switch(c) {
        case 'A':
        case 'a':
            shipCoordinate->x = 0;
            break;
        case 'B':
        case 'b':
            shipCoordinate->x = 1;
            break;
        case 'C':
        case 'c':
            shipCoordinate->x = 2;
            break;
        case 'D':
        case 'd':
            shipCoordinate->x = 3;
            break;
        case 'E':
        case 'e':
            shipCoordinate->x = 4;
            break;
        case 'F':
        case 'f':
            shipCoordinate->x = 5;
            break;
        case 'G':
        case 'g':
            shipCoordinate->x = 6;
            break;
        case 'H':
        case 'h':
           shipCoordinate->x = 7;
           break;
       case 'I':
       case 'i':
           shipCoordinate->x = 8;
           break;
       case 'J':
       case 'j':
           shipCoordinate->x = 9;
           break;
       default:
           Game_Printf("Coordinate outside of range. Please enter a character A-J \n\r"
                       "X: ");
           break;
    }
}

void ReceiveCoordinates(uint8_t c) {
    switch(c) {
        case 'A':
        case 'a':
            shipCoordinate->x = 0;
            break;
        case 'B':
        case 'b':
            shipCoordinate->x = 1;
            break;
        case 'C':
        case 'c':
            shipCoordinate->x = 2;
            break;
        case 'D':
        case 'd':
            shipCoordinate->x = 3;
            break;
        case 'E':
        case 'e':
            shipCoordinate->x = 4;
            break;
        case 'F':
        case 'f':
            shipCoordinate->x = 5;
            break;
        case 'G':
        case 'g':
            shipCoordinate->x = 6;
            break;
        case 'H':
        case 'h':
           shipCoordinate->x = 7;
           break;
       case 'I':
       case 'i':
           shipCoordinate->x = 8;
           break;
       case 'J':
       case 'j':
           shipCoordinate->x = 9;
           break;
       case '0':
           shipCoordinate->y = 0;
           break;
       case '1':
           shipCoordinate->y = 1;
           break;
       case '2':
           shipCoordinate->y = 2;
           break;
       case '3':
           shipCoordinate->y = 3;
           break;
       case '4':
           shipCoordinate->y = 4;
           break;
       case '5':
           shipCoordinate->y = 5;
           break;
       case '6':
           shipCoordinate->y = 6;
           break;
       case '7':
          shipCoordinate->y = 7;
          break;
      case '8':
          shipCoordinate->y = 8;
          break;
      case '9':
          shipCoordinate->y = 9;
          break;
       default:
           Game_Printf("Coordinate outside of range. Please enter a character A-J \n\r"
                       "X: ");
           break;
    }
}

void ReceiveYCoordinate(uint8_t c) {
    switch(c) {
        case '0':
            shipCoordinate->y = 0;
            break;
        case '1':
            shipCoordinate->y = 1;
            break;
        case '2':
            shipCoordinate->y = 2;
            break;
        case '3':
            shipCoordinate->y = 3;
            break;
        case '4':
            shipCoordinate->y = 4;
            break;
        case '5':
            shipCoordinate->y = 5;
            break;
        case '6':
            shipCoordinate->y = 6;
            break;
        case '7':
           shipCoordinate->y = 7;
           break;
       case '8':
           shipCoordinate->y = 8;
           break;
       case '9':
           shipCoordinate->y = 9;
           break;
       default:
           Game_Printf("Coordinate outside of range. Please enter a number 0-9\n\r"
                       "Y: ");
           break;
    }
}

void BuildField() {
    const char player[] = "Player";
    const char opponent[] = "Opponent";
    const char horizontalLabel[] = "A|B|C|D|E|F|G|H|I|J";
    const char verticalLabel[] = "0-1-2-3-4-5-6-7-8-9";
    static char field[23][46];

    volatile uint8_t i, j;
    size_t size;

    //Set field titles
    //Player
    size = sizeof(player) - 1;
    for(i = 0; i < size; i++) field[1][9+i] = player[i];

    //Opponent
    size = sizeof(opponent) - 1;
    for(i = 0; i < size; i++) field[1][31+i] = opponent[i];

    //Set horizontal labels
    size = sizeof(horizontalLabel) - 1;
    for(i = 0; i < size; i++) {
        field[2][3+i] = field[2][26+i] = horizontalLabel[i];
        field[4+i][1] = field[4+i][24] = verticalLabel[i];
    }

    //Set borders
    for(i = 3; i < 24; i++){
        for(j = 2; j < 23; j++){
            if( (i == 3) || (i == 23) )
                field[i][j] = field[i][j + 23] = 205;
            else if( (j == 2) || (j == 22) )
                field[i][j] = field[i][j + 23] = 186;
            else{
                if( (i % 2 == 0) && (j % 2 == 0) )
                    field[i][j] = field[i][j + 23] = 179;
                else if( (i % 2 != 0) && (j % 2 != 0))
                    field[i][j] = field[i][j + 23] = 196;
            }
        }
    }

    //Set corners
    field[3][2]   = field[3][25]  = 201;
    field[3][22]  = field[3][45]  = 187;
    field[23][2]  = field[23][25] = 200;
    field[23][22] = field[23][45] = 188;

    for(i = 0; i < 24; i++){
        for(j = 0; j < 46; j++){
            Game_CharXY(field[i][j], j, i);
            DelayMs(1);
        }
    }

    Game_Printf("\n\r");
}
