.intel_syntax noprefix
.global _start
.extern main          
#this is for 32 bit processor
_start:
    xor ebp, ebp
    mov eax, esp
    mov ecx, [eax]      # argc
    lea edx, [eax + 4]  # argv

    push edx
    push ecx
    call main          

    # Exit syscall (Linux x86)
    mov ebx, eax        # Use return value from main as exit code
    mov eax, 1          # sys_exit
    int 0x80