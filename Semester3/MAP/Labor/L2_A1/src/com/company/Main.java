package com.company;

import Execute.Methods;

public class Main {

    public static void main(String[] args) {
        Methods m = new Methods();
        int[] array_of_notes = new int[]{10, 14, 23, 25, 38, 41, 43, 47, 56, 30, 63, 66, 68, 74, 78, 86, 89, 90, 92, 95, 98};

        //Test for round_up(int[]) method
        System.out.println(java.util.Arrays.toString(m.round_up(array_of_notes)));

        //Test for not_sufficient(int[]) method
        System.out.println(java.util.Arrays.toString(m.not_sufficient(array_of_notes)));

        //Test for average(int[]) method
        System.out.println(m.average(array_of_notes));

        //Test for max_rounded_up(int[]) method
        System.out.println(m.max_rounded_up(array_of_notes));

    }
}
