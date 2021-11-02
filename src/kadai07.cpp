// kadai07.cpp
#include <iostream> 
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B 

bool IsPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}
/* --------------------------------------------------------------- */
/*
*  nth_prime
*
*  �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
*  �f����Ԃ��B
*
*  TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
*  �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	unsigned int* numptr;
	numptr = (unsigned int *)malloc(sizeof(unsigned int) * CPP2_PRIME_UPPER_LIMIT);

	unsigned int* prime;
	prime = (unsigned int *)malloc(sizeof(unsigned int) * CPP2_PRIME_UPPER_LIMIT);
	//�ŏ��̐���
	numptr[0] = a;

	for (int i = 1; i < CPP2_PRIME_UPPER_LIMIT; i++) {
		numptr[i] = numptr[i - 1] + d;
	}

	uint32_t prime_index = 0;
	for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++) {
		if (IsPrime(numptr[i]) == true) {
			prime[prime_index] = numptr[i];
			prime_index++;
		}
	}


	return prime[n - 1];
};


int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;

	return 0;
}