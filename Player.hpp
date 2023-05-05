#include <iostream>
#include "Person.hpp"
class Player :public person{
    public:
    std::string getHand();
    card getCard(int index);
    int getChips();
    void setHand(card c);
    void setChips(int num);
    int gethandValue();
    void sethandValue();
    private:
    std::vector<card> hand_;
    int handValue;
    int chips;
};
