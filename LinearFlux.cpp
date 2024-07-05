#include <immintrin.h> // Incluir instrucciones SIMD

void LinearFlux::computeFlux(const DataStruct<float> &U, DataStruct<float> &F) {
    int size = U.getSize();
    const float* uData = U.getData();
    float* fData = F.getData();

    __m256 a_vec = _mm256_set1_ps(a); // Cargar la constante `a` en un registro SIMD

    for (int i = 0; i < size; i += 8) {
        __m256 u_vec = _mm256_loadu_ps(&uData[i]); // Cargar 8 floats de uData
        __m256 f_vec = _mm256_mul_ps(a_vec, u_vec); // Multiplicar
        _mm256_storeu_ps(&fData[i], f_vec); // Almacenar el resultado en fData
    }
}

