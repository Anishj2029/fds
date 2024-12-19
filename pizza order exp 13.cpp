#include <iostream>
#include <string>
using namespace std;

#define size 5
string outlet[size];

class pizza {
private:
    int front, rear;

public:
    pizza() {
        front = -1;
        rear = -1;
    }

    void addorder(string order) {
        if ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) {
            cout << "The order queue is full!" << endl;
            return;
        }

        if (front == -1) { 
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) { 
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        outlet[rear] = order;
        cout << "Order added: " << outlet[rear] << endl;
    }

    void deleteorder() {
        if (front == -1) {
            cout << "There is no order to delete!" << endl;
            return;
        }

        cout << "Deleted order: " << outlet[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) { 
            front = 0;
        } else {
            front++;
        }
    }

    void displayorder() {
        if (front == -1) {
            cout << "There are no orders remaining!" << endl;
            return;
        }

        cout << "Orders in the queue:" << endl;

        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << outlet[i] << endl;
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << outlet[i] << endl;
            }
            for (int i = 0; i <= rear; i++) {
                cout << outlet[i] << endl;
            }
        }
    }
};

int main() {
    pizza p;
    int ch;
    string order;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Order pizza" << endl;
        cout << "2. Delete order" << endl;
        cout << "3. Display orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter your order (pizza): ";
            cin >> order;
            p.addorder(order);
            break;

        case 2:
            p.deleteorder();
            break;

        case 3:
            p.displayorder();
            break;

        case 4:
            cout << "THANK YOU FOR COMING!!!" << endl;
            break;

        default:
            cout << "Please enter a valid choice!" << endl;
        }
    } while (ch != 4);

    return 0;
}
