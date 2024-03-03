#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
class Kubek
{
public:
  double kawa;
  double woda;
};

class Ekspres
{
private:
  bool czyCieplaWoda = false;
  double tempWody = 20;
  double iloscKawy = 1000;
public:
  void podgrzejWode ()
  {
	while (tempWody < 100)
	  {
		tempWody += 10;
		this_thread::sleep_for (chrono::seconds (1));
		if (tempWody == 100)
		  {
			czyCieplaWoda = true;
		  }
		else
		  {
			czyCieplaWoda = false;
		  }
	  }
  }
  void zrobKawe ()
  {
	if (iloscKawy > 10)
	  {
		podgrzejWode ();
		if (tempWody)
		  {
			Kubek kawa;
			iloscKawy -= 10;
			kawa.kawa += 10;
			kawa.woda += 240;
			cout << "kawa gotowa :)" << endl;
		  }

	  }
	else
	  {
		cout << "Za malo kawy!" << endl;
	  }
  }

};

int
main ()
{
  Ekspres nowaKawa;
  nowaKawa.zrobKawe ();


  return 0;
}
