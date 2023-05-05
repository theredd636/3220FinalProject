#include "player.hpp"
std::string Player::getHand(){
    std::string temp;
    for(card c :hand_){
        temp+=c.to_string();
    }
    return temp;
}

card Player::getCard(int index){
    int size =hand_.size();
    if(index >= 0 && index < size) {
            return hand_[index];
        } else {
            std::cerr << "Invalid index!" << std::endl;
            return card("N/A", "N/A");
        }
}

int Player::getChips(){
    return chips;
}

void Player::setHand(card c){
    hand_.push_back(c);
}

void Player::setChips(int num){
    chips=num;
}

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