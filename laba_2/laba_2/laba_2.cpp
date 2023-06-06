#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class QueueRing
{
private:
    vector<int> queue;
public:
    QueueRing()
    {
        try
        {
            queue = { };
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
        }
    }
    void Clear()
    {
        queue = 0;
    }
    bool isEmpty()
    {
        return queue.size() == 0;
    }
    int Size() {
        return queue.size();
    }
    void Push(int item)
    {
        queue.push_back(item);
    }
    int Pop()
    {
        if (isEmpty()) {
            cout << "Queue  is empty.\n";
            system("pause");
            return 0;
        }
        else {
            int item;
            item = queue[0];

            try {
                for (int i = 0; i < queue.size() - 1; i++) {
                    queue[i] = queue[i + 1];
                }

                return item;
            }
            catch (bad_alloc e)
            {
                cout << e.what() << endl;
                return 0;
            }
        }
    }
    bool Roll()
    {
        if (!isEmpty())
        {
            T item = queue[0];

            for (int i = 1; i < queue.size(); i++)
                queue[i - 1] = queue[i];

            queue[queue.size() - 1] = item;
            return true;
        }
        else
            return false;
    }
    void Print(string msg)
    {
        cout << msg + " ";
        for (int i = 0; i < queue.size(); i++)
            cout << queue[i] << " ";
        cout << endl;
    }
    void Sort()
    {
        if (!isEmpty()) {
            for (int i = 0; i < queue.size() - 1; i++) {
                for (int j = 0; j < queue.size() - i - 1; j++) {
                    if (queue[j] > queue[j + 1]) {
                        std::swap(queue[j], queue[j + 1]);
                    }
                }
            }
        }
        else {
            cout << "Queue is empty.\n";
            return;
        }
    }
};


void textMenu();

int main()
{
    setlocale(LC_ALL, "RU");
    QueueRing<int> q1, q2;
    int choice;

    do
    {
        textMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int tempChoice;
            do
            {
                system("cls");
                cout << "1. Добавить элемент;\n";
                cout << "0. Вернуться в меню;\n";
                cout << "-----------------------------\n";
                cout << "Ваш выбор: ";
                cin >> tempChoice;

                if (tempChoice != 0) {
                    int tempData;
                    cout << "-----------------------------\n";
                    cout << "Введите данные (int): ";
                    cin >> tempData;
                    q1.Push(tempData);
                }
            } while (tempChoice != 0);
            break;
        }
        case 2:
        {
            system("cls");

            if (q1.isEmpty()) {
                cout << "В очереди нет элементов.\n";
            }
            else {
                int tempData = q1.Pop();
                cout << "Элемент \"" << tempData << "\" удален.\n";
            }

            system("pause");
            break;
        }
        case 3:
        {
            system("cls");

            if (q1.isEmpty()) {
                cout << "В очереди нет элементов.\n";
            }
            else {
                q1.Print("Очередь No1:");
            }

            system("pause");
            break;
        }
        case 4:
        {
            system("cls");

            if (q1.isEmpty()) {
                cout << "В очереди нет элементов.\n";
            }
            else {
                q1.Sort();
                cout << "Очередь отсортирована.\n";
            }

            system("pause");
            break;
        }
        case 5:
        {
            int tempChoice;
            do
            {
                system("cls");
                cout << "1. Добавить элемент;\n";
                cout << "0. Вернуться в меню;\n";
                cout << "-----------------------------\n";
                cout << "Ваш выбор: ";
                cin >> tempChoice;

                if (tempChoice != 0) {
                    int tempData;
                    cout << "-----------------------------\n";
                    cout << "Введите данные (int): ";
                    cin >> tempData;
                    q2.Push(tempData);
                }
            } while (tempChoice != 0);
            break;
        }
        case 6:
        {
            system("cls");

            if (q2.isEmpty()) {
                cout << "В очереди нет элементов.\n";
            }
            else {
                int tempData = q2.Pop();
                cout << "Элемент \"" << tempData << "\" удален.\n";
            }

            system("pause");
            break;
        }
        case 7:
        {
            system("cls");

            if (q2.isEmpty()) {
                cout << "В очереди нет элементов.\n";
            }
            else {
                q2.Print("Очередь No2:");
            }

            system("pause");
            break;
        }
        case 8:
        {
            system("cls");

            if (q2.isEmpty()) {
                cout << "В очереди нет элементов.\n";
            }
            else {
                q2.Sort();
                cout << "Очередь отсортирована.\n";
            }

            system("pause");
            break;
        }
        case 9:
        {
            system("cls");

            if (!q1.isEmpty() && !q2.isEmpty()) {
                QueueRing<int> q_result, q1_t = q1, q2_t = q2;
                int tempData1, tempData2;

                q1.Sort();
                q2.Sort();

                for (int i = 0; i < q1_t.Size(); i++)
                {
                    int counter = 0;
                    QueueRing<int> q2_temp = q2;

                    tempData1 = q1_t.Pop();
                    for (int i = 0; i < q2_temp.Size(); i++)
                    {
                        tempData2 = q2_temp.Pop();
                        if (tempData1 == tempData2) counter++;
                    }
                    if (counter == 0) q_result.Push(tempData1);
                    counter = 0;
                }

                for (int i = 0; i < q2_t.Size(); i++)
                {
                    int counter = 0;
                    QueueRing<int> q1_temp = q1;

                    tempData1 = q2_t.Pop();
                    for (int i = 0; i < q1_temp.Size(); i++)
                    {
                        tempData2 = q1_temp.Pop();
                        if (tempData1 == tempData2) counter++;
                    }
                    if (counter == 0) q_result.Push(tempData1);
                    counter = 0;
                }

                system("cls");

                if (q_result.isEmpty()) {
                    cout << "Не юыло найдено уникальных элементов в очередях No1 и No2.\n";
                }
                else {
                    q1.Print("Очередь No1:");
                    q2.Print("Очередь No2:");
                    cout << "-----------------------------------\n";
                    q_result.Print("Очередь без повторяющихся элеменов в 2х очередях:");
                }

            }
            else if (q1.isEmpty() && !q2.isEmpty()) cout << "Очередь No1 не имеет данных. Сначала запоните очередь No1.\n";
            else if (q2.isEmpty() && !q1.isEmpty()) cout << "Очередь No2 не имеет данных. Сначала запоните очередь No2.\n";
            else  cout << "Очередь No1 и No2 не имеют данных. Сначала запоните очередь No1 и No2.\n";

            system("pause");


            break;
        }
        default:
            if (choice != 0) {
                cout << "\nТакого пункта в меню не найдено, повторите попытку.\n";
                system("pause");
            }
            break;
        }

    } while (choice != 0);


    return 0;
}

void textMenu() {
    system("cls");
    cout << "-----------------------------\n";
    cout << "ОЧЕРЕДЬ No1:\n";
    cout << "1. Добавить элементы;\n";
    cout << "2. Удалить верхний элемент;\n";
    cout << "3. Распечатать очередь;\n";
    cout << "4. Отсортироват очередь;\n";
    cout << "-----------------------------\n";
    cout << "ОЧЕРЕДЬ No2:\n";
    cout << "5. Добавить элементы;\n";
    cout << "6. Удалить верхний элемент;\n";
    cout << "7. Распечатать очередь;\n";
    cout << "8. Отсортироват очередь;\n";
    cout << "-----------------------------\n";
    cout << "9. Выполнить упражнение;\n";
    cout << "0. Выход.\n";
    cout << "\nВаш выбор: ";
}