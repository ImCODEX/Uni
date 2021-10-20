package com.company;

import java.util.List;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	Spielkarte card1 = new Spielkarte(FarbeEnum.HERZ, "5");
    Spielkarte card2 = new Spielkarte(FarbeEnum.KREUZ, "J");
        List<Spielkarte> card_deck = new ArrayList<>();
        card_deck.add(card1);
        card_deck.add(card2);
        Deck my_deck = new Deck(card_deck);
        for(Spielkarte c : my_deck){
           System.out.println("hallo "+ c.getFarbe());
        }
    }
}
