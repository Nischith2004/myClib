typedef unsigned int size_t;/*aliasing as there doesnt exist size_t and etc as primitive datatype  */
typedef int ssize_t;
/*Same as in write*/
ssize_t write(int fd, void *buf, size_t count){

     ssize_t ret;

    asm volatile (
        "int $0x80"
        : "=a"(ret)           
        : "a"(3),             // SYS_read = 4
          "b"(fd),            
          "c"(buf),           
          "d"(count)          
        : "memory"
    );

    return ret;
}
