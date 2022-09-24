#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	char32_t idk;
	__asm {
		pushad

		mov eax, 2433934443
		mov ebx, 2015149002
		mov di, 56190
		mov si, 5075
		mov dh, 236
		mov dl, 69
		
		/*7*/
		 xchg eax, ebx

		 mov esi, eax
		 mov eax, ebx
		 mov ebx, esi

		 push eax
		 mov eax, ebx
		 pop ebx

		 lea ecx, idk
		 mov [ecx], eax
		 mov eax, ebx
		 mov ebx, [ecx]
		/*8*/
		 xchg di, si

		 mov cx, di
		 mov di, si
		 mov si, cx

		 push di
		 mov di, cx
		 pop cx

		 lea ecx, idk
		 mov [ecx], si
		 mov si, di
		 mov di, [ecx]

		/*9*/
		 xchg dh, dl

		 mov ch, dh
		 mov dh, dl
		 mov dl, ch

		 push dh
		 mov dh, dl
		 pop dl

		 lea ecx, idk
		 mov [ecx], dh
		 mov dh, dl
		 mov dl, [ecx]

		 /*10*/
		 movsx cx, dh
		 movsx dx, dl

		 /*11*/
		 movzx eax, si
		 movzx ebx, di

		 popad
	}
	return (0);
}