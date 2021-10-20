package com.company;

import java.util.List;

public class Zeitschriften implements Subject{
    private String name;
    private int preis;
    private List<Abonnent> subscriber_list;
    private String currentissue;

    public Zeitschriften(String name, int preis, List<Abonnent> subscriber_list, String currentissue) {
        this.name = name;
        this.preis = preis;
        this.subscriber_list = subscriber_list;
        this.currentissue = currentissue;
    }

    public String getName() {
        return name;
    }

    public int getPreis() {
        return preis;
    }

    public String getCurrentissue() {
        return currentissue;
    }

    public void newIssue(String futureIssue){
        currentissue = futureIssue;
        notifyAlles();
    }


    @Override
    public void attach(Observer obs) {
        subscriber_list.add((Abonnent) obs);
    }

    @Override
    public void detach(Observer obs) {
        subscriber_list.remove((Abonnent) obs);
    }

    @Override
    public void notifyAlles() {
        for (Abonnent abo : subscriber_list){
            abo.update();
        }

    }
}

