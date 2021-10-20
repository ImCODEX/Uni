package com.company;



class Spielkarte {
    private FarbeEnum farbe;
    private String wert;

    public Spielkarte(FarbeEnum farbe, String wert) {
        this.farbe = farbe;
        this.wert = wert;
    }

    public FarbeEnum getFarbe() {
        return farbe;
    }

    public void setFarbe(FarbeEnum farbe) {
        this.farbe = farbe;
    }

    public String getWert() {
        return wert;
    }

    public void setWert(String wert) {
        this.wert = wert;
    }
}