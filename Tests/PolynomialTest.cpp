#include "pch.h"
#include"/Учеба/ППОИС/Лабы/ППОИС_1лаба/ППОИС_1лаба/Polynomial.h"

#include <gtest/gtest.h>  // Подключаем Google Test
#include <sstream>  // Для использования istringstream и ostringstream
#include <vector>
using namespace std;



TEST(PolynomialTest, SetStepenFunction) {
    Polynomial poly;

    int expectedStepen = 3;
    poly.setStepen(expectedStepen);

    
    EXPECT_EQ(poly.getStepen(), expectedStepen);
}


TEST(PolynomialTest, SetKoefficientFunction) {
    Polynomial poly;

    
    vector<double> expectedCoefficients = { 1.0, -2.5, 3.5 };
    poly.setKoefficient(expectedCoefficients);

    
    EXPECT_EQ(poly.getKoefficient(), expectedCoefficients);
}



TEST(PolynomialTest, AccessOperator) {

    vector<double> coefficients = { 2.0, -3.0, 4.0 };
    Polynomial poly(2, coefficients);

    EXPECT_EQ(poly[0], 2.0);   
    EXPECT_EQ(poly[1], -3.0); 
    EXPECT_EQ(poly[2], 4.0);   
}


TEST(PolynomialTest, FunctionCallOperator) {

    vector<double> coefficients = { 2.0, 3.0, 4.0 };
    Polynomial poly(2, coefficients);
    
    EXPECT_DOUBLE_EQ(poly(1.0), 9.0);

   
    EXPECT_DOUBLE_EQ(poly(2.0), 24.0);

   
    EXPECT_DOUBLE_EQ(poly(0.0), 2.0);
}


TEST(PolynomialTest, AdditionAssignmentOperator) {
    
    Polynomial poly1(2, { 2.0, 3.0, 4.0 });
    Polynomial poly2(1, { 1.0, 2.0 });

    
    vector<double> expectedCoefficients = { 3.0, 5.0, 4.0 };

    poly1 += poly2;  
    EXPECT_EQ(poly1.getKoefficient(), expectedCoefficients);  
}

TEST(PolynomialTest, AdditionOperator) {
    
    Polynomial poly1(2, { 2.0, 3.0, 4.0 });
    Polynomial poly2(1, { 1.0, 2.0 });

    
    vector<double> expectedCoefficients = { 3.0, 5.0, 4.0 };

    Polynomial sum = poly1 + poly2;
    EXPECT_EQ(sum.getKoefficient(), expectedCoefficients);  
}


TEST(PolynomialTest, SubtractionAssignmentOperator) {
    
    Polynomial poly1(2, { 5.0, 3.0, 4.0 });
    Polynomial poly2(1, { 2.0, 1.0 });

    
    vector<double> expectedCoefficients = { 3.0, 2.0, 4.0 };

    poly1 -= poly2;  
    EXPECT_EQ(poly1.getKoefficient(), expectedCoefficients);  
}

TEST(PolynomialTest, SubtractionOperator) {
    
    Polynomial poly1(2, { 5.0, 3.0, 4.0 });
    Polynomial poly2(1, { 2.0, 1.0 });

    
    vector<double> expectedCoefficients = { 3.0, 2.0, 4.0 };

    Polynomial difference = poly1 - poly2;
    EXPECT_EQ(difference.getKoefficient(), expectedCoefficients);  
}






TEST(PolynomialTest, MultiplicationAssignmentOperator) {
    
    Polynomial poly1(1, { 1.0, 1.0 });
    Polynomial poly2(1, { 2.0, 3.0 });

    
    vector<double> expectedCoefficients = { 2.0, 5.0, 3.0 };

    poly1 *= poly2;  
    EXPECT_EQ(poly1.getKoefficient(), expectedCoefficients);  
}


TEST(PolynomialTest, MultiplicationOperator) {
    Polynomial poly1(1, { 1.0, 1.0 });
    Polynomial poly2(1, { 2.0, 3.0 });

    vector<double> expectedCoefficients = { 2.0, 5.0, 3.0 };
}


TEST(PolynomialTest, DivisionByZeroPolynomial) {
    Polynomial poly1;
    poly1.setStepen(2);
    poly1.setKoefficient({ 6.0, 4.0, 0.0 }); 

    Polynomial poly2;
    poly2.setStepen(0);
    poly2.setKoefficient({ 0.0 }); 

    
    EXPECT_THROW(poly1 /= poly2, std::invalid_argument);
}



TEST(PolynomialTest, DivisionOperator) {
    Polynomial poly1;
    poly1.setStepen(2);
    poly1.setKoefficient({ 6.0, 4.0, 0.0 }); 

    Polynomial poly2;
    poly2.setStepen(1);
    poly2.setKoefficient({ 0.0, 2.0 }); 

    Polynomial expected;
    expected.setStepen(0);
    expected.setKoefficient({ 2.0 }); 

    Polynomial result = poly1 / poly2;
    EXPECT_EQ(result.getKoefficient(), expected.getKoefficient()); 
}



TEST(PolynomialTest, DivisionAssignmentOperator) {
    Polynomial poly1;
    poly1.setStepen(2);
    poly1.setKoefficient({ 8.0, 4.0, 2.0 }); 

    Polynomial poly2;
    poly2.setStepen(1);
    poly2.setKoefficient({ 0.0, 2.0 }); 

    Polynomial expected;
    expected.setStepen(1);
    expected.setKoefficient({ 2.0, 1.0 }); 

    poly1 /= poly2; 
    EXPECT_EQ(poly1.getKoefficient(), expected.getKoefficient()); 
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}