def main():
    
    lines = open('2sum.txt').read().splitlines()
    
    data = map(lambda x: int(x), lines)
    hashTable = dict()
    
    for x in data:
        hashTable[x] = True
    print('size:' + str(len(hashTable)))
    
    
    result = dict()
    counter = 0
    for ix,value in hashTable.items():
        counter += 1
        for sum in range(-10000, 10000+1):
            iy = sum -ix
            if ix != iy and iy in hashTable and ix in hashTable:
                result[sum] = True
        print(counter,'size:' + str(len(result)))
    print(str(len(result)))
    
    
if __name__ == '__main__':
    main()
    