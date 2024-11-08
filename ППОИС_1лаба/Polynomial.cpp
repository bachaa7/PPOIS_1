#include"/�����/�����/����/�����_1����/�����_1����/Polynomial.h"

Polynomial poly;







Polynomial& Polynomial::operator-=(const Polynomial& other) {
    int maxDegree = max(stepen, other.stepen);
    koefficent.resize(maxDegree + 1, 0.0);

    for (int i = 0; i <= other.stepen; ++i) {
        koefficent[i] -= other.koefficent[i];
    }
    stepen = maxDegree;

    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this;  // ������ ����� �������� �������
    result -= other;           // ���������� �������� -= ��� ���������
    return result;             // ���������� ���������
}




Polynomial& Polynomial::operator+=(const Polynomial& other) {
    int maxDegree = max(stepen, other.stepen);
    koefficent.resize(maxDegree + 1, 0.0);

    for (int i = 0; i <= other.stepen; ++i) {
        koefficent[i] += other.koefficent[i];
    }
    stepen = maxDegree;

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this;  // ������ ����� �������� �������
    result += other;           // ���������� �������� += ��� ��������
    return result;             // ���������� ���������
}




const double& Polynomial::operator[](int index) const {
    return koefficent[index];
}

double Polynomial::operator()(double x) const {
    double result = 0;
    for (int i = 0; i <= stepen; ++i) {
        result += koefficent[i] * pow(x, i);
    }
    return result;
}




Polynomial& Polynomial::operator*=(const Polynomial& other) {
    int newDegree = stepen + other.stepen;
    vector<double> newCoefficients(newDegree + 1, 0.0);

    for (int i = 0; i <= stepen; ++i) {
        for (int j = 0; j <= other.stepen; ++j) {
            newCoefficients[i + j] += koefficent[i] * other.koefficent[j];
        }
    }

    koefficent = newCoefficients;
    stepen = newDegree;

    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result = *this;  // ������ ����� �������� �������
    result *= other;           // ���������� �������� *= ��� ���������
    return result;             // ���������� ���������
}


Polynomial::Polynomial(int s, const vector<double>& k) : stepen(s), koefficent(k) {
    koefficent.resize(s + 1, 0.0); // ������������ ���������� ������ �������
}






Polynomial& Polynomial::operator/=(const Polynomial& divisor) {
    if (divisor.getStepen() == 0 && divisor.getKoefficient()[0] == 0.0) {
        throw std::invalid_argument("������� �� ������� ��������� �����������");
    }

    if (stepen < divisor.getStepen()) {
        koefficent = { 0.0 };
        stepen = 0;
        return *this;
    }

    Polynomial remainder = *this;
    std::vector<double> quotient(stepen - divisor.getStepen() + 1, 0.0);

    for (int i = stepen; i >= divisor.getStepen(); --i) {
        quotient[i - divisor.getStepen()] = remainder.koefficent[i] / divisor.koefficent[divisor.getStepen()];
        for (int j = 0; j <= divisor.getStepen(); ++j) {
            remainder.koefficent[i - j] -= quotient[i - divisor.getStepen()] * divisor.koefficent[divisor.getStepen() - j];
        }
    }

    while (quotient.size() > 1 && quotient.back() == 0.0) {
        quotient.pop_back();
    }

    koefficent = quotient;
    stepen = koefficent.size() - 1;

    return *this;
}

Polynomial Polynomial::operator/(const Polynomial& divisor) const {
    Polynomial result = *this;
    result /= divisor;
    return result;
}



