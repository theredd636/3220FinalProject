#include <iostream>
#include "deck.hpp"
#include "Player.hpp"
class game{
    public:
    game();
    void blackJack();
    std::pair<std::vector<card>, std::vector<card>> ruleSplit(Player P);
    private:
    deck D;
};