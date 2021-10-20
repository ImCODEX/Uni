package com.company;

public class Main {

    public static void main(String[] args) {
        Methods m = new Methods();
        int[] kb_prices = new int[]{40, 35, 70, 15, 45};
        int[] usb_prices = new int[]{20, 15, 40, 15};

        System.out.println(m.min_kb(kb_prices));
        System.out.println(m.max_price(kb_prices,usb_prices));
        System.out.println(m.max_by_budget(usb_prices, 30));
        System.out.println(m.max_consumerism(new int[]{55, 70, 80}, new int[]{5, 12}, 60));
        System.out.println(m.max_consumerism(new int[]{60}, new int[]{8, 12}, 60));
        System.out.println(m.max_consumerism(new int[]{40, 60}, new int[]{8, 12}, 60));
    }
}
