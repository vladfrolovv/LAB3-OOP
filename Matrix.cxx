#include "Matrix.hxx"
#include "cmath"

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

template<typename T> template<typename R>
Matrix<T>::Matrix(Matrix<R> &matrixToCopyFrom) : height(matrixToCopyFrom.GetHeight()), width(matrixToCopyFrom.GetWidth()) {
  if (typeid(matrixToCopyFrom) == typeid(T)) {
    Matrix<T>::AllocateMatrix(height, width);
    Matrix<T>::CopyMatrix(matrixToCopyFrom.matrix);
  } else {
    Matrix<T>::AllocateMatrix(height, width);
  }
}

template<typename T>
Matrix<T>::Matrix(int height, int width) : height(height), width(width) {
  Matrix<T>::AllocateMatrix(height, width);
}

template<typename T>
Matrix<T>::Matrix(int height, int width, T filler) : height(height), width(width) {
  Matrix<T>::AllocateMatrix(height, width, filler);
}

template<typename T>
Matrix<T>::Matrix(int height, int width, T** matrixToCopyFrom) : height(height), width(width) {
  Matrix<T>::AllocateMatrix(height, width);
  Matrix<T>::CopyMatrix(matrixToCopyFrom);
}

template<typename T>
T** Matrix<T>::AllocateMatrix(int height, int width) {
  Matrix<T>::matrix = new T*[height];
  for (int i = 0; i < height; i++) {
    Matrix<T>::matrix[i] = new T[width];
  }

  FillRandom();
  return matrix;
}

template<typename T>
T** Matrix<T>::AllocateMatrix(int height, int width, T filler) {
  Matrix<T>::matrix = new T*[height];
  for (int i = 0; i < height; i++) {
    Matrix<T>::matrix[i] = new T[width];
    for (int j = 0; j < width; j++) {
      matrix[i][j] = filler;
    }
  }

  return matrix;
}

template<typename T>
T **Matrix<T>::FillRandom() {
  for (int i = 0; i < Matrix<T>::GetHeight(); i++) {
    for (int j = 0; j < Matrix<T>::GetWidth(); j++) {
      if (Matrix<T>::isNumericType()) {
        Matrix<T>::matrix[i][j] = Matrix<T>::GetRand(0, 100);
      }
    }
  }

  return Matrix<T>::matrix;
}

template<typename T>
T **Matrix<T>::CopyMatrix(T** matrixToCopyFrom) {
  Matrix<T>::AllocateMatrix(Matrix<T>::GetHeight(), Matrix<T>::GetWidth());
  for (int i = 0; i < Matrix<T>::GetHeight(); i++) {
    for (int j = 0; j < Matrix<T>::GetWidth(); j++) {
      Matrix<T>::matrix[i][j] = matrixToCopyFrom[i][j];
    }
  }

  return Matrix<T>::matrix;
}

template <typename T> template<int fromX, int fromY, int toX, int toY>
void Matrix<T>::InsertMatrix(Matrix<T> matrixToInsert) {
  Matrix<T> oldMatrix(this);

  int xMax = Matrix<T>::getX(toX), xMin = Matrix<T>::getX(fromX);
  int yMax = Matrix<T>::getX(toY), yMin = Matrix<T>::getX(fromY);

  int newHeight = max(oldMatrix.GetHeight(), max(xMin, xMax)), newWidth = max(oldMatrix.GetWidth(), max(yMin, yMax));

  Matrix<T>::Resize<newHeight, newWidth>();
  for (int i = 0; i < oldMatrix.GetHeight(); i++) {
    for (int j = 0; j < oldMatrix.GetWidth(); j++) {

    }
  }

}

template<typename T>
int Matrix<T>::GetWidth() {
  return Matrix<T>::width;
}

template<typename T>
int Matrix<T>::GetHeight() {
  return Matrix<T>::height;
}

template<typename T>
T Matrix<T>::GetElement(int y, int x) {
  if (abs(x) >= Matrix<T>::GetWidth() || abs(y) >= Matrix<T>::GetWidth()) {
    // std::cout << "Error: Index is out of bounds" << std::endl;
    return -1;
  }

  return Matrix<T>::matrix[y >= 0 ? y : Matrix<T>::height + y][x >= 0 ? x : Matrix<T>::width + x];
}

template<typename T>
T** Matrix<T>::OperationPlus(T glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::Operation(glazier, '+');
  return Matrix<T>::matrix;
}

