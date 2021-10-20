package teatru;

public class OrderLine {

    private Movie movie;
    private int quantity;

    public OrderLine(Movie movie, int quantity) {
        this.movie = movie;
        this.quantity = quantity;
    }

    public Movie getMovie() {
        return movie;
    }

    public void setMovie(Movie movie) {
        this.movie = movie;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public double calculatePrice(){
        return this.quantity*this.movie.calculatePrice();
    }
}
