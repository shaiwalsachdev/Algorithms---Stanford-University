import sys
import math
import itertools
import numpy as np

INF = 99999999

def read():
    cities = []
    for line in sys.stdin.readlines():
        xandy = line.split()
        x = float(xandy[0])
        y = float(xandy[1])
        cities.append((x, y))
    return cities

def edgescalculation(nodes,cities):
    dist = []
    for j in range(nodes):
        dist.append([])
        for i in range(nodes):
            dist[j].append(math.sqrt((cities[i][0] - cities[j][0])**2 + (cities[i][1] - cities[j][1])**2))
    return dist


def dpsol(nodes,dist):
    #Storing DP solutions to subproblems
    dp = {}
    cityno = []
    for i in range(1,nodes+1):
        cityno.append(i)

    #print (cityno)

    #Intialize the dp table
    for i in itertools.combinations(cityno, 1):
        dp[i] = dp.get(i, {})
        #print (i,dp[i])
        if i[0] == 1:
            dp[i][i[0]] = 0
        else:
            dp[i][i[0]] = INF

    #print (dp)
    #Outer Loop ,Number of Cities
    for i in range(2, nodes+1):
        #print (i)
        for j in itertools.combinations(cityno, i):
            #print (i,j)
            dp[j] = dp.get(j, {})
            for element in j:
                #Except the Starting and Element In Set Make Combnations
                current_set = set(j)
                current_set.discard(element)
                sorted_set = tuple(sorted(current_set))
                
                mini1 = INF
                for k in sorted_set:
                    y = dp[sorted_set].get(k, INF)  + dist[k-1][element-1]
                    if y < mini1:
                        mini1 = y
                dp[j][element] = y
                #print (j,element,y)
             



    #For Every COmbination add the last edge and check minimum value
    mini = INF
    for j in range(1,nodes+1):
        x = dp[tuple(cityno)][j] + dist[j-1][0]
        if x < mini:
            mini = x

    return mini


def main():
    
    nodes = int(sys.stdin.readline())

    cities = read()

    dist = edgescalculation(nodes,cities)

    mini = dpsol(nodes,dist)
    
    print ("Minimum Distance of The Route :")
    print (int(mini))
    


if __name__ == '__main__':
    main()

    