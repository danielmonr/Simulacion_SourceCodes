ALL: corr kstest mult sqr poisson expo triang
.PHONY=clean

clean:
	\rm -f corr kstest mult sqr poisson expo

corr: autocorr_test.cpp
	g++ --std=c++11 autocorr_test.cpp -o corr

kstest: ks_test.cpp test.h
	g++ ks_test.cpp --std=c++11 -o kstest

mult: mcongr_rand.cpp
	g++ --std=c++11 mcongr_rand.cpp -o mult

sqr: sqr_rand.cpp
	g++ --std=c++11 sqr_rand.cpp -o sqr

poisson: va_poisson.cpp
	g++ --std=c++11 va_poisson.cpp -o poisson

expo: exponential.cpp
	g++ --std=c++11 exponential.cpp -o expo

triang: triangular.cpp
	g++ --std=c++11 triangular.cpp -o triang
