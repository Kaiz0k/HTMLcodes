void add_lists() {
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int num1 = 0, num2 = 0;

        if (l1 != NULL) {
            num1 = l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            num2 = l2->data;
            l2 = l2->next;
        }

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        insert_begin(&l3, sum % 10);
    }
}