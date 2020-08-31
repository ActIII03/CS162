
//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

class Pizza extends Food {
    //Data fields
    protected int size;
    protected boolean pepperoni;
    protected boolean ham;
    protected boolean sausage;
    protected boolean pineapple;
    protected boolean olives;
    //Default constructor
    Pizza(){
        size = 0;
        pepperoni = true;
        ham = false;
        sausage = false;
        pineapple = false;
        olives = false;
    }
    //Copy constructor
    public Pizza(Pizza to_copy) {
        quantity = to_copy.quantity;
        delivery = to_copy.delivery;
        size = to_copy.size;
        pepperoni = to_copy.pepperoni;
        ham = to_copy.ham;
        sausage = to_copy.sausage;
        pineapple = to_copy.pineapple;
        olives = to_copy.olives;
    }
    //Display current's data item(s)
    public void display(){
        String pizza_size;
        //Check integer to print corresponding string equivalent
        if(size == 1)
            pizza_size = new String("Small");
        else if(size == 2)
            pizza_size = new String("Medium");
        else
            pizza_size = new String("Large");
        //Print current items
        System.out.print("\nQuantity of items: " + quantity
                + "\nDelivery : " + delivery
                + "\nSize: " + pizza_size
                + "\nPepperoni: " + pineapple
                + "\nHam: " + ham
                + "\nSausage: " + sausage
                + "\nPineapple: " + pineapple
                + "\nOlives: " + olives);
    }
    //Delete user-picked item
    public boolean delete(Pizza to_delete){
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
        System.out.print("What size of pizza do you want?(1 = Small, 2 = Medium, 3 = Large): ");
        size = input.nextInt();
        System.out.print("Pepperoni?(Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("N") )
            pepperoni = false;
        System.out.print("Ham (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y") )
            ham = true;
        System.out.print("Sausage (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y") )
            sausage = true;
        System.out.print("Sausage (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y") )
            sausage = true;
        System.out.print("Olives (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y") )
            sausage = true;
    }
}
