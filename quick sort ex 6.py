# Write a Python program to store first year percentage of students in array. Write 
# function for sorting array of floating point numbers in ascending order using quick sort 
# and display top five scores.

def quick_sort(arr):
    if len(arr) <= 1:  
        return arr
    pivot = arr[len(arr)//2]
    right =[per for per in arr if per > pivot]
    middle =[per for per in arr if per == pivot]
    left =[per for per in arr if per < pivot]
    return quick_sort(left) + middle + quick_sort(right)

n=int(input("Enter the number of students: "))
q=[]
for i in range(n):
    per=float(input(f"Enter the percentage{i+1}: "))
    q.append(per)
print("The percentage are: ",q)

sorted_list = quick_sort(q)

print("The sorted list is: ",sorted_list)

top5=sorted_list
top5.reverse()
if (len(top5))<5:
    for i in range(0,n):
        print(top5[i])
else:
    for i in range(0,5):
        print(top5[i])
    


        
        