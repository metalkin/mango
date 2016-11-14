/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2016 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include <cassert>
#include "configure.hpp"
#include "bits.hpp"

namespace mango
{

    // --------------------------------------------------------------
    // aligned load/store
    // --------------------------------------------------------------

    inline uint16 load16(const uint8* p)
    {
        uint16 value = reinterpret_cast<const uint16*>(p)[0];
        return value;
    }

    inline uint32 load32(const uint8* p)
    {
        uint32 value = reinterpret_cast<const uint32*>(p)[0];
        return value;
    }

    inline uint64 load64(const uint8* p)
    {
        uint64 value = reinterpret_cast<const uint64*>(p)[0];
        return value;
    }

    inline void store16(uint8* p, uint16 value)
    {
        reinterpret_cast<uint16*>(p)[0] = value;
    }

    inline void store32(uint8* p, uint32 value)
    {
        reinterpret_cast<uint32*>(p)[0] = value;
    }

    inline void store64(uint8* p, uint64 value)
    {
        reinterpret_cast<uint64*>(p)[0] = value;
    }

    // --------------------------------------------------------------
    // unaligned load/store
    // --------------------------------------------------------------

#ifdef MANGO_UNALIGNED_MEMORY

    inline uint16 uload16(const uint8* p)
    {
        uint16 value = reinterpret_cast<const uint16*>(p)[0];
        return value;
    }

    inline uint32 uload32(const uint8* p)
    {
        uint32 value = reinterpret_cast<const uint32*>(p)[0];
        return value;
    }

    inline uint64 uload64(const uint8* p)
    {
        uint64 value = reinterpret_cast<const uint64*>(p)[0];
        return value;
    }

    inline void ustore16(uint8* p, uint16 value)
    {
        reinterpret_cast<uint16*>(p)[0] = value;
    }

    inline void ustore32(uint8* p, uint32 value)
    {
        reinterpret_cast<uint32*>(p)[0] = value;
    }

#else

    // Platform does not support unaligned load/store

    inline uint16 uload16(const uint8* p)
    {
        uint16 value;
        std::memcpy(&value, p, sizeof(uint16));
        return value;
    }

    inline uint32 uload32(const uint8* p)
    {
        uint32 value;
        std::memcpy(&value, p, sizeof(uint32));
        return value;
    }

    inline uint64 uload64(const uint8* p)
    {
        uint64 value;
        std::memcpy(&value, p, sizeof(uint64));
        return value;
    }

    inline void ustore16(uint8* p, uint16 value)
    {
        std::memcpy(p, &value, sizeof(uint16));
    }

    inline void ustore32(uint8* p, uint32 value)
    {
        std::memcpy(p, &value, sizeof(uint32));
    }

#endif

    inline void ustore64(uint8* p, uint64 value)
    {
        std::memcpy(p, &value, sizeof(uint64));
    }

    // --------------------------------------------------------------
	// endian load/store
    // --------------------------------------------------------------

#ifdef MANGO_LITTLE_ENDIAN

    #define load16le(p)  mango::load16(p)
    #define load32le(p)  mango::load32(p)
    #define load64le(p)  mango::load64(p)
    #define load16be(p)  mango::byteswap16(mango::load16(p))
    #define load32be(p)  mango::byteswap32(mango::load32(p))
    #define load64be(p)  mango::byteswap64(mango::load64(p))

    #define uload16le(p)  mango::uload16(p)
    #define uload32le(p)  mango::uload32(p)
    #define uload64le(p)  mango::uload64(p)
    #define uload16be(p)  mango::byteswap16(mango::uload16(p))
    #define uload32be(p)  mango::byteswap32(mango::uload32(p))
    #define uload64be(p)  mango::byteswap64(mango::uload64(p))

    #define store16le(p,v)  mango::store16(p, v)
    #define store32le(p,v)  mango::store32(p, v)
    #define store64le(p,v)  mango::store64(p, v)
    #define store16be(p,v)  mango::store16(p, mango::byteswap16(v))
    #define store32be(p,v)  mango::store32(p, mango::byteswap32(v))
    #define store64be(p,v)  mango::store64(p, mango::byteswap64(v))

    #define ustore16le(p,v)  mango::ustore16(p, v)
    #define ustore32le(p,v)  mango::ustore32(p, v)
    #define ustore64le(p,v)  mango::ustore64(p, v)
    #define ustore16be(p,v)  mango::ustore16(p, mango::byteswap16(v))
    #define ustore32be(p,v)  mango::ustore32(p, mango::byteswap32(v))
    #define ustore64be(p,v)  mango::ustore64(p, mango::byteswap64(v))

#else

