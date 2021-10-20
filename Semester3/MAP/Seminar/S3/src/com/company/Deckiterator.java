package com.company;

import java.util.Iterator;

public class Deckiterator implements Iterator<Spielkarte> {
    private Deck deck;
    private int cursor;

    public Deckiterator(Deck deck) {
        this.deck = deck;
        this.cursor = 0;
    }

    @Override
    public boolean hasNext() {
        if(this.cursor >= this.deck.getCard_deck().size())
            return false;
        return true;
    }

    @Override
    public Spielkarte next() {
        if(hasNext()){
            Spielkarte next_card = this.deck.getCard_deck().get(this.cursor);
            this.cursor+=1;
            return next_card;
        }
        return null;
    }
}
