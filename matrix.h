#ifndef __CREATEMATRIX_H__
#define __CREATEMATRIX_H__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

const int kMaxRow = 1000;
const int kMaxColumn = 1000;
const int kThreadWorkQuantum = kMaxRow / 4;

class MyMatrix{
public:
    MyMatrix();
    explicit MyMatrix(const std::string& file_name);
    ~MyMatrix();
    void CreateMatrix();
    void CreateDataFile();
    void ReadMatrix(const std::string& file_name);
    void PrintMatrix() const;
    void PrintMatrix(const int& start, const int& end) const;
    int matrix_[kMaxRow][kMaxColumn] = {0};

private:
    int row_ = 0;
    int column_ = 0;
    std::string file_name_ = "";
};

#endif
