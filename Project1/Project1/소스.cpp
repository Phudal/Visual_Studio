//#include <iostream>
//#pragma warning (disable:4996)
//
//using namespace std; 
//
//class c_info 
//{
//private:
//	char name[256];
//	int age;
//
//public:
//	void setname(char* value) { strcpy(name, value); }
//	void setage(int value) { age = value; }
//
//	char* getname() { return name; }
//	int getage() { return age; }
//};
//
//class c_parent
//{
//private:
//	int secret_key;
//
//public:
//	c_parent() { secret_key = 1234; }
//	void setkey(int value) { secret_key = value; }
//	int getkey() { return secret_key; }
//};
//
//class c_child : public c_parent
//{
//private:
//	c_info  *m_pinfo = nullptr;
//
//public:
//	c_child() { setkey(4567); }
//	~c_child() { if (m_pinfo = nullptr) { delete m_pinfo; m_pinfo = nullptr; } }
//	
//	void setinfo(c_info* pinfo) { m_pinfo = pinfo; }
//	c_info* getinfo() { return m_pinfo; }
//
//	void Print()
//	{
//		cout << "----------------info--------------------" << endl;
//		cout << "ID: " << getkey() << endl;
//		cout << "이름: " << m_pinfo->getname() << endl;
//		cout << "나이: " << m_pinfo->getage() << endl;
//		cout << "----------------------------------------" << endl;
//	}
//};
//
//int main()
//{
//	c_child mchild;
//	mchild.setinfo(new c_info);
//
//	char tempname[256];
//	int tempage;
//
//	cout << "이름" << endl;
//	cin >> tempname;
//	cout << "나이" << endl;
//	cin >> tempage;
//
//	mchild.getinfo()->setname(tempname);
//	mchild.getinfo()->setage(tempage);
//
//	mchild.Print();
//}

#include <iostream>

using namespace std;
#pragma warning (disable:4996)

class CarInformation
{
private:
	char color[256];
	int carnumber;
	int speed;
	int gear;

public:
	char* Getcolor() { return color; }
	int Getcarnumber() { return carnumber; }
	int Getspeed() { return speed; }
	int Getgear() { return gear; }

	void Setcolor(char* data) { strcpy(color, data); }
	void Setcarnumber(int data) { carnumber = data; }
	void Setspeed(int data) { speed = data; }
	void Setgear(int data) { gear = data; }

	void Print()
	{
		cout << "color: " << color << endl;
		cout << "carnumber: " << carnumber << endl;
		cout << "speed: " << speed << endl;
		cout << "gear: " << gear << endl;
	}
};

class C_Car : public CarInformation
{
private:
	int ID;
	char name[256];

public:
	int GetID() { return ID; }
	char* Getname() { return this->name; }

	void SetID(int data) { ID = data; }
	void Setname(char* data) { strcpy(this->name, data); }

	void Print()
	{
		cout << "color: " << Getcolor() << endl;
		cout << "carnumber: " << Getcarnumber() << endl;
		cout << "speed: " << Getspeed() << endl;
		cout << "gear: " << Getgear() << endl;
		cout << "ID: " << ID << endl;
		cout << "name: " << name << endl;
	}
};

int main()
{
	CarInformation *car_info = new CarInformation;
	C_Car *mcar = new C_Car;

	char tempColor[256];
	int tempSpeed;
	int tempGear;
	int tempNumber;
	char tempName[256];
	int tempID;

	cout << "car_info color:";
	cin >> tempColor;

	cout << "car_info number:";
	cin >> tempNumber;

	cout << "car_info speed:";
	cin >> tempSpeed;

	cout << "car_info Gear:";
	cin >> tempGear;

	car_info->Setcolor(tempColor);
	car_info->Setcarnumber(tempNumber);
	car_info->Setspeed(tempSpeed);
	car_info->Setgear(tempGear);

	cout << "mCar id:";
	cin >> tempID;

	cout << "mcar name:";
	cin >> tempName;

	cout << "mcar_info color:";
	cin >> tempColor;

	cout << "mcar_info number:";
	cin >> tempNumber;

	cout << "mcar_info speed:";
	cin >> tempSpeed;

	cout << "mcar_info Gear:";
	cin >> tempGear;

	mcar->SetID(tempID);
	mcar->Setname(tempName);
	mcar->Setcolor(tempColor);
	mcar->Setcarnumber(tempNumber);
	mcar->Setspeed(tempSpeed);
	mcar->Setgear(tempGear);

	car_info->Print();
	mcar->Print();

	delete car_info;
	delete mcar;
}