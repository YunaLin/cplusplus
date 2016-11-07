#include"Matrix.h"
using namespace std;

Matrix::Matrix(string n, int h, int w, int **p) {
    name = n;
    width = w;
    height = h;
    param = new int*[height];
    for (int i = 0; i < height; i++)
        param[i] = new int[width];
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
        param[i][j] = p[i][j];
}
Matrix::Matrix(const Matrix& other) {
    name = other.name;
    width = other.width;
    height = other.height;
    param = new int*[height];
    for (int i = 0; i < height; i++)
        param[i] = new int[width];
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
        param[i][j] = other.param[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < height; i++)
        delete []param[i];
    delete []param;
}
bool Matrix::operator==(const Matrix& other) {
    if (name == other.name)
        if (height == other.height)
            if (width == other.width)
            return true;
    return false;
}
bool Matrix::operator!=(const Matrix& other) {
    if (name == other.name)
        if (height == other.height)
            if (width == other.width)
            return false;
    return true;
}
void Matrix::operator+=(const Matrix& other) {
    if (width != other.width||height != other.height) {
        cout << "invalid addition." << endl;
    } else {
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    param[i][j] += other.param[i][j];
    }
}
void Matrix::operator-=(const Matrix& other) {
    if (width != other.width||height != other.height) {
        cout << "invalid substraction." << endl;
    } else {
    for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    param[i][j] -= other.param[i][j];
    }
}

Matrix Matrix::operator*(const Matrix& other) {
    if (width != other.height) {
        cout << "invalid multiplication." << endl;
        Matrix m;
        return m;
    } else {
    int mheight = height;
    int mwidth = other.width;
    int max1 = (width > other.width ? width:other.width);
    int max2 = (height > other.height ? height:other.height);
    int **mparam = new int*[max2];
    for (int i = 0; i < max2; i++) {
        mparam[i] = new int[max1];
        for (int j = 0; j < max1; j++)
        mparam[i][j] = 0;
    }
    for (int i = 0; i < mheight; i++)
    for (int j = 0; j < mwidth; j++)
    for (int k = 0; k < width; k++)
    mparam[i][j] += param[i][k] * other.param[k][j];
    Matrix m = Matrix("newMat", mheight, mwidth, mparam);
    for (int i = 0; i < max2; i++)
        delete []mparam[i];
    delete []mparam;
    return m;
    }
}
 
