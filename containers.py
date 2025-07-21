
# Lists -> Lists are the containers that can hold any data type.
# They are muttables

fruits = ["bannana", "apple", 1, 2, [1,2,3]]
print(fruits)

# Tuples -> Tuples are immutable. They are of same data type
elements = (1,2,3)
print(elements)

# dictionaries -> They are like key and value pairs

person = {
    "name" : "lala",
    "age" : 26,
    "address": "california"
}
print(person)

# set -> returns unique values
numbers = {1,2,3,2,1} 
print(numbers)

# convert list to dictionary
a = [10,20,30]
b = {}
for index, value in enumerate(a):
    b[index] = value
# b = {index : value for index, value in enumerate(a)}
print(b)


keys = ["a","b","c"]
values = [1,2,3]

d = dict(zip(keys, values))
print(d)

# create a mask of even
a = [10,20,33,41,50]
mask = [x%2 == 0 for x in a]
print(mask)