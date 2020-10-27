# Mathematical Analysis for Tower of Hanoi.

 M(n) = 2 M(n-1) + 1     ------- 1 

## Required equation-:<br>
### [BY putting n-1, n-2, n-3 into eq 1]  <br>
  a) M(n-1) = 2M(n-2) + 1        -----2 <br>
  b) M(n-2) = 2M(n-3) + 1        -----3  <br>
  c) M(n-3) = 2M(n-4) + 1        -----4 <br>
 
## Now put values of n-1, n-2, n-3
M(n) = 2 [2M(n-2) + 1] + 1     from eq 2 <br>
   ### = 2<sup>2</sup> M(n-2) +3    -----A  <br> 
    (Now put the value of M(n-2) from eq 3)<br>
    = 2^2 [2M(n-3) + 1 ] + 3   <br>
   ### = 2<sup>3</sup> M(n-3) + 7   ------B  <br> 
    (Now put the value of M(n--3) from eq 4)<br>
     = 2^3 [2M(n-4) + 1 ] + 7   <br>
   ### = 2<sup>4</sup> M(n-4) + 15  ------C <br> 
    
 #### By observing above equation A, B, C from above we can write general equation as-
 #### 2<sup>i</sup> M(n-i) + 2<sup>i</sup> -1
 
 Putting i= n-1
On solving we will get -- 2^n -1  n = no of disk 

## No of steps taken by algorithm to move stack to diff rod is 2^n-1
## SO TIME COMPLEXITY WILL BE O(2^n)
 
