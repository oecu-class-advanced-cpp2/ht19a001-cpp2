// report2.cpp
#include <iostream> 
#include <vector>
#include <exception>
#include <stdexcept>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

bool isPrime(int num){
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2){
		if (num % i == 0){
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
	if (n <= 0) {
		throw std::runtime_error("n must be more than one, or else, could cause access error");
	}

	uint32_t* prime;
	prime = (uint32_t *)malloc(sizeof(uint32_t) * n);
	uint32_t prime_index = 0;
	uint32_t num = a;

	for (int i = 1; i < CPP2_PRIME_UPPER_LIMIT; i++) {
		if (isPrime(num) == true) {
			prime[prime_index] = num;
			prime_index++;
			if (prime_index > n) {
				break;
			}
		}
		num += d;
	}
	return prime[n - 1];
	free(prime);
};


int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177) << std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;
	
	getchar();
	return 0;
}
# ht19a001-cpp2 
