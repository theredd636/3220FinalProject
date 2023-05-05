#include "game.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
game::game(){
    D.shuffle(1);
}
void game::blackJack(){ 
    Player player;
    Dealer dealer;
    int input;
    player.setChips(100);
    dealer.setChips(5000000);
    //while (player.getChips()!=0 && dealer.getChips()!=0)
    {
        /* code */
    }
    
    if(D.getPosition() > 40)
    {
        std::cout << "***********************************" <<std::endl;
        std::cout << "Shuffle" << std::endl;
        std::cout << "***********************************" << std::endl;

    }

    card temp = D.deal();
    std::cout << "The Player was dealt a " << temp.to_string() << std::endl; // players first card
    player.setHand(temp);
    temp = D.deal();
    std::cout << "The Dealer was dealt a " << temp.to_string() <<std::endl; // dealers first card
    dealer.setHand(temp);

    temp = D.deal();
    std::cout << "The Player was dealt a " << temp.to_string() << std::endl; // players second card
    player.setHand(temp);
    temp = D.deal();
    dealer.setHand(temp);
    if(dealer.gethandValue()  == 21)
    {
        std::cout << "Dealer has BlackJack " <<std:: endl;
        player.setChips(player.getChips()-1);
        dealer.setChips(dealer.getChips()+1);
    }else if(player.gethandValue() == 21)
    {
        std::cout << "PLAYER BLACKJACK\n blackjack pays 3:2" <<std:: endl;
        player.setChips(player.getChips()*2.5);
        dealer.setChips(dealer.getChips()/2.5);
    }else if((player.gethandValue() == 21) && (dealer.gethandValue() ) == 21)
    {
        std::cout << "Player and Dealer have blackjack push" <<std::endl;
    }


    if(player.getCard(0).getValue() == player.getCard(1).getValue()){
        input = 0;
        while(input == 0){
        std::cout << "----------" <<std:: endl;
        std::cout << "Hit == 1" << std::endl;
        std::cout << "Split == 2" << std::endl;
        std::cout << "double == 3" << std::endl;
        std::cout << "Stand == 4" << std::endl;
        std::cin >> input;
        }
        if(input == 2)
        {
            //write code to split hand
        }

    }else{
        std::cout << "----------"  <<std::endl;
        std::cout << "Hit == 1" << std::endl;
        std::cout << "double == 2" << std::endl;
        std::cout << "Stand == 3" << std::endl;
        std::cin>>input;
    }
    if(input == 1)
    {
        
    }

    if(input == 2)
    {
        
    }

    if(input == 3)
    {
       
    }
}