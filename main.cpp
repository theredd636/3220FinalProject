#include "deck.hpp"
int main(void)
{
   deck d;
   d.printDeck();
   puts("");
   d.shuffle(5);
}