#include <iostream>
#include <string>
using namespace std;


struct Data {
    string surname;
    int points;
    string place;
};


class HashTable {
private:
    int size;
    Data* table;
public:
    HashTable(int s) {
        size = s;
        table = new Data[size];
        for (int i = 0; i < size; i++) {
            table[i].surname = "empty";
            table[i].points = -1;
            table[i].place = "empty";
        }
    }

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 1 + (key % (size - 1));
    }

    void insert(int key, Data data) {
        int index = hash1(key);
        int step = hash2(key);
        while (table[index].surname != "empty") {
            index += step;
            index %= size;
        }
        table[index] = data;
    }

    void print() {

        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].surname == "empty") {
                cout << "empty" << endl;
            }
            else {
                cout << table[i].surname << ", " << table[i].points << ", " << table[i].place << endl;
            }
        }
    }

    Data search(int key) {

        int index = hash1(key);
        int step = hash2(key);
        while (table[index].surname != "empty") {
            if (table[index].points == key) {
                return table[index];
            }
            index += step;
            index %= size;
        }
        Data empty;
        empty.surname = "not found";
        return empty;
    }
};


void maxValue(Data* array, int size) {
    int maxIndex;
    Data temp;
    for (int i = 0; i < size - 1; i++) {
        maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j].points > array[maxIndex].points) {
                maxIndex = j;
            }
        }
        temp = array[i];
        array[i] = array[maxIndex];
        array[maxIndex] = temp;
    }
}


int main() {
    setlocale(LC_ALL, "Ru");
    Data dataArray[7];
    for (int i = 0; i < 7; i++) {
        cout << "Введите информацию " << i << endl;
        cout << "Фамилия: ";
        cin >> dataArray[i].surname;
        cout << "количество очков: ";
        cin >> dataArray[i].points;
        cout << "место: ";
        cin >> dataArray[i].place;
    }

    maxValue(dataArray, 7);


    HashTable hashTable(15);
    for (int i = 0; i < 7; i++) {
        hashTable.insert(dataArray[i].points, dataArray[i]);
    }

    cout << "оригинальная таблица:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << dataArray[i].surname << ", " << dataArray[i].points << ", " << dataArray[i].place << endl;
    }
    cout << endl;
    cout << "хеш-таблица:" << endl;
    hashTable.print();
    cout << endl;


    int key;
    cout << "ключ: ";
    cin >> key;

    Data result = hashTable.search(key);
    cout << "результат поиска: " << result.surname << ", " << result.points << ", " << result.place << endl;

    return 0;
}