#include "HandRanker.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    double total = 0.0;
    int numTimes = 1000;
    HandRanker handRanker;
    for(int i = 0; i < numTimes; i++){
//        Card card1 = Card(1, 1);
//        Card card2 = Card(1, 2);
//        Card card3 = Card(2, 2);
//        vector<int> remainingCardNums = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13};
        Card card11 = Card(9, 2);
        Card card21 = Card(10, 2);
        Card card31 = Card(11, 2);
        Card card41 = Card(12, 2);
        Card card51 = Card(13, 2);
        
        Card card12 = Card(2, 1);
        Card card22 = Card(3, 1);
        Card card32 = Card(4, 1);
        Card card42 = Card(5, 1);
        Card card52 = Card(6, 1);
        
//        vector<int> remainingCardNums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13, 13};
//        int randCard1 = rand() % 49;
//        int randCard2 = randCard1;
//        while (randCard2 != randCard1){
//            randCard2 = rand() % 49;
//        }
//        int randCard3 = randCard1;
//        while (randCard3 != randCard1 and randCard3 != randCard2){
//            randCard3 = rand() % 49;
//        }
//        randCard1 = remainingCardNums[randCard1];
//        randCard2 = remainingCardNums[randCard2];
//        randCard3 = remainingCardNums[randCard3];
//        Card card6 = Card(randCard1, 1);
//        Card card7 = Card(randCard2, 2);
//        Card card8 = Card(randCard3, 3);
        
        Hand hand1 = Hand(card11, card21, card31, card41, card51);
        Hand hand2 = Hand(card12, card22, card32, card42, card52);
        
        total = total + handRanker.compareHands(hand1, hand2);
    }
    double holdThreeWinPerc = total / numTimes * 100;
    cout<< holdThreeWinPerc << endl;
    
//    Card card10 = Card(1, 2);
//    Card card11 = Card(2, 2);
//    Card card12 = Card(2, 2);
//    Card card13 = Card(2, 2);
//    Card card14 = Card(2, 1);
//    Hand hand3 = Hand(card10, card11, card12, card13, card14);
//    cout << handRanker.isStraight(hand3) << endl;
//    cout << handRanker.isFlush(hand3) << endl;
//    cout << handRanker.pairThreeFour(hand3) << endl;
    
}

