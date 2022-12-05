#include "Matrix.cxx"

int main() {
  std::cout << "\tInitial Matrix" << std::endl;
  Matrix<int> matrix(3, 3);
  matrix.Output();

  std::cout << "\tMatrix Plus 100" << std::endl;
  matrix.OperationPlus(100);
  matrix.Output();

  std::cout << "\tMatrix Divided by 10" << std::endl;
  matrix.OperationDivide(10);
  matrix.Output();

  std::cout << "\tMatrix Minus 100" << std::endl;
  matrix.OperationMinus(100);
  matrix.Output();

  std::cout << "\tMatrix Multiplied by 100" << std::endl;
  matrix.OperationMultiply(100);
  matrix.Output();


  std::cout << "\tMatrix To Multiply I" << std::endl;
  Matrix<int> matrixToMultiplyI(3, 5);
  matrixToMultiplyI.Output();

  std::cout << "\tMatrix To Multiply II" << std::endl;
  Matrix<int> matrixToMultiplyII(5, 3);
  matrixToMultiplyI.Output();

  std::cout << "\tmatrixToMultiplyI * matrixToMultiplyII" << std::endl;
  auto[multipliedMatrix, multipliedMatrixHeight, multipliedMatrixWidth] = matrixToMultiplyI.MatrixMultiplication(matrixToMultiplyII);
  Matrix<int> MultipliedMatrix(multipliedMatrixHeight, multipliedMatrixWidth, multipliedMatrix);
  MultipliedMatrix.Output();

  std::cout << "\tSubMatrix from Matrix" << std::endl;
  auto[subMatrix, subMatrixHeight, subMatrixWidth] = matrix.GetSubMatrix<1,1,5,5>();
  Matrix<int> SubMatrixFromMatrix(subMatrixHeight, subMatrixWidth, subMatrix);
  SubMatrixFromMatrix.Output();

  std::cout << "\tMatrix" << std::endl;
  Matrix<char> m(10, 10, '-');
  m.Output();

  std::cout << "\tMatrix to Insert" << std::endl;
  Matrix<char> mi(5, 5, '|');
  mi.Output();

  std::cout << "\tInserted Matrix" << std::endl;
  m.SetSubMatrix<3, 3, 8, 8>(mi);
  m.Output();

  return 0;
}
