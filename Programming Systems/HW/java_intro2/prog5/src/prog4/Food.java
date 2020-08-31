//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this
package prog4;

// Abstract base class for picking food item(s) to order creating the "glue"
abstract class Food extends Util{
    //Data fields
    protected int quantity = 0;
    protected boolean delivery = false;
    protected Food next;
    //Default constructor
    Food(){
        next = null;
    }
    //Read in user's input <--- Implement virtual method
    public abstract void read_in();
    //Set next to a new, instantiated item
    public Food set_next(Food current){
        this.next = current;
        return this.next;
    }
    //Return current's next reference to calling routine
    public Food get_next() {
        return this.next;
    }
    //Display data <--- Implement virtual method
    protected abstract void display();
}
