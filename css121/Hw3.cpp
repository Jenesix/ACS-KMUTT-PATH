#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
struct Node {
    string name;
    int score;
    Node* prev;
    Node* next;
};

class Scoreboard {
private:
    int size;
    Node* head;
    Node* tail;

public:
    Scoreboard(int size) : size(size), head(nullptr), tail(nullptr) {}

    void addScore(string name, int score) {
        if (head == nullptr) {
            head = new Node{name, score, nullptr, nullptr};
            tail = head;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->score >= score) {
                current = current->next;
            }
            if (current->prev == nullptr) {
                head = new Node{name, score, nullptr, head};
                head->next->prev = head;
            } else if (current->next == nullptr) {
                tail = new Node{name, score, tail, nullptr};
                tail->prev->next = tail;
            } else {
                Node* newNode = new Node{name, score, current->prev, current};
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }

        if (getLength() > size) {
            printremoveScore(tail->name, tail->score);
        }
    }
    void printAddScore(string name, int score) {
        cout <<  name << " got new score = " << score << endl << endl;
        addScore(name, score);
        printScores();
    }

    void removeScore(string name, int score) {
    Node* current = head;
    while (current != nullptr && (current->name != name || current->score != score)) {
        current = current->next;
    }
    if (current == nullptr) {
        cerr << "Score not found\n";
        return;
    }
    if (current->prev == nullptr) {
        head = current->next;
        head->prev = nullptr;
    } else if (current->next == nullptr) {
        tail = current->prev;
        tail->next = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
}
void printremoveScore(string name, int score) {
    cout <<  name << " was remove from the score board" <<  endl << endl;
    removeScore(name, score);
}


    
    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    void sort(bool ascending) {
    Node *current = head, *temp = nullptr;
    int swap = 0;

        if (ascending) {
            for (current = head; current->next != nullptr; current = current->next) {
                for (temp = current->next; temp != nullptr; temp = temp->next) {
                    if (current->score > temp->score) {
                        swap = current->score;
                        current->score = temp->score;
                        temp->score = swap;

                        string name = current->name;
                        current->name = temp->name;
                        temp->name = name;
                    }
                }
            }
        } else {
            for (current = head; current->next != nullptr; current = current->next) {
                for (temp = current->next; temp != nullptr; temp = temp->next) {
                    if (current->score < temp->score) {
                        swap = current->score;
                        current->score = temp->score;
                        temp->score = swap;

                        string name = current->name;
                        current->name = temp->name;
                        temp->name = name;
                    }
                }
            }
        }
    }


    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* current = node;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        return prev;
    }

    void printScores() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " " << current->score << "\n";
            current = current->next;
        }
    }
};

int main() {
    Scoreboard scoreboard(5);

    scoreboard.addScore("Jenesix", 99);
    scoreboard.addScore("TLN Foxz", 75);
    scoreboard.addScore("SEN Tenz", 69);
    scoreboard.addScore("C9 yay", 45);
    scoreboard.addScore("MITH PTC", 50);

    scoreboard.sort(false);
    scoreboard.printScores();
    
    cout << endl;

    scoreboard.printAddScore("PRX f0rsakeN", 80);
    

    return 0;
}
