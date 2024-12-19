#In second year computer engineering class, group A student’s play cricket, group B 
# students play badminton and group C students play football. 
# Write a Python program using functions to compute following: -
# a) List of students who play both cricket and badminton 
# b) List of students who play either cricket or badminton but not both 
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton.
# (Note- While realizing the group, duplicate entries should be avoided, Do not use SET 
# built-in functions



def cricket_badmintion_both(cricket,badminton):
    both=[]
    for student in cricket:
        if student in badminton and student not in both:
            both.append(student)
    return both

def either_cricket_or_badminton(cricket,badminton):
    either=[]
    for student in cricket:
        if student not in badminton and student not in either:
            either.append(student)
    for student in badminton:
        if student not in cricket and student not in either:
            either.append(student)
    return either        
 
def neither_cricket_not_badminton(cricket,badminton,football):
    neither = 0
    for student in football:
        if student not in cricket and student not in badminton:
            neither = neither + 1
    return neither     

def cricekt_and_football_but_not_badminton(cricket,badminton,football):
    count = 0
    for student in cricket:
        if student in football and student not in badminton:
            count = count + 1
    return count
    
cricket=[]
badminton=[]
football=[]

n=int(input("Enter number of students playing cricket: "))

for i in range(n):
    student=(input("Enter the student name: "))
    cricket.append(student)
    
m=int(input("Enter number of students playing Badminton: "))

for i in range(m):
    student=(input("Enter the student name: "))
    badminton.append(student)    

m=int(input("Enter number of students playing football: "))

for i in range(m):
    student=(input("Enter the student name: "))
    football.append(student) 

print("Students playing both cricket and badminton are: ")
print(cricket_badmintion_both(cricket,badminton))

print("Student plyaing either cricket or badminton but not both")
print(either_cricket_or_badminton(cricket,badminton))

print("Number of students who play neither cricket nor badminton")
print(neither_cricket_not_badminton(cricket,badminton,football))

print("Number of students who play cricket and football but not badminton.")
print(cricekt_and_football_but_not_badminton(cricket,football,badminton))