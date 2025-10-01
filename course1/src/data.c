#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t * start = ptr;
    uint8_t temp[33]; // Enough for 32-bit binary + null terminator
    uint8_t * temp_ptr = temp;
    uint8_t length = 0;
    int is_negative = 0;

    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return 2; // '0' + null terminator
    }

    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data;
    }

    // Convert number to string in reverse
    while (data != 0) {
        int32_t remainder = data % base;
        data /= base;
        *temp_ptr++ = (remainder < 10) ? ('0' + remainder) : ('A' + remainder - 10);
        length++;
    }

    if (is_negative) {
        *temp_ptr++ = '-';
        length++;
    }

    // Reverse the string into ptr
    while (length > 0) {
        ptr[0] = *(--temp_ptr);
        ptr++;
        length--;
    }

    *ptr = '\0'; // Null terminator

    return (uint8_t)(ptr - start + 1); // Including null terminator
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int is_negative = 0;

    if (*ptr == '-') {
        is_negative = 1;
        ptr++;
        digits--;
    }

    while (digits > 0) {
        uint8_t ch = *ptr++;
        int32_t value;

        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        } else {
            break; // Invalid character
        }

        result = result * base + value;
        digits--;
    }

    return is_negative ? -result : result;
}