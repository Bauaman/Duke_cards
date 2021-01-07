#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS); 
}

const char * ranking_to_string(hand_ranking_t r) {
  
  switch (r)
    {
    case STRAIGHT_FLUSH:
      return "STRAIGHT_FLUSH";
      break;
    case STRAIGHT:
      return "STRAIGHT";
      break;
    case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND";
      break;
    case FULL_HOUSE:
      return "FULL_HOUSE";
      break;
    case FLUSH:
      return "FLUSH";
      break;
    case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
      break;
    case TWO_PAIR:
      return "TWO_PAIR";
      break;
    case PAIR:
      return "PAIR";
      break;
    case NOTHING:
      return "NOTHING";
      break;
    default:
      break;
    }
   return "";
}

char value_letter(card_t c) {
  int x = 0;
  assert_card_valid(c);
  switch(c.value)
    {
    case 0:
      x=48;
      break;
      
    case 10:
      x=48;
      break;
    case 11:
      x=74;
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
  if (c.value >=2 && c.value < 10)
    {
      x= 48 + c.value;
    }
  return (char)x;
}


char suit_letter(card_t c) {
  assert_card_valid(c);
  char x;
  switch(c.suit)
    {
    case SPADES:
      x = 's';
      break;
    case HEARTS:
      x = 'h';
      break;
    case DIAMONDS:
      x = 'd';
      break;
    case CLUBS:
      x = 'c';
      break;
    default:
      break;
    }
  return x;
}

void print_card(card_t c) {
  // std::cout << value_letter(c) << suit_letter(c);
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  int i_value_let = value_let - '0';
  assert(suit_let == 's' || suit_let == 'd' || suit_let == 'h' || suit_let == 'c');
  assert((value_let >= '0' && value_let <= '9') || (value_let == 'A' || value_let == 'K' || value_let == 'Q' || value_let == 'J'));
  switch(suit_let)
    {
    case 's':
      temp.suit = SPADES;
      break;
    case 'h':
      temp.suit = HEARTS;
      break;
    case 'd':
      temp.suit = DIAMONDS;
      break;
    case 'c':
      temp.suit = CLUBS;
      break;
    default:
      break;
    }
  if (value_let > '0' && value_let <='9')
    {
      temp.value = i_value_let;
    }
  else
    {
      switch(value_let)
	{
	case '0':
	  temp.value = 10;
	  break;
	case 'A':
	  temp.value = 14;
	  break;
	case 'K':
	  temp.value = 13;
	  break;
	case 'Q':
	  temp.value = 12;
	  break;
	case 'J':
	  temp.value = 11;
	  break;
	default:
	  break;
	}
    }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c%13;
  if (temp.value >=1 && temp.value < 9) temp.value = temp.value + 1;
  else if (temp.value >= 9) temp.value = temp.value+2;
  //else if (temp.value == 10) temp.value = VALUE_QUEEN;
  //else if (temp.value == 12) temp.value = VALUE_KING;
  //else if (temp.value == 13) temp.value = VALUE_ACE;
  switch(c/13)
    {
    case 0:
      temp.suit = SPADES;
      break;
    case 1:
      temp.suit = HEARTS;
      break;
    case 2:
      temp.suit = DIAMONDS;
      break;
    case 3:
      temp.suit = CLUBS;
      break;
    default:
      break;
    }
  return temp;
}
