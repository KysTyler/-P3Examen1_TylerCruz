/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler C
 *
 * Created on November 20, 2020, 1:17 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void FreeMatrix(int**& m, int row, int col);
int** FillRandom(int**& M, int row, int col, int cells);
int** GenerateMatrix(int row, int col);
void printMatrix(int**& matrix, int row, int col);
void conway(int**& mat, int sizeX, int sizeY, int generations, int limitX, int limitY,int acuum);

/*
 * 
 */
int main(int argc, char** argv) {
    //Good main
    cout << "Hello World" << endl;
    srand(time(NULL));
    int mainOption = 0;
    while (mainOption != 3) {
        cout << "#1- Jugar con un tablero aleatorio" << endl;
        cout << "#2- Jugar con el tablero predefinido" << endl;
        cout << "#3- Opcion salida " << endl;
        cout << "Ingrese su opcion: " << endl;
        cin >> mainOption;
        switch (mainOption) {
            case 1:
            {
                int row, col, cells, generations;
                cout << "Ingrese el tamaño del row: " << endl;
                cin >> row;
                cout << "Ingrese el tamaño del coluna: " << endl;
                cin >> col;
                cout << "Ingrese la cantidad de celulas vivas: " << endl;
                cin >> cells;
                cout << "Ingrese cantidad de generaciones: " << endl;
                cin >> generations;

                int** matrixAleatorio = NULL;
                matrixAleatorio = GenerateMatrix(row, col);
                matrixAleatorio = FillRandom(matrixAleatorio, row, col, cells);
                //printMatrix(matrixAleatorio, row, col);

                conway(matrixAleatorio,row,col,generations,0,0,0);
                
                FreeMatrix(matrixAleatorio, row, col);
                
                break;
            }
            case 2:
            {   
                int generations;
                cout << "Ingrese la cantidad de generations quieres ver: " << endl;
                cin >> generations;
                int x = 20, y = 20;
                int temp_mat [20][20] = {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                };

                int ** mat = new int*[y];
                for (int i = 0; i < y; i++) {
                    mat[i] = new int[x];
                    for (int j = 0; j < x; j++) {
                        mat[i][j] = temp_mat[i][j];
                    }
                }
                
                conway(mat,x,y,generations,0,0,0);
                
                FreeMatrix(mat, x, y);
                break;
            }

        }
    }

    return 0;
}

void FreeMatrix(int**& m, int row, int col) {
    if (m != NULL && row > 0) {
        for (int i = 0; i < row; i++) {
            if (m[i] != NULL) {
                delete[] m[i];
                m[i] = NULL;
            }
        }
        delete[] m;
        m = NULL;
    }
}

int** FillRandom(int**& M, int row, int col, int cells) {
    int** tempM = GenerateMatrix(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((rand() % 2) == 1 && cells != 0) {
                tempM[i][j] = 1;
                cells--;
            } else {
                tempM[i][j] = 0;
            }
        }
    }
    return tempM;
}

int** GenerateMatrix(int row, int col) {
    if (row > 0 && col > 0) {
        int** intArray = new int*[row];
        for (int i = 0; i < row; i++) {
            intArray[i] = new int[col];
        }
        return intArray;
    }
    return NULL;
}

void printMatrix(int**& matrix, int row, int col) {
    if (row > 0 && col > 0 && matrix != NULL) {
        for (int i = 0; i < row; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < col; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}

void conway(int**& mat, int sizeX, int sizeY, int generations, int limitX, int limitY,int acuum) {
    if (generations > 0) {
//        if(limitX==0 && limitY >= 0 && limitY <= sizeY -1){
//            if(mat[limitX][limitY - 1] == 1)
//            acuum++;
//        if(mat[limitX][limitY + 1] == 1)
//            acuum++;
//        }
        //mat[limitX -1][limitY - 1] != NULL &&
        //checking each position
//        if(limitX >=0 && limitY >= 0)
//            if( mat[limitX -1][limitY - 1] == 1)
//                acuum++;
//        if(limitX >=0)
//            if( mat[limitX-1][limitY] == 1)
//                acuum++;
//        if(limitX >= 0 && limitY <= sizeY)
//            if(mat[limitX-1][limitY + 1] == 1)
//                acuum++;
//        if(limitY >=0)
//            if(mat[limitX][limitY - 1] == 1)
//                acuum++;
//        if(limitY <= sizeY)
//            if(mat[limitX][limitY + 1] == 1)
//                acuum++;
//        if(limitX <= sizeX && limitY >=0)
//            if(mat[limitX + 1][limitY - 1] == 1)
//                acuum++;
//        if(limitX <= sizeX )
//            if(mat[limitX + 1][limitY])
//                acuum++;
//        if(limitX<=sizeX && limitY <= sizeY)
//            if(mat[limitX+1][limitY + 1] == 1)
//                acuum++;
        //checking how alive
            if(acuum < 2){
                mat[limitX][limitY] = 0;
            }else if(acuum > 3){
                mat[limitX][limitY] = 0;
            }else if(acuum == 3){
                mat[limitX][limitY] = 1;
            }
        
        //running through matrix
        if (limitX == sizeX-1 && limitY == sizeY-1) {
            printMatrix(mat,sizeX,sizeY);
            conway(mat, sizeX, sizeY, generations - 1, 0, 0,0);
        } 
        //else {
            if (limitY == sizeY - 1) {
                conway(mat, sizeX, sizeY, generations, limitX + 1, 0,acuum);
            } 
            conway(mat, sizeX, sizeY, generations, limitX, limitY+1,acuum);
        //}
    }
}

