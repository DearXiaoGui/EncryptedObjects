#pragma once
#include <cstdint>

#define _key1 0x2F7D8AE8FDF13CED
#define _key2 0x5669F32AF4ABC3AE
#define _key3 0x0E939877C426795B
#define _key4 0x2C553A004B41FF58
#define _key5 0x6DBBC48D1CFCAD51
#define _key6 0x58566BEC79001692
#define _key7 0xB63CDD8A3CBC3A4F
#define _key8 0x4478D118DC981EEC

/*Key为随机生成*/


namespace Xor
{
    template<typename T>
    inline T Encrypt(T value) {
        uintptr_t uintptr_value = reinterpret_cast<uintptr_t>(value);
        uint64_t a = (uintptr_value ^ _key1) ^ ((uintptr_value ^ _key1) << 0x20) ^ _key2;
        uint32_t b = a & 0xFFFFFFFF;
        uint32_t c = (a >> 0x20) & 0xFFFFFFFF;
        b = (b ^ _key3) ^ ((_key4 << 0x10) | (_key5 >> 0x10));
        c = (c ^ _key6) ^ ((_key7 << 0x10) | (_key8 >> 0x10));
        uintptr_t encrypted_value = ((uintptr_t)c << 0x20) | b;
        return reinterpret_cast<T>(encrypted_value);
    }

    template<typename T>
    inline T Decrypt(T value) {
        uintptr_t uintptr_value = reinterpret_cast<uintptr_t>(value);
        uint32_t b = uintptr_value & 0xFFFFFFFF;
        uint32_t c = (uintptr_value >> 0x20) & 0xFFFFFFFF;
        c = (c ^ ((_key7 << 0x10) | (_key8 >> 0x10))) ^ _key6;
        b = (b ^ ((_key4 << 0x10) | (_key5 >> 0x10))) ^ _key3;
        uint64_t a = ((uint64_t)c << 0x20) | b;
        a = (a ^ _key2) ^ ((a ^ _key2) << 0x20) ^ _key1;
        uintptr_t decrypted_value = a & 0xFFFFFFFFFFFFFFFF;
        return reinterpret_cast<T>(decrypted_value);
    }
}