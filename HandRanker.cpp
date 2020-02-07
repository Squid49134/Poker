#include "HandRanker.h"
#include <iostream>

/*
 10. Royal Flush
 9.  Straight Flush
 8.  Four of a Kind
 7.  Full House
 6.  Flush
 5.  Straight
 4.  Three of a Kind
 3.  Two Pair
 2.  Pair
 1.  High Card
 */

vector<int> HandRanker::rankHand(Hand theHand){
    vector<int> handData = findSets(theHand);
    if (handData[0] == 1){
        bool straight = isStraight(theHand);
        bool flush = isFlush(theHand);
        if(flush){
            if(straight){
                if(theHand.cards[4].num == 13){
                    handData[0] = 10;
                }
                else{
                    handData[0] = 9;
                }
            }
            else{
                handData[0] = 6;
            }
        }
        else if(straight){
            handData[0] = 5;
        }
    }
    return handData;
}

double HandRanker::compareHands(Hand hand1, Hand hand2){
    vector<int> rank1 = rankHand(hand1);
    vector<int> rank2 = rankHand(hand2);
    if(rank1[0] > rank2[0]){
        return 1.0;
    }
    else if(rank2[0] > rank1[0]){
        return 0.0;
    }
    else{
        if(rank1[1] > rank2[1]){
            return 1.0;
        }
        else if(rank2[1] > rank1[1]){
            return 0.0;
        }
        else{
            if(rank1[2] > rank2[2]){
                return 1.0;
            }
            else if(rank2[2] > rank1[2]){
                return 0.0;
            }
            else{
                for(int i = 4; i > -1; i--){
                    if(hand1.cards[i].num > hand2.cards[i].num){
                        return 1.0;
                    }
                    else if(hand2.cards[i].num > hand1.cards[i].num){
                        return 0.0;
                    }
                }
                return .5;
            }
        }
    }
}

bool HandRanker::isFlush(Hand theHand){
    if(theHand.cards[0].sut == theHand.cards[1].sut and theHand.cards[0].sut == theHand.cards[2].sut 
            and theHand.cards[0].sut == theHand.cards[3].sut and theHand.cards[0].sut == theHand.cards[4].sut){
        return true;
    }
    else{
        return false;
    }
}

bool HandRanker::isStraight(Hand theHand){
    if(theHand.cards[0].num == 1){
        int breakInd = 1;
        while(theHand.cards[breakInd].num == theHand.cards[breakInd - 1].num + 1){
            breakInd++;
        }
        if(breakInd == 5){
            return true;
        }
        else{
            int checkInd = breakInd + 1;
            while(checkInd < 5 and theHand.cards[checkInd].num == theHand.cards[checkInd - 1].num + 1){
                checkInd++;
            }
            if(checkInd == 5 and theHand.cards[4].num == 13){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        if(theHand.cards[4].num == theHand.cards[3].num + 1 and theHand.cards[3].num == theHand.cards[2].num + 1 
            and theHand.cards[2].num == theHand.cards[1].num + 1 and theHand.cards[1].num == theHand.cards[0].num + 1){
        return true;
        }
        else{
            return false;
        }
    }
}

vector<int> HandRanker::findSets(Hand theHand){
    vector<int> setData = {0, 0, 0};
    if(theHand.cards[0].num == theHand.cards[1].num){
        if(theHand.cards[0].num == theHand.cards[2].num){
            if(theHand.cards[0].num == theHand.cards[3].num){
                setData[0] = 8;
                setData[1] = theHand.cards[0].num;
            }
            else if(theHand.cards[3].num == theHand.cards[4].num){
                setData[0] = 7;
                setData[1] = theHand.cards[0].num;
                setData[2] = theHand.cards[4].num;
            }
            else{
                setData[0] = 4;
                setData[1] = theHand.cards[0].num;
            }
            
        }
        else if(theHand.cards[2].num == theHand.cards[3].num){
            if(theHand.cards[2].num == theHand.cards[4].num){
                setData[0] = 7;
                setData[1] = theHand.cards[4].num;
                setData[2] = theHand.cards[0].num;
            }
            else{
                setData[0] = 3;
                if(theHand.cards[0].num > theHand.cards[3].num){
                    setData[1] = theHand.cards[0].num;
                    setData[1] = theHand.cards[3].num;
                }
                else{
                    setData[1] = theHand.cards[3].num;
                    setData[1] = theHand.cards[0].num;
                }
            }
        }
        else if(theHand.cards[3].num == theHand.cards[4].num){
            setData[0] = 3;
            if(theHand.cards[0].num > theHand.cards[4].num){
                setData[1] = theHand.cards[0].num;
                setData[1] = theHand.cards[4].num;
            }
            else{
                setData[1] = theHand.cards[4].num;
                setData[1] = theHand.cards[0].num;
            }
        }
        else{
            setData[0] = 2;
            setData[1] = theHand.cards[0].num;
        }
    }
    else if(theHand.cards[1].num == theHand.cards[2].num){
        if(theHand.cards[1].num == theHand.cards[3].num){
            if(theHand.cards[1].num == theHand.cards[4].num){
                setData[0] = 8;
                setData[1] = theHand.cards[1].num;
            }
            else{
                setData[0] = 4;
                setData[1] = theHand.cards[1].num;
            }
        }
        else if(theHand.cards[3].num == theHand.cards[4].num){
            setData[0] = 3;
            if(theHand.cards[1].num > theHand.cards[4].num){
                setData[1] = theHand.cards[1].num;
                setData[1] = theHand.cards[4].num;
            }
            else{
                setData[1] = theHand.cards[4].num;
                setData[1] = theHand.cards[1].num;
            }
        }
        else{
            setData[0] = 2;
            setData[1] = theHand.cards[1].num;
        }
    }
    else if(theHand.cards[2].num == theHand.cards[3].num){
        if(theHand.cards[2].num == theHand.cards[4].num){
            setData[0] = 4;
            setData[1] = theHand.cards[2].num;
        }
        else{
            setData[0] = 2;
            setData[1] = theHand.cards[2].num;
        }
    }
    else if(theHand.cards[3].num == theHand.cards[4].num){
        setData[0] = 2;
        setData[1] = theHand.cards[3].num;
    }
    else{
        setData[0] = 1;
    }
    return setData;
}
