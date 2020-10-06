def towerofhanoi(n, source_P, destination_P, auxiliary_P):
    if n == 1:
        print("move", n, "from", source_P, "to", destination_P)
        return
    towerofhanoi(n - 1, source_P, auxiliary_P, destination_P)
    print("Move disk", n, "from", source_P, "to", destination_P)
    towerofhanoi(n - 1, auxiliary_P, destination_P, source_P)
    # print("move",n,"disk from",source_P,"to",destination_P)


# main
n = 3
towerofhanoi(n, "A", "B", "C")
