#include "game.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
game::game(){
    D.shuffle(13);
}
void game::blackJack(){
    bool over=false; 
    bool handnotHandled1=false,handnotHandled2=false;
    Player player;
    Dealer dealer;
    int input;
    player.setChips(100);
    dealer.setChips(5000000);
    int risk;
    while (player.getChips()>0 && dealer.getChips()>0)
    {
        //begin blackJack game
        
        bool splitf=false;//flag for handeling if player split
        if(D.getPosition() > 40)
        {
            std::cout << "***********************************" <<std::endl;
            std::cout << "Shuffle" << std::endl;
            std::cout << "***********************************" << std::endl;
            D.shuffle(player.getChips());

        }
        std::cout<<"How much will you risk? \n Player current has "<<player.getChips()<<" Chips\n"<<std::endl;
        std::cin>>risk;
        card temp = D.deal();
        std::cout << "Player was dealt a " << temp.to_string() << std::endl; // players first card
        player.setHand(temp);
        temp = D.deal();
        std::cout << "Dealer was dealt a " << temp.to_string() <<std::endl; // dealers first card
        dealer.setHand(temp);
        temp = D.deal();
        std::cout << "Player was dealt a " << temp.to_string() << std::endl; // players second card
        player.setHand(temp);
        temp = D.deal();
        dealer.setHand(temp);
        player.sethandValue();
        dealer.sethandValue();
        if(dealer.gethandValue()  == 21)
        {
            std::cout << "Dealer has BlackJack " <<std:: endl;
            player.setChips(player.getChips()-risk);
            dealer.setChips(dealer.getChips()+risk);
            over=true;
        }else if(player.gethandValue() == 21)
        {
            std::cout << "PLAYER BLACKJACK\n blackjack pays 3:2" <<std:: endl;
            player.setChips(risk*2.5+player.getChips());
            dealer.setChips(risk/2.5+dealer.getChips());
            over=true;
        }else if((player.gethandValue() == 21) && (dealer.gethandValue() ) == 21)
        {
            std::cout << "Player and Dealer have blackjack push" <<std::endl;
            over=true;
            risk=0;
        }

        while(over!=true && player.gethandValue()<=21){
            if(player.getCard(0).getValue() == player.getCard(1).getValue()){
                input = 0;
                while(input == 0){
                std::cout << "----------" <<std:: endl;
                std::cout << "Hit == 1" << std::endl;
                std::cout << "double == 2" << std::endl;
                std::cout << "Stand == 3" << std::endl;
                std::cout << "Split == 4" << std::endl;
                std::cin >> input;
                }
                if(input == 4)
                {
                    splitf=true;
                    std::pair<std::vector<card>, std::vector<card>> hands = ruleSplit(player);
                    std::vector<card> hand1,hand2;
                    hand1=hands.first;
                    hand2 = hands.second;
                    player.emptyHand();
                    for(card c:hand1){
                        player.setHand(c);
                    }
                    for(card c:hand2){
                        player.setHand2(c);
                    }
                    std::cout<<"Player Now has 2 hands"<<std::endl;
                    std::cout<<"hand 1: "<<player.getHand(false)<<std::endl;
                    // handle hand 1
                    player.sethandValue2();
                    player.sethandValue();
                    bool OH1=false;
                    bool OH2=false;
                    while (OH1!=true && player.gethandValue()<=21)
                    {
                        
                        std::cout<<"Player Currently Has "<<player.gethandValue()<<std::endl;
                        std::cout << "----------"  <<std::endl;
                        std::cout << "Hit == 1" << std::endl;
                        std::cout << "double == 2" << std::endl;
                        std::cout << "Stand == 3" << std::endl;
                        std::cin>>input;
                        if(input == 1)
                        {
                            temp=D.deal();
                            std::cout<< "\nPlayer was delt a "<<temp.to_string()<<std::endl;
                            player.setHand(temp);
                        }

                        if(input == 2)
                        {
                            std::cout<<"Double\n"<<std::endl;
                            risk=risk*2;
                            std::cout<< "\nPlayer was delt a "<<temp.to_string()<<std::endl;
                            player.setHand(temp);
                        }

                        if(input == 3)
                        {
                            OH1=true;
                        }
                        player.sethandValue();
                        
                    }
                    // handle hand 2
                    std::cout<<player.getHand(true)<<std::endl;
                    while(OH2!=true && player.gethandValue2()<=21){
                        std::cout<<"Player Currently Has "<<player.gethandValue2()<<std::endl;
                        std::cout << "----------"  <<std::endl;
                        std::cout << "Hit == 1" << std::endl;
                        std::cout << "double == 2" << std::endl;
                        std::cout << "Stand == 3" << std::endl;
                        std::cin>>input;
                        if(input == 1)
                        {
                            temp=D.deal();
                            std::cout<< "\nPlayer was delt a "<<temp.to_string()<<std::endl;
                            player.setHand2(temp);
                        }

                        if(input == 2)
                        {
                            std::cout<<"Double\n"<<std::endl;
                            risk=risk*2;
                            std::cout<< "\nPlayer was delt a "<<temp.to_string()<<std::endl;
                            player.setHand2(temp);
                        }

                        if(input == 3)
                        {
                            OH2=true;
                        }
                        player.sethandValue2();
                    }
                    over=true;
                }

            }else{
                std::cout<<"Player Currently Has "<<player.gethandValue()<<std::endl;
                std::cout << "----------"  <<std::endl;
                std::cout << "Hit == 1" << std::endl;
                std::cout << "double == 2" << std::endl;
                std::cout << "Stand == 3" << std::endl;
                std::cin>>input;
            }
            if(splitf==false){
                if(input == 1)
                {
                    temp=D.deal();
                    std::cout<< "\nPlayer was delt a "<<temp.to_string()<<std::endl;
                    player.setHand(temp);
                }

                if(input == 2)
                {
                    std::cout<<"Double\n"<<std::endl;
                    risk=risk*2;
                    std::cout<< "\nPlayer was delt a "<<temp.to_string()<<std::endl;
                    player.setHand(temp);
                }

                if(input == 3)
                {
                    over=true;
                }
                player.sethandValue();
            }
        }
        while(dealer.gethandValue()<=17 && player.gethandValue()<21){
            temp=D.deal();
            std::cout<< "\nDealer was delt a "<<temp.to_string()<<std::endl;
            dealer.setHand(temp);
            dealer.sethandValue();
        }
        //handle who wins and who loses
        if(splitf==false){
            if(player.gethandValue()>21 && dealer.gethandValue()<21){
                std::cout<<"Player Bust"<<std::endl;
                player.setChips(player.getChips()-risk);
            }else if(player.gethandValue()<21 && dealer.gethandValue()>21){
                std::cout<<"Dealer Bust"<<std::endl;
                player.setChips(player.getChips()+risk);
            }
            else if(player.gethandValue()>21 && dealer.gethandValue()>21){
                std::cout<<"Dealer and Player Bust (PUSH)"<<std::endl;
                risk=0;
                player.setChips(player.getChips()+risk);
            }else if(player.gethandValue()<dealer.gethandValue()){
                std::cout<<"Dealer wins"<<std::endl;
                player.setChips(player.getChips()-risk);
            }else if(player.gethandValue()>dealer.gethandValue()){
                std::cout<<"Player wins"<<std::endl;
                player.setChips(player.getChips()+risk);
            }else if(player.gethandValue()==dealer.gethandValue()){
                std::cout<<"PUSH"<<std::endl;
            }
            std::cout<<"Player had "<<player.getHand(false)<<"\n value: "<<player.gethandValue()<<std::endl;
        }else{
            std::cout<<"For hand 1:"<<std::endl;
            if(dealer.gethandValue()>21){
                std::cout<<"Dealer Bust"<<std::endl;
                if(player.gethandValue()>21){
                    std::cout<<"Player Bust hand 1"<<std::endl;
                    handnotHandled1=true;
                }else{
                    player.setChips(player.getChips()+risk);
                    dealer.setChips(dealer.getChips()-risk);
                    handnotHandled1=true;
                }
                if(player.gethandValue2()>21){
                    std::cout<<"For hand 2:"<<std::endl;
                    std::cout<<"Player Bust hand 2"<<std::endl;
                    handnotHandled2=true;
                }else{
                    player.setChips(player.getChips()+risk);
                    dealer.setChips(dealer.getChips()-risk);
                    handnotHandled1=true;
                }
            }else{
                if(handnotHandled1==false){
                    if(player.gethandValue()>21){
                        std::cout<<"Player hand 1 Bust"<<std::endl;
                        player.setChips(player.getChips()-risk);
                        dealer.setChips(dealer.getChips()+risk);
                    }else{      
                        if(player.gethandValue()<dealer.gethandValue()){
                            std::cout<<"Dealer wins hand 1"<<std::endl;
                            player.setChips(player.getChips()-risk);
                            dealer.setChips(dealer.getChips()+risk);
                        }   
                        if(player.gethandValue()>dealer.gethandValue()){
                            std::cout<<"Player wins hand 1"<<std::endl;
                            player.setChips(player.getChips()+risk);
                            dealer.setChips(dealer.getChips()-risk);
                        }
                        if(player.gethandValue()==dealer.gethandValue()){
                            std::cout<<"Hand 1 PUSH"<<std::endl;
                        }
                    }
                }
                if(handnotHandled2==false){
                    std::cout<<"For hand 2:"<<std::endl;
                    if(player.gethandValue2()>21){
                        std::cout<<"Player hand 2 Bust"<<std::endl;
                        player.setChips(player.getChips()-risk);
                        dealer.setChips(dealer.getChips()+risk);
                    }else{      
                        if(player.gethandValue2()<dealer.gethandValue()){
                            std::cout<<"Dealer wins hand 2"<<std::endl;
                            player.setChips(player.getChips()-risk);
                            dealer.setChips(dealer.getChips()+risk);
                        }   
                        if(player.gethandValue2()>dealer.gethandValue()){
                            std::cout<<"Player wins hand 2"<<std::endl;
                            player.setChips(player.getChips()+risk);
                            dealer.setChips(dealer.getChips()-risk);
                        }
                        if(player.gethandValue2()==dealer.gethandValue()){
                            std::cout<<"Hand 2 PUSH"<<std::endl;
                        }
                    }
                }
            }
            std::cout<<"Player had "<<player.getHand(true)<<"\n Hand 1 value: "<<player.gethandValue()<<"\n Hand 2 value: "<<player.gethandValue2()<<std::endl;
        }
        std::cout<<"Dealer had "<<dealer.getHand()<<"\n value: "<<dealer.gethandValue()<<std::endl;
        //reset hands
        player.emptyHand();
        dealer.emptyHand();   
        over=false;
    }
    std::cout<<"Game over Either Player or Dealer ran out of mone"<<std::endl;
}

std::pair<std::vector<card>, std::vector<card>>  game::ruleSplit(Player P){
    std::vector<card> hand1,hand2;
    card temp;
    hand1.push_back(P.getCard(0));
    hand2.push_back(P.getCard(1));
    temp=D.deal();
    std::cout << "Player was dealt a " << temp.to_string() << std::endl; //hand 1 second card
    hand1.push_back(temp);
    temp=D.deal();
    std::cout << "Player was dealt a " << temp.to_string() << std::endl; //hand 2 second card 
    hand2.push_back(temp);
    return std::make_pair(hand1, hand2);
}