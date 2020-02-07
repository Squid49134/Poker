#include <vector>
#include "Card.h"

using namespace std;

#ifndef HAND_H
#define HAND_H

class Hand{
    public:
        vector<Card> cards;
        Hand(Card card1, Card card2, Card card3, Card card4, Card card5);
};

#endif /* HAND_H */
