package Wetterstation;

import java.util.ArrayList;
import java.util.List;

public class Wetterstation {

    private int[] temperaturen = new int[]{12, 14, 9, 12, 15, 16, 15, 15, 11, 8, 13, 13, 15, 12};

    public double average_week(){
        int sum=0;
        for(int i=0; i < temperaturen.length; i++){
            sum+=temperaturen[i];
        }
        return sum/temperaturen.length;
    }

    public double mintemp(){
        int min  = temperaturen[0];
        for (int i = 1 ; i < temperaturen.length; i++){
            if(temperaturen[i] < min){
                min = temperaturen[i];
            }
        }
        return min;
    }

    public double maxtemp(){
        int max = temperaturen[0];
        for (int i = 1 ; i < temperaturen.length; i++){
            if(temperaturen[i] > max){
                max = temperaturen[i];
            }
        }
        return max;
    }

    public List<int[]> umschwung(){
        List<int[]> ergebniss = new ArrayList<int[]>();
        int maxSchwung = 0;
        int tag = 0, schwung;
        for(int i = 0; i < temperaturen.length-1; i++){
            schwung = Math.abs(temperaturen[i] - temperaturen[i+1]);
            if(schwung > maxSchwung){
                maxSchwung = schwung;
                tag =  i+1;
            }
        }
        for(int i = 0; i < temperaturen.length-1; i++){
            schwung = Math.abs(temperaturen[i] - temperaturen[i+1]);
            if(schwung == maxSchwung)
                ergebniss.add(new int[] {i+1,i+2});
        }
        return ergebniss;

    }
}
