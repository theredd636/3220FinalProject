#include "card.hpp"

card::card(){} 

card::card(std::string face,std::string suit){
    this->face_ = face;
    this->suit_ = suit;
}

void card::setCard(std::string suit, std::string face){
    suit_ = suit;
    face_ = face;
}
std::string card::to_string(){
    std::string temp=" of ";
    std::string output= face_ + temp + suit_;
    return output;
}
int card::getValue(){
    if(face_ =="two")
        return 2;
    else if(face_=="three")
        return 3;
    else if(face_=="four")
        return 4;
    else if(face_=="five")
        return 5;
    else if(face_=="six")
        return 6;
    else if(face_=="seven")
        return 7;
    else if(face_=="eight")
        return 8;
    else if(face_=="nine")
        return 9;
    else if((face_=="ten") || (face_=="jack") || (face_=="queen") || (face_=="king"))
        return 10;
    else if(face_=="ace")
        return 11;
    return 1;
}
