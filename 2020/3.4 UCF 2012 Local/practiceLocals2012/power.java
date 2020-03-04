// Arup Guha
// 8/25/07
// Solution for 2007 UCF Local Contest Problem: Power

import java.util.*;
import java.io.*;

// Stores a single term of a prime factorization.
class Term implements Comparable<Term> {
	
	public int base;
	public int exp;
		
	public Term(int b, int e) {
		base = b;
		exp = e;
	}
	
	// Used to help sort terms, we only want to order terms by base.
	public int compareTo(Term t) {
		return base - t.base;
	}
	
	// Allows us to combine the current object with t.
	// If the bases aren't equal, null is returned, otherwise, the product
	// of the two terms is returned.
	public Term combine(Term t) {
		
		if (base != t.base)
			return null;
		else
			return new Term(base, exp+t.exp);
	}
	
}
public class power {
	
	// Stores all of our terms.
	private ArrayList<Term> thisNumber;
	
	public power(Scanner fin) {
		
		thisNumber = new ArrayList<Term>();
		
		// Get the number of terms.
		int numTerms = fin.nextInt();
		
		// Read through each term and add it into the object.
		for (int i=0; i<numTerms; i++) {
			int my_base = fin.nextInt();
			int my_exp = fin.nextInt();
			Term tmp = new Term(my_base, my_exp);
			this.add(tmp);	
		}
		
		// Sort the terms, in ascending order by base.
		Collections.sort(thisNumber);
		
	}
	
	// Adds t into the current object.
	public void add(Term t) {
		
		// Check if t's in there...if so, combine and add.
		for (int i=0; i<thisNumber.size(); i++) {
			
			// Found a term with the same base.
			if ((thisNumber.get(i)).compareTo(t) == 0) {
			
				// Combine these terms.
				t = (thisNumber.get(i)).combine(t);
				
				// Get rid of the old term.
				thisNumber.remove(i);
				
				// Add the new one in.
				thisNumber.add(t);
				return;
			}
		}
		
		// t is not in there, so just add it.
		thisNumber.add(t);
	}
	
	public void outputCase(int casenum) {
		
		// This is enough space to store the output because each base is 4 digits
		// or less and each exponent is 5 digits or less, and there are never
		// more than 19 original terms.
		char[][] grid = new char[2][9*19*thisNumber.size()];
		
		// Fill the grid with all blanks at first.
		for (int i=0; i<2; i++)
			for (int j=0; j<grid[i].length; j++)
				grid[i][j] = ' ';
				
				
		int cnt = 0;
		
		// We will copy the digits into the grid in reverse order.
		for (int i=thisNumber.size()-1; i>=0; i--) {
			
			// First copy the exponent into the grid.
			int tmpexp = (thisNumber.get(i)).exp;
			while (tmpexp > 0) {
				
				// Extract the digits we want.
				// 0 signifies placing the digit in the top row.
				grid[0][cnt] = (char)(tmpexp%10+'0');
				
				// "Advance" to the next digit.
				tmpexp /= 10;
				cnt++;
			}
			
			// Now we will copy the base into the grid.
			int tmpbase = (thisNumber.get(i)).base;
			while (tmpbase > 0) {
				
				// Extract the digits we want.
				// 1 signifies placing the digit on the bottom row.
				grid[1][cnt] = (char)(tmpbase%10+'0');
				
				// "Advance" to the next digit.
				tmpbase /= 10;
				cnt++;
			}
		}
		
		// Output Header.
		System.out.println("Prime Factorization #"+casenum+":");
		
		// Print out the grid, in reverse order, so it prints out properly.
		
		// The rows are already in order,
		for (int i=0; i<2; i++) {
			
			// but the columns were stored in reverse order.
			for (int j=cnt-1; j>=0; j--)
				System.out.print(grid[i][j]);
			System.out.println();
		}
		System.out.println();
		
	}
	
	public static void main(String[] args) throws IOException {
		
		// Set up reading from the input file.
		Scanner fin = new Scanner(new File("power.in"));
		
		// Get the number of cases.
		int numcases = fin.nextInt();
		
		// Process each case and print out the corresponding output!
		for (int my_case=1; my_case<=numcases; my_case++) {
		
			power thisCase = new power(fin);
			thisCase.outputCase(my_case);		
		}
		
		// Close the input file.
		fin.close();
	}
	
}