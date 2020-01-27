#include <iostream>
#include <cmath>
using namespace std;

int msgSizeCalc(int size)
{
    int msg_size = 0;
    while (pow(2, msg_size) < size + msg_size + 1)
    {
        msg_size++;
    }
    return msg_size;
}

int checkposition(int a)
{
    int i = 0;
    while (pow(2, i) < a)
    {
        i++;
    }
    if (pow(2, i) == a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int calcValue(int *m, int msg_size, int i)
{
    int count = 0;
    int index = pow(2, i);
    int continuous_index = pow(2, i);
    int increment_index = pow(2, i);
    int j = index, k;
    while (j < msg_size)
    {
        k = j;
        while (k < msg_size && k - j != continuous_index)
        {
            if (m[k] == 1)
            {
                count++;
            }
            k++;
        }
        j = k + increment_index;
    }
    if (count % 2 == 0)
        return 0;
    else 
        return 1;
}

int main()
    {
        int *m, size, msg;
        cout << "Enter the size of message: ";
        cin >> size;
        int msg_size = msgSizeCalc(size);
        //cout << "The value of p is: " << msg_size << endl;
        msg_size = size + msg_size;
        cout << "Enter the message: ";
        cin >> msg;
        m = (int *)malloc(msg_size * sizeof(int));
        for (int i = msg_size - 1; i >= 0; i--)
        {
            if (checkposition(i + 1))
            {
                m[i] = 2;
                //cout << "2 placed at position " << i << endl;
            }
            else
            {
                m[i] = msg % 10;
                //cout << msg%10 << " placed at position " << i << endl;
                msg = msg / 10;
            }
        }
        /*
     cout << "The message is: ";
     for(int i = 0; i < msg_size; i ++){
     cout << m[i];
     }cout << endl;
   */
        for (int i = 0; i < msg_size; i++)
        {
            if (m[i] == 2)
            {
                m[i] = calcValue(m, msg_size, i);
            }
        }
        cout << "The message is: ";
        for (int i = 0; i < msg_size; i++)
        {
            cout << m[i];
        }
        cout << endl;
        return 0;
    }
