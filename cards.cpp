#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "cards.h"

void assert_card_valid(card_t c){
    assert (c.value >= 2 && c.value<=VALUE_ACE);
    assert (c.suit >= SPADES && c.suit <= CLUBS);
}

char value_letter (card_t c){
    int x = 0;
    assert_card_valid(c);
    switch (c.value)
    {
    case 10:
        x = 0;
        break;
    case 11:
        x = 74;
        break;
    case 12:
        x=81;
        break;
    case 13:
        x=75;
        break;
    case 14:
        x=65;
        break;
    default:
        break;
    }
    if (c.value>=2 && c.value<10){
        x = 48 + c.value;
    }
    return x;
}

int main(){
    
    card_t card;
    card.value = 14;
    card.suit = CLUBS;
    char card_value_text = value_letter(card);
    std::cout << card_value_text << " / " << card.suit << std::endl;

    return 0;
}