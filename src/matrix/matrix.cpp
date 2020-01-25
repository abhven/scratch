#include <iostream>
#include <vector>
#include <cassert>
#include "matrix.h"

using std::vector;
using std::cout;

Matrix::Matrix(size_t r, size_t c) : rows_{r}, cols_{c} {
    assert(r>0 && r <= MAX_LENGTH  && c>0 && c<= MAX_LENGTH);
    values_ = vector<float> (r*c);
}

Matrix::Matrix(vector<float>& linear, size_t rows) : rows_{rows}{
    assert(rows > 0 && rows <= MAX_LENGTH);
    assert(linear.size() % rows == 0);
    cols_ = linear.size()/ rows;
    values_ = linear;
}

Matrix::Matrix(vector<vector<float>>& mat) {
    rows_ = mat.size();
    assert(rows_);
    cols_ = mat[0].size();
    assert(cols_);
    values_ = vector<float> (rows_ * cols_);
    
    for(size_t i = 0; i< rows_; i++) {
        assert(mat[i].size() >= cols_);
        for(size_t j = 0; j< cols_; j++) {
            values_[i*cols_ + j] = mat[i][j];
        }
    }
}

float Matrix::operator [](size_t idx) {
    assert(idx < rows_ * cols_);
    return values_[idx];
}

float Matrix::operator [](vector<size_t> idx) {
    assert(idx.size() == 2);
    assert(idx[0] >= 0 && idx[0] <rows_ );
    assert(idx[1] >= 0 && idx[1] <cols_ );
    return values_[idx[0] * cols_ + idx[1]];
}

void Matrix::print() {
    cout<<"\n";
    for(size_t i = 0; i< rows_; i++) {
        for(size_t j = 0; j< cols_; j++)
            cout<< values_[i * cols_ + j] <<" ";
        cout<<"\n";
    }
}

/**
 * @brief 
 * 
 * @param m 
 * @return Matrix 
 */
Matrix Matrix::multiply(Matrix m){
    assert(cols_ == m.get_rows());
    Matrix res(rows_, m.get_cols());
    for(size_t i = 0; i< rows_ ; i++)
        for(size_t j = 0; j< m.get_cols(); j++){
            float sum = 0.f;
            for(size_t k = 0 ; k< cols_; k++)
                sum += values_[i*cols_ + k] * m[vector<size_t>{k, j}];
            res.values_[i*res.cols_ + j] =  sum;
        }
    return res;
}
