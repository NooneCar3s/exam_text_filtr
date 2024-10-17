#pragma once

#include "Header.h"

#include <iostream>

using namespace std;

#include <string>
#include <cctype>

void filterText(string& text, const char* filterChars) {
    for (char& ch : text) {
        for (int i = 0; filterChars[i] != '\0'; ++i) {
            if (ch == filterChars[i]) {
                ch = ' ';
                break;
            }
        }
    }
}