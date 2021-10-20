package com.company;

public class Methods {

    /**
     * Sum between two arrays with the same length
     * treated as a decimal representation of a number
     * @param zahl1: number represented on array
     * @param zahl2: number represented on array
     * @return: sum of zahl1 and zahl2
     */
    public int[] add(int[] zahl1, int[] zahl2) {
        int[] sum = new int[zahl1.length + 1];
        //create sum array with len+1 in case of overflow
        for (int i = zahl1.length - 1; i >= 0; i--) {
            //sum, overflow treated
            sum[i + 1] += zahl1[i] + zahl2[i];
            if (sum[i + 1] > 9) {
                sum[i]++;
                sum[i + 1] -= 10;
            }
        }
        //in case of no overflow, remove first 0
        if (sum[0] == 0) {
            int[] new_sum = new int[zahl1.length];
            System.arraycopy(sum, 1, new_sum, 0, sum.length - 1);
            return new_sum;
        }
        return sum;
    }

    /**
     * Difference between two arrays with the same length
     * treated as a decimal representation of a number
     * with most significant digit a negative number if the
     * difference is negative
     * @param zahl1: number represented on array
     * @param zahl2: number represented on array
     * @return: difference of zahl1 and zahl2
     */
    public int[] diff(int[] zahl1, int[] zahl2) {
        int[] diff = new int[zahl1.length];
        //create  diff array
        for (int i = zahl1.length - 1; i > 0; i--) {
            //underflow treated by adding 10 to negative difference
            //and decrementing higher digit
            diff[i] += zahl1[i] - zahl2[i];
            if (diff[i] < 0) {
                diff[i] += 10;
                diff[i - 1] -= 1;
            }
        }
        //avoiding index out of range error
        diff[0] += zahl1[0] - zahl2[0];
        //underflow case treated
        if (diff[0] == 0) {
            int[] new_diff = new int[zahl1.length - 1];
            System.arraycopy(diff, 1, new_diff, 0, diff.length - 1);
            return new_diff;
        }
        return diff;
    }

    /**
     * Multiply between an array treated as a decimal
     * representation of a number and a digit
     * @param zahl: number represented on array
     * @param ziffer: integer digit
     * @return: Multiply of zahl and ziffer
     */
    public int[] mul(int[] zahl, int ziffer) {
        int[] mul = new int[zahl.length + 1];
        //create mul array with size + 1 in case of overflow
        for (int i = zahl.length - 1; i >= 0; i--) {
            //multiply with digit
            mul[i + 1] += zahl[i] * ziffer;
            //add overflow
            mul[i] += mul[i + 1] / 10;
            mul[i + 1] %= 10;
        }

        //if not overflow remove first digit
        if (mul[0] == 0) {
            int[] new_mul = new int[zahl.length];
            System.arraycopy(mul, 1, new_mul, 0, mul.length - 1);
            return new_mul;
        }
        return mul;
    }

    /**
     * division between an array treated as a decimal
     * representation of a number and a digit
     * @param zahl: number represented on array
     * @param ziffer: integer digit
     * @return: division of zahl and ziffer
     */
    public int[] div(int[] zahl, int ziffer) {
        int[] div = new int[zahl.length];
        //create div array
        int i = 0, j = 0, buff = 0;
        //case if most significant digit is not dividable by ziffer
        //sets most significant digit from div array to 0
        if (zahl[0] / ziffer == 0){
            j++;
        }
        //divide
        while (i < zahl.length) {
            buff = buff * 10 + zahl[i];
            if (buff / ziffer != 0) {
                div[j] = buff / ziffer;
                j++;
                buff %= ziffer;
            }

            i++;
        }

        //remove first digit in case of not overflow
        if (div[0] == 0) {
            int[] new_div = new int[zahl.length - 1];
            System.arraycopy(div, 1, new_div, 0, div.length - 1);
            return new_div;
        }
        return div;
    }


}
