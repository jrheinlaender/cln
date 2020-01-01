#include "test_I.h"

int test_I_factorial(int /* iterations */) {
	int error = 0;
	cl_I result = factorial(14U);
	ASSERT1(result > cl_I(UINT64_C(1) << 32), result);
	return error;
}

int test_I_doublefactorial(int /* iterations */) {
	int error = 0;
	cl_I result = doublefactorial(21U);
	ASSERT1(result > cl_I(UINT64_C(1) << 32), result);
	return error;
}
