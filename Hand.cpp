#include "Hand.h"
#include <iostream>
Hand::Hand(Card card1, Card card2, Card card3, Card card4, Card card5){
    vector<Card> hand = {card1, card2, card3, card4, card5};
    for(int i = 0; i < 4; i++){
        int lowest = 0;
        for(int j = 1; j < hand.size(); j++){
            if (hand[j].num < hand[lowest].num){
                lowest = j;
            }
            else if(hand[j].num == hand[lowest].num){
                if (hand[j].sut < hand[lowest].sut){
                    lowest = j;
                }
            }
        }
        cards.push_back(hand[lowest]);
        hand.erase(hand.begin() + lowest);
    }
    cards.push_back(hand[0]);
}
