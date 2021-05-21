//
//  Player.h
//  CoinFlip
//
//  Created by Lihua Xu on 5/17/21.
//

#ifndef Player_h
#define Player_h
#include <vector>

class Player{
public:
    std::vector<std::string>coinOp{"head","tail"};
    Player(std::string newName):name(newName){};
    std::string getCoinOption();
    void setCoinOption(std::string opponentFlip);
    std::string getRandCoinOption();
    void didPlayerWin(std::string winningFlip);
    char tryAgain();
private:
    std::string name;
    std::string coinOption;
};

std::string Player::getCoinOption(){
    return coinOption;
};

void Player::setCoinOption(std::string opponentFlip){
    coinOption=opponentFlip==coinOp[0]?coinOp[1]:coinOp[0];
    //std::cout << name << " get the coin option " << coinOption<< std::endl;
};

std::string Player::getRandCoinOption(){
    coinOption=coinOp[rand()%2];
    //std::cout << name << " randomly chosed the coin option " << coinOption << std::endl;
    return getCoinOption();
};

void Player::didPlayerWin(std::string winningFlip){
    if(getCoinOption()==winningFlip){
        std::cout << name << " wins the game!\n";
    }else{
        std::cout << name << " loses the game!\n";
    }
};

char Player::tryAgain(){
    char s;
    std::cin >> s;
    return s;
};

#endif /* Player_h */
