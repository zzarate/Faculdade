import java.util.*;
import java.io.*;
import java.math.*;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
class TheDescent {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int maxMountain=0; //O tamanho maximo da maior montanha 
        int mountain=0; //Numero da montanha 

        // game loop
        while (true) {
            maxMountain=0;
            mountain=0;

            for (int i = 0; i < 8; i++) {
                int mountainH = in.nextInt(); // represents the height of one mountain.

                if (maxMountain<mountainH) { 
                    maxMountain=mountainH;
                    mountain=i;
                }
            }

            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");

            System.out.println(mountain); // The index of the mountain to fire on.
        }
    }
}