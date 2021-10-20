package teatru;

import java.util.List;

public class HorrorMovie extends Movie{

    public HorrorMovie(String title, int jahr, double rating, List<String> cast, double basePrice) {
        super(title, jahr, rating, cast, basePrice);
    }

    @Override
    public double calculatePrice(){
            return this.getBasePrice()*0.9;

    }
}
