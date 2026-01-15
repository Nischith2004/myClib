typedef unsigned int size_t;
typedef int ssize_t;
ssize_t write(int fd, const void *buf, size_t count);

size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
void print_str(const char *s){
    write(1, s, strlen(s));
}

void print_int(int x){
    char buf[16];
    int i = 0;
    if(x==0){
        char c = '0';
        write(1, &c, 1);
        return;
    }
    while(x>0){
        buf[i++] = '0' + (x % 10);
        x /= 10;
    }
    while(i>0){
        i--;
        write(1, &buf[i], 1);
}
}

int main(int argc, char **argv) {
    const char message[] = "Hello, World!\n";
    write(1, message, sizeof(message)-1);
    print_str("Argc=");
    print_int(argc);
    print_str("\n");
    for(int i=0;i<argc;i++){
        print_str("argv[");
        print_int(i);
        print_str("]=");
        print_str(argv[i]);
        print_str("\n");
    }
    return argc;
}

//this is dummy main func to satisfy linker and avoid errs
void __main() { }