#ifndef CARD_HPP
#define CARD_HPP





#include<iostream>
class card
{
    public:
    card();
    card(std::string face , std::string suit);
    void setCard(std::string value, std::string temp);

    std::string to_string();
    int getValue();
    private:
    std::string face_, suit_;
};
#endif 