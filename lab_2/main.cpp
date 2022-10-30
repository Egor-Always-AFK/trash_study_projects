#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <cstdint>

int main()
{
	//a = 0x1'527D'27F2; 5'678'901'234
	//b = 0x1'94A8'1B79; 6'789'012'345;
	//c = 0x1'D649'BAC0; 7'890'123'456;
	//d = 0x2'128E'0F87; 8'901'234'567; 
	//e = 0x2'192D'7B4E; 9'012'345'678;
	//f = 0x2'5B67'B115; 10'123'456'789;
	//result = (c*d + 23)/(a/2 - 4*d - 1);

	uint32_t memo;

	__asm
	{
		pushad

		//d*c (ebp:esp)
		mov edi, 0x1
		mov esi, 0xD649'BAC0
		mov ecx, 0x2
		mov ebx, 0x128E'0F87
		mov eax, esi
		mul ebx
		mov ebp, edx
		mov esp, eax
		mov eax, edi
		mul ebx
		add esp, eax
		adc ebp, edx
		mov eax, esi
		mul ecx
		add esp, eax
		adc ebp, edx
		mov eax, edi
		mul ecx
		add ebp, eax

		//c*d + 23(ebp:esp)
		mov eax, 0x17
		add esp, eax
		adc ebp, edx

		//a/2 (eax)
		mov edx, 0x1
		mov eax, 0x527D'27F2
		mov ecx, 0x2
		div ecx
		mov ebx, eax

		//4*d (edi:esi)
		mov ecx, 0x4
		mov eax, 0x128E'0F87
		mov ebx, 0x2
		mul ecx
		mov esi, eax
		mov edi, edx
		mov eax, ebx
		mul ecx
		add edi, eax

		//a/2 - 4*d - 1 = (-1)(4*d-a/2 + 1)//4*d-a/2 + 1(edi:esi)
		mov edx, 0
		sub esi, eax
		sbb edi, edx
		inc esi
		sbb edi, edx

		//(c*d + 23)/(4*d-a/2 + 1) // edi = 0 halyavi radi
		mov edx, ebp
		mov eax, esp
		div esi

		//(c*d + 23)/(4*d-a/2 + 1)*(-1)
		neg eax

		lea ecx, memo
		mov [ecx], eax
		// mov dword ptr[result], eax
		popad
	}

	std::cout << memo;
	return 0;
}
