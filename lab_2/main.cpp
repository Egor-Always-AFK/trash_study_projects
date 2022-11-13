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
		// сначала нужно избавится от нулей которые получились при сдвиге
		lea esi, Memo[8] // Memo[1] = Memo[8] = d
		mov eax, [esi]
		mov ecx, 10h
		div ecx // d649bac0/10 = 0d649bac
		mov ebx, [esi + 4]
		xchg eax, ebx
		mov ecx, 10000000h
		mul ecx // 00000001*10000000 = 10000000
		add eax, ebx // 10000000 + 0d649bac = 1d649bac
		xchg eax, ebx
		lea esi, Memo[16] // Memo[2] = Memo[16] = c
		mov eax, [esi + 4]
		mul ecx // 00000002 * 10000000 = 20000000
		mul ebx // 20000000 * 1d649bac = eax : edx = 80000000 : 03ac9375 
		mov ecx, 10h
		xchg eax, edx
		xchg edx, edi
		mul ecx // 03ac9375 * 10 = 3ac93750
		mov ecx, 10000000h
		xchg eax, edi
		div ecx // 80000000/10000000 = 00000008
		//от нулей избавились можем работать дальше умножаем
		add eax, edi // старшие разряды складываем 3ac93750 + 00000008 = 3ac93758
		mov edi, eax // edi для старших разрядов 
		lea esi, Memo[16] // Memo[2] = Memo[16] = c
		mov eax, [esi] // младшие разряды c
		mul ebx // 128e0f87 * 1d649bac = eax : edx = d6952bb4 : 02216288
		mov ebx, eax // eax => ebx (eax - произведение младших разрядов)
		xchg eax, edx // eax <=> edx
		add eax, edi // 02216288 + 3ac937558 = 3cea99e0
		mov ecx, 10h 
		mul ecx // 3cea99e0 * 10 = cea99e00
		xchg eax, ebx
		mul ecx // d6952bb4 * 10 = 6952bb40
		add ebx, edx // cea99e00 + 0000000d = cea99e0d
		xchg edx, ebx
		lea esi, Memo[56]
		mov[esi], edx // результат произведения в Memo[7]

		//c*d + 23
		mov ecx, 23
		add eax, ecx
		lea esi, Memo[64]
		mov[esi], eax // результат сложения в Memo[8]

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

