#include<iostream>
#include<string>

using namespace std;
int mashrot  ;
int pass = 0;
int NUMSUM;
string dars[7] = { "fizik_p","fizik_1","riazi p","riazi_1","Barname nevisi","adabiat","zaban_p" };
int Num[7] = {11,1,6,5,0,13};
int vahed[7] = {2,3,2,3,3,3,2,};
string id[6] = { "First_Name:","Last_name:","Father_Name:","Born_Date(0000/00/00):","National_code:","Field of Study:" };
string pardakht[5] = { "pish_pardakht", "pardakht_Bime","pardakht_khadamat","pardakht_khbgah","pardkht_agsaat" };


void Etkhb_vahed(string dars[],int vahed[],int num[], int size) {


	for (int i = 0; i < size; i++)
	{

		NUMSUM += Num[i];
	}
	mashrot = NUMSUM / 7;
	if (mashrot < 12) {

		cout << "|vaziat: mashrot!|" << endl;
		cout << "===========================" << endl;
		cout << "mojaze be entkhab:14 vahed" << endl;
		cout << "===========================" << endl;
	}
	else {
		cout << "|vaziat: ghabol|" << endl;
		cout << "===========================" << endl;
		cout << "mojaze be entkhab:18 vahed" << endl;
		cout << "===========================" << endl;
	}
	for (int i = 0; i < size; i++)
	{

		cout << "shomare dars" << "|" << i << "|" << dars[i] << "|" << "| vahed |" << vahed[i] << endl;
		cout << "==============================================================================" << endl;
		 
	}
	if (mashrot<12)
	{
		mashrot = 14;
	}
	else
	{
		mashrot = 18;
	}

	int p;

	for (int i = 0; i <= mashrot; i++)
	{
		cout << "Entekhab_kon:>>";
		cin >> p;
		i += vahed[p];



	}
	cout << "=========================="<<endl;
	cout << "Entekhab_Shoma_tamam_shod:"<<endl;





};

void malli(string pardakht[],int size) {

	for (int i = 0; i < size; i++)
	{
		cout << i << "|" << pardakht[i] << "|" << ">>"<<"0-IRR"<<"|" << endl;
	}
};
void karnameh(string karnameh[],int num[],int vahed[], int size) {

	for (int i = 0; i < size; i++)
	{
		cout << "shomare dars" << "|" << i << "|" << karnameh[i] << "|"<< "numre" <<"|" << num[i] << "|" <<"vahed |"<<vahed[i] << endl;

	}

};
void profil(string id[], string prof[], int size){


	//id
	for (int i = 0; i < size; i++)
	{

		cout << i << " |-Enter>>" << id[i] ;
		cin >> prof[i];
		cout << "|=====================|" << endl;


	}
	system("cls");
	//profil
	cout << "<|your profil|>:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "|" << id[i] << "<|" << prof[i] << "|> " << endl;
		cout << "|=========================|" << endl;
	}
	cout << "<(Welcome to Amozeshyar)>" << endl;
	cout << "===========================" << endl;


};
void menu(){
	string menu[4] = { "Entkhab vahed","karnamehm ", "vaziat_mali" ,"vaziat_Term" };
	for (int i = 0; i < 4; i++)
	{
		cout << i << "|" << menu[i] << "|" << endl;
	}

}

int main(){
	string profill[6]= { };
	profil(id, profill, 6);
Menu:
	menu();
	 int op;
	 cout << "======================" << endl;
	cout << "what can i help you?:";
	cin >> op;
	/////////
	system("cls");
	string exit;
	int sum = 0;
	 switch (op)
	{
	 case 0:
		 Etkhb_vahed(dars, vahed,Num, 7);
		 cout << "do you want exit ? ";
		 cin >> exit;
		 if (exit == "yes")
			 system("cls");
		 goto  Menu;
		 break;
	case 1:
		karnameh(dars,Num,vahed,7);
		cout << "do you want exit ? ";
		cin >> exit;
		if (exit == "yes")
			system("cls");
			goto  Menu;
	
			break;

	case 2:
		malli(pardakht, 5);
		cout << "do you want exit ? ";
		cin >> exit;
		if (exit == "yes")
			system("cls");
		goto  Menu;
		break;

	case 3:
		for (int i = 0; i < 6; i++)
		{
			cout << "|" << id[i] << "<|" << profill[i] << "|> " << endl;
			cout << "|=========================|" << endl;
		}
		cout << "========================" << endl;
		cout << "|Nimsall tahsili:(4021)|" << endl;
		cout << "========================" << endl;
		for (int i = 0; i < 7; i++)
		{
			sum += vahed[i];
		}
		for (int i = 0; i < 7; i++)
		{
		
			NUMSUM += Num[i];
		}
		for (int i = 0; i < 7; i++)
		{
			if (Num[i] >= 10)
			{
				pass++;

			}

		}
		mashrot = NUMSUM / 7;
		cout << "|Kole_Vahed:|" << sum << "|" << endl;
		cout << "|jame_numre:|" << NUMSUM << "|" << endl;
		cout << "|Kole_dars_pass_shode:|" << pass << "|" << endl;
		cout << "|Kole_vahed_pass_shode:|" << pass << "|" << endl;
		cout << "|kole_nomre_sal:|" << mashrot << "|" << endl;
		if (mashrot <= 10)
			cout << "|vaziat : Mashrot|" << endl;
		else
		{
			cout << "|vaziat : ghabul|" << endl;
		}
		cout << "do you want exit ? ";
		cin >> exit;
		if (exit == "yes")
			system("cls");
		goto  Menu;
		break;
	} 

}