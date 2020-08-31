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
    protected Food previous;
    protected String name_of_person;
    private String name;
    //Default constructor
    Food(){
        next = null;
        previous = null;
    }
    //User-supplied name constructor
    public Food(String name){
        next = null;
        previous = null;
        this.name_of_person = new String(name);
    }
    //Read in user's input
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
    //Return current's previous reference to calling routine
    public Food get_previous() {
        return this.previous;
    }
    //Set previous
    public Food set_previous(Food current){
        this.previous = current;
        return this.previous;
    }
    //Display data
    protected abstract void display();
}
