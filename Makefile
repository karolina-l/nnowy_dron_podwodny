CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o main.o vector.o bryla.o prostopadloscian.o p_prost.o dron.o sruba.o interfejs_drona.o graniastoslup.o dno.o tafla.o templates.o m_obrotu.o
	g++ -o example.out main.o vector.o Dr3D_gnuplot_api.o bryla.o prostopadloscian.o p_prost.o dron.o sruba.o interfejs_drona.o graniastoslup.o dno.o tafla.o templates.o\
	 m_obrotu.o -lpthread

main.o: main.cpp Dr3D_gnuplot_api.hh vector.hh templates.cpp m_obrotu.hh dron.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

tafla.o: powierzchnia.hh przeszkoda.hh tafla.cpp tafla.hh rysowanie_int.hh vector.hh
	g++ ${CPPFLAGS} -o tafla.o tafla.cpp

dno.o: powierzchnia.hh przeszkoda.hh dno.cpp dno.hh rysowanie_int.hh vector.hh
	g++ ${CPPFLAGS} -o dno.o dno.cpp

sruba.o: graniastoslup.hh sruba.cpp sruba.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o sruba.o sruba.cpp

graniastoslup.o: bryla.hh graniastoslup.cpp graniastoslup.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o graniastoslup.o graniastoslup.cpp

dron.o: interfejs_drona.hh prostopadloscian.hh przeszkoda.hh dron.cpp dron.hh sruba.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o dron.o dron.cpp

p_prost.o: przeszkoda.hh prostopadloscian.hh p_prost.cpp p_prost.hh interfejs_drona.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o p_prost.o p_prost.cpp

interfejs_drona.o: interfejs_drona.hh interfejs_drona.cpp vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o interfejs_drona.o interfejs_drona.cpp

prostopadloscian.o: bryla.hh prostopadloscian.cpp prostopadloscian.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o prostopadloscian.o prostopadloscian.cpp

bryla.o: bryla.hh bryla.cpp rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o bryla.o bryla.cpp

m_obrotu.o: m_obrotu.cpp m_obrotu.hh matrix.hh vector.hh
	g++ ${CPPFLAGS} -o m_obrotu.o m_obrotu.cpp

templates.o: templates.cpp vector.hh vector.cpp matrix.hh matrix.cpp
		g++ ${CPPFLAGS} -o templates.o templates.cpp

vector.o: vector.hh vector.cpp Dr3D_gnuplot_api.hh rozmiar.h
	g++ ${CPPFLAGS} -o vector.o vector.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm example.out
	@rm -f *.o *~
