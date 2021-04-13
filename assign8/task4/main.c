char password[8] = "secret";
int main() {
    char input[8];
    printf("please enter your password\n");
    scanf("%s", input);

    if(strcmp(input, password)==0) {
        return 0;
    } else {
        return -1;
    }

}
