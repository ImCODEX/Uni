package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Zeitschriften demonSlayer = new Zeitschriften("Demon Slayer", 120, new ArrayList<>(), "Volume 1");

        Abonnent ana = new Abonnent("Ana Pop", 200, demonSlayer);
        Abonnent dana = new Abonnent("Dana Pop", 200, demonSlayer);

        demonSlayer.newIssue("Volume 2");

        ana.printSum();
        dana.printSum();
    }
}
