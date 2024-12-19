# a) Write a Python program to store names and mobile numbers of your friends in sorted 
# order on names. Search your friend from list using binary search (recursive and non-recursive). Insert friend if not present in phonebook
# b) Write a Python program to store names and mobile numbers of your friends in sorted 
# order on names. Search your friend from list using Fibonacci search. Insert friend if not 
# present in phonebook.
def recursive_search(phonebook,target,low,high):
    mid = (low + high)//2
    if phonebook[mid][0] == target:
        print("we got the target")
        return mid
    elif phonebook[mid][0] > target:
        recursive_search(phonebook,target,low,mid-1)
    elif phonebook[mid][0] < target:
        recursive_search(phonebook,target,mid+1,high)
    
    return target    

def non_recursive_search(phonebook,target):
    low = 0;
    high = len(phonebook) - 1
    
    while low < high:
        mid = (low + high)//2
        
        if phonebook[mid][0] > target:
            high = mid - 1
        elif phonebook[mid][0] < target:
            low = mid + 1
        elif phonebook[mid][0] == target:
            return mid
            
    return mid        



n=int(input("Enter the number of students : "))
phonebook=[]
for i in range(n):
    name=(input("Enter the name of student : "))
    num=(input("Enter the mobile number :"))
    phonebook.append((name,num))
phonebook.sort()

low = 0;
high = len(phonebook)-1    
target = (input("Enter the name to to searched: "))
while True: 
    print("\nMenu")
    print("\n1.Rescusrive search")
    print("\n2.non-recursive search")
    print("\n3.Insert the friend")
    print("\n4.exit")
    ch=(input("\nEnter the choice: "))
    if ch == 1:
        result = recursive_search(phonebook,target,0,len(phonebook)-1)
        if result == -1:
            print("Not found !!!")
    elif ch == 2:
        result = non_recursive_search(phonebook,target)
        if result == -1:
            print("target is not found !!!")
    elif ch == 3:
        print("Exiting from program!!!")
        break
    else ch == 4:
        print("Please enter the valid choice !!!")
    
