#include <iostream>
#include <bitset>
using namespace std;

int add(int a, int b) {
	return b == 0 ? a : add(a ^ b, (a & b) << 1);
}

bool two(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	return (num & 1) == 0;
}

bool three(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	while (num > 3) {
		unsigned sum{};
		while (num) {
			sum = add(num & 3, sum);
			num >>= 2;
		}
		num = sum;
	}
	return num == 0 || num == abs(3);
}

bool four(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	return !(num & 3);
}

bool five(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	return num * 0xCCCCCCCD <= 0x33333333;
	/*bitset<16> b(num);
	bitset<2> tmp;
	int sum_even = 0, sum_odd = 0;

	int count = 0;
	for (int i = 1; i < b.size(); i += 2) {
		if ((count & 1) == 0) {
			tmp[0] = b[i];
			tmp[1] = b[i - 1];
			sum_even += tmp.to_ulong();
		}
		else {
			tmp[0] = b[i];
			tmp[1] = b[i - 1];
			sum_odd += tmp.to_ulong();
		}
		count++;
	}
	return (sum_even - sum_odd) == 0 || (sum_even - sum_odd) == 5 || (sum_even - sum_odd) % 5 == 0;*/
}

bool six(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	return two(num) && three(num);
}

bool seven(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	while (num > 7) {
		int sum{};
		while (num) {
			sum = add(num & 7, sum);
			num >>= 3;
		}
		num = sum;
	}
	return num == 0 || num == 7;
}

bool eight(int num) {
	if (num < 0 || num > 65535) cout << "Wrong number" << endl;
	return !(num & 7);
}

bool nine(int num) {
	if (num == 0 || num == 9)
		return true;
	if (num < 9)
		return false;
	return nine((int)(num >> 3) - (int)(num & 7));
}

int main()
{
	int num;
	{
		cout << "2:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (two(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 2 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (two(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "3:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (three(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 3 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (three(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "4:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (four(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 4 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (four(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "5:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (five(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 5 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (five(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "6:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (two(num) && three(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 6 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (six(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "7:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (seven(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 7 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (seven(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "8:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (eight(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 8 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (eight(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}

	{
		cout << "9:\n";
		cout << "Enter number (0 - 65, 535): "; cin >> num;
		if (nine(num)) cout << "Yes\n";
		else cout << "No\n";

		int c1 = 0, c2 = 0;
		for (int i = 0; i <= 65535; i++) if (i % 9 == 0) c1++;
		for (int i = 0; i <= 65535; i++) if (nine(i)) c2++;
		cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	}
	return 0;
}