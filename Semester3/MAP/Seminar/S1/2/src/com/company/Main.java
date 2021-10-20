package com.company;

import Wetterstation.Wetterstation;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Wetterstation w = new Wetterstation();
        System.out.println(w.average_week());

        List<int[]> schwung = w.umschwung();
        for(int i = 0; i <  schwung.size(); i++){
            System.out.println(schwung.get(i)[0]);
            System.out.println(schwung.get(i)[1]);
        }
    }
}
