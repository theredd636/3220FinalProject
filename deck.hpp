#ifndef DECK_H
#define DECK_H
#include "card.hpp"
#include <vector>
class deck
{
    public:
    deck();
    void printDeck();
    void shuffle(int r);
    int getPosition();
    card deal();
    private:
    std::vector<card> cards_;
    int Position ; // this is the current spot of the deck
};
        
#endif        