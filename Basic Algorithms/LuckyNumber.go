/*
Lucky numbers are subset of integers. 
Take the set of integers
1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,……

First, delete every second number, we get following reduced set.
1,3,5,7,9,11,13,15,17,19,…………

Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….

Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Therefore, set of lucky numbers is 1, 3, 7, 13,………
*/
package main
import "fmt"
func main() {
    n:=5
    result := util(n,2)
    if result==false{
        fmt.Printf("%v is not a Lucky number.\n",n)
    }else{
        fmt.Printf("%v is a Lucky number.\n",n)
    }
}

func util(n int, counter int) bool{
    if counter>n{
        return true
    }
    if n%counter==0{
        return false
    }
    n = n-n/counter
    return util(n,counter+1)
}