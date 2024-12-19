# Write a Python program to store first year percentage of students in array. Write 
# function for sorting array of floating point numbers in ascending order using 
# a) Selection Sort 
# b) Bubble sort and display top five scores.

while True:
    print("Menu")
    print("1. Bubble sort")
    print("2. selection sort")
    print("3. Exit")
    
    choice = int(input("Enter the choice : "))
    if choice == 1:
        print("Bubble sort")
        n=int(input("Enter the number of students: "))
        s=[]
        for i in range(n):
            per =float(input("Enter the percentage of student: "))
            s.append(per)
        print("The percentages are: ",s)
        
        for i in range(0,n-1):
            for j in range(n-i-1):
                if s[j] > s[j+1]:
                    temp = s[j]
                    s[j] = s[j+1]
                    s[j+1] = temp
        print("The sorted list is: ",s)
        
        print("The top 5 are: ")
        top5=s
        top5.reverse()
        if(len(top5))<5:
            for i in range(0,n):
                print(top5[i])
        else:
            for i in range(0,5):
                print(top5[i])
    
    elif choice ==2:    
        print("selection sort")
        n= int(input("Enter the number of students: "))
        b=[]
        for i in range(n):
            per=float(input("Enter the percentage: "))
            b.append(per)
        print("The percentages are: ",b)
        
        for i in range(n):
            min_index=i
            for j in range(i+1,n):
                if b[j] < b[min_index]:
                    temp = b[j]
                    b[j] = b[min_index]
                    b[min_index] = temp
        print("The sorted list is: ",b)
        
        print("The Top 5 are: ")
        top5=b 
        b.reverse()
        if(len(b))<5:
            for i in range(0,n):
                print(top5[i])
        else:
            for i in range(0,5):
                print(top5[i])
                
    elif choice == 3:
        print("exiting program !!!!")
        break
    else:
        print("Enter the valid choice !!!")
        
        
        