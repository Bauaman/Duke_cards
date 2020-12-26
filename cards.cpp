#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "cards.h"

void assert_card_valid(card_t c)
{
    assert(c.value >= 2 && c.value <= VALUE_ACE);
    assert(c.suit >= SPADES && c.suit <= CLUBS);
}
const char *ranking_to_string(hand_ranking_t r)
{
    char *hand_r;
    switch (r)
    {
    case STRAIGHT_FLUSH:
        hand_r = "straight flush";
        break;
    case STRAIGHT:
        hand_r = "straight";
        break;
    case FOUR_OF_A_KIND:
        hand_r = "four of a kind";
        break;
    case FULL_HOUSE:
        hand_r = "full house";
        break;
    case FLUSH:
        hand_r = "flush";
        break;
    case THREE_OF_A_KIND:
        hand_r = "three of a kind";
        break;
    case TWO_PAIR:
        hand_r = "two pairs";
        break;
    case PAIR:
        hand_r = "pair";
        break;
    case NOTHING:
        hand_r = "nothing";
        break;
    default:
        break;
    }
return hand_r;
}

char value_letter(card_t c)
{
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
        x = 81;
        break;
    case 13:
        x = 75;
        break;
    case 14:
        x = 65;
        break;
    default:
        break;
    }
    if (c.value >= 2 && c.value < 10)
    {
        x = 48 + c.value;
    }
    return x;
}

char suit_letter(card_t c)
{
    assert_card_valid(c);
    switch (c.suit)
    {
    case SPADES:
        return 's';
        break;
    case HEARTS:
        return 'h';
        break;
    case DIAMONDS:
        return 'd';
        break;
    case CLUBS:
        return 'c';
        break;
    default:
        return '?';
        break;
    }
}

void print_card(card_t c)
{
    std::cout << value_letter(c) << suit_letter(c);
}

card_t card_from_num(unsigned c)
{
    card_t card;
    card.value = c % 13;
    switch (c / 13)
    {
    case 0:
        card.suit = SPADES;
        break;
    case 1:
        card.suit = HEARTS;
        break;
    case 2:
        card.suit = DIAMONDS;
        break;
    case 3:
        card.suit = CLUBS;
    default:
        break;
    }
    return card;
}

card_t card_from_letters(char value_let, char suit_let)
{
    card_t c;
    int i_value_let = value_let - '0';
    assert(suit_let == 's' xor suit_let == 'h' xor suit_let == 'd' xor suit_let == 'c');
    assert(i_value_let >= 2 && i_value_let <= 10 && i_value_let != 1);
    assert(value_let == 'A' xor value_let == 'J' xor value_let == 'Q' xor value_let == 'K');

    switch (suit_let)
    {
    case 's':
        c.suit = SPADES;
        break;
    case 'h':
        c.suit = HEARTS;
        break;
    case 'd':
        c.suit = DIAMONDS;
        break;
    case 'c':
        c.suit = CLUBS;
        break;
    default:
        break;
    }
    if (i_value_let >= 0 && i_value_let <= 10)
    {
        c.value = i_value_let;
    }
    else
    {
        switch (value_let)
        {
        case 'A':
            c.value = 14;
            break;
        case 'K':
            c.value = 13;
            break;
        case 'Q':
            c.value = 12;
            break;
        case 'J':
            c.value = 11;
            break;
        default:
            break;
        }
    }
    return c;
}

int main()
{

    card_t card;
    card.value = 14;
    card.suit = CLUBS;
    print_card(card);
    return 0;
}