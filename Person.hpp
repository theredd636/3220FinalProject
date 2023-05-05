#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include "card.hpp"
class person{
    public:
    std::string getHand();
    card getCard(int index);
    int getChips();
    void setHand(card c);
    void setChips(int num);
    private:
    std::vector<card> hand_;
    int chips;
};
#endif