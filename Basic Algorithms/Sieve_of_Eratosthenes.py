#importes math for sqrt function
from math import *
def generate_prime(n):
    prime_num= [True]*(n+1)
#making 0 and 1 False since they are not prime numbers
    prime_num[0] = False
    prime_num[1] = False
    for i in range(2,int(sqrt(n))+1):
        if prime_num[i] == True:
            for j in range(i*i,n+1,i):
                prime_num[j] = False #if divided by that number 
    for a in range(0,len(prime_num)):
        if primes [a]== True:
            print (a) #printing the prime numbers
#taking input from the user
inp = int(input('Enter the maximum number limit for the prime numbers'))
generate_prime(inp)