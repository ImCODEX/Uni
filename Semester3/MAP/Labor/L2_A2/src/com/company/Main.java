package com.company;

public class Main {

    public static void main(String[] args) {

        int[] array = new int[]{1,23,41,421,4,90,234,5321,5,124,4124,546456,4,56,1234,2,3,464,356,8,5978};
        Methods m = new Methods();
        System.out.println(m.max_nr(array));
        System.out.println(m.min_nr(array));
        System.out.println(m.max_sum(array));
        System.out.println(m.min_sum(array));
    }
}
