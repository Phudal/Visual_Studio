#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Shape
{
private: 
	int width;
	int height;

public:
	void SetWidth(int value) { width = value; }
	void SetHeight(int value) { height = value; }

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	virtual void PrintArea() = 0;
};

class Rectangle : public Shape
{
public:
	virtual void PrintArea()
	{
		cout << "»ç°¢ÇüÀÇ ³ÐÀÌ: " << GetWidth() * GetHeight() << endl;
	}
};

class Triangle : public Shape
{
public:
	virtual void PrintArea()
	{
		cout << "»ï°¢ÇüÀÇ ³ÐÀÌ: " << GetWidth() * GetHeight() / 2 << endl;
	}
};

int main()
{
	Rectangle mRect;
	Triangle mTri;

	int tempWidth;
	int tempHeight;

	cout << "mRect width?";
	cin >> tempWidth;

	cout << "mRect Height?";
	cin >> tempHeight;

	mRect.SetWidth(tempWidth);
	mRect.SetHeight(tempHeight);

	cout << "mTri width?";
	cin >> tempWidth;

	cout << "mTri Height?";
	cin >> tempHeight;

	mTri.SetWidth(tempWidth);
	mTri.SetHeight(tempHeight);
	mRect.PrintArea();
	cout << mRect.GetWidth() << endl;
	cout << mRect.GetHeight() << endl;
	mTri.PrintArea();
}