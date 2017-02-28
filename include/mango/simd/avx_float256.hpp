/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#ifdef MANGO_INCLUDE_SIMD

    // -----------------------------------------------------------------
    // float32x8
    // -----------------------------------------------------------------

    static inline float32x8 float32x8_zero()
    {
        return _mm256_setzero_ps();
    }

    static inline float32x8 float32x8_set1(float s)
    {
        return _mm256_set1_ps(s);
    }

    static inline float32x8 float32x8_set8(float s0, float s1, float s2, float s3, float s4, float s5, float s6, float s7)
    {
        return _mm256_setr_ps(s0, s1, s2, s3, s4, s5, s6, s7);
    }

    static inline float32x8 float32x8_uload(const float* source)
    {
        return _mm256_loadu_ps(source);
    }

    static inline void float32x8_ustore(float* dest, float32x8 a)
    {
        _mm256_storeu_ps(dest, a);
    }

    static inline float32x8 float32x8_unpackhi(float32x8 a, float32x8 b)
    {
        return _mm256_unpackhi_ps(a, b);
    }

    static inline float32x8 float32x8_unpacklo(float32x8 a, float32x8 b)
    {
        return _mm256_unpacklo_ps(a, b);
    }

    // logical

    static inline float32x8 float32x8_and(float32x8 a, float32x8 b)
    {
         return _mm256_and_ps(a, b);
    }

    static inline float32x8 float32x8_nand(float32x8 a, float32x8 b)
    {
        return _mm256_andnot_ps(a, b);
    }

    static inline float32x8 float32x8_or(float32x8 a, float32x8 b)
    {
         return _mm256_or_ps(a, b);
    }

    static inline float32x8 float32x8_xor(float32x8 a, float32x8 b)
    {
         return _mm256_xor_ps(a, b);
    }

    static inline float32x8 float32x8_min(float32x8 a, float32x8 b)
    {
        return _mm256_min_ps(a, b);
    }

    static inline float32x8 float32x8_max(float32x8 a, float32x8 b)
    {
        return _mm256_max_ps(a, b);
    }

    static inline float32x8 float32x8_abs(float32x8 a)
    {
        return _mm256_and_ps(a, _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff)));
    }

    static inline float32x8 float32x8_neg(float32x8 a)
    {
        return _mm256_xor_ps(a, _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000)));
    }

    static inline float32x8 float32x8_add(float32x8 a, float32x8 b)
    {
        return _mm256_add_ps(a, b);
    }

    static inline float32x8 float32x8_sub(float32x8 a, float32x8 b)
    {
        return _mm256_sub_ps(a, b);
    }

    static inline float32x8 float32x8_mul(float32x8 a, float32x8 b)
    {
        return _mm256_mul_ps(a, b);
    }

    static inline float32x8 float32x8_div(float32x8 a, float32x8 b)
    {
        return _mm256_div_ps(a, b);
    }

    static inline float32x8 float32x8_div(float32x8 a, float b)
    {
        return _mm256_div_ps(a, _mm256_set1_ps(b));
    }

    static inline float32x8 float32x8_fast_reciprocal(float32x8 a)
    {
        return _mm256_rcp_ps(a);
    }

    static inline float32x8 float32x8_fast_rsqrt(float32x8 a)
    {
        return _mm256_rsqrt_ps(a);
    }

    static inline float32x8 float32x8_fast_sqrt(float32x8 a)
    {
        const __m256 n = _mm256_rsqrt_ps(a);
        return _mm256_mul_ps(a, n);
    }

    static inline float32x8 float32x8_reciprocal(float32x8 a)
    {
        const __m256 n = _mm256_rcp_ps(a);
        const __m256 m = _mm256_mul_ps(_mm256_mul_ps(n, n), a);
        return _mm256_sub_ps(_mm256_add_ps(n, n), m);
    }

    static inline float32x8 float32x8_rsqrt(float32x8 a)
    {
        __m256 n = _mm256_rsqrt_ps(a);
        __m256 e = _mm256_mul_ps(_mm256_mul_ps(n, n), a);
        n = _mm256_mul_ps(_mm256_set1_ps(0.5f), n);
        e = _mm256_sub_ps(_mm256_set1_ps(3.0f), e);
        return _mm256_mul_ps(n, e);
    }

    static inline float32x8 float32x8_sqrt(float32x8 a)
    {
        return _mm256_sqrt_ps(a);
    }

    // compare

    static inline float32x8 float32x8_compare_neq(float32x8 a, float32x8 b)
    {
        return _mm256_cmp_ps(a, b, 4);
    }

    static inline float32x8 float32x8_compare_eq(float32x8 a, float32x8 b)
    {
        return _mm256_cmp_ps(a, b, 0);
    }

    static inline float32x8 float32x8_compare_lt(float32x8 a, float32x8 b)
    {
        return _mm256_cmp_ps(a, b, 1);
    }

    static inline float32x8 float32x8_compare_le(float32x8 a, float32x8 b)
    {
        return _mm256_cmp_ps(a, b, 2);
    }

    static inline float32x8 float32x8_compare_gt(float32x8 a, float32x8 b)
    {
        return _mm256_cmp_ps(b, a, 1);
    }

    static inline float32x8 float32x8_compare_ge(float32x8 a, float32x8 b)
    {
        return _mm256_cmp_ps(b, a, 2);
    }

    static inline float32x8 float32x8_select(float32x8 mask, float32x8 a, float32x8 b)
    {
        return _mm256_blendv_ps(b, a, mask);
    }

    // rounding

    static inline float32x8 float32x8_round(float32x8 s)
    {
        return _mm256_round_ps(s, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
    }

    static inline float32x8 float32x8_trunc(float32x8 s)
    {
        return _mm256_round_ps(s, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
    }

    static inline float32x8 float32x8_floor(float32x8 s)
    {
        return _mm256_round_ps(s, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    }

    static inline float32x8 float32x8_ceil(float32x8 s)
    {
        return _mm256_round_ps(s, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
    }

    static inline float32x8 float32x8_fract(float32x8 s)
    {
        return _mm256_sub_ps(s, float32x8_floor(s));
    }

#endif // MANGO_INCLUDE_SIMD