#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>

using namespace std;
const int DataSize = 144;

std::string IntToHex(int n)
{
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}
int main()
{
	long long Memo[DataSize];
	for (int i = 0; i++; i < DataSize) {
		Memo[i] = NULL;
	}
	//a = 0x1'56'A735 = 5678901
	//c = 0x1'78'64CB = 7890123
	//d  = 0x2'87'D272 = 8901234
	__asm {
		pushad

		//a/2
		mov eax, 5678901
		mov edx, 0
		mov ecx, 2
		div ecx
		push eax // в стэк


		//d*4
		mov eax, 8901234
		mov ecx, 4
		mul ecx
		mov ebx, eax


		//a/2 - d*4 - 1
		pop eax
		push ebx
		push eax
		neg eax
		add ebx, eax //a/2 - d*4
		inc ebx // - 1
		mov edi, ebx
		//результат от a/2 - d*4 - 1 => edi

		//c*d
		mov eax, 7890123
		mov ebx, 8901234
		mul ebx

		//c*d + 23
		mov ecx, 23
		add eax, ecx
		
		//старший разряд edx, младший eax

		//(c*d + 23)/(a/2 - d*4 - 1)
		mov ebx, edi
		div ebx
		neg eax

		pop edi
		popad
	}
	for (int i = 0; i < DataSize; i++) 
	{
		if ((i % 16) == 0) {
			cout << "\n" << setw(2) << i / 16 << ":";
		}
		else {
			cout << " " << setw(2) << IntToHex(Memo[i - 1]);
		}
	}
	_getch();
	return 0;
}

