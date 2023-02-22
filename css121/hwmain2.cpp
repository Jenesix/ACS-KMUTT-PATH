#include <iostream>

using namespace std;

class Term {
public:
    int coeff;
    int exp;
    Term* next;
    Term(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial {
private:
    Term* head;
public:
    Polynomial() {
        head = NULL;
    }

    // Insert a new term into the polynomial in descending order of exponents.
    void insertTerm(Term* newTerm) {
        if (head == NULL || newTerm->exp > head->exp) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next != NULL && newTerm->exp < current->next->exp) {
                current = current->next;
            }
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }

    // Find and return the term with the given exponent, or NULL if not found.
    Term* findTerm(int exp) {
        Term* current = head;
        while (current != NULL) {
            if (current->exp == exp) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    // Add another polynomial to this polynomial.
    Polynomial add(Polynomial p2) {
        Polynomial result;
        Term* term1 = head;
        Term* term2 = p2.head;
        while (term1 != NULL && term2 != NULL) {
            if (term1->exp == term2->exp) {
                int newCoeff = term1->coeff + term2->coeff;
                if (newCoeff != 0) {
                    Term* newTerm = new Term(newCoeff, term1->exp);
                    result.insertTerm(newTerm);
                }
                term1 = term1->next;
                term2 = term2->next;
            } else if (term1->exp > term2->exp) {
                result.insertTerm(new Term(term1->coeff, term1->exp));
                term1 = term1->next;
            } else {
                result.insertTerm(new Term(term2->coeff, term2->exp));
                term2 = term2->next;
            }
        }
        while (term1 != NULL) {
            result.insertTerm(new Term(term1->coeff, term1->exp));
            term1 = term1->next;
        }
        while (term2 != NULL) {
            result.insertTerm(new Term(term2->coeff, term2->exp));
            term2 = term2->next;
        }
        return result;
    }

    // Multiply this polynomial by another polynomial.
    Polynomial multiply(Polynomial p2) {
        Polynomial result;
        Term* term1 = head;
        while (term1 != NULL) {
            Term* term2 = p2.head;
            while (term2 != NULL) {
                int newCoeff = term1->coeff * term2->coeff;
                int newExp = term1->exp + term2->exp;
                Term* existingTerm = result.findTerm(newExp);
                if (existingTerm != NULL) {
                    existingTerm->coeff += newCoeff;
                } else {
                    Term* newTerm = new Term(newCoeff, newExp);
                    result.insertTerm(newTerm);
                }
                term2 = term2->next;
            }
            term1 = term1->next;
        }
        return result;
    }

    // Print the polynomial in a human-readable format.
    void print() {
        Term* current = head;
        while (current != NULL) {
            cout << current->coeff << "x^" << current->exp << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main () {
    Polynomial p1;
    p1.insertTerm(new Term(3, 4));
    p1.insertTerm(new Term(2, 3));
    p1.insertTerm(new Term(1, 2));
    p1.insertTerm(new Term(5, 1));
    p1.insertTerm(new Term(6, 0));
    p1.print();

    Polynomial p2;
    p2.insertTerm(new Term(2, 3));
    p2.insertTerm(new Term(1, 2));
    p2.insertTerm(new Term(3, 1));
    p2.insertTerm(new Term(4, 0));
    p2.print();

    Polynomial p3 = p1.add(p2);
    p3.print();

    Polynomial p4 = p1.multiply(p2);
    p4.print();

    return 0;
}