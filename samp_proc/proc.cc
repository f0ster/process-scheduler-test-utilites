
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int r(int u) {
	return (rand()%u)+1;
}

int main(int argc, char** argv)
{
  if(argc != 2){
  		cout << "Usage: proc <number of processes to generate>" << endl;
		exit(1);
	}
  const int MAX = atoi(argv[1]);
  int priority, arrv, burst, deadline;
 	srand( time(NULL) ); 

  cout << "Pid\tBurst\tArr\tPri\tDeadline\n" << endl;
  for  (int i = 1; i <= MAX; i++) {

      cout << i << "\t" ;
      burst = r(150);
		cout << burst << "\t" ;
      arrv = r(79);
		cout << arrv << "\t" ;
      priority = r(90);
		cout << priority << "\t" ;
      deadline = r(150)+arrv;
		cout << deadline << endl ;
  }

  return (0);
}
