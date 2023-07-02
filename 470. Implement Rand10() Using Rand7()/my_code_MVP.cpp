    int rand10() {
        return 1 + (rand7() + rand7()+ rand7()+ rand7() + rand7())%10; // если сумм rand7() будет меньше -- будет ошибка!
    }
