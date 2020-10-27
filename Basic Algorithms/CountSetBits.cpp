/* An efficient C++ program to count No. of set/high bits in an integer-
    using Brian Kernighan's Algorithm */

/*  Useful Prerequisite knowledge-

	 When u subtract 1 from a decimal no. 'n', all bits after the rightmost set bit(i.e 1) are flipped 
	 including this righmost bit.
	 For eg.  8 = 1000 , 7= 0111, Here Rightmost set bit in 8 is at index 0.
	 So,(n & n-1) : this operation Unsets the righmost set bit in n i.e 8&7= 0000  
  */

  
/*  Algorithm-

     step 1: Initialize count=0.
     step 2: Define a recursive function that performs following-
             if(n is 0)
               return 1.
             else return 1+ func(n&n-1)
      step 3: print value returned by function as count.
   */


// C++ Code implementing Brian Kernighan's Algorithm:-

#include<iostream>        // basic I/O header

// Recursive function to count set bits
unsigned int set_bits(int x)     
	{
		if (x==0)
			return 0;
		else 
			 // unset righmost set bit and call function with updated value
	         // symbol '&' refers to bitwise and operation
			return 1+set_bits(x & x-1); . 
	}

int main()
	{   
	  // Variable to read non-negative integer
		unsigned int n;          
	    printf("Enter number:");
	    scanf("%d",&n);
	    //calling function set_bits defined above.
	    int count = set_bits(n);   
	              
	     printf("No. of set bits in %d = %d", n, count);

	     return 0;
     }	


   /*
		Sample Input:
		11

		Sample Output:
		No. of set bits in 11 = 3
  */
        // About Time complexity:  No. of recursive calls/iterations(in case u use loop) here is equal to no. of set bits.

          //   Contributor - Abhinav Pathak.   
