# Write a Python program to store marks scored in subject “Fundamental of Data 
# Structure” by N students in the class. Write functions to compute following:
# a) The average score of class 
# b) Highest score and lowest score of class 
# c) Count of students who were absent for the test
# d) Display mark with highest frequency
def avg(marks):
    total_marks=0
    count=0
    
    for mark in marks:
        if mark != 'AB':
            total_marks = total_marks + int(mark)
            count = count + 1
    avg=total_marks/count
    print(avg)

def highlow(marks):
    mark1=[]
    for mark in marks:
        if mark !='AB':
            mark1.append(int(mark))
    max_marks=max(mark1)
    min_marks=min(mark1)
    print("highest score: ",max_marks)
    print("lowesr score:",min_marks)
    
def  abscount(marks):
    count = 0
    for mark in marks:
        if mark == 'AB':
            count = count + 1    
    print(count)
    
def  display(marks):
    mark1=[]
    for mark in marks:
        if mark != 'AB':
            mark1.append(int(mark))
    display={mark:mark1.count(mark)for mark in mark1}
    print(display)
    key_max=max(display,key=display.get)
    print("Highest kay is :",key_max)

n=int(input("Enter the number of students: "))
marks=[]

for i in range(n):
    mark=input("Enter the number:").upper()
    marks.append(mark)
while True:
    print("menu")
    print("1. The average score of class")
    print("2. Highest score and lowest score of class")
    print("3. Count of students who were absent for the test")
    print("4. Display mark with highest frequency")


    choice=int(input("Enter the choice number: "))
    if choice == 1:
        avg(marks)
    elif choice == 2:
        highlow(marks)
    elif choice == 3:
        abscount(marks)
    elif choice == 4:
        display(marks)
    else:
        print("Invaild choice")

