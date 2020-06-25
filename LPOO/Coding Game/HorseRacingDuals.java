
import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class HorseRacingDuals {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();	// Numbers of horses
        int [] V;
        V = new int [N];
        for (int i = 0; i < N; i++) {
            V[i] = in.nextInt();
        }
        Arrays.sort (V);
        
        int d= Integer.MAX_VALUE;
        for (int i=0; i< N-1; i++) {
        	int aux= V[i+1] - V[i];
        	if (aux < d) {
        		d= aux;
        	}
        }

        // Write an action using System.out.println()
        // To debug: System.err.println("Debug messages...");

        System.out.println(d);
        in.close();
    }
}