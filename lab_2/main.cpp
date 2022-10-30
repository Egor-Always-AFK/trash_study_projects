#include<conio.h>
#include <iostream>

using namespace std;

int main() {
	unsigned long long int a = 5678901234;
	unsigned long long int c = 7890123456;
	unsigned long long int d = 8901234567;
	unsigned int divider = 0;
	unsigned long long int dividend = 0;
	long long answer = 0;
	char memo[144];
	for (int i = 0; i++; i < 144) {
		memo[i] = 0;
	}

	_asm {
		pushad

		lea edi, c
		mov ebx, [edi]
		mov si, [edi + 4]

		bswap esi

		lea edi, d
		mov ecx, [edi]
		mov si, [edi + 4] 

		mov eax, ebx
		mul ecx 
		
		lea edi, memo
		mov [edi], eax 
		mov [edi + 4], edx 

		movzx eax, si
		mul ebx 

		push si
		bswap esi
		push si

		mov esi, [edi + 4]
		add esi, eax
		mov [edi + 4], esi
		
		mov [edi + 8], edx

		xor esi, esi
		pop si 


		mov eax, ecx
		mul esi

		push si 

		mov esi, [edi + 4]
		add esi, eax 
		mov [edi + 4], esi

		pop si 
		xor eax, eax
		mov ax, si	

		pop si
		mul si 

		mov esi, [edi + 8]
		add eax, esi
		mov [edi + 8], eax

		add [edi], 23

		lea edi, a
		mov eax, [edi]
		mov edx, [edi + 4]
		
		xor ebx, ebx
		mov ebx, 2

		div ebx
		dec eax // a/2 - 1


		lea edi, memo[12]
		mov [edi], eax 

		lea edi, d
		mov ecx, [edi] 
		mov ebx, [edi + 4]
		
		mov esi, 4
		
		mov eax, ecx 
		mul esi

		imul ebx, esi
		
		mov ecx, eax


		lea edi, memo[12]
		mov eax, [edi]

	

		sub ecx, eax
		sbb ebx, 0

		
		mov edx, ebx
		mov eax, ecx
		mov esi, 8
		div esi

		lea edi, divider
		mov [edi], eax
		

		lea edi, memo
		mov eax, [edi]
		div esi
		xor eax, 0x80000000
		mov ecx, eax


		mov eax, [edi + 4]
		imul eax, 0x00000100
		xor edx, edx
		div esi
		
		mov ebx, eax
		bswap ecx
		add cl, bl
		bswap ecx
		lea edi, dividend
		mov [edi], ecx

		mov edi, 0x00000100
		div edi
		mov ebx, eax

		lea edi, memo[7]
		mov eax, [edi]
		imul eax, 0x00000010
		xor dl, dl
		div esi
		imul eax, 0x00100000

		add ebx, eax

		mov edx, ebx
		mov eax, ecx


		lea edi, divider
		mov ebx, [edi]


		div ebx

		neg eax
		cdq
	
		lea edi, answer
		mov [edi], eax
		mov [edi + 4], edx

		popad
	}

	cout << "Answer is: " << answer;
	return 0;
}
