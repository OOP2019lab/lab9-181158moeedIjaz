#include"Address.h"
#include"Employee.h"
#include"Project.h"




Address::Address(char* House_Number, char* Street_Name, char * City,char* County){
	house_Number=new char[strlen(House_Number)+1];
	int i=0;
	for(i=0;i<strlen(House_Number);i++){
		house_Number[i]=House_Number[i];
	}
	house_Number[i]='\0';
	street_Name=new char[strlen(Street_Name)+1];
	for(i=0;i<strlen(Street_Name);i++){
		street_Name[i]=Street_Name[i];
	}
	street_Name[i]='\0';
	city=new char[strlen(City)+1];
	for(i=0;i<strlen(City);i++){
		city[i]=City[i];
	}
	city[i]='\0';
	county=new char[strlen(County)+1];
	for(i=0;i<strlen(County);i++){
		county[i]=County[i];
	}
	county[i]='\0';
}
Address::Address(const Address& a){
	house_Number=new char[strlen(a.house_Number)+1];
	int i=0;
	for(i=0;i<strlen(a.house_Number);i++){
		house_Number[i]=a.house_Number[i];
	}
	house_Number[i]='\0';
	street_Name=new char[strlen(a.street_Name)+1];
	for(i=0;i<strlen(a.street_Name);i++){
		street_Name[i]=a.street_Name[i];
	}
	street_Name[i]='\0';
	city=new char[strlen(a.city)+1];
	for(i=0;i<strlen(a.city);i++){
		city[i]=a.city[i];
	}
	city[i]='\0';
	county=new char[strlen(a.county)+1];
	for(i=0;i<strlen(a.county);i++){
		county[i]=a.county[i];
	}
	county[i]='\0';

}
ostream& operator<<(ostream& osObject, const Address& a){
	osObject<<"House Number : "<<a.house_Number<<endl;
	osObject<<"Street Name : "<<a.street_Name<<endl;
	osObject<<"City Name : "<<a.city<<endl;
	osObject<<"County Name : "<<a.county<<endl;
	return osObject;
}
const Address &  Address:: operator=(const Address& other){
	delete house_Number;
	house_Number=new char[strlen(other.house_Number)+1];
	int i=0;
	for(i=0;i<strlen(other.house_Number);i++){
		house_Number[i]=other.house_Number[i];
	}
	house_Number[i]='\0';
	delete street_Name;
	street_Name=new char[strlen(other.street_Name)+1];
	for(i=0;i<strlen(other.street_Name);i++){
		street_Name[i]=other.street_Name[i];
	}
	street_Name[i]='\0';
	delete city;
	city=new char[strlen(other.city)+1];
	for(i=0;i<strlen(other.city);i++){
		city[i]=other.city[i];
	}
	city[i]='\0';
	delete county;
	county=new char[strlen(other.county)+1];
	for(i=0;i<strlen(other.county);i++){
		county[i]=other.county[i];
	}
	county[i]='\0';
	return *this;
}
Address::~Address(){
	delete house_Number;
	delete street_Name;
	delete city;
	delete county;
}