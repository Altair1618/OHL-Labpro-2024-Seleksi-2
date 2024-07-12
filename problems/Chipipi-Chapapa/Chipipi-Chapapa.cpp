#include <iostream>
using namespace std;

/**
 * CUSTOM NUM (& turunannya)
 * Menyimpan bilangan bulat
 * Namun dapat mengembalikan bilangan bulat yang berbeda */
class CustomNum
{
protected:
    int num = 0;

public:
    void setNum(int num) { this->num = num; }
    virtual int getCustomNum() const { return num / 3; }
};

class DerivedCustomNum : public CustomNum
{
public:
    int getCustomNum() const override { return num; }
};

/**
 * A & B
 * A menyimpan bilangan bulat p
 * B adalah kelas turunan dari A yang juga menyimpan bilangan bulat q
 * Hati-hati dengan beberapa metode di bawah ini! */
class A
{
private:
    int p = 0;

protected:
    int getP() const { return p; }

public:
    A() {}
    A(const A &a) : p(a.p + 999) {}
    void operator-(CustomNum cn) { p -= cn.getCustomNum(); }
    void operator-(CustomNum *cn) { p -= cn->getCustomNum(); }
};

class B : public A
{
private:
    int q = 0;

public:
    void operator-(CustomNum cn) { q -= cn.getCustomNum(); }
    void operator-(CustomNum *cn) { q -= cn->getCustomNum(); }
    void print() const { cout << getP() << " " << q << endl; }
};

/**
 * WRAPPER
 * Wrapper adalah kelas yang menyimpan objek B
 * DerivedWrapper adalah turunan dari Wrapper
 * whoAmI1 dan whoAmI2 adalah fungsi yang menerima objek Wrapper
 */
class Wrapper
{
    friend void whoAmI1(Wrapper w);
    friend void whoAmI2(Wrapper &w);

private:
    B b;

protected:
    virtual void whoAmI() const { cout << "Wrapper" << endl; }

public:
    B getB() const { return b; }
    B *getBPtr() { return &b; }
};

class DerivedWrapper : public Wrapper
{
protected:
    void whoAmI() const override { cout << "DerivedWrapper" << endl; }
};

void whoAmI1(Wrapper w) { w.whoAmI(); }
void whoAmI2(Wrapper &w) { w.whoAmI(); }

int main()
{
    int m, n;      // Jangan diubah
    cin >> m >> n; // Jangan diubah

    DerivedWrapper dw; // Jangan diubah

    /**
     * TULIS KODE ANDA DI SINI
     */

    return 0; // Jangan diubah
}
