#include <array>
#include <cmath>
#include <iostream>

template < typename T >
class Wektor3D
{
private:
    std::array< T, 3 > dane; // kontener na wspolrzedne

public:
    Wektor3D() : dane{0, 0, 0} {} // konstruktor domyslny

    Wektor3D(T x, T y, T z) : dane{x, y, z} {} // konstruktor parametryczny

    Wektor3D operator+(const Wektor3D& other) const
    {
        return Wektor3D(dane[0] + other.dane[0], dane[1] + other.dane[1], dane[2] + other.dane[2]);
    } // przeciazenie operatora +

    Wektor3D operator-(const Wektor3D& other) const
    {
        return Wektor3D(dane[0] - other.dane[0], dane[1] - other.dane[1], dane[2] - other.dane[2]);
    } // przeciazenie operatora -

    Wektor3D operator*(T skalar) const
    {
        return Wektor3D(dane[0] * skalar, dane[1] * skalar, dane[2] * skalar);
    } // przeciazenie operatora * przez skalar

    T dot(const Wektor3D& other) const
    {
        return dane[0] * other.dane[0] + dane[1] * other.dane[1] + dane[2] * other.dane[2];
    } // iloczyn skalarny

    Wektor3D cross(const Wektor3D& other) const
    {
        return Wektor3D(dane[1] * other.dane[2] - dane[2] * other.dane[1],
                        dane[2] * other.dane[0] - dane[0] * other.dane[2],
                        dane[0] * other.dane[1] - dane[1] * other.dane[0]);
    } // iloczyn wektorowy

    T length() const
    {
        return std::sqrt(dane[0] * dane[0] + dane[1] * dane[1] + dane[2] * dane[2]);
    } // iloczyn wektorowy

    void display() const
    {
        std::cout << "(" << dane[0] << ", " << dane[1] << ", " << dane[2] << ")\n";
    } // funkcja wyœwietlania wektora
};

int main()
{
    Wektor3D< int > wektor1(1, 2, 3); // przykladowy wektor1
    Wektor3D< int > wektor2(4, 5, 6); // przykladowy wektor2

    Wektor3D< int > suma             = wektor1 + wektor2;
    Wektor3D< int > roznica          = wektor1 - wektor2;
    Wektor3D< int > iloczynSkalar    = wektor1 * 2;
    Wektor3D< int > iloczynWektorowy = wektor1.cross(wektor2);

    std::cout << "Wektor1: ";
    wektor1.display();
    std::cout << "Wektor2: ";
    wektor2.display();

    std::cout << "Suma: ";
    suma.display();
    std::cout << "Roznica: ";
    roznica.display();
    std::cout << "Iloczyn skalarny: " << wektor1.dot(wektor2) << "\n";
    std::cout << "Iloczyn wektorowy: ";
    iloczynWektorowy.display();
    std::cout << "Dlugosc wektora1: " << wektor1.length() << "\n";

    return 0;
}
