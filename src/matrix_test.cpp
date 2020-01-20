#include<cassert>
#include "matrix.h"

int main() {
    vector<float> val{1.0, 2.0, 3.0};
    vector<vector<float>> mat{{1.0, 2.0}, {3.0, 4.0}};

    Matrix m1(2,2);
    Matrix m2(val, 1);
    Matrix m22(val, 3);
    Matrix m3(mat);
    Matrix m4(mat);
    Matrix m5 = m4.multiply(m3); 
    m1.print();
    m2.print();
    m22.print();
    m3.print();
    m4.print();
    m5.print();
}