#Pigeonhole sorting in python programming
def pigeonhole_sorting(a): 
    # size of range of values in the list  
    # (ie, number of pigeonholes we need) 
    minN = min(a) 
    maxN = max(a) 
    margin = maxN - minN + 1
  
    # our list of pigeonholes 
    holes = [0] * margin 
  
    # Populate the pigeonholes. 
    for x in a: 
        assert type(x) is int, "integers only please"
        holes[x - minN] += 1
  
    # Put the elements back into the array in order. 
    i = 0
    for cnt in range(margin): 
        while holes[cnt] > 0: 
            holes[cnt] -= 1
            a[i] = cnt + minN 
            i += 1