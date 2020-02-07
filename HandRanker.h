#include "Hand.h"

#ifndef HANDRANKER_H
#define HANDRANKER_H

class HandRanker{
    public:
        vector<int> rankHand(Hand theHand);
        double compareHands(Hand hand1, Hand hand2);
        bool isFlush(Hand theHand);
        bool isStraight(Hand theHand);
        vector<int> findSets(Hand theHand);
};


#endif /* HANDRANKER_H */