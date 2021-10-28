// Copyright 2021 Marina Usova

/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода. 
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции. 
Помогите ему в этом, а также допишите функционал, который он не успел.

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
/// Генерация случайного числа из указанного диапазона.
/// </summary>
/// <param name="maximum"> Максимальное допустимое значение. </param>
/// <param name="minimum"> Минимальное допустимое значение. </param>
/// <returns> Сгенерированное значение. </returns>
int mtxNumberGen(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

/// <summary>
/// Выделение указанного размера памяти.
/// </summary>
/// <param name="matrix"> Матрица. </param>
/// <param name="n"> Кол-во строк. </param>
/// <param name="m"> Кол-во столбцов. </param>
/// <returns> Матрица. </returns>
int** mtxSetMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// Печать матрицы.
/// </summary>
/// <param name="matrix"> Матрица. </param>
/// <param name="n"> Кол-во столбцов. </param>
/// <param name="m"> Кол-во строк. </param>
void mtxPrint(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/// <summary>
/// Умножение матрицы на число. 
/// </summary>
/// <param name="matrix"> Матрица. </param>
/// <param name="n"> Кол-во столбцов. </param>
/// <param name="m"> Кол-во строк. </param>
/// <param name="value"> Число. </param>
/// <returns> Матрица. </returns>
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
/// Заполняет матрицу случайными значениями.
/// </summary>
/// <param name="matrix"> Матрица. </param>
/// <param name="n"> Кол-во столбцов. </param>
/// <param name="m"> Кол-во строк. </param>
/// <param name="max"> Макс. допустимое значение. </param>
/// <param name="min"> Мин. допустимое значение. </param>
/// <returns> Матрица. </returns>
void mtxFillRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = mtxNumberGen(max, min);
        }
    }
}

/// <summary>
/// Освобождает память от матрицы.
/// </summary>
/// <param name="matrix"> Матрица. </param>
/// <param name="n"> Кол-во столбцов. </param>
/// <param name="m"> Кол-во строк. </param>
void mtxFreeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

/// <summary>
/// Генерирует матрицу.
/// </summary>
/// <param name="matrix"> Матрица </param>
/// <param name="n"> Кол-во столбцов. </param>
/// <param name="m"> Кол-во строк. </param>
/// <param name="max"> Макс. допустимое значение. </param>
/// <param name="min"> Мин. допустимое значение.  </param>
/// <param name="name"> Буква. </param>
/// <returns> Матрица. </returns>
int** mtxCreate(int** matrix, int n, int m, int max, int min, char name) {
    matrix = mtxSetMemory(matrix, n, m);
    mtxFillRandValues(matrix, n, m, max, min);
    printf("Matrix %c = \n", name);
    mtxPrint(matrix, n, m);
    return matrix;
}

/// <summary>
/// Выделяет память для вектора.
/// </summary>
/// <param name="matrixVector"> Вектор. </param>
/// <param name="vc"> Кол-во координат вектора. </param>
/// <returns> Вектор. </returns>
int* mtxVectorSetMemory(int* matrixVector, int vc) {
    matrixVector = (int*)malloc(vc * sizeof(int*));
    return matrixVector;
}

/// <summary>
/// Заполняет координаты вектора случайными значениями.
/// </summary>
/// <param name="matrixVector"> Вектор. </param>
/// <param name="vc"> Кол-во координат вектора. </param>
/// <param name="max"> Макс. допустимое значение. </param>
/// <param name="min"> Мин. допустимое значение. </param>
void mtxVectorFillRandValues(int** matrixVector, int vc, int max, int min) {
    for (int i = 0; i < vc; i++) {
        matrixVector[i] = mtxNumberGen(max, min);
    }
}

/// <summary>
/// Печатает вектор.
/// </summary>
/// <param name="matrixVector"> Вектор. </param>
/// <param name="vc"> Кол-во координат. </param>
void mtxVectorPrint(int* matrixVector, int vc) {
    for (int i = 0; i < vc; i++) {
        printf("%d ", matrixVector[i]);
    } 
    printf("\n");
}

/// <summary>
/// Генерирует вектор.
/// </summary>
/// <param name="matrixVector"> Вектор. </param>
/// <param name="vc"> Кол-во координат. </param>
/// <param name="max"> Макс. допустимое значение. </param>
/// <param name="min"> Мин. допустимое значение. </param>
/// <param name="name"> Буква. </param>
/// <returns> Вектор. </returns>
int* mtxVectorCreate(int* matrixVector, int vc, int max, int min, char name) {
    matrixVector = mtxVectorSetMemory(matrixVector, VECTOR_COORDINATES);
    mtxVectorFillRandValues(matrixVector, VECTOR_COORDINATES, max, min);
    printf("Vector %c = \n", name);
    mtxVectorPrint(matrixVector, vc);
    return matrixVector;
}

/// <summary>
/// Умножает вектор на скаляр.
/// </summary>
/// <param name="matrixVector"> Вектор. </param>
/// <param name="vc"> Кол-во координат. </param>
/// <param name="value"> Скаляр. </param>
/// <returns> Вектор. </returns>
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

  // транспонирование матрицы
  result = mtxSetMemory(result, M, N);

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      result[i][j] = matrix_A[j][i];
    }
  }

  printf("Matrix AT =\n");
  mtxPrint(result, M, N);
  mtxFreeMemory(result, M, N);

  // умножение двух матриц

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

  // сложение двух матриц
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

  // вектора

  vector_A = mtxVectorCreate(vector_A, VECTOR_COORDINATES, max, min, 'A');
  vector_B = mtxVectorCreate(vector_B, VECTOR_COORDINATES, max, min, 'B');

  // умножение вектора на число

  value = mtxNumberGen(max, min);

  resultV = mtxVectorSetMemory(resultV, VECTOR_COORDINATES);

  resultV = mtxVectorMultOnNumb(vector_A, VECTOR_COORDINATES, value);
  printf("Vector A x %d\n", value);
  mtxVectorPrint(resultV, VECTOR_COORDINATES);

  free(resultV);

  // сложение двух векторов

  resultV = mtxVectorSetMemory(resultV, VECTOR_COORDINATES);

  for (int i = 0; i < VECTOR_COORDINATES; i++) {
      resultV[i] = vector_A[i] + vector_B[i];
  }

  printf("Vector A + B =\n");
  mtxVectorPrint(resultV, VECTOR_COORDINATES);

  free(resultV);

  // умножение двух векторов
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

  // очищение всей выделенной памяти
  mtxFreeMemory(matrix_A, N, M);
  mtxFreeMemory(matrix_B, M, N);

  free(vector_A);
  free(vector_B);
  

  return 0;
}
