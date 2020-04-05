#include <iostream>
using namespace std;

void TakeDamage(int damage);

int health = 15;

int main()
{
	int x = 10;
	cout << "The value of x is : " << x << endl;
	int y = x << 2;
	cout << "The value of y (x << 2) is : " << y << endl;
	int z = y >> 1;
	cout << "The value of z (y >> 1) is : " << z << endl;
	int w = ++x << 3;
	cout << "The value of w (x++ << 3) is : " << w << endl;
	int t = y & z;
	cout << "The value of t (y & z) is : " << t << endl;
	int s = w | 13;
	cout << "The value of s (w | 13) is : " << s << endl;
	int m = 100 ^ z;

	cout << "The value of m (100 ^ z) is : " << m << endl;

	const char* name = "my name is....";
	const char* last = &name[8];

	cout << last << endl;

	typedef void(*funcPtr)(int);
	funcPtr j = TakeDamage;
	j(10);

	cout << health << endl;

}

void TakeDamage(int damage) {
	health -= damage;
}