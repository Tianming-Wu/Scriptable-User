#include "ScriptableUser.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if(!(GetStartupMessage(lpCmdLine)>0))return 1;
	
} 

int GetStartupMessage(LPSTR lpMessage) {
	if(strlen(lpMessage)==0)return -1;
	
	
} 

int ScriptHost(LPSTR scrFileName) {
	ifstream ifs (scrFileName);
	if(ifs.bad())return -1;
	BOOL brun = TRUE;
	string commandfirst, line;
	vector<string> arguments;
	stringstream sstr;
	while(brun) {
		getline(ifs, line);
		if(ifs.get()==EOF)break;
		sstr<<line;
		sstr>>commandfirst;
		switch(UnderstandCommand(commandfirst)) {
			case 0 : { //comment
				continue;
			}
			case 1 : { //environment 
				string envname, envvar;
				sstr>>envname>>envvar;
				int err;
				if((err = EnvironmentHost(envname, envvar))<0)ThrowError(1,err);
				
				
				
				
				break;
			} 
			case 2 : {
				
				break;
			}
		}
		
		
		
	}
	
	
	ifs.close();
	return 0;
}

int UnderstandCommand(string cmd) {
	transform(cmd.begin(),cmd.end(),cmd.begin(),::tolower);
	if(cmd.substr(0,2)=="//"||cmd[0]==';')return 0;
	else if(cmd[0]=='#')return 2;
	else if(cmd=="environment")			return 1;
	else if(cmd=="selectwindow")		return 3;
	else if(cmd=="searchwindow")		return 4;
	else if(cmd=="closewindow")			return 5;
	else if(cmd=="miniwindow")			return 6;
	else if(cmd=="maxwindow")			return 7;
	else if(cmd=="ctWndCtrl")			return 8;
}

int VariableHost(int type, string name, int& value) {
	
}

int EnvironmentHost(string name, string var) {
	if(name=="StopOnError") {
		transform(var.begin(),var.end(),var.begin(),::tolower);
		if(args=="true")
	}
}

int CFunctionHost(CHOST host, string FunctionName) {
	int ia = -1, ib = -1; BOOL found = FALSE;
	for(int idll = 0; idll < host.dlls.size() - 1; idll++) {
		for(int ifunc = 0; ifunc < host.dlls[idll].functions.size() - 1; ifunc++) {
			if(host.dlls[idll].functions[ifunc].Name == FunctionName) {
				found = TRUE;
				ia = idll, ib = ifunc;
				break;
			}
		}
		if(found)break;
	}
	if(found==FALSE) return -2;
	
	
	
}

int ThrowError(int ErrorIndex, int ErrorType) {
	
} 
