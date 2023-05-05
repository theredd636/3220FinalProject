#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include "card.hpp"
class Player {
    public:
    std::string getHand(bool one);
    card getCard(int index);
    int getChips();
    void setHand(card c);
    void setHand2(card c);
    void setChips(int num);
    int gethandValue();
    void sethandValue();
    int gethandValue2();
    void sethandValue2();
    void emptyHand();
    private:
    std::vector<card> Phand_;
    std::vector<card> P2hand_;
    int PhandValue;
    int P2handValue;
    int Pchips;
};
#endif