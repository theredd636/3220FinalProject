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
    private:
    std::vector<card> cards_;
    int post ; // this is the current spot of the deck
};
        
#endif        