#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  int i=0;
  while (i<hand->n_cards)
  {
    print_card(* hand->cards[i]);
    printf(" ");
    i++;
  }  
}

int deck_contains(deck_t * d, card_t c) {
  int contains = 0;
  int i=0;
  while (i<d->n_cards)
  {
    if (d->cards[i]->value == c.value && d->cards[i]->suit == c.suit){
    contains =1;
    }
    else {contains =0;}
  }
 return contains;
}

void shuffle(deck_t * d){
  card_t temp;
  int num_cards = d->n_cards;
  for (int i=0; i<num_cards; i++)
  {
    int r = i + (rand()%(52-i));
    temp.suit = d->cards[i]->suit;
    temp.value = d->cards[i]->value;
    d->cards[i]->suit = d->cards[r]->suit;
    d->cards[i]->value = d->cards[r]->value;
    d->cards[r]->suit = temp.suit;
    d->cards[r]->value = temp.value; 

  }

}

void assert_full_deck(deck_t * d) {
  card_t curr_card;
  for (int i=0; i<52; i++)
  {
    int k=0;
    curr_card = card_from_num(i);
    int find_card = 0;
    while (k<d->n_cards)
    {     
      if (curr_card.value == d->cards[i]->value && curr_card.suit == d->cards[i]->suit) find_card++;
    }
    assert(find_card <=1);
  }
}

int main(void){
  return EXIT_SUCCESS;
}
