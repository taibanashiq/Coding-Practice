#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int coeff, int exp) {
 struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert in sorted order (descending exponent)
struct Node* insert(struct Node* head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);

    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }

    if (temp->exp == exp) {
        temp->coeff += coeff;
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Addition
struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Subtraction
struct Node* subtract(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = insert(result, -p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            result = insert(result, p1->coeff - p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        result = insert(result, -p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Multiplication
struct Node* multiply(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    for (struct Node* i = p1; i != NULL; i = i->next) {
        for (struct Node* j = p2; j != NULL; j = j->next) {
            int coeff = i->coeff * j->coeff;
            int exp = i->exp + j->exp;
            result = insert(result, coeff, exp);
        }
    }

    return result;
}

// Create polynomial
struct Node* createPolynomial() {
    struct Node* head = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    return head;
}

// Main function
int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;

    printf("Create First Polynomial:\n");
    p1 = createPolynomial();

    printf("Create Second Polynomial:\n");
    p2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    printf("\nChoose Operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = add(p1, p2);
            printf("Result (Addition): ");
            display(result);
            break;

        case 2:
            result = subtract(p1, p2);
            printf("Result (Subtraction): ");
            display(result);
            break;

        case 3:
            result = multiply(p1, p2);
            printf("Result (Multiplication): ");
            display(result);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}










