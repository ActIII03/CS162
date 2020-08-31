//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

public class Burger extends Food{
    //Data fields
    protected int patties;
    protected boolean cheese;
    protected boolean pickles;
    protected boolean lettuce;
    protected boolean onions;
    //Default constructor
    Burger() {
        patties = 0;
        cheese = true;
        pickles = true;
        lettuce = true;
        onions = true;
    }
    //User supplied constructor
    public Burger(int num_patties) {
        patties = num_patties;
        cheese = true;
        pickles = true;
        lettuce = true;
        onions = true;
    }
    //Copy constructor
    public Burger(Burger to_copy) {
        quantity = to_copy.quantity;
        delivery = to_copy.delivery;
        patties = to_copy.patties;
        cheese = to_copy.cheese;
        pickles = to_copy.pickles;
        lettuce = to_copy.lettuce;
        onions = to_copy.onions;
    }
    public void display(){
        System.out.print("\nQuantity of items: " + quantity
        + "\nDelivery : " + delivery
        + "\nNumber of patties: " + patties
        + "\nCheese: " + cheese
        + "\nPickles: " + pickles
        + "\nLettuce: " + lettuce
        + "\nOnions: " + onions + "\n");
    }
    //Delete user-picked item
    public boolean delete(Burger to_delete){
        return false;
    }
    //Read in user's input for burger order
    public void read_in(){
        String choice = new String();
        System.out.print("How many items do you want?: ");
        quantity = input.nextInt();
        System.out.print("Delivery? (Y/N): ");
        choice = input.next();
        input.nextLine();
        choice.toUpperCase();
        if(choice.equals("Y"))
            delivery = true;
        System.out.print("How many patties do you want?(1 - 3): ");
        patties = input.nextInt();
        input.nextLine();
        System.out.print("Cheese (Y/N): ");
        choice = input.next();
        input.nextLine();
        choice.toUpperCase();
        if(choice.equals("N") )
            cheese = false;
        System.out.print("Pickles (Y/N): ");
        choice = input.next();
        input.nextLine();
        choice.toUpperCase();
        if(choice.equals("N") )
            pickles = false;
        System.out.print("Lettuce (Y/N): ");
        choice = input.next();
        input.nextLine();
        choice.toUpperCase();
        if(choice.equals("N") )
            lettuce = false;
        System.out.print("Onions (Y/N): ");
        choice = input.next();
        input.nextLine();
        choice.toUpperCase();
        if(choice.equals("N") )
            onions = false;
    }
}
