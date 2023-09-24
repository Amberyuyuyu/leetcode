int distMoney(int money, int children) {
    if (money < children) {
        return -1;
    }
    else if (8 * children < money) {
        return children - 1;
    }
    else if (money - 8 * (children - 1) == 4) {
        return children - 2;
    }
    else {
        return (money - children) / 7;
    }

}