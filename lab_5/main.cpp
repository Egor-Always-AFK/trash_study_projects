#include <iostream>
#include <random>
#include <iomanip>


size_t min = 0;
size_t max = 5;
const size_t arrSize = 3;

size_t random() 
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<size_t> uni(min, max);

    return uni(rng);
}

void randomArray(size_t arr[arrSize]) 
{
    for (size_t i = 0; i < arrSize; i++)
        arr[i] = random();
}

void randomMatrix(size_t arr[arrSize][arrSize]) 
{
    for (size_t i = 0; i < arrSize; i++)
        for (size_t j = 0; j < arrSize; j++)
            arr[i][j] = random();
}

size_t main()
{
    size_t X = 0;
    size_t Y = 3;
    size_t term = 0;
    size_t anotherCounter = 0;
    size_t result = 0;
    size_t Bytes = 4;
    bool overflow = false;


    int A[arrSize] = {1, 1, 1};
    int C[arrSize] = {-4, 5, 6};
    int B[arrSize][arrSize] = { {1, 1, 1}, {1, -1, 1 }, {1, 1, 1} };

    //randomArray(A);
    //randomArray(C);
    //randomMatrix(B);

    std::cout << "X: " << X << " Y: " << Y << "\n";

    std::cout << "A: \n";
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << std::setw(3) << A[i];
    }

    std::cout << "\nB:";
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << "\n";
        for (size_t j = 0; j < arrSize; j++)
        {
            std::cout << std::setw(3) << B[i][j];
        }
    }

    std::cout << "\nC: \n";
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << std::setw(3) << C[i];
    }
    // result = X * Σ(A_i * B_i_j) + Y * ΣC_i

	__asm
	{
		pushad
		

        lea edx, arrSize
        mov ecx, [edx]

        lea esi, C

    c_sum: //Σ(C_i)

        jo except
        mov eax, [esi]
        cmp eax, 0
        js below_zero1
        jmp above_zero1
        below_zero1:
        call my_abs
        above_zero1:
        add term, eax
        add esi, 4
        loop c_sum
        mov eax, term
        mul Y //Y * Σ(C_i)
        jo except
        add result, eax
        mov term, 0

    //Σ(A_i * B_i_j)

        lea esi, A
        lea edi, B

        mov ecx, arrSize
        mov ebx, 0

    mul_loop:
    
        mov eax, [esi]
        cmp eax, 0
        js below_zero
        jmp above_zero
        below_zero:
        call my_abs
        above_zero:
        cmp [edi], 0
        js below_zero2
        jmp above_zero2
        below_zero2:
        push eax
        mov eax, [edi]
        call my_abs
        mov [edi], eax
        pop eax
        above_zero2:
        mul[edi]
        jo except
        add term, eax

        mov eax, arrSize
        mul Bytes
        add edi, eax
        loop mul_loop

        inc anotherCounter
        mov eax, anotherCounter
        mul Bytes
        lea edi, B
        add edi, eax
        add esi, 4
        mov ecx, arrSize
        add ecx, 1
        inc ebx
        cmp ebx, arrSize
        jge after_loop
        loop mul_loop

    after_loop:

        mov eax, term //X * Σ(A_i * B_i_j)
        mul X
        jo except
        add result, eax

        jmp no_trouble

    except:

        add overflow, 1

    my_abs:
        neg eax
        ret

    no_trouble:
            
		popad
	}

    if (overflow)
    {
        std::cout << "\noverflow" << "\n";
    }
    else
    {
        std::cout << "\n" << result << "\n";
    }
	return 0;
}