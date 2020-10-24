#include "matrix.h"

MyMatrix::MyMatrix() {}
MyMatrix::MyMatrix(const std::string& file_name) : file_name_(file_name) {}   
MyMatrix::~MyMatrix() {}


void MyMatrix::CreateMatrix(){
    for (row_ = 0; row_<kMaxRow; row_++){
        for (column_ = 0; column_<kMaxColumn; column_++){
            matrix_[row_][column_] = rand() % 10;
        }
    }
}


void MyMatrix::CreateDataFile(){
    std::fstream output_stream(file_name_, std::ios::out);

    if(!output_stream){
        std::cout << "file open failed!" << std::endl;
    }

    for(row_ = 0; row_<kMaxRow; row_++) {
        for(column_ = 0; column_<kMaxColumn; column_++){
            output_stream << matrix_[row_][column_] << " ";
        }
        output_stream << std::endl;
    }
    output_stream.close();

    std::cout << "create finish" << std::endl;
}


void MyMatrix::ReadMatrix(const std::string& file_name){
    file_name_ = file_name;
    std::fstream input_stream(file_name_, std::ios::in);

    if(!input_stream){
        std::cout << "file open failed!" << std::endl;
    }

    for(row_ = 0; row_<kMaxRow; row_++){
        for(column_ = 0; column_<kMaxColumn; column_++){
            input_stream >> matrix_[row_][column_];            
        }
    }
    input_stream.close();

    std::cout << "read finish" << std::endl;
}


void MyMatrix::PrintMatrix() const{
    int row = row_;
    int column = column_;

    for(row = 0; row<kMaxRow;row++){
        for(column = 0; column<kMaxColumn;column++){
            std::cout << matrix_[row][column] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "print finish" << std::endl;
}


void MyMatrix::PrintMatrix(const int& start, const int& end) const{
    int row;
    int column;
    
    for (row = start; row<=end; row++){
        for(column = 0; column<kMaxColumn; column++){
            std::cout << matrix_[row][column] << " ";
        }
        std::cout << std::endl;
    }
}
