#include <iostream>
using namespace std;

class Fraction { // 分数类，分数可以被看成double
    public:
    // explicit-one-argument constructor
    explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    Fraction operator+(const Fraction& f)
    {
        return Fraction(f.m_numerator, f.m_denominator);
    }
    operator double() const // 最好加const 
    {
        return ((double)m_numerator / m_denominator);
    } // 转换函数

    private:
        int m_denominator; // 分母
        int m_numerator; // 分子
};
// 使用
int main()
{
    Fraction f(3,5);
    Fraction d = 4 + f; //  [Error] conversion from double to Fraction requested, 4 不能自动转为Fraction
    //cout << d << endl;// 4.6
}