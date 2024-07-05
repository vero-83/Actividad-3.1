#include <immintrin.h> // Incluir instrucciones SIMD

void Central1D::evalRHS(DataStruct<float> &U) {
    int size = U.getSize();
    float* uData = U.getData();
    float* rhsData = rhs.getData();

    for (int i = 0; i < size; i += 8) {
        __m256 u_vec = _mm256_loadu_ps(&uData[i]); // Cargar 8 floats de uData
        __m256 rhs_vec = _mm256_mul_ps(u_vec, _mm256_set1_ps(2.0f)); // Multiplicar por 2
        _mm256_storeu_ps(&rhsData[i], rhs_vec); // Almacenar el resultado en rhsData
    }
}

