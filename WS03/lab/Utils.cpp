
#include <iostream>
#include "Utils.h"

namespace sdds {

    int strlen(const char* str) {
        int len{};
        while (str[len]) {
            len++;
        }
        return len;
    }

    char* strcpy(char* des, const char* src) { //(m_itemName, name
        int i;
        for (i = 0; src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0;
        return des;
    }

    char* strncpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; i < len; i++) {
            des[i] = src[i];
        }
        if (strlen(src) == len) {
            des[i] = '\0';
        }
       return des;
    }

}