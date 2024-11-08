#include"/Учеба/ППОИС/Лабы/ППОИС_1лаба/ППОИС_1лаба/Polynomial.h"

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
    Polynomial result = *this;  // Создаём копию текущего объекта
    result -= other;           // Используем оператор -= для вычитания
    return result;             // Возвращаем результат
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
    Polynomial result = *this;  // Создаём копию текущего объекта
    result += other;           // Используем оператор += для сложения
    return result;             // Возвращаем результат
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
    Polynomial result = *this;  // Создаём копию текущего объекта
    result *= other;           // Используем оператор *= для умножения
    return result;             // Возвращаем результат
}


Polynomial::Polynomial(int s, const vector<double>& k) : stepen(s), koefficent(k) {
    koefficent.resize(s + 1, 0.0); // Обеспечиваем правильный размер вектора
}






Polynomial& Polynomial::operator/=(const Polynomial& divisor) {
    if (divisor.getStepen() == 0 && divisor.getKoefficient()[0] == 0.0) {
        throw std::invalid_argument("Деление на нулевой многочлен недопустимо");
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