template<typename T> template<typename R>
T** Matrix<T>::OperationPlus(Matrix<R> glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::CopyMatrix(Matrix<T>::Operation(glazier, '+'));
  return Matrix<T>::matrix;
}

template<typename T>
T** Matrix<T>::OperationMinus(T glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::Operation(glazier, '-');
  return Matrix<T>::matrix;
}

template<typename T> template<typename R>
T** Matrix<T>::OperationMinus(Matrix<R> glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::CopyMatrix(Matrix<T>::Operation(glazier, '-'));
  return Matrix<T>::matrix;
}

template<typename T>
T** Matrix<T>::OperationDivide(T glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::Operation(glazier, '/');
  return Matrix<T>::matrix;
}

template<typename T> template<typename R>
T** Matrix<T>::OperationDivide(Matrix<R> glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::CopyMatrix(Matrix<T>::Operation(glazier, '/'));
  return Matrix<T>::matrix;
}

template<typename T>
T** Matrix<T>::OperationMultiply(T glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::Operation(glazier, '*');
  return Matrix<T>::matrix;
}

template<typename T> template<typename R>
T** Matrix<T>::OperationMultiply(Matrix<R> glazier) {
  if (!Matrix<T>::isNumericType()) {
    return Matrix<T>::matrix;
  }

  Matrix<T>::CopyMatrix(Matrix<T>::Operation(glazier, '*'));
  return Matrix<T>::matrix;
}

template<typename T>
T **Matrix<T>::Operation(T glazier, char operation) {
  if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
    return Matrix<T>::matrix;
  }

  for (int i = 0; i < Matrix<T>::GetHeight(); i++) {
    for (int j = 0; j < Matrix<T>::GetWidth(); j++) {
      switch (operation) {
        case ('+'):
          Matrix<T>::matrix[i][j] += (T)glazier;
          break;
        case ('-'):
          Matrix<T>::matrix[i][j] -= (T)glazier;
          break;
        case ('/'):
          Matrix<T>::matrix[i][j] /= (T)glazier;
          break;
        case ('*'):
          Matrix<T>::matrix[i][j] *= (T)glazier;
          break;
        default:
          break;
      }
    }
  }

  return Matrix<T>::matrix;
}

template<typename T>
std::tuple<T**, int, int> Matrix<T>::MatrixMultiplication(Matrix<T> &matrix) {
  if (matrix.GetHeight() != Matrix<T>::GetWidth() && matrix.GetWidth() != Matrix<T>::GetHeight()) {
    return { Matrix<T>::matrix, Matrix<T>::GetHeight(), Matrix<T>::GetWidth() } ;
  }

  if (!Matrix<T>::isNumericType()) {
    return { Matrix<T>::matrix, Matrix<T>::GetHeight(), Matrix<T>::GetWidth() } ;
  }

  Matrix<T> multipliedMatrix(Matrix<T>::GetHeight(), Matrix<T>::GetHeight());

  for (int i = 0; i < multipliedMatrix.GetHeight(); i++) {
    for (int j = 0; j < multipliedMatrix.GetWidth(); j++) {
      T cell = 0;
      for (int k = 0; k < Matrix<T>::GetWidth(); k++) {
        cell += Matrix<T>::GetElement(i, k) * matrix.GetElement(k, j);
      }
      multipliedMatrix.matrix[i][j] = cell;
    }
  }

  return { multipliedMatrix.matrix, multipliedMatrix.GetHeight(), multipliedMatrix.GetWidth() };
}

template<typename T> template<typename R>
T **Matrix<T>::Operation(Matrix<R> glazier, char operation) {
  if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
    std::cout << "ERROR: unknown operation" << std::endl;
    return Matrix<T>::matrix;
  }

  if (!Matrix<T>::isNumericType() || !Matrix<R>::isNumericType()) {
    std::cout << "ERROR: can't perform mathematical operation with !numeric type" << std::endl;
    return Matrix<T>::matrix;
  }

  T** matrix = AllocateMatrix(Matrix<T>::GetHeight(), Matrix<T>::GetWidth());
  for (int i = 0; i < min(Matrix<T>::GetHeight(), Matrix<R>::GetHeight()) ; i++) {
    for (int j = 0; j < min(Matrix<T>::GetHeight(), Matrix<R>::GetHeight()); j++) {
      switch (operation) {
        case ('+'):
          matrix[i][j] += (T)glazier[i][j];
          break;
        case ('-'):
          matrix[i][j] -= (T)glazier[i][j];
          break;
        case ('/'):
          matrix[i][j] /= (T)glazier[i][j];
          break;
        case ('*'):
          matrix[i][j] *= (T)glazier[i][j];
          break;
        default:
          break;
      }
    }
  }

  return matrix;
}

