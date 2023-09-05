#include <iostream>
#include <math.h>

class Complex {
public:
	void   SetReal(double Real) { this->Real = Real; }
	double GetReal() { return Real; }
	void   SetImag(double Imag) { this->Imag = Imag; }
	double GetImag() { return Imag; }

	void ShowComplex();

private:
	double Real;
	double Imag;

public:
	Complex operator+(Complex m);
	Complex operator-(Complex m);
	Complex operator*(Complex m);
	Complex operator/(Complex m);
};

Complex Complex::operator+(Complex m) {
	Complex n;
	n.Real = Real + m.Real;
	n.Imag = Imag + m.Imag;
	return n;
}
Complex Complex::operator-(Complex m) {
	Complex n;
	n.Real = Real - m.Real;
	n.Imag = Imag - m.Imag;
	return n;
}
Complex Complex::operator*(Complex m) {
	Complex n;
	n.Real = Real * m.Real - Imag * m.Imag;
	n.Imag = Real * m.Imag + Imag * m.Real;
	return n;
}
Complex Complex::operator/(Complex m) {
	Complex n;
	n.Real =
		(Real * m.Real + Imag * m.Imag) / (m.Real * m.Real + m.Imag * m.Imag);
	n.Imag =
		(Real * m.Imag - Imag * m.Real) / (m.Real * m.Real + m.Imag * m.Imag);
	return n;
}

void Complex::ShowComplex() {
	std::cout << Real;
	(Imag >= 0) ? (std::cout << " + " << Imag)
				: (std::cout << " - " << fabs(Imag));
	std::cout << "i";
}
int main() {
	Complex a, b, c;
	double	real, imag;
	scanf("%lf", &real);
	scanf("%lf", &imag);
	a.SetReal(real);
	a.SetImag(imag);
	scanf("%lf", &real);
	scanf("%lf", &imag);
	b.SetReal(real);
	b.SetImag(imag);

	/////////////////
	c = a + b;
	std::cout << "(";
	a.ShowComplex();
	std::cout << ") + (";
	b.ShowComplex();
	std::cout << ") = ";
	c.ShowComplex();
	std::cout << std::endl;
	/////////////////
	c = a - b;
	std::cout << "(";
	a.ShowComplex();
	std::cout << ") - (";
	b.ShowComplex();
	std::cout << ") = ";
	c.ShowComplex();
	std::cout << std::endl;
	/////////////////
	c = a * b;
	std::cout << "(";
	a.ShowComplex();
	std::cout << ") * (";
	b.ShowComplex();
	std::cout << ") = ";
	c.ShowComplex();
	std::cout << std::endl;
	/////////////////
	c = a / b;
	std::cout << "(";
	a.ShowComplex();
	std::cout << ") / (";
	b.ShowComplex();
	std::cout << ") = ";
	c.ShowComplex();
	std::cout << std::endl;
	/////////////////

	return 0;
}