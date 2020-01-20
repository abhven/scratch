#include <vector>

using std::vector;

class Matrix {
        size_t rows_;
        size_t cols_;
        vector <float> values_;
        static size_t constexpr MAX_LENGTH = 100;
    public:
        size_t get_rows() {return rows_; }
        size_t get_cols() {return cols_; }
        float  get_value(size_t r, size_t c) {return values_[r* cols_ + c];}
        float operator [](size_t idx);
        float operator [](vector<size_t> idx);
        Matrix(size_t r, size_t c);
        Matrix(vector<float>& linear, size_t rows);
        Matrix(vector<vector<float>>& mat);
        Matrix multiply(Matrix m);
        void print();
};