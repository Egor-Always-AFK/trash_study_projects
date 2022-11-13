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
	__int64 Memo[DataSize];
	for (int i = 0; i++; i < DataSize) {
		Memo[i] = NULL;
	}
	Memo[0] = 5678901234; //a 0x1'527D'27F2
	Memo[1] = 7890123456; //c 0x1'D649'BAC0
	Memo[2] = 8901234567; //d 0x2'128E'0F87
	__asm {
		pushad

		// Memo[0] == Memo[0]
		// Memo[1] == Memo[8]
		// Memo[2] == Memo[16]
		// Memo[3] == Memo[24]
		// итд Memo[n] == Memo [8 * n]

		//a/2 пара eax:ebx
		lea esi, Memo[0]
		mov eax, [esi] // eax = 527D'27F2
		mov edx, [esi + 4] // ebx = 0x1
		mov ecx, 2
		div ecx
		lea esi, Memo[24]
		mov[esi], eax //результат от деления в Memo[3]

		//d*4
		lea esi, Memo[16]
		mov eax, [esi] // eax = 128E'0F87
		mov ecx, 4
		mul ecx
		mov ebx, eax // ebx = 128E'0F87 * 4
		mov eax, [esi + 4] // eax = 0x2
		mul ecx
		lea esi, Memo[32]
		mov[esi], ebx // заносим младшие разряды в Memo[4]
		mov[esi + 4], eax // заносим старший разрял в Memo[4]

		//a/2 - d*4 - 1
		lea esi, Memo[24] // Memo[24] = Memo[3] = a/2 
		mov eax, [esi]
		lea esi, Memo[32] // Memo[32] = Memo[4] = d * 4
		mov ebx, [esi]
		sub eax, ebx //a/2 - d*4
		dec eax // - 1
		mov ecx, eax // результат переносим в ecx
		mov eax, [esi + 4] 
		neg eax // a/2 < d*4 ==> 0x1 - 0x2 = -0x1
		lea esi, Memo[40]
		mov[esi], eax // старшие разряды в Memo[5]
		lea esi, Memo[48] 
		mov[esi], ecx // младшие разряды в Memo[6]

		//c*d
		lea esi, Memo[8]
		mov eax, [esi]
		mov ecx, 10h
		div ecx
		mov ebx, [esi + 4]
		xchg eax, ebx
		mov ecx, 10000000h
		mul ecx
		add eax, ebx
		xchg eax, ebx
		lea esi, Memo[16]
		mov eax, [esi + 4]
		mul ecx
		mul ebx
		mov ecx, 10h
		xchg eax, edx
		xchg edx, edi
		mul ecx
		mov ecx, 10000000h
		xchg eax, edi
		div ecx
		add eax, edi
		mov edi, eax
		lea esi, Memo[16]
		mov eax, [esi]
		mul ebx
		mov ebx, eax
		xchg eax, edx
		add eax, edi
		mov ecx, 10h
		mul ecx
		xchg eax, ebx
		mul ecx
		add ebx, edx
		xchg edx, ebx
		lea esi, Memo[56]
		mov[esi], edx

		//c*d + 23
		mov ecx, 23
		add eax, ecx
		lea esi, Memo[64]
		mov[esi], eax

		//(c*d + 23)/(a/2 - d*4 - 1)
		lea esi, Memo[56]
		mov eax, [esi]
		lea esi, Memo[40]
		mov ecx, [esi]
		div ecx
		dec eax
		lea esi, Memo[72]
		mov[esi], eax
		lea esi, Memo[80]
		mov[esi], edx


		popad
	}
	std::cout << Memo[80];
	//for (int i = 0; i < DataSize; i++) 
	//{
	//	if ((i % 16) == 0) {
	//		cout << "\n" << setw(2) << i / 16 << ":";
	//	}
	//	else {
	//		cout << " " << setw(2) << IntToHex(Memo[i - 1]);
	//	}
	//}
	_getch();
	return 0;
}

