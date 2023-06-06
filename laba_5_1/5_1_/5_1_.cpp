#include <iostream>
#include <vector>

const int HASH_TABLE_SIZE = 15;
const int MIN_RANGE = 27000;
const int MAX_RANGE = 58000;

int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n=12;
 
    std::vector<int> arr(n);
    std::cout << "Готовый массив: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%(MAX_RANGE- MIN_RANGE)+ MIN_RANGE;
        std::cout << arr[i]<<" ";
    }
    std::cout << std::endl;

    std::vector<int> hashTable(HASH_TABLE_SIZE, -1);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= MIN_RANGE && arr[i] <= MAX_RANGE) {
            int index = hashFunction(arr[i]);
            while (hashTable[index] != -1) {
                index = (index + 1) % HASH_TABLE_SIZE;
            }
            hashTable[index] = arr[i];
        }
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Хеш-таблица: ";
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        std::cout << hashTable[i] << ' ';
    }
    std::cout << '\n';

    int searchKey;
    std::cout << "Введите ключ для поиска: ";
    std::cin >> searchKey;

    int index = hashFunction(searchKey);
    while (hashTable[index] != searchKey && hashTable[index] != -1) {
        index = (index + 1) % HASH_TABLE_SIZE;
    }

    if (hashTable[index] == searchKey) {
        std::cout << "Элемент найден в хеш-таблице\n";
    }
    else {
        std::cout << "Элемент не найден в хеш-таблице\n";
    }

    return 0;
}