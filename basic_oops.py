from abc import ABC, abstractmethod

# Step 1: Abstract Class - Person (Encapsulation & Abstraction)
class Person(ABC):
    def __init__(self, name, email):
        self.name = name  # Public attribute
        self.email = email  # Public attribute

    @abstractmethod
    def get_info(self):
        pass  # To be implemented in subclasses


# Step 2: Book Class (Encapsulation)
class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.available = True  # A book is available by default

    def borrow(self):
        if self.available:
            self.available = False
            print(f"{self.title} has been borrowed.")
        else:
            print(f"{self.title} is currently unavailable.")

    def return_book(self):
        self.available = True
        print(f"{self.title} has been returned.")

    def get_details(self):
        return f"Title: {self.title}, Author: {self.author}, Available: {'Yes' if self.available else 'No'}"


# Step 3: User Class (Inheritance from Person)
class User(Person):
    def __init__(self, name, email):
        super().__init__(name, email)
        self.borrowed_books = []

    def borrow_book(self, book):
        if book.available:
            book.borrow()
            self.borrowed_books.append(book)
        else:
            print(f"{self.name} cannot borrow {book.title}. It's not available.")

    def return_book(self, book):
        if book in self.borrowed_books:
            book.return_book()
            self.borrowed_books.remove(book)
        else:
            print(f"{self.name} did not borrow {book.title}.")

    def get_info(self):
        return f"User: {self.name}, Email: {self.email}"


# Step 4: Admin Class (Inheritance from User, Polymorphism)
class Admin(User):
    def __init__(self, name, email):
        super().__init__(name, email)

    def add_book(self, book, library):
        library.append(book)
        print(f"Admin {self.name} added {book.title} to the library.")

    def remove_book(self, book, library):
        if book in library:
            library.remove(book)
            print(f"Admin {self.name} removed {book.title} from the library.")
        else:
            print(f"Book {book.title} not found in the library.")

    def get_info(self):
        return f"Admin: {self.name}, Email: {self.email}"


# Step 5: Regular User Class (Inheritance from User)
class RegularUser(User):
    def __init__(self, name, email):
        super().__init__(name, email)

    def get_info(self):
        return f"Regular User: {self.name}, Email: {self.email}"


# Step 6: Library Management System
class Library:
    def __init__(self):
        self.books = []

    def display_books(self):
        print("Available Books in the Library:")
        for book in self.books:
            print(book.get_details())


# Test the System

# Create a library object
library = Library()

# Create books
book1 = Book("1984", "George Orwell")
book2 = Book("To Kill a Mockingbird", "Harper Lee")
book3 = Book("The Great Gatsby", "F. Scott Fitzgerald")

# Add books to library using Admin
admin = Admin("Alice", "alice@library.com")
admin.add_book(book1, library.books)
admin.add_book(book2, library.books)
admin.add_book(book3, library.books)

# Display books in the library
library.display_books()

# Create users
user1 = RegularUser("Bob", "bob@library.com")
user2 = RegularUser("Charlie", "charlie@library.com")

# Users borrow books
user1.borrow_book(book1)
user2.borrow_book(book2)

# Display books after borrowing
library.display_books()

# Users return books
user1.return_book(book1)
user2.return_book(book2)

# Display books after returning
library.display_books()

# Admin removes a book
admin.remove_book(book3, library.books)

# Display books after removing
library.display_books()




#############################################################################################################################
                                        #         LIST
#############################################################################################################################

my_list = [1, 2, 3, 4]
my_list.append(5)  # Appends an element to the list
print(my_list)

#############################################################################################################################
##################################### DICTIONARY##############################################################################
###############################################################################################################################
my_dict = {"a": 1, "b": 2, "c": 3}
my_dict["d"] = 4  # Adds a new key-value pair
print(my_dict)

##############################################################################################################################
###################################### TUPLE ##############################################################
##############################################################################################################################
my_tuple = (1, 2, 3)
print(my_tuple)

###############################################################################################################################
####################################### SET ##############################################################
################################################################################################################################
my_set = {1, 2, 3}
my_set.add(4)  # Adds an element to the set
print(my_set)

##############################################################################################################################
######################################### ARRAYS ##############################################################
##############################################################################################################################
import array
arr = array.array('i', [1, 2, 3, 4])  # 'i' stands for integer type
arr.append(5)  # Append an element
print(arr)
##############################################################################################################################

