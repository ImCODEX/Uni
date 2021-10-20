package com.company;

public class Methods {

    /**
     *
     * @param kb: array of prices
     * @return: min value
     */
    public int min_kb(int[] kb){
        int min = Integer.MAX_VALUE;
        for (int j : kb) {
            if (j < min)
                min = j;
        }
        return min;
    }

    /**
     * Maximum of two arrays
     * @param kb: keyboard prices
     * @param usb: usb prices
     * @return: maximum price
     */
    public int max_price(int[] kb, int[] usb){
        int max = 0;
        for (int j : kb) {
            if (j > max)
                max = j;
        }

        for (int j : usb) {
            if (j > max)
                max = j;
        }

        return max;
    }

    /**
     * Maximum with upper limit
     * @param usb: list of prices
     * @param budget: int aka upper limit
     * @return: max
     */
    public int max_by_budget(int[] usb, int budget){
        int max = 0;
        for (int j : usb) {
            if (j > max && j <= budget)
                max = j;
        }
        return max;
    }

    /**
     * Maximum with upper limit but with two arrays
     * @param kb: list of prices
     * @param usb: list of prices
     * @param budget: int aka upper limit
     * @return: max
     */
    public int max_consumerism(int[] kb, int[] usb, int budget){
        int max = -1;
        for(int i : kb){
            for(int j : usb){
                if(i + j <= budget && i + j > max)
                    max = i + j;
            }
        }
        return max;
    }

}
