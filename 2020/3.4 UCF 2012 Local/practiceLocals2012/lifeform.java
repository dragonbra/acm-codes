// Arup Guha
// 8/27/2012
// Solution to 2007 Locals Contest Question: Lifeform

import java.util.*;
import java.io.*;

public class lifeform {

	public static void main(String[] args) throws Exception {

		Scanner fin = new Scanner(new File("lifeform.in"));

		int numCases = fin.nextInt();

		// Process all the cases.
		for (int loop=1; loop<=numCases; loop++) {

			String s = fin.next();

			if (inGrammar(s))
				System.out.println("Pattern "+loop+": More aliens!");
			else
				System.out.println("Pattern "+loop+": Still Looking.");
			System.out.println();
		}
	}

	public static boolean inGrammar(String s) {

		Stack<Character> mystack = new Stack<Character>();

		// If you inspect the grammar carefully, all we're doing is matching a's to b's
		// like parentheses, and allowing c's to go anywhere.
		for (int i=0; i<s.length(); i++) {

			if (s.charAt(i) == 'a')
				mystack.push('a');
			else if (s.charAt(i) == 'b') {
				if (mystack.empty())
					return false;
				else
					mystack.pop();
			}

			// Trick case allowed in the input spec.
			else if (s.charAt(i) != 'c')
				return false;
		}

		return mystack.empty();
	}

}