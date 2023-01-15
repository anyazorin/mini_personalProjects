#!/bin/python3

import csv
from pprint import pprint


if __name__ == '__main__':
    #replace with correct file path name
    with open('test.txt') as f:
        contents = f.readlines()
    #prefix for rule
    prefix="D"
    pl=1
    arr = [['start','start','start']]
    for i in range(len(contents)):
        s= contents[i]
        if s[0:pl]==prefix:
            newRow=[]
            newRow.append(prefix)
            restOfRow= s[pl:].split(" ",1)
            newRow.append(restOfRow[0])
            newRow.append(restOfRow[1])
            #pprint(newRow)
            for j in range(len(contents)-i-1):
                j=j+i+1
                r=contents[j]
                if r[0:pl]==prefix:
                    i=j-1
                    break
                else:
                    newRow[2]=newRow[2]+r
            arr.append(newRow)
            
    with open('rules.csv', 'a') as csvfile: 
        # creating a csv writer object 
        csvwriter = csv.writer(csvfile) 
        # writing the data rows 
        csvwriter.writerows(arr)