template<typename T> template<int height, int width>
Matrix<T> Matrix<T>::Resize() {
  T** matrix = AllocateMatrix(height, width);

  Matrix<T>::height = height;
  Matrix<T>::width = width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (!Matrix<T>::OutOfBounds(i, j)) {
        matrix[i][j] = Matrix<T>::GetElement(i, j);
      }
    }
  }

  CopyMatrix(matrix);
  return matrix;
}

template<typename T> template<typename R>
Matrix<T> Matrix<T>::ChangeType() {
  return new Matrix<R>(Matrix<T>::GetHeight(), Matrix<T>::GetWidth());
}

template<typename T> template<int fromX, int fromY, int toX, int toY>
std::tuple<T**, int, int> Matrix<T>::GetSubMatrix() {
  int xMax = Matrix<T>::getX(toX), xMin = Matrix<T>::getX(fromX);
  int yMax = Matrix<T>::getX(toY), yMin = Matrix<T>::getX(fromY);

  Matrix<T> subMatrix(abs(yMin - yMax), abs(xMin - xMax));
  for (int i = 0; i < subMatrix.GetHeight(); i++) {
    for (int j = 0; j < subMatrix.GetWidth(); j++) {
      if (!Matrix<T>::OutOfBounds(min(yMin, yMax) + i, min(xMin, xMax) + j)) {
        subMatrix.matrix[i][j] = Matrix<T>::GetElement(min(yMin, yMax) + i, min(xMin, xMax) + j);
      }
    }
  }
  return {subMatrix.matrix, subMatrix.GetHeight(), subMatrix.GetWidth()};
}

template<typename T> template<int fromX, int fromY, int toX, int toY>
void Matrix<T>::SetSubMatrix(Matrix<T> &subMatrix) {
  int xMax = Matrix<T>::getX(toX), xMin = Matrix<T>::getX(fromX);
  int yMax = Matrix<T>::getX(toY), yMin = Matrix<T>::getX(fromY);

  if (xMax > Matrix<T>::GetWidth() || yMax > Matrix<T>::GetHeight()) {
    std::cout << "ERROR: SubMatrix is out of bounds(use Insert instead)";
  }

  for (int i = 0; i < subMatrix.GetHeight(); i++) {
    for (int j = 0; j < subMatrix.GetWidth(); j++) {
      if (!Matrix<T>::OutOfBounds(min(yMin, yMax) + i, min(xMin, xMax) + j)) {
        Matrix<T>::matrix[min(yMin, yMax) + i][min(xMin, xMax) + j] = subMatrix.GetElement(i, j);
      }
    }
  }
}



template<typename T>
void Matrix<T>::Output() {
  for (int i = 0; i < Matrix<T>::GetHeight(); i++) {
    for (int j = 0; j < Matrix<T>::GetWidth(); j++) {
      std::cout << Matrix<T>::GetElement(i, j) << " ";
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

template<typename T>
int Matrix<T>::getY(int y) {
  return (y >= 0 ? min(y, Matrix<T>::GetHeight()) : min(Matrix<T>::GetHeight() + y, Matrix<T>::GetHeight()));
}

template<typename T>
int Matrix<T>::getX(int x) {
  return (x >= 0 ? min(x, Matrix<T>::GetWidth()) : min(Matrix<T>::GetWidth() + x, Matrix<T>::GetWidth()));
}

template <typename T>
T Matrix<T>::GetRand(T min, T max) {
  return min + rand() % (( max + 1 ) - min);
}

template<typename T>
bool Matrix<T>::OutOfBounds(int y, int x) {
  return !(y >= 0 && y < Matrix<T>::GetHeight() && x >= 0 && x < Matrix<T>::GetWidth());
}

template<typename T>
bool Matrix<T>::isNumericType() {
  return (
    typeid(T) == typeid(int) ||
    typeid(T) == typeid(float) ||
    typeid(T) == typeid(double) ||
    typeid(T) == typeid(long) ||
    typeid(T) == typeid(long int) ||
    typeid(T) == typeid(long double) ||
    typeid(T) == typeid(long long) ||
    typeid(T) == typeid(long long int)
  );
}
