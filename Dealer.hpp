#include <iostream>
#include "Person.hpp"
class Dealer :public person{
    public:
    int gethandValue();
    void sethandValue();
    private:
    std::vector<card> hand_;
    int handValue;
};