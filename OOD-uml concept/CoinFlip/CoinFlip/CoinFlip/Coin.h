//
//  Coin.h
//  CoinFlip
//
//  Created by Lihua Xu on 5/17/21.
//

#ifndef Coin_h
#define Coin_h
#include <vector>
#include <random>

class Coin{
private:
    std::string coinOption;
public:
    std::vector<std::string>coinOp{"head","tail"};
    //Constructor (create the coin)
    Coin(){
        int randNum=rand()%2;
        coinOption=coinOp[randNum];
    };
    std::string getCoinOption();
};
std::string Coin::getCoinOption(){
    std::cout << "Coin itself is: " << coinOption << std::endl;
    return coinOption;
};

#endif /* Coin_h */
