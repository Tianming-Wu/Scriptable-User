#ifndef ScrUserh
#define ScrUserh
using namespace std;

	#include <windows.h>
	#include <cstring>
	#include <cstdio>
	#include <conio.h>
	#include <fstream>
	#include <sstream>
	#include <vector>
	#include <unistd.h>
	#include <algorithm>
	
	struct CFUNC{
		string Name;
		string args;
	};
	
	struct CDLL{
		string DllFile;
		vector<CFUNC> functions;
		HANDLE dllHandle;
	};
	
	struct CHOST{
		int id;
		vector<CDLL> dlls;
	};
	
	struct ENVIRONMENT{
	};
	
	int GetStartupMessage(LPSTR);
	int ScriptHost(LPSTR);
	int UnderstandCommand(string);
	int VariableHost(int,string,&int);
	int EnvironmentHost(string,string);
	int CFunctionHost(CHOST,string);
	int ThrowError(int,int);
	
	#define VAR_TYPE_INT				(-1)
	#define VAR_TYPE_LONGINT			(-2)
	#define VAR_TYPE_LONGLONGINT		(-3)
	#define VAR_TYPE_STRING				(-4)
	#define VAR_TYPE_FUNCTION			(-16)
	#define VAR_TYPE_NULL				(0)
	
#endif
