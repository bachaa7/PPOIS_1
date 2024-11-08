
#include <iostream>
#include<vector>
#include <stdexcept>
#include <cmath>


using namespace std;


class Polynomial {

public:

	string name;
	double stepen;

    void setStepen(int s) { stepen = s; }
    int getStepen() const { return stepen; }
    void setKoefficient(const vector<double>& k) { koefficent = k; }
    vector<double> getKoefficient() const { return koefficent; }


    Polynomial(int s = 0, const vector<double>& k = {});

   

    const double& operator[](int index) const;

    double operator()(double x) const;



    Polynomial& operator+=(const Polynomial& other);

    Polynomial operator+(const Polynomial& other) const;



    Polynomial& operator-=(const Polynomial& other);

    Polynomial operator-(const Polynomial& other) const;



    Polynomial& operator*=(const Polynomial& other);

    Polynomial operator*(const Polynomial& other) const;



    Polynomial& operator/=(const Polynomial& other);

    Polynomial operator/(const Polynomial& other) const;



private:

	vector <double> koefficent;

};


void input(Polynomial& poly);

void print(const Polynomial& poly);

void menu(vector<Polynomial>& polynomials);