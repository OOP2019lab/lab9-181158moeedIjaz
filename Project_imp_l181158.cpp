#include"Address.h"
#include"Employee.h"
#include"Project.h"

Project::Project(char* Name, int Budget, int Duration){

	name=new char[strlen(Name)+1];
	int i=0;
	for( i=0;i<strlen(Name);i++){
		name[i]=Name[i];
	}
	name[i]='\0';
	budget=Budget;
	duration=Duration;
}
Project::Project(const Project& P1){
	name=new char[strlen(P1.name)+1];
	int i=0;
	for(i=0;i<strlen(P1.name);i++){
		name[i]=P1.name[i];
	}
	name[i]='\0';
	budget=P1.budget;
	duration=P1.duration;

}
ostream& operator<<(ostream& osObject, const Project& P1){
	osObject<<"Project name : "<<P1.name<<endl;
	osObject<<"Budget alloted : "<<P1.budget<<endl;
	osObject<<"Duration : "<<P1.duration<<endl;
	return osObject;
}
const Project& Project::operator=(const Project& other){
	delete name;
	name=new char[strlen(other.name)+1];
	int i=0;
	for(i=0;i<strlen(other.name);i++){
		name[i]=other.name[i];
	}
	name[i]='\0';
	budget=other.budget;
	duration=other.duration;
	return *this;
}
void Project::setBudget(int a){
	budget=a;
}
Project::~Project(){
	delete name;
}

bool Project::exists(Project const* a)const{
	if(strlen(name)==strlen(a->name)){
		for(int i=0;i<strlen(name);i++){
			if(name[i]!=a->name[i]){
				return false;
			
			}
		}
		return true;
	}else{
		return false;
	
	}


}
