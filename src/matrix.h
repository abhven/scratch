#include <vector>
#include <iostream>

using std::vector;
using std::cout;

template <class T>
class Matrix {
        size_t rows_;
        size_t cols_;
        vector <T> values_;
        static size_t constexpr MAX_LENGTH = 100;
    public:
        size_t get_rows() {return rows_; }
        size_t get_cols() {return cols_; }
        T get_value(size_t r, size_t c) {return values_[r* cols_ + c];}
        T operator [](size_t idx);
        T operator [](vector<size_t> idx);
        Matrix(size_t r, size_t c);
        Matrix(vector<T>& linear, size_t rows);
        Matrix(vector<vector<T>>& mat);
        Matrix<T> multiply(Matrix<T> m);
        void print();
};

template <class T>
Matrix<T>::Matrix(size_t r, size_t c) : rows_{r}, cols_{c} {
    assert(r>0 && r <= MAX_LENGTH  && c>0 && c<= MAX_LENGTH);
    values_ = vector<T> (r*c);
}

template <class T>
Matrix<T>::Matrix(vector<T>& linear, size_t rows) : rows_{rows}{
    assert(rows > 0 && rows <= MAX_LENGTH);
    assert(linear.size() % rows == 0);
    cols_ = linear.size()/ rows;
    values_ = linear;
}

template <class T>
Matrix<T>::Matrix(vector<vector<T>>& mat) {
    rows_ = mat.size();
    assert(rows_);
    cols_ = mat[0].size();
    assert(cols_);
    values_ = vector<T> (rows_ * cols_);
    
    for(size_t i = 0; i< rows_; i++) {
        assert(mat[i].size() >= cols_);
        for(size_t j = 0; j< cols_; j++) {
            values_[i*cols_ + j] = mat[i][j];
        }
    }
}

template <class T>
T Matrix<T>::operator [](size_t idx) {
    assert(idx < rows_ * cols_);
    return values_[idx];
}

template <class T>
T Matrix<T>::operator [](vector<size_t> idx) {
    assert(idx.size() == 2);
    assert(idx[0] >= 0 && idx[0] <rows_ );
    assert(idx[1] >= 0 && idx[1] <cols_ );
    return values_[idx[0] * cols_ + idx[1]];
}

template <class T>
void Matrix<T>::print() {
    cout<<"\n";
    for(size_t i = 0; i< rows_; i++) {
        for(size_t j = 0; j< cols_; j++)
            cout<< values_[i * cols_ + j] <<" ";
        cout<<"\n";
    }
}

template <class T>
Matrix<T> Matrix<T>::multiply(Matrix m){
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
