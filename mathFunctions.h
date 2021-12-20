#ifndef _FUNCTIONS_H__
#define _FUNCTIONS_H__

extern "C" double seno(double x);
extern "C" double arcoseno(double x);

extern "C" double coseno(double x);
extern "C" double arcocoseno(double x);

extern "C" double tangente(double x);
extern "C" double arcotangente(double x);

extern "C" double raizCuadrada(double x);
extern "C" double potenciaCuadrada(double x);

extern "C" double logaritmo(double x);
extern "C" double antiLogaritmo(double x);

extern "C" double suma(double x ,double y);
extern "C" double resta(double x, double y);
extern "C" double multiplicacion(double x, double y);
extern "C" double division(double x, double y);

extern "C" double cambiarSigno(double x);
extern "C" double aGrados(double x);
extern "C" double aRadianes(double x);
#endif
