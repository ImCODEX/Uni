package teatru;

import java.util.List;

public class user {
    private String firstName, lastName;
    private List<Order> orders;

    public user(String firstName, String lastName, List<Order> orders) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.orders = orders;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public List<Order> getOrders() {
        return orders;
    }

    public void setOrders(List<Order> orders) {
        this.orders = orders;
    }

    public double calculateTotalPriceForOrder(Order order){
        return order.calculateTotalPrice();

    }

    public double calculateTotalPriceForAllOrders(){
        double sume = 0;
        for(Order o : orders){
            sume += o.calculateTotalPrice();
        }
        return sume;
    }
}
