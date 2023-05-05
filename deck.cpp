#include "deck.hpp"
#include <random>
deck::deck(){
    std::string faces[13] = {"ace" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" , "jack" , "queen" , "king"}; // 1 is an ace, then 2 - 10 and 11 -13 is jack queen king
    std::string suits[4] = {"Heart" , "Diamond" , " Spade" , "Clubs"};
    post = 0;
    for (std::string suit : suits) {
            for (std::string face : faces) {
                cards_.push_back(card(face, suit));
            }
        }
}
void deck::printDeck(){
    for (card c : cards_) {
            std::cout << c.to_string() << std::endl;
        }
}

void deck::shuffle(int random){

    std::default_random_engine rng(random);
        for (int i = cards_.size() - 1; i > 0; i--) {
            int j = rng() % (i + 1);
            std::swap(cards_[i], cards_[j]);
        }
    }