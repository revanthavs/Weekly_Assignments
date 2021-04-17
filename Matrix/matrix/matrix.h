/*
	Name: Atmakuri Venkata Sai Revanth
	ID: 1684293
	CMPUT 275, Winter 2021

	Exercise 4: Matrix Class
*/

#ifndef __MATRIX_H__
#define __MATRIX_H__

using namespace std;

class Matrix{
public:
	// Creates the 2DARRAY(Matrix) and initializes all the elements to init
	Matrix(unsigned int num_rows, unsigned int num_columns, float init);
	// Creates the 2DARRAY(Matrix) and initializes the elements using data
	// stored in a 1DARRAY which is pointed to arr_ptr
	Matrix(unsigned int num_rows, unsigned int num_columns, float* arr_ptr);

	// Overloads the + addition operator and performs operation
	// according to Matrix addition
	// Since we are creating the new instance rather than modifying
	// the existing object it's a constant
	Matrix operator+(const Matrix& rhs) const;

	// Overloads the - subtraction operator and performs operation
	// according to Matrix subraction
	// Since we are creating the new instance rather than modifying
	// the existing object it's a constant
	Matrix operator-(const Matrix& rhs) const;

	// Overloads the x multiplication operator and performs operation
	// according to Matrix multiplication
	// Since we are creating the new instance rather than modifying
	// the existing object it's a constant
	Matrix operator*(const Matrix& rhs) const;

	// Return matrix where all the the elements signs are flipped
	// Since we are creating the new instance rather than modifying
	// the existing object it's a constant
	Matrix operator~() const;

	// Returns a transpose matrix by turning rows into columns
	// Since we are creating the new instance rather than modifying
	// the existing object it's a constant
	Matrix transpose() const;

	// Returns a submatrix of the original matrix
	// Since we are creating the new instance rather than modifying
	// the existing object it's a constant
	Matrix submatrix(unsigned int row_start, unsigned int row_end,
		unsigned int column_start, unsigned int column_end) const;

	// Returns the index row of matrix as a float pointer
	float* operator[](unsigned int index);
	const float* operator[](unsigned int index) const;

	// The Insertion operator reads num_rows x num_columns space separated
	// elements from the input stream
	friend istream& operator>>(istream& in, Matrix& rhs);

	// The extraction operator print elements row by row
	friend ostream& operator<<(ostream& out,const Matrix& rhs);

	// Makes a deep copy of the Matrix class
	Matrix(const Matrix& copy);

	// All the allocated memeory is freed when a matrix object goes
	// out of scope
	~Matrix();

	unsigned int num_rows, num_columns, size;
private:
	float** matrix;
};

#endif