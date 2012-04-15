#include <iostream>
#include <random>
#include <string>

using namespace std;

int r(int l, int u){
	tr1::mt19937 eng;
	tr1::uniform_int<int> unif(l,u);
	return (int)unif(eng);
}

int main( )
{
  const int MAX = 20;
  int priority, arrv, burst, deadline;
  

  cout << "Pid\tBurst\tArr\tPri\tDeadline\n" << endl;
  /*for  (int i = 1; i <= MAX; i++) {

      cout << i << "\t" ;
      arrv = ((int)(1000 *rndom() )% 79 )  ;
      cout << burst << "\t" ;
      burst =  ((int)(1000 *rndom() )% MAX+1) ;
      cout << arrv << "\t" ;
      priority = (int)(1000 *rndom() )% 90 ;
      cout << priority << "\t" ;
      deadline =  ((int)(1000 *rndom() )% 150 ) + arrv ;
      cout << deadline << endl ;
  }*/
	cout <<	r(1,5) << endl;
  return (0);
}

