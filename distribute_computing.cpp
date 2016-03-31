#include <iostream>
int T;

int main()
{
	int A, B, C, s, i;
	//freopen("Text.txt", "r", stdin);
	std::cin >> T;
	while (T--) {
		s = 1;
		std::cin >> A >> B;
		C = B % 4;
		if (C % 4 == 0) C = 4;
		for (int i = 0; i < C; i++)
			s = s*A;
		if (s % 10 == 0) s = 10;
		else s = s % 10;

		std::cout << s << "\n";
	}
	return 0;
}
