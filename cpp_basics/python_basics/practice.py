
# n = 10
# for i in range(1,n+1):
#     print(i)

# def swap(arr, x,y):
#       if(arr[x] > arr[y]):
#             arr[x], arr[y] = arr[y], arr[x]
    

# list1 = [12,42,13,42,15,62,71,18,29,10]
# for i in range (0, len(list1)):
#     for j in range(i, len(list1)):
#             swap(list1, i,j)
# print(list1)

# # multiply two lists
# l1 = [1,2,3,4,5]
# l2 = [2,4,6]

# result = []
# def multiply(l1:list, l2:list) ->list:
#     while(len(l1) < len(l2)):
#         l1.append(0)
#     while(len(l2) < len(l1)):
#         l2.append(0)
#     for i in range(len(l1)):
#         result.append(l1[i] * l2[i])
#     return result
# print(multiply(l1,l2))

# mask of 2
# import numpy as np
#l1 = [2,3,4,5,6]
# # return [t,f,t,f,t]
#mask = [i%2==0 for i in range(len(l1))]
# arr = np.array(l1)
# mask = (arr%2 == 0)
#print(mask)

# take a number as input and convert to square and cube
# l1 = [1,2,3,4]
# square_l1 = []
# cube_l1 = []
# for i in range(len(l1)):
#     square_l1.append(l1[i] * l1[i])
#     cube_l1.append(l1[i] * l1[i] * l1[i])
# print(square_l1)
# print(cube_l1)

# check if the number is even or odd
# l1 = [1,2,3,4,5,6]
# result = []
# for i in range(len(l1)):
#     if(l1[i]%2 == 0):
#         result.append("even")
#     else:
#         result.append("odd")
# print(result)

# func to convert celcius to farenheit

# def faren_conv(deg):
#     f = (deg * (9/5)) + 32
#     return f
# print(faren_conv(0))