package com.company;

public class Methods {

    /**
     * Computes maximum from a given array
     * @param array: array of numbers
     * @return: maximum
     */
    public int max_nr(int[] array){
        int max = 0;
        for (int j : array)
            if (j > max)
                max = j;
        return max;
    }

    /**
     * Computes minimum from a given array
     * @param array: array of numbers
     * @return: minimum
     */
    public int min_nr(int[] array){
        int min = Integer.MAX_VALUE;
        for (int j : array)
            if (j < min)
                min = j;
        return min;
    }

    /**
     * Computes maximum sum with n-1 elements from a given array
     * @param array: array of numbers
     * @return: maximum sum
     */
    public int max_sum(int[] array){
        int min = min_nr(array), sum=0;
        for (int j : array)
            if (j != min)
                sum += j;

        return sum;
    }

    /**
     * Computes minimum sum with n-1 elements from a given array
     * @param array: array of numbers
     * @return: minimum sum
     */
    public int min_sum(int[] array){
        int max = max_nr(array), sum=0;
        for (int j : array)
            if (j != max)
                sum += j;

        return sum;
    }

}
