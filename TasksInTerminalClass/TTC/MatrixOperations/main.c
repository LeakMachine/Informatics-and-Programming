// Copyright 2021 Marina Usova

/*
���������� ������.

����������� ��������� ���������, ���������� � ���������� ����������.

����������� ����� �������� ��� ��� � �����, ��� � ��� ����� ������������ ����. 
�� ��������� ���� ��� � �� ������ ������� � ����� ����. ����� ���������
�������� ������������ �� ����� ������� ����� ���� � �������. 
�������� ��� � ����, � ����� �������� ����������, ������� �� �� �����.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2
#define VECTOR_COORDINATES 3

/// <summary>
/// ��������� ���������� ����� �� ���������� ���������.
/// </summary>
/// <param name="maximum"> ������������ ���������� ��������. </param>
/// <param name="minimum"> ����������� ���������� ��������. </param>
/// <returns> ��������������� ��������. </returns>
int mtxNumberGen(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

/// <summary>
/// ��������� ���������� ������� ������.
/// </summary>
/// <param name="matrix"> �������. </param>
/// <param name="n"> ���-�� �����. </param>
/// <param name="m"> ���-�� ��������. </param>
/// <returns> �������. </returns>
int** mtxSetMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// ������ �������.
/// </summary>
/// <param name="matrix"> �������. </param>
/// <param name="n"> ���-�� ��������. </param>
/// <param name="m"> ���-�� �����. </param>
void mtxPrint(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/// <summary>
/// ��������� ������� �� �����. 
/// </summary>
/// <param name="matrix"> �������. </param>
/// <param name="n"> ���-�� ��������. </param>
/// <param name="m"> ���-�� �����. </param>
/// <param name="value"> �����. </param>
/// <returns> �������. </returns>
int** mtxMultOnNumb(int** matrix, int n, int m, int value) {
    int** res = NULL;
    res = mtxSetMemory(res, N, M);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * value;
        }
    }
    return res;
}

/// <summary>
/// ��������� ������� ���������� ����������.
/// </summary>
/// <param name="matrix"> �������. </param>
/// <param name="n"> ���-�� ��������. </param>
/// <param name="m"> ���-�� �����. </param>
/// <param name="max"> ����. ���������� ��������. </param>
/// <param name="min"> ���. ���������� ��������. </param>
/// <returns> �������. </returns>
void mtxFillRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = mtxNumberGen(max, min);
        }
    }
}

/// <summary>
/// ����������� ������ �� �������.
/// </summary>
/// <param name="matrix"> �������. </param>
/// <param name="n"> ���-�� ��������. </param>
/// <param name="m"> ���-�� �����. </param>
void mtxFreeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

/// <summary>
/// ���������� �������.
/// </summary>
/// <param name="matrix"> ������� </param>
/// <param name="n"> ���-�� ��������. </param>
/// <param name="m"> ���-�� �����. </param>
/// <param name="max"> ����. ���������� ��������. </param>
/// <param name="min"> ���. ���������� ��������.  </param>
/// <param name="name"> �����. </param>
/// <returns> �������. </returns>
int** mtxCreate(int** matrix, int n, int m, int max, int min, char name) {
    matrix = mtxSetMemory(matrix, n, m);
    mtxFillRandValues(matrix, n, m, max, min);
    printf("Matrix %c = \n", name);
    mtxPrint(matrix, n, m);
    return matrix;
}

/// <summary>
/// �������� ������ ��� �������.
/// </summary>
/// <param name="matrixVector"> ������. </param>
/// <param name="vc"> ���-�� ��������� �������. </param>
/// <returns> ������. </returns>
int* mtxVectorSetMemory(int* matrixVector, int vc) {
    matrixVector = (int*)malloc(vc * sizeof(int*));
    return matrixVector;
}

/// <summary>
/// ��������� ���������� ������� ���������� ����������.
/// </summary>
/// <param name="matrixVector"> ������. </param>
/// <param name="vc"> ���-�� ��������� �������. </param>
/// <param name="max"> ����. ���������� ��������. </param>
/// <param name="min"> ���. ���������� ��������. </param>
void mtxVectorFillRandValues(int** matrixVector, int vc, int max, int min) {
    for (int i = 0; i < vc; i++) {
        matrixVector[i] = mtxNumberGen(max, min);
    }
}

/// <summary>
/// �������� ������.
/// </summary>
/// <param name="matrixVector"> ������. </param>
/// <param name="vc"> ���-�� ���������. </param>
void mtxVectorPrint(int* matrixVector, int vc) {
    for (int i = 0; i < vc; i++) {
        printf("%d ", matrixVector[i]);
    } 
    printf("\n");
}

/// <summary>
/// ���������� ������.
/// </summary>
/// <param name="matrixVector"> ������. </param>
/// <param name="vc"> ���-�� ���������. </param>
/// <param name="max"> ����. ���������� ��������. </param>
/// <param name="min"> ���. ���������� ��������. </param>
/// <param name="name"> �����. </param>
/// <returns> ������. </returns>
int* mtxVectorCreate(int* matrixVector, int vc, int max, int min, char name) {
    matrixVector = mtxVectorSetMemory(matrixVector, VECTOR_COORDINATES);
    mtxVectorFillRandValues(matrixVector, VECTOR_COORDINATES, max, min);
    printf("Vector %c = \n", name);
    mtxVectorPrint(matrixVector, vc);
    return matrixVector;
}

/// <summary>
/// �������� ������ �� ������.
/// </summary>
/// <param name="matrixVector"> ������. </param>
/// <param name="vc"> ���-�� ���������. </param>
/// <param name="value"> ������. </param>
/// <returns> ������. </returns>
int* mtxVectorMultOnNumb(int* matrixVector, int vc, int value) {
    int* res = NULL;
    res = mtxVectorSetMemory(res, VECTOR_COORDINATES);
    for (int i = 0; i < vc; i++) {
        res[i] = matrixVector[i] * value;
    }
    return res;
}

int main() {
  int **matrix_A = NULL, **matrix_B = NULL, **result = NULL;
  int *vector_A = NULL, *vector_B = NULL, *resultV = NULL;
  int max = 4, min = 0, value = 0;

  srand(time(NULL));

  matrix_A = mtxCreate(matrix_A, N, M, max, min, 'A');
  matrix_B = mtxCreate(matrix_B, M, K, max, min, 'B');
  value = mtxNumberGen(max, min);

  result = mtxSetMemory(result, N, M);
  result = mtxMultOnNumb(matrix_A, N, M, value);
  printf("Matrix A x %d =\n", value);
  mtxPrint(result, N, M);

  mtxFreeMemory(result, N, M);

  // ���������������� �������
  result = mtxSetMemory(result, M, N);

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      result[i][j] = matrix_A[j][i];
    }
  }

  printf("Matrix AT =\n");
  mtxPrint(result, M, N);
  mtxFreeMemory(result, M, N);

  // ��������� ���� ������

  result = mtxSetMemory(result, N, K);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      result[i][j] = 0;
      for (int k = 0; k < M; k++) {
        result[i][j] += matrix_A[i][k] * matrix_B[k][j];
      }
    }
  }

  printf("Matrix A x B =\n");
  mtxPrint(result, N, K);
  mtxFreeMemory(result, N, K);

  // �������� ���� ������
  result = mtxSetMemory(result, N, M);

  if (N == K) {
      for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
              result[i][j] = matrix_A[i][j] + matrix_B[i][j];
          }
      }
      printf("Matrix A + B =\n");
      mtxPrint(result, N, K);
  }
  else {
      printf("Matrices can't be added. \n\n");
  }

  mtxFreeMemory(result, N, K);

  // �������

  vector_A = mtxVectorCreate(vector_A, VECTOR_COORDINATES, max, min, 'A');
  vector_B = mtxVectorCreate(vector_B, VECTOR_COORDINATES, max, min, 'B');

  // ��������� ������� �� �����

  value = mtxNumberGen(max, min);

  resultV = mtxVectorSetMemory(resultV, VECTOR_COORDINATES);

  resultV = mtxVectorMultOnNumb(vector_A, VECTOR_COORDINATES, value);
  printf("Vector A x %d\n", value);
  mtxVectorPrint(resultV, VECTOR_COORDINATES);

  free(resultV);

  // �������� ���� ��������

  resultV = mtxVectorSetMemory(resultV, VECTOR_COORDINATES);

  for (int i = 0; i < VECTOR_COORDINATES; i++) {
      resultV[i] = vector_A[i] + vector_B[i];
  }

  printf("Vector A + B =\n");
  mtxVectorPrint(resultV, VECTOR_COORDINATES);

  free(resultV);

  // ��������� ���� ��������
  resultV = mtxVectorSetMemory(resultV, VECTOR_COORDINATES);

  if (VECTOR_COORDINATES < 3) {
      printf("Can't do vector A x vector B.");
  }
  else {
      for (int i = 0; i < VECTOR_COORDINATES; i++) {
          switch (i) {
                case 0:

                    resultV[0] = vector_A[1] * vector_B[2] - vector_A[2] * vector_B[1];
                    break;

                 case 1:

                    resultV[1] = -1 * (vector_A[0] * vector_B[2] - vector_A[2] * vector_B[0]);
                    break;

                 case 2:

                    resultV[2] = vector_A[0] * vector_B[1] - vector_A[1] * vector_B[0];
                    break;

          }
      }
      printf("Vector A x B =\n");
      mtxVectorPrint(resultV, VECTOR_COORDINATES);
  }

  free(resultV);

  // �������� ���� ���������� ������
  mtxFreeMemory(matrix_A, N, M);
  mtxFreeMemory(matrix_B, M, N);

  free(vector_A);
  free(vector_B);
  

  return 0;
}
