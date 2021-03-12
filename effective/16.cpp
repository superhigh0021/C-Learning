#include<iostream>
using namespace std;

template<typename T>
class SquareMatrixBase {
protected:
    SquareMatrixBase(std::size_t n, T* pMem)
        :size(n), pData(pMem) {}
    void invert(std::size_t matrixSize);
    void setDataPtr(T* ptr) { pData = ptr; }
private:
    std::size_t size;
    T* pData;
};//ksd

template<typename T, std::size_t n>
class SquareMatrix :private SquareMatrixBase<T> {
private:
    using SquareMatrixBase<T>::invert;
    T data[n * n];
public:
    SquareMatrix() :SquareMatrixBase<T>(n, data) {}
    void invert() {
        this->invert(n);
    }
};
template<typename T>
void SquareMatrixBase<T>::invert(std::size_t matrixSize) {
    cout << matrixSize << endl;
}

int main(void) {
    SquareMatrix<int, 6> s;
    s.invert();
    return 0;
}
