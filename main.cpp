#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>


void MatrixProduct(const MyMatrix& matrix_a, const MyMatrix& matrix_b, MyMatrix *matrix_result, const int& start, const int& end);

int main(int argc, char* argv[]){
    clock_t start, end;
    double result = 0;
    srand(time(NULL));

    auto matrix_c = new MyMatrix();
    auto matrix_d = new MyMatrix();
    auto matrix_result = new MyMatrix("C.dat");
    
    if (argv[1] == nullptr){ // if not exist A.dat B.dat
                            // create A.dat B.dat
        auto matrix_a = new MyMatrix("A.dat");
        auto matrix_b = new MyMatrix("B.dat");

        matrix_a->CreateMatrix();
        matrix_b->CreateMatrix();
        matrix_a->CreateDataFile();
        matrix_b->CreateDataFile();
        matrix_c->ReadMatrix("A.dat");
        matrix_d->ReadMatrix("B.dat");
        delete matrix_a;
        delete matrix_b;

    } else {
        matrix_c->ReadMatrix(argv[1]);
        matrix_d->ReadMatrix(argv[2]);
    }
   
    matrix_c->PrintMatrix();
    std:: cout << "-----------------------------" << std::endl;
    matrix_d->PrintMatrix();
    std:: cout << "-----------------------------" << std::endl;

    start = clock();

    std::thread t1(MatrixProduct, *matrix_c, *matrix_d, matrix_result, 0, kThreadWorkQuantum);
    std::thread t2(MatrixProduct, *matrix_c, *matrix_d, matrix_result, kThreadWorkQuantum, kThreadWorkQuantum*2);
    std::thread t3(MatrixProduct, *matrix_c, *matrix_d, matrix_result,kThreadWorkQuantum*2 ,kThreadWorkQuantum*3);
    std::thread t4(MatrixProduct, *matrix_c, *matrix_d, matrix_result,kThreadWorkQuantum*3 ,kThreadWorkQuantum*4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    end = clock();
    result = (double)(end-start);
    
    std::cout << std::endl << "Thread 1 Result" << std::endl;
    matrix_result->PrintMatrix(0,kThreadWorkQuantum -1);    //thread work range
    std:: cout << "-----------------------------" << std::endl;

    std::cout << std::endl << "Thread 2 Result" << std::endl;
    matrix_result->PrintMatrix(kThreadWorkQuantum,(kThreadWorkQuantum*2)-1);
    std:: cout << "-----------------------------" << std::endl;

    std::cout << std::endl << "Thread 3 Result" << std::endl;
    matrix_result->PrintMatrix(kThreadWorkQuantum*2,(kThreadWorkQuantum*3)-1);
    std:: cout << "-----------------------------" << std::endl;

    std::cout << std::endl << "Thread 4 Result" << std::endl;
    matrix_result->PrintMatrix(kThreadWorkQuantum*3,(kThreadWorkQuantum*4)-1);
    std:: cout << "-----------------------------" << std::endl;

    matrix_result->PrintMatrix();
    matrix_result->CreateDataFile();    //create C.dat

    delete matrix_c;
    delete matrix_d;
    delete matrix_result;

    std::cout << "End main()" << std::endl;
    std::cout << "time :" << (double)result/ CLOCKS_PER_SEC << "sec" << std::endl;

    return 0;
}


void MatrixProduct(const MyMatrix& matrix_a, const MyMatrix& matrix_b, MyMatrix *matrix_result, const int& start, const int& end){
    int row, column;
    int i;

    for (row = start; row<end; row++){
        for (column = 0; column<kMaxColumn;column++){
            for (i=0;i<kMaxColumn;i++){
                matrix_result->matrix_[row][column] += matrix_a.matrix_[row][i] * matrix_b.matrix_[i][column];
            }
        }
    }
}