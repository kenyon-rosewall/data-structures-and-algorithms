#pragma once

#ifndef TYPES_H
#define TYPES_H

//
// TYPES
//

#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef bool b32;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef intptr_t intptr;
typedef uintptr_t uintptr;

typedef float f32;
typedef double f64;

#define Real32Maximum FLT_MAX

#if !defined(internal)
#define internal static
#endif
#define global_variable static
#define local_persist static

//
// CONSTANTS
//

#define Pi32 3.14159265359f
#define Tau32 6.28318530717958647692f

#endif // !TYPES_H
