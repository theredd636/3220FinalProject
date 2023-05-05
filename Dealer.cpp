#include "Dealer.hpp"
std::string Dealer::getHand(){
    std::string temp;
    for(card c :hand_){
        temp+=c.to_string();
    }
    return temp;
}

card Dealer::getCard(int index){
    int size =hand_.size();
    if(index >= 0 && index < size) {
            return hand_[index];
        } else {
            std::cerr << "Invalid index!" << std::endl;
            return card("N/A", "N/A");
        }
}

int Dealer::getChips(){
    return chips;
}

void Dealer::setHand(card c){
    hand_.push_back(c);
}

void Dealer::setChips(int num){
    chips=num;
}
int Dealer::gethandValue(){
    return handValue;
}
void Dealer::sethandValue(){
    int total=0;
    for(card c :hand_){
        total+=c.getValue();
    }
    handValue=total;
}