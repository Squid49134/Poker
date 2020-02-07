#include "Card.h"

Card::Card(int number, int suit){
    num = number;
    sut = suit;
    val = 4*number + suit;
}

