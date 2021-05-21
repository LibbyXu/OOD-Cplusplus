//
//  CoinGame.h
//  CoinFlip
//
//  Created by Lihua Xu on 5/17/21.
//

#ifndef CoinGame_h
#define CoinGame_h
#include "Player.h"
#include "Coin.h"
#include <iostream>

class CoinGame{
    friend class iostream;
protected:
    Player *player1=nullptr;
    Player *player2=nullptr;
    Coin *theCoin;
public:
    CoinGame(Player* playerName1, Player* playerName2){
        player1=playerName1;
        player2=playerName2;
    };
    
    void StartGame();
};

void CoinGame::StartGame(){
    if(rand()%2==0){
        player1->getRandCoinOption();
        player2->setCoinOption(player1->getCoinOption());
        theCoin=new Coin();
        std::string coinResult=theCoin->getCoinOption();
        player1->didPlayerWin(coinResult);
        player2->didPlayerWin(coinResult);
    }else{
        player2->getRandCoinOption();
        player1->setCoinOption(player2->getCoinOption());
        theCoin=new Coin();
        std::string coinResult=theCoin->getCoinOption();
        player1->didPlayerWin(coinResult);
        player2->didPlayerWin(coinResult);
    }
    
    std::cout << "Want to Player again?(y/n)" << std::endl;
    
    char ans1=tolower(player1->tryAgain());
    char ans2=tolower(player2->tryAgain());;
    
    
    if(ans1=='y' && ans2=='y')this->StartGame();
    else std::cout << "Game Over!" << std::endl;
};

#endif /* CoinGame_h */
