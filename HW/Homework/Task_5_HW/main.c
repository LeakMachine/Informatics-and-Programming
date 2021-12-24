#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "dirent-master/include/dirent.h"
#include <sys/stat.h>     
#include <locale.h>
#include <time.h>

int quick_count = 0, merge_count = 0, selection_count = 0;

int getFileSize(const char* file) {
  struct stat st;
  int full_size = 0;

  if (stat(file, &st) == 0) {
    if ((st.st_mode & S_IFMT) == S_IFDIR)
      return -1;
    else if ((st.st_mode & S_IFMT) == S_IFREG)
      return st.st_size;
    else
      return -2;
  }
}

int getSizesFromDir(char* path, char** testchar2, int* fileSizeArray, int i) {
  struct dirent* cur_file;
  DIR* dir;

  char full_file_path[200];

  dir = opendir(path);
  if (dir) {
    while ((cur_file = readdir(dir)) != NULL) {
      if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
        strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
        int cur_file_size = getFileSize(full_file_path);
        if (cur_file_size >= 0) {
          printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
          fileSizeArray[i] = cur_file_size;
          int k;
          for (k = 0; cur_file->d_name[k] != '\0'; k++)
            testchar2[i][k] = cur_file->d_name[k];
          testchar2[i][k] = '\0';
          i++;
        }
        else if (cur_file_size == -1)
          getSizesFromDir(full_file_path, testchar2, fileSizeArray, i);
      }
    }
    closedir(dir);
  }
  return i;
}

void selectionSort(int* arr1, char** arr2, int size) {

  for (int i = 0; i < size - 1; i++)
  {
    int min_i = i;

    for (int j = i + 1; j < size; j++)
    {
      if (arr1[j] < arr1[min_i])
      {
        min_i = j;
        selection_count++;
      }
    }

    if (min_i != i)
    {
      int temp = arr1[i];
      arr1[i] = arr1[min_i];
      arr1[min_i] = temp;

      char* temp2 = arr2[i];
      arr2[i] = arr2[min_i];
      arr2[min_i] = temp2;

      selection_count++;
    }
  }

  int j = 0;

  for (int i = 0; i < size; i++) {
    for (j = 0; j < 100; j++) {
        printf("%c", arr2[i][j]);
    }
    j = 0;
    printf(" - %d (B) (%d kB)\n", arr1[i], arr1[i] / 1024);
  }
}

void quickSort(int* arr1, int size, int first, int last, char** arr2)
{
    int i = first, j = last;
    int x = arr1[(first + last) / 2];
    do {
        while (arr1[i] < x) {
            i++;
        }
        while (arr1[j] > x) {
            j--;
        }

        if (i <= j)
        {
            if (i != j && arr1[i] != arr1[j])
            {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;

                char* temp2 = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp2;
                quick_count++;
            }
            i++;  j--;
        }
    } while (i <= j);

    if (i < last)
        quickSort(arr1, size, i, last, arr2);
    if (first < j)
        quickSort(arr1, size, first, j, arr2);
    if (i == ((size - 1) / 2)) {
        for (int i = 0; i < size; i++) {
            for (j = 0; j < 100; j++) {
            printf("%c", arr2[i][j]);
            }
           j = 0;
            printf(" - %d (B) (%d kB)\n", arr1[i], arr1[i] / 1024);
        }
    }
}

void Merge(int* arr1, char** arr2, int first, int middle, int last, int size) {
    int n1 = middle - first + 1;
    int n2 = last - middle;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    int** L2 = (char**)malloc(n1 * sizeof(char*));
    int** R2 = (char**)malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++)
        L[i] = arr1[first + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr1[middle + 1 + i];
    for (int i = 0; i < n1; i++)
        L2[i] = arr2[first + i];
    for (int i = 0; i < n2; i++)
        R2[i] = arr2[middle + 1 + i];

    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr1[k] = L[i];
            arr2[k] = L2[i];
            merge_count++;
            i++;
        }
        else
        {
            arr1[k] = R[j];
            arr2[k] = R2[j];
            merge_count++;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr1[k] = L[i];
        arr2[k] = L2[i];
        i++;
        k++;
        merge_count++;
    }

    while (j < n2)
    {
        arr1[k] = R[j];
        arr2[k] = R2[j];
        j++;
        k++;
        merge_count++;
    }

    if (i == (size / 2)) {
       int j = 0;
       for (int i = 0; i < (size); i++) {
            for (j = 0; j < 100; j++) {
                printf("%c", arr2[i][j]);
            }
            j = 0;
            printf(" - %d (B) (%d kB)\n", arr1[i], arr1[i] / 1024);
       }
    }

}