    #define load16le(p)  mango::byteswap16(mango::load16(p))
    #define load32le(p)  mango::byteswap32(mango::load32(p))
    #define load64le(p)  mango::byteswap64(mango::load64(p))
    #define load16be(p)  mango::load16(p)
    #define load32be(p)  mango::load32(p)
    #define load64be(p)  mango::load64(p)

    #define uload16le(p)  mango::byteswap16(mango::uload16(p))
    #define uload32le(p)  mango::byteswap32(mango::uload32(p))
    #define uload64le(p)  mango::byteswap64(mango::uload64(p))
    #define uload16be(p)  mango::uload16(p)
    #define uload32be(p)  mango::uload32(p)
    #define uload64be(p)  mango::uload64(p)

    #define store16le(p,v)  mango::store16(p, mango::byteswap16(v))
    #define store32le(p,v)  mango::store32(p, mango::byteswap32(v))
    #define store64le(p,v)  mango::store64(p, mango::byteswap64(v))
    #define store16be(p,v)  mango::store16(p, v)
    #define store32be(p,v)  mango::store32(p, v)
    #define store64be(p,v)  mango::store64(p, v)

    #define ustore16le(p,v)  mango::ustore16(p, mango::byteswap16(v))
    #define ustore32le(p,v)  mango::ustore32(p, mango::byteswap32(v))
    #define ustore64le(p,v)  mango::ustore64(p, mango::byteswap64(v))
    #define ustore16be(p,v)  mango::ustore16(p, v)
    #define ustore32be(p,v)  mango::ustore32(p, v)
    #define ustore64be(p,v)  mango::ustore64(p, v)

#endif

    // --------------------------------------------------------------
    // endian storage types
    // --------------------------------------------------------------

    template <typename T>
    class TypeCopy {
    protected:
        char data[sizeof(T)];

    public:
        TypeCopy() = default;

        TypeCopy(const T &value) {
            std::memcpy(data, &value, sizeof(T));
        }

        const TypeCopy& operator = (const T &value) {
            std::memcpy(data, &value, sizeof(T));
            return *this;
        }

        operator T () const {
            T temp;
            std::memcpy(&temp, data, sizeof(T));
            return temp;
        }
    };

    template <typename T>
    class TypeSwap {
    protected:
        char data[sizeof(T)];

    public:
        TypeSwap() = default;

        TypeSwap(const T &value) {
            T temp = byteswap(value);
            std::memcpy(data, &temp, sizeof(T));
        }

        const TypeSwap& operator = (const T &value) {
            T temp = byteswap(value);
            std::memcpy(data, &temp, sizeof(T));
            return *this;
        }

        operator T () const {
            T temp;
            std::memcpy(&temp, data, sizeof(T));
            return byteswap(temp);
        }
    };

#ifdef MANGO_LITTLE_ENDIAN

    typedef TypeCopy<int16>  int16le;
    typedef TypeCopy<int32>  int32le;
    typedef TypeCopy<int64>  int64le;
    typedef TypeCopy<uint16> uint16le;
    typedef TypeCopy<uint32> uint32le;
    typedef TypeCopy<uint64> uint64le;
    typedef TypeCopy<half>   float16le;
    typedef TypeCopy<float>  float32le;
    typedef TypeCopy<double> float64le;

    typedef TypeSwap<int16> int16be;
    typedef TypeSwap<int32> int32be;
    typedef TypeSwap<int64> int64be;
    typedef TypeSwap<uint16> uint16be;
    typedef TypeSwap<uint32> uint32be;
    typedef TypeSwap<uint64> uint64be;
    typedef TypeSwap<half>   float16be;
    typedef TypeSwap<float>  float32be;
    typedef TypeSwap<double> float64be;

#else

    typedef TypeSwap<int16> int16le;
    typedef TypeSwap<int32> int32le;
    typedef TypeSwap<int64> int64le;
    typedef TypeSwap<uint16> uint16le;
    typedef TypeSwap<uint32> uint32le;
    typedef TypeSwap<uint64> uint64le;
    typedef TypeSwap<half>   float16le;
    typedef TypeSwap<float>  float32le;
    typedef TypeSwap<double> float64le;

    typedef TypeCopy<int16> int16be;
    typedef TypeCopy<int32> int32be;
    typedef TypeCopy<int64> int64be;
    typedef TypeCopy<uint16> uint16be;
    typedef TypeCopy<uint32> uint32be;
    typedef TypeCopy<uint64> uint64be;
    typedef TypeCopy<half>   float16be;
    typedef TypeCopy<float>  float32be;
    typedef TypeCopy<double> float64be;

#endif
    
} // namespace mango
