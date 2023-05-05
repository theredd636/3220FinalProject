#include "Person.hpp"

std::string person::getHand(){
    std::string temp;
    for(card c :hand_){
        temp+=c.to_string();
    }
    return temp;
}

card person::getCard(int index){
    int size =hand_.size();
    if(index >= 0 && index < size) {
            return hand_[index];
        } else {
            std::cerr << "Invalid index!" << std::endl;
            return card("N/A", "N/A");
        }
}

int person::getChips(){
    return chips;
}

void person::setHand(card c){
    hand_.push_back(c);
}

void person::setChips(int num){
    chips=num;
}