typedef unsigned int size_t;/*aliasing as there doesnt exist size_t and etc as primitive datatype  */
typedef int ssize_t;
ssize_t write(int fd, const void *buf, size_t count){
    ssize_t ret;
    //this is inline assembly code
    //the typical sysntax looks like asm("asm code":"output op":"input op":"clobber");
    asm volatile (
        "int $0x80\n"//usd for system call
        //interrupt 0x80 helps to jump to system callwhich happens in kernel mode 
        /*typical system call uses eax register
         to get the system call no. which represents a prticularsys call
         and ebx,ecx,edx for arguments in sequence*/
         /*here a represnts eax
         b for ebc,c for ecx, d for edx*/
        : "=a" (ret)
        : "a"(4),
            "b"(fd),
            "c"(buf),
            "d"(count)
        : "memory"/* clobber which says compiler that dont 
        mess with registers while i'm executing assembly */
    );
    return ret;
}