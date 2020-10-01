# Money Problem
In this problem, we will use a greedy algorithm to find the minimum number of coins/ notes that could makeup to the given sum. For this we will take under consideration all the valid coins or notes i.e. denominations of { 1, 2, 5, 10, 20, 50 , 100, 200 , 500 ,2000 }. And we need to return the number of these coins/notes we will need to make up to the sum.

Example-
    Input : 1231
    Output : 7

We will need two Rs 500 notes, two Rs 100 notes, one Rs 20 note, one Rs 10 note and one Re 1 coin.
That sums to 2+2+1+1+1 = 7

Example-
    Input : 2150
    Output : 3

## Algorithm
Input: sum, </br>
Initialise the coins = 0 </br>
Step 1: Find the largest denomination that can be used i.e. smaller than sum. </br>
Step 2: Add denomination two coins and subtract it from the Sum </br>
Step 3: Repeat step 2 until the sum becomes 0. </br>
Step 4: Print each value in coins. </br>
