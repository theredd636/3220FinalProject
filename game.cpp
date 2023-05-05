#include "game.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
game::game(){
    D.shuffle(13);
}
void game::blackJack(){
    bool over=false; 
    Player player;
    Dealer dealer;
    int input;
    player.setChips(100);
    dealer.setChips(5000000);
    int risk;
    while (player.getChips()>0 && dealer.getChips()>0)
    {
        //begin blackJack game
        
        
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
                    std::cout<<"hand 1 :"<<player.getHand(false)<<std::endl;
                }

            }else{
                std::cout<<"Player Currently Has "<<player.gethandValue()<<std::endl;
                std::cout << "----------"  <<std::endl;
                std::cout << "Hit == 1" << std::endl;
                std::cout << "double == 2" << std::endl;
                std::cout << "Stand == 3" << std::endl;
                std::cin>>input;
            }
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
        while(dealer.gethandValue()<=17 && player.gethandValue()<21){
            temp=D.deal();
            std::cout<< "\nDealer was delt a "<<temp.to_string()<<std::endl;
            dealer.setHand(temp);
            dealer.sethandValue();
        }
        //handle who wins and who loses
        if(player.gethandValue()>21 && dealer.gethandValue()<21){
            std::cout<<"Player Bust"<<std::endl;
            std::cout<<"Player had "<<player.getHand(true)<<"\n value: "<<player.gethandValue()<<std::endl;
            std::cout<<"Dealer had "<<dealer.getHand()<<"\n value: "<<dealer.gethandValue()<<std::endl;
            player.setChips(player.getChips()-risk);
        }else if(player.gethandValue()<21 && dealer.gethandValue()>21){
            std::cout<<"Dealer Bust"<<std::endl;
            std::cout<<"Player had "<<player.getHand(true)<<"\n value: "<<player.gethandValue()<<std::endl;
            std::cout<<"Dealer had "<<dealer.getHand()<<"\n value: "<<dealer.gethandValue()<<std::endl;
            player.setChips(player.getChips()+risk);
        }
        else if(player.gethandValue()>21 && dealer.gethandValue()>21){
            std::cout<<"Dealer and Player Bust (PUSH)"<<std::endl;
            std::cout<<"Player had "<<player.getHand(true)<<"\n value: "<<player.gethandValue()<<std::endl;
            std::cout<<"Dealer had "<<dealer.getHand()<<"\n value: "<<dealer.gethandValue()<<std::endl;
            risk=0;
            player.setChips(player.getChips()+risk);
        }else if(player.gethandValue()<dealer.gethandValue()){
            std::cout<<"Dealer wins"<<std::endl;
            std::cout<<"Player had "<<player.getHand(true)<<"\n value: "<<player.gethandValue()<<std::endl;
            std::cout<<"Dealer had "<<dealer.getHand()<<"\n value: "<<dealer.gethandValue()<<std::endl;
            player.setChips(player.getChips()-risk);
        }else if(player.gethandValue()>dealer.gethandValue()){
            std::cout<<"Player wins"<<std::endl;
            std::cout<<"Player had "<<player.getHand(true)<<"\n value: "<<player.gethandValue()<<std::endl;
            std::cout<<"Dealer had "<<dealer.getHand()<<"\n value: "<<dealer.gethandValue()<<std::endl;
            player.setChips(player.getChips()+risk);
        }
        //reset hands
        player.emptyHand();
        dealer.emptyHand();   
        over=false;
    }
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