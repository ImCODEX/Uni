package com.company;

import java.util.List;

public class Abonnent implements Observer{
    private String name;
    private int geldSumme;
    private Zeitschriften zeitschrift;

    public Abonnent(String name, int geldSumme, Zeitschriften zeitschrift) {
        this.name = name;
        this.geldSumme = geldSumme;
        this.zeitschrift = zeitschrift;
        zeitschrift.attach(this);
    }

    @Override
    public void update() {
        if(geldSumme < zeitschrift.getPreis())
            zeitschrift.detach(this);
        else
            geldSumme -= zeitschrift.getPreis();
    }

    public void printSum() {
        System.out.println(name + " has " + geldSumme + " Geld");
    }
}
