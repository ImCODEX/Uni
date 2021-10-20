package Mathe;

public class MatheAufgabe {
    public static double add(double x, double y){
        return x+y;
    }

    public double sub(double x, double y){
        return add(x,-y);
    }

    public static boolean isPerfect(int n){
        int ct = 0;
        for(int i = 1; i <= n/2; i++){
            if (n%i == 0)
                ct+=i;
        }
        if(ct == n)
            return true;
        return false;
    }

    public static double mul(double x, double y){
        double sum=0;
        for(double i = 1 ; i <= x ; i++)
            sum = add(sum, y);
        return sum;
    }
}
