#ifndef LAB3_OOP_MATRIX_HXX
#define LAB3_OOP_MATRIX_HXX

#include <iostream>

template<typename T>
class Matrix {
  public:
    template<typename R> Matrix(Matrix<R> &matrix);
    Matrix(int height, int width);
    Matrix(int height, int width, T filler);
    Matrix(int height, int width, T** from);

    T** AllocateMatrix(int height, int width);
    T** AllocateMatrix(int height, int width, T filler);

    T** FillRandom();

    void Output();

    T** CopyMatrix(T** matrix);

    T GetElement(int y, int x);

    int GetWidth();
    int GetHeight();

    T** OperationPlus(T glazier);
    template<typename R> T** OperationPlus(Matrix<R> glazier);

    T** OperationMinus(T glazier);
    template<typename R> T** OperationMinus(Matrix<R> glazier);

    T** OperationDivide(T glazier);
    template<typename R> T** OperationDivide(Matrix<R> glazier);

    T** OperationMultiply(T glazier);
    template<typename R> T** OperationMultiply(Matrix<R> glazier);

    std::tuple<T**, int, int> MatrixMultiplication(Matrix<T> &matrix);

    template<int newHeight, int newWidth> Matrix<T> Resize();
    template<typename R> Matrix<T> ChangeType();

    template<int fromX, int fromY, int toX, int toY> std::tuple<T**, int, int>  GetSubMatrix();
    template<int fromX, int fromY, int toX, int toY> void SetSubMatrix(Matrix<T> &subMatrix);
    template<int fromX, int fromY, int toX, int toY> void InsertMatrix(Matrix<T> matrixToInsert);


  private:
    int height, width;
    T** matrix;

    T** Operation(T glazier, char operation);
    template<typename R> T** Operation(Matrix<R> glazier, char operation);

    bool isNumericType();
    bool OutOfBounds(int y, int x);

    T GetRand(T min, T max);

    int getX(int x);
    int getY(int y);
};

#endif // LAB3_OOP_MATRIX_HXX
