import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse the standard input
 * according to the problem statement.
 **/
class Temperature {

	public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); // the number of temperatures to analyse
        int [] T;
        T = new int [n];
        for (int i = 0; i < n; i++) {
            T[i] = in.nextInt(); // a temperature expressed as an integer ranging from -273 to 5526
        }
        int result = 0;
        if (n == 0) {
        	result = 0;
        } else {
        	int mv= 0;
    		int mnv=0;
    		boolean v =true;
    		boolean v2=true;
        	for (int i=0; i<n; i++) {
        		if (T[i]== 0) {
        			result = T[i];
        		} else {
            		if (v){
            		    if (T[i]> 0){
            		        mv= T[i];
            		        v= false;
            		    }
            		}
            		if (v2){
            		    if (T[i]<0){
            		        mnv= T[i];
            		        v2= false;
            		    }
            		}
        			if (T[i]>0) {
    					if (T[i]< mv) {
    						mv= T[i];
    					}
    				} else {
    					if (T[i]<0) {
    						if (T[i]>mnv) {
    							mnv= T[i];
    						}
    					}
    				}
        		}
        	}
        	int aux= mnv *(-1);
        	if (mnv == 0){
        	    result = mv;
        	} else {
        	    if (mv == 0){
        	        result =mnv;
        	    } else {
        	        if (mv > aux) {
        	        		result = mnv;
        	        	} else {
        	        		result = mv;
        	            }
        	    }
        	}
        }
        

        // Write an action using System.out.println()
        // To debug: System.err.println("Debug messages...");

        System.out.println(result);
        in.close();
    }
}