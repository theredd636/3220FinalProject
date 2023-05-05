#include "player.hpp"
std::string Player::getHand(bool one){
    std::string temp;
    for(card c :Phand_){
        temp+=c.to_string()+" and ";
    }
    if(P2hand_.empty()!=true && one == true){
        temp=temp+"\n hand 2:\n";
        for(card c :P2hand_){
          temp+=c.to_string()+" and ";
        }
    }
    return temp;
}

card Player::getCard(int index){
    int size =Phand_.size();
    if(index >= 0 && index < size) {
            return Phand_[index];
        } else {
            std::cerr << "Invalid index!" << std::endl;
            return card("N/A", "N/A");
        }
}

int Player::getChips(){
    return Pchips;
}

void Player::setHand(card c){
    Phand_.push_back(c);
}

void Player::setChips(int num){
    Pchips=num;
}

int Player::gethandValue(){
    return PhandValue;
}
void Player::sethandValue(){
    int total=0;
    for(card c :Phand_){
        total+=c.getValue();
    }
    PhandValue=total;
}
void Player::setHand2(card c){
    P2hand_.push_back(c);
}
void Player::emptyHand(){
    Phand_.clear();
    P2hand_.clear();
}