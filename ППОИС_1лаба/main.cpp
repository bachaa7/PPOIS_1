#include"/Учеба/ППОИС/Лабы/ППОИС_1лаба/ППОИС_1лаба/Polynomial.h"


void menu(vector<Polynomial>& polynomials) {
    int choice;

    do {
        cout << "Выберите операцию, которую хотите выполнить:\n"
            << "1. Получить значения коэффициентов\n"
            << "2. Вычислить значение многочлена для заданного аргумента\n"
            << "3. Сложение двух многочленов\n"
            << "4. Вычитание двух многочленов\n"
            << "5. Произведение двух многочленов\n"
            << "6. Деление двух многочленов\n"
            << "7. Завершение программы\n"
            << "Ваш выбор: ";

        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1:

            for (int i = 0; i < polynomials.size(); ++i) {
                int stepen = polynomials[i].getStepen();
                cout << "Коэффициенты многочлена " << i + 1 << ": " << endl;
                for (int j = stepen; j >= 0; --j) {

                    cout << "Коэффициент при x^" << j << ": " << polynomials[i][j] << endl;
                }
                cout << endl;
            }
            break;

        case 2: {

            double x;
            cout << "Введите значение x: ";
            cin >> x;
            for (int i = 0; i < polynomials.size(); ++i) {
                double result = polynomials[i](x);
                cout << "Значение многочлена " << i + 1 << " при x = " << x << " равно " << result << endl;
            }

            break;
        }
        case 3:

            if (polynomials.size() < 2) {
                cout << "Недостаточно многочленов для сложения.\n";
            }
            else {
                Polynomial& poly1 = polynomials[0];
                Polynomial& poly2 = polynomials[1];


                Polynomial sum = poly1 + poly2;
                cout << "Сумма первых двух многочленов: ";
                print(sum);


                poly1 += poly2;
                cout << "Первый многочлен после сложения со вторым (через +=): ";
                print(poly1);
            }

            break;

        case 4:
            if (polynomials.size() < 2) {
                cout << "Недостаточно многочленов для вычитания.\n";
            }
            else {
                Polynomial& poly1 = polynomials[0];
                Polynomial& poly2 = polynomials[1];


                Polynomial difference = poly1 - poly2;
                cout << "Разность первых двух многочленов: ";
                print(difference);


                poly1 -= poly2;
                cout << "Первый многочлен после вычитания второго (через -=): ";
                print(poly1);
            }
            break;

        case 5:

            if (polynomials.size() < 2) {
                cout << "Недостаточно многочленов для умножения.\n";
            }
            else {
                Polynomial& poly1 = polynomials[0];
                Polynomial& poly2 = polynomials[1];


                Polynomial product = poly1 * poly2;
                cout << "Произведение первых двух многочленов: ";
                print(product);


                poly1 *= poly2;
                cout << "Первый многочлен после умножения на второй (через *=): ";
                print(poly1);
            }

            break;

        case 6:

            if (polynomials.size() < 2) {
                cout << "Недостаточно многочленов для деления.\n";
            }
            else {
                Polynomial& poly1 = polynomials[0];
                Polynomial& poly2 = polynomials[1];

                try {
                    Polynomial quotient = poly1 / poly2;
                    cout << "Частное первых двух многочленов: ";
                    print(quotient);

                    poly1 /= poly2;
                    cout << "Первый многочлен после деления на второй (через /=): ";
                    print(poly1);
                }
                catch (const invalid_argument& e) {
                    cout << "Ошибка: " << e.what() << endl;
                }
            }

            break;

        case 7:
            cout << endl << "Программа завершена\n";
            return;

        default:
            cout << endl << "Ошибка ввода\n";
        }
    } while (true);
}


void input(Polynomial& poly) {
    int stepen;
    cout << "Введите степень многочлена: ";
    cin >> stepen;
    poly.setStepen(stepen);

    vector<double> koeff(stepen + 1);
    for (int i = stepen; i >= 0; --i) {
        cout << "Введите коэффициент при x^" << i << ": ";
        cin >> koeff[i];
    }
    poly.setKoefficient(koeff);
}

void print(const Polynomial& poly) {

    int stepen = poly.getStepen();
    vector<double> koeff = poly.getKoefficient();


    for (int i = stepen; i >= 0; --i) {
        if (koeff[i] != 0) {
            cout << (koeff[i] > 0 && i != stepen ? " + " : "") << koeff[i];
            if (i > 0) cout << "x";
            if (i > 1) cout << "^" << i;
        }
    }
    cout << endl << endl;

}


int main() {

	setlocale(LC_ALL, "RU");

	vector<Polynomial> polynomials;
    Polynomial poly;  // Создаём объект класса
    Polynomial poly1, poly2;

	int kolichestvo;

	while (true) {

		cout << "Введите количество многочленов: ";
		cin >> kolichestvo;

		if (kolichestvo > 0) {
			break;
		}
		else {
			cout << "Try again pls\n";
		}
	}

	for (int i = 0; i < kolichestvo; i++) {

		input(poly);  // Вводим данные для объекта
		print(poly);  // Выводим объект
		polynomials.push_back(poly);

	}
	
	menu(polynomials);
	


	return 0;
}


