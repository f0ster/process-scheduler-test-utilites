
#include <iostream>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fstream>

using namespace std;

int main() {

	cout << "DO NOT RUN THIS PROGRAM AS ROOT!" << endl;
 cout << "8888888b.                                                                   " << endl;
 cout << "888   Y88b                                                                  " << endl;
 cout << "888    888                                                                  " << endl;
 cout << "888   d88P 888d888 .d88b.   .d8888b .d88b.  .d8888b  .d8888b                " << endl;
 cout << "8888888P\"  888P\"  d88\"\"88b d88P\"   d8P  Y8b 88K      88K                    " << endl;
 cout << "888        888    888  888 888     88888888 \"Y8888b. \"Y8888b.               " << endl;
 cout << "888        888    Y88..88P Y88b.   Y8b.          X88      X88               " << endl;
 cout << "888        888     \"Y88P\"   \"Y8888P \"Y8888   88888P'  88888P'               " << endl;
 cout << "                                                                            " << endl;
 cout << "                                                                            " << endl;
 cout << "                                                                            " << endl;
 cout << "                  888                    888          888                   " << endl;
 cout << "                  888                    888          888                   " << endl;
 cout << "                  888                    888          888                   " << endl;
 cout << ".d8888b   .d8888b 88888b.   .d88b.   .d88888 888  888 888  .d88b.  888d888  " << endl;
 cout << "88K      d88P\"    888 \"88b d8P  Y8b d88\" 888 888  888 888 d8P  Y8b 888P\"    " << endl;
 cout << "\"Y8888b. 888      888  888 88888888 888  888 888  888 888 88888888 888      " << endl;
 cout << "     X88 Y88b.    888  888 Y8b.     Y88b 888 Y88b 888 888 Y8b.     888      " << endl;
 cout << " 88888P'  \"Y8888P 888  888  \"Y8888   \"Y88888  \"Y88888 888  \"Y8888  888      " << endl;

	for(;;){
		cout << endl;
		cout << "Choose scheduling algorithm" << endl;
		cout << "(0) Highest Ratio Next" << endl;
		cout << "(1) RTS " << endl;
		cout << "(2) MFQS " <<endl;
		cout << "(3) UNIX " << endl;
		cout << "(4) ABORT" << endl;
		int choice = 5;
		char* filename = new char[256];
		cin >> choice;
		
		int pid = 0, burst = 0,arr = 0, pri = 0, dead = 0;		
		//char outFilename[35] = "temptempinput";
        //ofstream outFile(outFilename);
		int done = 1;
		if (choice == 4)
			exit(0);
		int in = 0;
		cout<< "Would you like to read from a file? (1,0)" << endl;
		cin >> in;
		
		if (in == 0){
		char outFilename[35] = "temptempinput";
      filename = outFilename;  
		ofstream outFile(outFilename);
		for (;done;){
			pid ++; burst = 0; arr = 0; pri = 0; dead = 0;		
			switch (choice) {
			case 0:
				cout << endl << "enter arrival: ";
				cin >> arr ; 
				cout << endl << "enter burst: ";
				cin >> burst; 
				break;
			case 1:
				cout << endl << "enter arrival: ";
				cin >> arr ; 
				cout << endl << "enter burst: ";
				cin >> burst; 
				cout << endl << "enter deadLine: ";
				cin >> dead;
				break;
			case 2:
				cout << endl << "enter arrival: ";
				cin >> arr ; 
				cout << endl << "enter burst: ";
				cin >> burst;
				break;
			case 3:
				cout << endl << "enter arrival: ";
				cin >> arr ; 
				cout << endl << "enter burst: ";
				cin >> burst;
				cout << endl<< "enter niceness: ";
				cin >> dead;
			break;
		}
			outFile <<  pid << "\t" << burst << "\t" << arr << "\t" << pri << "\t" << dead << "\n";
			cout << " enter another process? (1,0)";
			cin >> done;
		}
		outFile.close();
		goto afterread;
	}	
		cout << endl << "Please enter filename for process information." << endl;
		cin >> filename;
		afterread:
		char* programName = new char[256];
		char* pathname = new char[256];
		switch (choice) {
			case 0:
				programName = "hrn";
				pathname = "hrn/hrn";
				break;
			case 1:
				programName = "rts";
				pathname = "rts/rts";
				break;
			case 2:
				programName = "mfqs";
				pathname = "mfqs/mfqs";
				break;
			case 3:
				programName = "unix";
				pathname = "unix/unix";
				break;
			default:
				cout << "Please choose a proper option." << endl;
				break;	
		}
		char *cmd[] = { programName, filename, (char*)0}; 
		pid_t child_pid = fork();
		int status, ch_stat;
		if( child_pid < 0) 
			cout << "error forking!" << endl;
		if( child_pid == 0) //child
			execv(pathname,cmd);
		else { //parent
			while( (status=wait(&ch_stat)) != child_pid ) {
				if( status < 0 && errno == ECHILD) 
					break;
				errno = 0;
			}
		}
	
	}
	return 0;
}
