# // Write a Python program that determines the location of a saddle point of matrix if one 
# // exists. An m x n matrix is said to have a saddle point if some entry a[i][j] is the smallest 
# // value in row i and the largest value in j.

def find_saddle_point(matrix):
    for i in range(len(matrix)):
        row_min=min(matrix[i])
        col_index=matrix[i].index(row_min)
        
        if all(row_min >= matrix[k][col_index] for k in range(len(matrix))):
            return (i,row_min,col_index)
            
    return none        

matrix =[
    [1,2,3],
    [9,6,7],
    [2,1,4]
    ]
saddle_point = find_saddle_point(matrix)
if saddle_point:
    print("We got the saddle point at matrix =",saddle_point[0],"\nSmallest is = ",saddle_point[1],"\nIndex position ",saddle_point[2])
else:
    print("We dont get any saddle point!!!")