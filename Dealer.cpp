#include "Dealer.hpp"
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