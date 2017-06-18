#http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
#!/usr/bin/python

def tripletSum(x, a):
    for first_element in range(0, len(a) - 2):
        left = first_element + 1
        right = len(a) -1 
        
        while( left < right):
             if ( (a[first_element] + a[left] + a[right]) == x ):
                  print( "true, triples are: %d %d %d" %(a[first_element], a[left], a[right]) )
                  return
             elif ((a[first_element] + a[left] + a[right]) < x):
                  left = left + 1;
             else:
                  right = right - 1;
                
    return
    print("false")
    
def main():
    a = [1, 4, 45, 6, 10, 8]
    sum = 22
    a.sort()
    #print(a)
    tripletSum(sum, a)

main()
