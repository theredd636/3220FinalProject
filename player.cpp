#include "player.hpp"

int Player::gethandValue(){
    return handValue;
}
void Player::sethandValue(){
    int total=0;
    for(card c :hand_){
        total+=c.getValue();
    }
    handValue=total;
}