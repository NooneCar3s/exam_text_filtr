#include <iostream>
#include "Header.h"
#include <Windows.h>

using namespace std;

#include <string>
#include <cctype>


int main() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    string inputText;

    // Определение наборов символов как строки
    const char latinAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const char cyrillicAlphabet[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const char digits[] = "0123456789";
    const char punctuation[] = ".,!?;:'\"/()[]{}<>-";

    // Ввод текста
    cout << "Введите текст: ";
    getline(cin, inputText);

    bool filterLatin = false, filterCyrillic = false, filterDigits = false, filterPunctuation = false;

    system("color 5f");

    while (true) {
        cout << "\nВыберите фильтры (введите номер, чтобы переключить):\n";
        cout << "1. Латинские буквы (текущий: " << (filterLatin ? "включен" : "выключен") << ")\n";
        cout << "2. Кириллица (текущий: " << (filterCyrillic ? "включен" : "выключен") << ")\n";
        cout << "3. Цифры (текущий: " << (filterDigits ? "включен" : "выключен") << ")\n";
        cout << "4. Пунктуация (текущий: " << (filterPunctuation ? "включен" : "выключен") << ")\n";
        cout << "5. Применить фильтры и показать результат\n";
        cout << "6. Выход\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: filterLatin = !filterLatin; break;
        case 2: filterCyrillic = !filterCyrillic; break;
        case 3: filterDigits = !filterDigits; break;
        case 4: filterPunctuation = !filterPunctuation; break;
        case 5:
            // Применение фильтров
            if (filterLatin) filterText(inputText, latinAlphabet);
            if (filterCyrillic) filterText(inputText, cyrillicAlphabet);
            if (filterDigits) filterText(inputText, digits);
            if (filterPunctuation) filterText(inputText, punctuation);

            cout << "Результат: " << inputText << endl;
            break;
        case 6: return 0;
        default: cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}

