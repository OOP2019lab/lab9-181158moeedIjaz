#include"Address.h"
#include"Employee.h"
#include"Project.h"



Employee::Employee(char* name, const Address& a){
	emp_name=new char[strlen(name)+1];
	int i=0;
	for( i=0;i<strlen(name);i++){
		emp_name[i]=name[i];
	}
	emp_name[i]='\0';
	adr=&a;
	proj=new Project*[2];
	no_of_projects=0;
}
Employee::Employee(const Employee& e){
	emp_name=new char[strlen(e.emp_name)+1];
	int i=0;
	for( i=0;i<strlen(e.emp_name);i++){
		emp_name[i]=e.emp_name[i];
	}
	emp_name[i]='\0';
	adr=e.adr;
	no_of_projects=e.no_of_projects;
	proj=new Project*[2];
	for(int i=0;i<no_of_projects;i++){
		proj[i]=e.proj[i];
	}

}
ostream& operator<<(ostream& osObject, const Employee& e){
	osObject<<"Employee Name : "<<e.emp_name<<endl;
	osObject<<"Address of employee :"<<endl;
	osObject<<*e.adr;
	osObject<<"No of Projects : "<<e.no_of_projects<<endl;
	for(int i=0;i<e.no_of_projects;i++){
		osObject<<"Project "<<i+1<<endl;
		osObject<<e.proj[i];
	}
}
const Employee &  Employee::operator=(const Employee& other){
	delete emp_name;
	emp_name=new char[strlen(other.emp_name)+1];
	int i=0;
	for( i=0;i<strlen(other.emp_name);i++){
		emp_name[i]=other.emp_name[i];
	}
	emp_name[i]='\0';
	delete adr;
	adr=new Address(*other.adr);
	no_of_projects=other.no_of_projects;
	if(no_of_projects!=0){
		proj=new Project*[no_of_projects];
	}
	for(int i=0;i<no_of_projects;i++){
		proj[i]=other.proj[i];
	}
}
void Employee::addProject(Project const * a){
	bool check=true;;
	for(int i=0;i<no_of_projects;i++){
		if(proj[i]->exists(a)){
			check=false;
		}
	}
	if(check){
	if(no_of_projects<2){
		proj[no_of_projects]=a;
	}
	no_of_projects++;
	}
}
void Employee::removeProject(Project const * a ){
	for(int i=0;i<no_of_projects;i++){
		if(proj[i]->exists(a)){
			for(int j=i;j<no_of_projects-1;j++){
				proj[j]=proj[j+1];
			}
		}
	}
}
	
