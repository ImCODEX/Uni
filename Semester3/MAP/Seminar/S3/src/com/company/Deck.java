package com.company;

import java.util.Iterator;
import java.util.List;

public class Deck implements Iterable<Spielkarte>{
    private List<Spielkarte> card_deck;

    public Deck(List<Spielkarte> card_deck) {
        this.card_deck = card_deck;
    }

    public List<Spielkarte> getCard_deck() {
        return card_deck;
    }

    public void setCard_deck(List<Spielkarte> card_deck) {
        this.card_deck = card_deck;
    }

    @Override
    public Iterator<Spielkarte> iterator() {
        return new Deckiterator(this);
    }
}
