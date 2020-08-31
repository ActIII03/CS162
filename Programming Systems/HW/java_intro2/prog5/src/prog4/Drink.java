
//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

public class Drink extends Food{
    //Data fields
    protected String drink;
    protected int size;
    //Default constructor
    Drink(){
        size = 0;
    }
    //Copy constructor
    public Drink(Drink to_copy) {
        quantity = to_copy.quantity;
        delivery = to_copy.delivery;
        //drink = new String(to_copy.drink);
        size = to_copy.size;
    }
    //Display current's data item(s)
    public void display(){
        String drink_size;
        //Check integer to print corresponding string equivalent
        if(size == 1)
            drink_size = new String("Small");
        else if(size == 2)
            drink_size = new String("Medium");
        else
            drink_size = new String("Large");
        //Display current drink
        System.out.print("\nQuantity of items: " + quantity
        + "\nDelivery : " + delivery
        + "\nDrink" + drink
        + "\nSize: " + drink_size);
    }
    //Delete user-picked item
    public boolean delete(Drink to_delete){
        return false;
    }
    //Read in user's input
    public void read_in(){
        String choice = new String();
        System.out.print("How many items do you want?: ");
        quantity = input.nextInt();
        System.out.print("Delivery? (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            delivery = true;
        drink = new String();
        System.out.print("What type of drink do you want?: ");
        drink = input.next();
        System.out.print("Size of drink?(1 = Small, 2 = Medium, 3 = Large: ");
        size = input.nextInt();
    }
}
