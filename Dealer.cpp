#include "Dealer.hpp"

std::string Dealer::getHand(){
    std::string temp;
    for(card c :Dhand_){
        temp+=c.to_string()+" and ";
    }
    return temp;
}

card Dealer::getCard(int index){
    int size =Dhand_.size();
    if(index >= 0 && index < size) {
            return Dhand_[index];
        } else {
            std::cerr << "Invalid index!" << std::endl;
            return card("N/A", "N/A");
        }
}

int Dealer::getChips(){
    return Dchips;
}

void Dealer::setHand(card c){
    Dhand_.push_back(c);
}

void Dealer::setChips(int num){
    Dchips=num;
}
int Dealer::gethandValue(){
    return DhandValue;
}
void Dealer::sethandValue(){
    int total=0;
    for(card c :Dhand_){
        total+=c.getValue();
    }
    DhandValue=total;
}

void Dealer::emptyHand(){
    Dhand_.clear();
}