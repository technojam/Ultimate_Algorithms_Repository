/** WAP to find whether 2 strings are Anagram
 * 'cat ' and 'act' are anagrams because length and same characters in both word
 * 
 * @author Yash Shah
 * @date Jan 23 ,2020
 */

package codes;

import java.util.Arrays;
import java.util.Scanner;

public class Anagram {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String s1, s2;
		System.out.println("Enter the First word");
		s1 = sc.next();
		System.out.println("Enter the Second word");
		s2 = sc.next();

		int l1 = s1.length();
		int l2 = s2.length();
		boolean flag = true;
		char ch1[] = s1.replaceAll("\\s", "").toCharArray();
		char ch2[] = s2.replaceAll("\\s", "").toCharArray();
		if (l1 == l2) {
			Arrays.sort(ch1);
			Arrays.sort(ch2);
			flag = Arrays.equals(ch1, ch2);

			if (flag == true) {
				System.out.println("Anagram .........");
			} else {
				System.out.println("Not an Anagram .........");
			}
		} else {
			System.out.println("Not Anagram..");
		}

	}

}
