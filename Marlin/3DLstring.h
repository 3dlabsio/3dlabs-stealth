/**
 * ADVstring - String without dynamic allocation and a fixed maximum size
 *
 * Copyright (C) 2018 Sebastien Andrivet [https://github.com/andrivet/]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ADVSTRING_H
#define ADVSTRING_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "duration_t.h"

class __FlashStringHelper;
using FlashChar = __FlashStringHelper;

namespace _3dlabs {

// --------------------------------------------------------------------
// String without dynamic allocation and a fixed maximum size
// --------------------------------------------------------------------

enum class Base: uint8_t
{
    Decimal = 10,
    Hexadecimal = 16
};

enum class Alignment: uint8_t
{
    None, Left, Center, Right
};

enum class Duration: uint8_t
{
    full, digital, digitalWithDays
};

template<size_t L>
struct _3DLString
{
    _3DLString() = default;
    explicit _3DLString(const char* s);
    explicit _3DLString(const FlashChar* s);
    explicit _3DLString(char c);
    explicit _3DLString(duration_t d, Duration options = Duration::full);
    explicit _3DLString(int16_t n, Base b = Base::Decimal);
    explicit _3DLString(int32_t n, Base b = Base::Decimal);
    explicit _3DLString(uint16_t n, Base b = Base::Decimal);
    explicit _3DLString(uint32_t n, Base b = Base::Decimal);
    explicit _3DLString(double n, uint8_t decimals = 2);

    _3DLString& operator=(const char* str);
    _3DLString& operator=(const FlashChar* str);
    _3DLString& operator=(char c);
    template<size_t L2> _3DLString& operator=(const _3DLString<L2>& str);

    _3DLString& set(const char* s);
    _3DLString& set(const char* fmt, va_list& args);
    _3DLString& set(const FlashChar* s);
    _3DLString& set(const FlashChar* fmt, va_list& args);
    template<size_t L2> _3DLString& set(const _3DLString<L2>& s);
    template<size_t L2> _3DLString& set(const _3DLString<L2>& s, Alignment alignment);
    _3DLString& set(char c);
    _3DLString& set(duration_t d, Duration options = Duration::full);
    _3DLString& set(int16_t n, Base base = Base::Decimal);
    _3DLString& set(int32_t n, Base base = Base::Decimal);
    _3DLString& set(uint16_t n, Base base = Base::Decimal);
    _3DLString& set(uint32_t n, Base base = Base::Decimal);
    _3DLString& set(double n, uint8_t decimals = 2);
    _3DLString& reset();

    _3DLString& format(const char* fmt, ...);

    _3DLString& append(const char* s);
    _3DLString& append(const FlashChar* s);
    _3DLString& append(char c);
    _3DLString& append(int16_t n, Base base = Base::Decimal);
    _3DLString& append(int32_t n, Base base = Base::Decimal);
    _3DLString& append(uint16_t n, Base base = Base::Decimal);
    _3DLString& append(uint32_t n, Base base = Base::Decimal);
    _3DLString& append(double n, uint8_t decimals = 2);
    void operator+=(const char* s);
    void operator+=(const FlashChar* s);
    void operator+=(char c);

    _3DLString& align(Alignment alignment);

    size_t length() const;
    char operator[](size_t i) const;
    bool is_empty() const;
    const char* get() const;
    bool has_changed(bool reset = true);

private:
    char string_[L + 1] = {};
    bool dirty_ = true;
};

// --------------------------------------------------------------------

template<size_t L, typename T>
inline _3DLString<L>& operator<<(_3DLString<L>& rhs, T lhs) { rhs.append(lhs); return rhs; }

// --------------------------------------------------------------------

template<size_t L> inline _3DLString<L>::_3DLString(const char* s) { set(s); }
template<size_t L> inline _3DLString<L>::_3DLString(const FlashChar* s) { set(s); }
template<size_t L> inline _3DLString<L>::_3DLString(const char c) { set(c); }
template<size_t L> inline _3DLString<L>::_3DLString(duration_t d, Duration options) { set(d, options); }
template<size_t L> inline _3DLString<L>::_3DLString(int16_t n, Base b) { set(n, b); }
template<size_t L> inline _3DLString<L>::_3DLString(int32_t n, Base b) { set(n, b); }
template<size_t L> inline _3DLString<L>::_3DLString(uint16_t n, Base b) { set(n, b); }
template<size_t L> inline _3DLString<L>::_3DLString(uint32_t n, Base b) { set(n, b); }
template<size_t L> inline _3DLString<L>::_3DLString(double n, uint8_t decimals) { set(n, decimals); }

template<size_t L> inline _3DLString<L>& _3DLString<L>::operator=(const char* str)  { set(str); return *this; }
template<size_t L> inline _3DLString<L>& _3DLString<L>::operator=(const FlashChar* str)  { set(str); return *this; }
template<size_t L> inline _3DLString<L>& _3DLString<L>::operator=(const char c)  { set(c); return *this; }
template<size_t L> template<size_t L2> inline _3DLString<L>& _3DLString<L>::operator=(const _3DLString<L2>& str) { set(str); return *this; }

template<size_t L> template<size_t L2> _3DLString<L>& _3DLString<L>::set(const _3DLString<L2>& s, Alignment alignment)
{
    auto l = s.length();
    size_t pad = 0;

    if(l >= L)
        pad = 0;
    else if(alignment == Alignment::Center)
        pad = (L - l) / 2;
    else if(alignment == Alignment::Right)
        pad = L - l;

    // Left part
    size_t index = 0;
    for(; index < pad; ++index)
        string_[index] = ' ';

    // Middle part
    strlcpy(string_ + index, s.get(), L + 1 - pad);
    index += l;

    // Right part
    if(alignment == Alignment::Left || alignment == Alignment::Center)
    {
        for(; index < L; ++index)
            string_[index] = ' ';
    }

    // End of string
    string_[index] = 0;

    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::align(Alignment alignment)
{
    _3DLString<L> tmp{*this};
    return this->set(tmp, alignment);
}

template<size_t L>
inline _3DLString<L>& _3DLString<L>::set(const char* s)
{
    strlcpy(string_, s, L + 1);
    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(const char c)
{
    if(L < 1)
        return *this;
    string_[0] = c;
    string_[1] = 0;

    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(const char* fmt, va_list& args)
{
    vsnprintf(string_, L + 1, fmt, args);
    dirty_ = true;
    return *this;
}

#ifndef ADVi3PP_UNIT_TEST

template<size_t L>
inline _3DLString<L>& _3DLString<L>::set(const FlashChar* s)
{
    strlcpy_P(string_, reinterpret_cast<const char*>(s), L + 1);
    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(const FlashChar* fmt, va_list& args)
{
    vsnprintf_P(string_, L + 1, reinterpret_cast<const char*>(fmt), args);
    dirty_ = true;
    return *this;
}

#endif

template<size_t L> template<size_t L2>
inline _3DLString<L>& _3DLString<L>::set(const _3DLString<L2>& s)
{
    return set(s.get());
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(duration_t d, Duration options)
{
    char buffer[22]; // 21 + 1, from the doc
    switch(options)
    {
        case Duration::full:            d.toString(buffer); break;
        case Duration::digital:         d.toDigital(buffer); break;
        case Duration::digitalWithDays: d.toDigital(buffer, true); break;
    }

    return set(buffer);
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(int16_t n, Base base)
{
    char buffer[2 + 8 * sizeof(int16_t)];
    itoa(n, buffer, static_cast<int>(base));
    return set(buffer);
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(int32_t n, Base base)
{
    char buffer[2 + 8 * sizeof(int32_t)];
    ltoa(n, buffer, static_cast<int>(base));
    return set(buffer);
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(uint16_t n, Base base)
{
    char buffer[1 + 8 * sizeof(uint16_t)];
    utoa(n, buffer, static_cast<int>(base));
    return set(buffer);
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(uint32_t n, Base base)
{
    char buffer[1 + 8 * sizeof(uint16_t)];
    ultoa(n, buffer, static_cast<int>(base));
    return set(buffer);
}

template<size_t L>
_3DLString<L>& _3DLString<L>::set(double n, uint8_t decimals)
{
    char buffer[33];
    dtostrf(n, decimals + 2, decimals, buffer);
    return set(buffer);
}

template<size_t L>
inline _3DLString<L>& _3DLString<L>::reset() { string_[0] = 0; dirty_ = true; return *this; }

template<size_t L>
_3DLString<L>& _3DLString<L>::format(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    set(fmt, args);
    va_end(args);
    return *this;
}

template<size_t L> inline void _3DLString<L>::operator+=(const char* s) { append(s); }
template<size_t L> inline void _3DLString<L>::operator+=(const FlashChar* s) { append(s); }
template<size_t L> inline void _3DLString<L>::operator+=(char c) { append(c); }

template<size_t L>
_3DLString<L>& _3DLString<L>::append(const char* s)
{
    strlcat(string_, s, L + 1);
    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(char c)
{
    auto l = length();
    if(l >= L)
        return *this;

    string_[l] = c;
    string_[l + 1] = 0;
    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(const FlashChar* s)
{
    strlcat_P(string_, reinterpret_cast<const char*>(s), L + 1);
    dirty_ = true;
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(int16_t n, Base base)
{
    char buffer[2 + 8 * sizeof(int16_t)];
    itoa(n, buffer, static_cast<int>(base));
    append(buffer);
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(int32_t n, Base base)
{
    char buffer[2 + 8 * sizeof(int32_t)];
    ltoa(n, buffer, static_cast<int>(base));
    append(buffer);
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(uint16_t n, Base base)
{
    char buffer[1 + 8 * sizeof(uint16_t)];
    utoa(n, buffer, static_cast<int>(base));
    append(buffer);
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(uint32_t n, Base base)
{
    char buffer[1 + 8 * sizeof(uint16_t)];
    ultoa(n, buffer, static_cast<int>(base));
    append(buffer);
    return *this;
}

template<size_t L>
_3DLString<L>& _3DLString<L>::append(double n, uint8_t decimals)
{
    char buffer[33];
    dtostrf(n, decimals + 2, decimals, buffer);
    append(buffer);
    return *this;
}

template<size_t L> inline size_t _3DLString<L>::length() const { return strlen(string_); }
template<size_t L> inline char _3DLString<L>::operator[](size_t i) const { return string_[i]; }
template<size_t L> inline bool _3DLString<L>::is_empty() const { return string_[0] == 0; }
template<size_t L> inline const char* _3DLString<L>::get() const { return string_; }

template<size_t L> bool _3DLString<L>::has_changed(bool reset)
{
    auto dirty = dirty_;
    if(reset)
        dirty_ = false;
    return dirty;
}

// --------------------------------------------------------------------

}

#endif // ADVSTRING_H
