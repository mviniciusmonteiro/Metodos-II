#ifndef UTILANALISE_HPP
#define UTILANALISE_HPP

#include "newton-cotes.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <tuple>
#include <vector>

#define INF numeric_limits<double>::infinity();

using namespace std;

long double calcularErroRelativo(long double valorAtual, long double valorAnterior);
tuple<long double, int> testar(func f, long double a, long double b, long double eps, int grau = 2, char filosofia ='a');

#endif