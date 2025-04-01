class Matrix:
    def __init__(self, data):
        self.data = data
        self.rows = len(data)
        self.cols = len(data[0])

    def multiply(self, others):
        result = []
        for i in range(self.rows):
            rows = []
            for j in range(others.cols):
                rows.append(0)
            result.append(rows)

    #multiplication
    for i in range(self.rows):
        for j in range(others.cols):
            for k in range(self.cols):
                result[i][j] += self.data[i][k] * others.data[k][j]
    return Matrix(result)


matrix1 = Matrix([[1,2],[3,4]])
matrix2 = Matrix([[5,6],[7,8]])
result_matrix = matrix1.multiply(matrix2)
print(result_matrix)

