//Name: Armant Touche
//Class: CS202
//Program: Food Order
//Notes: Used Intellij Idea IDE to program this

package prog4;
//Libraries for utilities
import java.io.*;
import java.lang.Runtime;
import java.util.Scanner;

public class Util {
    //Input utility
    final String OS;
    protected Scanner input;
    protected String choice;
    //Default constructor
    public Util(){
        OS = System.getProperty("os.name");
        input = new Scanner(System.in);
    }
    //Greet User
    public void greet(){
        System.out.print("Welcome to the Food Ordering system!\n");
    }
    //Prompt user of choices
    public int prompt_menu(){
        System.out.print("List of items to pick from:\n"
                + "(1) Burgers\n"
                + "(2) Pizza\n"
                + "(3) Drink\n"
                + " Choice (1-3) : ");
        int choice = input.nextInt();
        input.nextLine();
        return choice;
    }
    //Ask user to delete current item
    public boolean ask_delete(){
        choice = new String();
        System.out.print("\nWould you like to delete? (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            return true;
        return false;
    }
    //Ask user to keep viewing
    public boolean ask_to_view(){
        choice = new String();
        System.out.print("\nWould you like to keep viewing? (Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            return true;
        return false;
    }
    //Ask Again
    protected boolean again(){
        choice = new String();
        System.out.print("\nWould you like to go again?(Y/N): ");
        choice = input.next();
        choice.toUpperCase();
        if(choice.equals("Y"))
            return true;
        return false;
    }
    //Clear screen of text
    public void clear_screen() {
        //Check Operating Sytem
        if (OS.contains("Windows")) {
            try {
                Runtime.getRuntime().exec("cls");
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            try {
                Runtime.getRuntime().exec("clear");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
