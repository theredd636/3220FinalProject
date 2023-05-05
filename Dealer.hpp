#include <iostream>
#include <vector>
#include "card.hpp"
class Dealer {
    public:
    std::string getHand();
    card getCard(int index);
    int getChips();
    void setHand(card c);
    void setChips(int num);
    int gethandValue();
    void sethandValue();
    void emptyHand();
    private:
    std::vector<card>Dhand_;
    int DhandValue;
    int Dchips;
};