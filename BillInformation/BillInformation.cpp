#include <iostream>

struct Bill {
    int billId;
    char clientName[50];
    char productName[50];
    float price;
    int amount;
};

void inputBillInfo(struct Bill* bill) {
    printf("Enter bill ID: ");
    scanf_s("%d", &bill->billId);
    printf("Enter client name: ");
    scanf_s(" %[^\n]", bill->clientName, (unsigned int)sizeof(bill->clientName));
    printf("Enter product name: ");
    scanf_s(" %[^\n]", bill->productName, (unsigned int)sizeof(bill->productName));
    printf("Enter price: ");
    scanf_s("%f", &bill->price);
    printf("Enter amount: ");
    scanf_s("%d", &bill->amount);
}

float calculateTotalPrice(struct Bill* bill) {
    return bill->price * bill->amount;
}

float calculateDiscount(struct Bill* bill) {
    float discount = 0;
    if (bill->amount > 50)
        discount = 0.1f;
    else if (_stricmp(bill->productName, "mitsumi mouse") == 0)
        discount = 0.05f;
    return discount * calculateTotalPrice(bill);
}

void outputBillInfo(struct Bill* bill) {
    float totalPrice = calculateTotalPrice(bill);
    float discount = calculateDiscount(bill);
    printf("Bill ID: %d\n", bill->billId);
    printf("Client Name: %s\n", bill->clientName);
    printf("Total Price: %.2f\n", totalPrice);
    printf("Discount: %.2f\n", discount);
}

int main() {
    struct Bill bill;
    inputBillInfo(&bill);
    outputBillInfo(&bill);
    return 0;
}
