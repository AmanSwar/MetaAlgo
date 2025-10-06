#pragma once

#include <cuda_fp16.h>
#include <cuda_bf16.hpp>
#include <cuda_fp8.h>

#define FP32 float
#define FP16 half
#define BF16 __nv_bfloat16
#define FP8 __nv_fp8_e4m3

#define INT32 int
#define INT16 std::int16_t
#define INT8 std::int8_t

#define UINT8 uint8_t
#define UINT16 uint16_t
#define UINT32 uint32_t

