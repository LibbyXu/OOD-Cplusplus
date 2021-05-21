//
//  main.cpp
//  CoinFlip
//
//  Created by Lihua Xu on 5/16/21.
//from the class diagram

#include <iostream>
#include <string>
#include "Coin.h"
#include "Player.h"
#include "CoinGame.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Player* player1=new Player("Libby");
    Player* player2=new Player("Chao");

    CoinGame *CurGame=new CoinGame(player1, player2);
    
    CurGame->StartGame();
    
    delete player1;
    delete player2;
    delete CurGame;
    
    return 0;
}
