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
void FreeMatrix(int**& m, int row,int col);
int** FillRandom(int**& M,int row,int col);
int** GenerateMatrix(int row, int col);


/*
 * 
 */
int main(int argc, char** argv) {
    //Good main
    cout << "Hello World" << endl;
    srand ( time(NULL) );
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
                int random = (rand() % 2);
                cout << "random: " << random <<endl;
                break;
            }
            case 2:
            {
                int x=20,y=20;
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
                
                
                FreeMatrix(mat,x,y);
                break;
            }

        }
    }
    
    return 0;
}
void FreeMatrix(int**& m, int row,int col) {
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

int** FillRandom(int**& M,int row,int col){
    int** tempM = GenerateMatrix(row,col);
    int random = (rand() % 2) - 1;
    return NULL;
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