void mergeSort(int* arr1, char** arr2, int first, int last, int size) {
    int middle = (last + first) / 2;
    if (last - first == 0)
        return;
    mergeSort(arr1, arr2, first, middle, size);
    mergeSort(arr1, arr2, middle + 1, last, size);
    Merge(arr1, arr2, first, middle, last, size);
  
}

#define MAX_FILE_COUNT 10000

int main() {

  setlocale(LC_ALL, "LC_CTYPE=.utf8");

  char path[200];

  struct dirent* cur_file;
  DIR* dir;

  time_t time0, time1;

  int file_count = 0;

  char full_file_path[200];

  int fileSizeArray[MAX_FILE_COUNT];

  char** testchar2 = (char**)malloc(MAX_FILE_COUNT * sizeof(char*));
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
    testchar2[i] = (char*)malloc(100 * sizeof(char));
  }

  char** testchar3 = (char**)malloc(MAX_FILE_COUNT * sizeof(char*));
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
      testchar3[i] = (char*)malloc(100 * sizeof(char));
  }

  char** testchar4 = (char**)malloc(MAX_FILE_COUNT * sizeof(char*));
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
      testchar4[i] = (char*)malloc(100 * sizeof(char));
  }

  int exit = 0;

  printf("Input path to dir: ");
  gets(path);

  dir = opendir(path);

  file_count = getSizesFromDir(path, testchar2, fileSizeArray, 0);

  do {

      int cFileSizeArray[MAX_FILE_COUNT];
      int cFileSizeArray2[MAX_FILE_COUNT];

      for (int i = 0; i < file_count; i++) {
          testchar3[i] = testchar2[i];
      }

      for (int i = 0; i < file_count; i++) {
          testchar4[i] = testchar2[i];
      }

      for (int i = 0; i < file_count; i++) {
          cFileSizeArray[i] = fileSizeArray[i];
      }

      for (int i = 0; i < file_count; i++) {
          cFileSizeArray2[i] = fileSizeArray[i];
      }

      int sortSelect;
      double timer;

      printf("Enter type of sort you would like to do (1 - Selection, 2 - Quick, 3 - Merge): ");
      scanf_s("%d", &sortSelect);

      switch (sortSelect) {
      case 1: {
          printf("-------------------------------------------\n");
          time0 = clock();
          selectionSort(fileSizeArray, testchar2, file_count);
          time1 = clock();
          timer = (double)(time1 - time0) / 1000;
          printf("%.7lf - time of work (ms) | %d - amount of permutations", timer, selection_count);
          break;
      }
      case 2: {
          printf("-------------------------------------------\n");
          time0 = clock();
          quickSort(cFileSizeArray, file_count, 0, file_count - 1, testchar3);
          time1 = clock();
          timer = (double)(time1 - time0) / 1000;
          printf("%.7lf - time of work (ms) | %d - amount of permutations", timer, quick_count);
          break;
      }

      case 3: {
          printf("-------------------------------------------\n");
          time0 = clock();
          mergeSort(cFileSizeArray2, testchar4, 0, file_count - 1, file_count);
          time1 = clock();
          timer = (double)(time1 - time0) / 1000;
          printf("%.7lf - time of work (ms) | %d - amount of permutations", timer, merge_count);
          break;
      }

      default: {
          printf("-------------------------------------------\n");
          printf("Error, wrong input.");
          break;
      }
      }
      printf("\nDo you want to exit the program? 1/0: ");
      scanf_s("%d", &exit);
  } while (exit != 1);

  return 0;
}