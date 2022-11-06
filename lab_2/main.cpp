#include<iostream>

int main()
{
	//a = 0x1'527D'27F2; 5'678'901'234
	//b = 0x1'94A8'1B79; 6'789'012'345;
	//c = 0x1'D649'BAC0; 7'890'123'456;
	//d = 0x2'128E'0F87; 8'901'234'567; 
	//e = 0x2'192D'7B4E; 9'012'345'678;
	//f = 0x2'5B67'B115; 10'123'456'789;
	//result = (c*d + 23)/(a/2 - 4*d - 1);
	unsigned long long memo = 0;

	__asm
	{
		pushad

		//d*c (ebx:ecx)+
		mov edi, 0x1
		mov esi, 0x7864CB
		mov ecx, 0x2
		mov ebx, 0x87D272
		mov eax, esi
		mul ebx //esi ebx
		push edx // h
		push eax // l
		mov eax, edi
		mul ebx //edi ebx
		push edx //h
		push eax //l
		mov eax, esi
		mul ecx //esi ecx
		push edx //h
		push eax // l
		mov eax, edi
		mul ecx //edi ecx
		//summ edx:eax
		mov edx, eax
		pop ebx //esi ecx l
		pop ecx //esi ecx h
		add eax, ebx
		adc edx, ecx
		pop ebx //edi ebx l
		pop ecx //edi ebx h
		add eax, ebx
		adc edx, ecx
		pop ebx //esi ebx l
		pop ecx //esi ebx h
		add eax, ebx
		adc edx, ecx
		mov ebx, edx
		mov ecx, eax



		//c*d + 23(ebx:ecx)+
		mov eax, 0x17
		mov edx, 0
		add ecx, eax
		adc ebx, edx
		push ebx //h
		push ecx //l
		lea eax, tmp1
		mov[eax], ebx
		lea eax, tmp2
		mov[eax], ecx

		//a/2 (esi)+
		mov edx, 0x1
		mov eax, 0x56A735
		mov edi, 2

		//a/2 (esi)+
		mov edx, 0x1
		mov eax, 0x527D'27F2
		mov edi, 0x2
		div edi
		mov esi, eax

		//4*d (edi:esi)+
		mov ecx, 0x4
		mov eax, 0x87D272
		mov ebx, 0x2
		mul ecx
		mov esi, eax
		mov edi, edx
		mov eax, ebx
		mul ecx
		add edi, eax

		//4*d-a/2 + 1(edi:esi)+
		mov edx, 0
		sub esi, eax
		sbb edi, edx
		inc esi
		sbb edi, edx

		//(c*d + 23)/(4*d-a/2 + 1) 
		mov eax, 0
		mov edx, 0
		pop eax //l
		pop edx //h
		div esi

		//(c*d + 23)/(4*d-a/2 + 1)*(-1)+
		neg eax

		lea ecx, memo
		mov[ecx], eax

		popad
	}

	std::cout << memo;
	return 0;
}
