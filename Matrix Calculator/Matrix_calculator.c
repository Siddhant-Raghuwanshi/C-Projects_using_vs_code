#include <stdio.h>
#include <stdlib.h>
int func();
int main()
{

    int n;
    printf("\nWelcome to the Matrix Claculator :\n");
    printf("1.Multiplication of Matrices.\n2.Addition of Matrices\n3.Substrcation of Matrices\n");
    printf("Please select the operation to be performed:");
    scanf("%d", &n);
    int row1, row2, col1, col2;

    // making pointer to pointer for matrix

    /*
      we used double pointer here because
      we want to allocate two parameters of
      the matrix row and column
    */

    int **ptr1, **ptr2, **ptr3, **ptr4, **ptr5;

    printf("\nEnter the no of rows for the first matrix : ");
    scanf("%d", &row1);
    printf("\nEnter the no of columns for the first matrix : ");
    scanf("%d", &col1);
    printf("\nEnter the no of rows for the second matrix : ");
    scanf("%d", &row2);
    printf("\nEnter the no of columns for the second matrix : ");
    scanf("%d", &col2);

    if (col1 != row2)
    {
        printf("The two matrices are incompatible for multiplication please choose another size of format :\n\t M*N=N*X \n\tOR \n\tM*N=X*M \n");
        return 0;
    }

    // allocating memory to all rows of all three matrices
    /*as the product of the matrix have same
    no of rows or columns as the first matrix
    we use size of row1 for allocating memory dynamicaly*/

    // here we use ** here for type casting a pointer to the pointer of row

    ptr1 = (int **)malloc(row1 * sizeof(int *));
    ptr2 = (int **)malloc(row2 * sizeof(int *));
    ptr3 = (int **)malloc(row1 * sizeof(int *));
    ptr4 = (int **)malloc(row1 * sizeof(int *));
    ptr5 = (int **)malloc(row1 * sizeof(int *));

    // Allocating memory for the col of three matrices.

    /* Where as here we use * as we have use one to
    point out no of rows and whats left is column*/

    for (int i = 0; i < row1; i++)
    {
        ptr1[i] = (int *)malloc(sizeof(int) * col1);
    }
    for (int i = 0; i < row2; i++)
    {
        ptr2[i] = (int *)malloc(sizeof(int) * col2);
    }
    for (int i = 0; i < row1; i++)
    {
        ptr3[i] = (int *)malloc(sizeof(int) * col2);
    }
    for (int i = 0; i < row1; i++)
    {
        ptr4[i] = (int *)malloc(sizeof(int) * col2);
    }

    // input of first matrix
    printf("\nEnter the elements for first matrix :\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("\t A[%d,%d] = ", i, j);
            scanf("%d", &ptr1[i][j]);
        }
    }

    // input of second matrix
    printf("\nEnter the elements for second matrix :\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("\t A[%d,%d] = ", i, j);
            scanf("%d", &ptr2[i][j]);
        }
    }

    // output for first matrix
    printf("\nThis is your first matrix: \n\n");
    for (int i = 0; i < row1; i++)
    {
        printf("\t  |");
        for (int j = 0; j < col1; j++)
        {
            printf(" %d ", ptr1[i][j]);
        }
        printf("|\t\n");
    }

    // output for second matrix
    printf("\nThis is your second matrix: \n\n");
    for (int i = 0; i < row2; i++)
    {
        printf("\t  |");
        for (int j = 0; j < col2; j++)
        {
            printf(" %d ", ptr2[i][j]);
        }
        printf("|\t\n");
    }

    switch (n)
    {
    case (1):
    {
        // multiplying matrices
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                ptr3[i][j] = 0;
                for (int k = 0; k < col2; k++)
                {
                    ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j];
                }
            }
        }

        printf("Resultant Matrix is : \n\n");
        for (int i = 0; i < row1; i++)
        {
            printf("\t  |");
            for (int j = 0; j < col1; j++)
            {
                printf(" %d ", ptr3[i][j]);
            }
            printf("|\n");
        }
        break;
    }
    case (2):
    {
        if (row1 != row2 && col1 != col2)
        {
            printf("The matrices cannot be multiplied try again and enter the matrices of same size");
        }
        else
        {
            for (int i = 0; i < row1; i++)
            {
                for (int j = 0; j < col1; j++)
                {
                    ptr4[i][j] = 0;
                    for (int k = 0; k < col2; k++)
                    {
                        ptr4[i][j] = ptr4[i][j] + ptr1[i][k] + ptr2[k][j];
                    }
                }
            }
        }
        printf("The Addition of the Matrix is : \n\n");
        for (int i = 0; i < row1; i++)
        {
            printf("\t  |");
            for (int j = 0; j < col1; j++)
            {
                printf(" %d ", ptr4[i][j]);
            }
            printf("|\n");
        }
        break;
    }
    case (3):
        if (row1 != row2 && col1 != col2)
        {
            printf("The matrices cannot be multiplied try again and enter the matrices of same size");
        }
        else
        {
            for (int i = 0; i < row1; i++)
            {
                for (int j = 0; j < col1; j++)
                {
                    ptr5[i][j] = 0;
                    for (int k = 0; k < col2; k++)
                    {
                        ptr5[i][j] = ptr5[i][j] + ptr1[i][k] + ptr2[k][j];
                    }
                }
            }
            printf("The Addition of the Matrix is : \n\n");
            for (int i = 0; i < row1; i++)
            {
                printf("\t  |");
                for (int j = 0; j < col1; j++)
                {
                    printf(" %d ", ptr5[i][j]);
                }
                printf("|\n");
            }
            break;
        }
    default:
        printf("Invalid Input:\n");
    }

    return 0;
}