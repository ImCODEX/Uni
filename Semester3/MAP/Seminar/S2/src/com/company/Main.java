package com.company;
import teatru.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Date;


public class Main {

    public static void main(String[] args) {

        List<String> matrixCast = new ArrayList<>();
        List<String> Castublanao = new ArrayList<>();
        matrixCast.add("Keanu Reeves");
        Castublanao.add("Adam Sandler");
        Movie sfmovie = new SciFiMovie("The Matrix", 1998, 8.9, matrixCast, 20);
        HorrorMovie hormovie = new HorrorMovie("The nun", 2020, 6.0, matrixCast, 5);
        assert(sfmovie.getBasePrice() == 20);
        System.out.println("da frate e bn pana aici");
        assert(hormovie.calculatePrice() == 5);
        System.out.println("da frate e bn pana aici");
        ComedyMovie cmmovie = new ComedyMovie("Mr. Deeds", 2002, 5.0, Castublanao, 10);
        assert(cmmovie.getBasePrice() == 5);
        System.out.println("da frate e bn pana aici");

        user user1 = new user("Ioan", "Doe", null);
        OrderLine orderLine1 = new OrderLine(sfmovie, 3);
        OrderLine orderLine2 = new OrderLine(hormovie, 5);
        List<OrderLine> orderLines = new ArrayList<>(
                Arrays.asList(orderLine1, orderLine2)
        );
        Order o = new Order(new Date(), orderLines);
        user1.setOrders(new ArrayList<>(
                Arrays.asList(o)
        ));
        System.out.println(user1.calculateTotalPriceForAllOrders());


    }

}


