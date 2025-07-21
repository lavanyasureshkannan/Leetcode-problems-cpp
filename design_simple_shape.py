from abc import ABC, abstractmethod 

class shape:
    @abstractmethod
    def display(self):
        pass
    def __del__(self):
        print("Shape is getting destroyed")
class circle(shape):
    def display(self):
        print("Draw a circle")
class square(shape):
    def display(self):
        print("Draw a sqaure")
class shape_factory:
    shape_map = {
        "CIRCLE" : circle,
        "SQUARE" : square
    }

    @staticmethod
    def create_shape(name_of_shape: str) ->shape:
        shape_class = shape_factory.shape_map.get(name_of_shape.upper())
        if not shape_class:
            print("Not a valid shape")
        return shape_class()

if __name__ == "__main__":
    shape1 = shape_factory.create_shape("circle")
    shape1.display()
