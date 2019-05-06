# Task List

## Combine the 2 Tasks

## P-Chip (Accelarator Chip) Project
- SIMD operations on BNN
- Low Bit Usages bit by bit Implementation
- Performance Gain of Extensions of Bitwise SIMD operations & Int Operations

## Encryption
- Make a plan
- Homomorphic encryption
- Implementating on Homomorphic encryption Library

## Preliminary Evaluation
- Codes on RasPi
- Extend Code to use wider INT types and test performacne

```
yuxuan$ ./a.out
Time taken: 8.81s
Time taken: 5.97s
```

- Bit by Bit, Int by Int & SIMD

```
popcnt8(unsigned char):
        push    rbp
        mov     rbp, rsp
        mov     eax, edi
        mov     BYTE PTR [rbp-20], al
        movzx   eax, BYTE PTR [rbp-20]
        sar     eax
        and     eax, 85
        mov     edx, eax
        movzx   eax, BYTE PTR [rbp-20]
        sub     eax, edx
        mov     BYTE PTR [rbp-1], al
        movzx   eax, BYTE PTR [rbp-1]
        sar     eax, 2
        and     eax, 51
        mov     edx, eax
        movzx   eax, BYTE PTR [rbp-1]
        and     eax, 51
        add     eax, edx
        mov     BYTE PTR [rbp-1], al
        movzx   eax, BYTE PTR [rbp-1]
        sar     eax, 4
        mov     edx, eax
        movzx   eax, BYTE PTR [rbp-1]
        add     eax, edx
        and     eax, 15
        pop     rbp
        ret
bdot(unsigned char const*, unsigned char const*, int):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 40
        mov     QWORD PTR [rbp-24], rdi
        mov     QWORD PTR [rbp-32], rsi
        mov     DWORD PTR [rbp-36], edx
        cvtsi2sd        xmm0, DWORD PTR [rbp-36]
        movsd   xmm1, QWORD PTR .LC0[rip]
        divsd   xmm0, xmm1
        cvtsi2sd        xmm1, DWORD PTR [rbp-36]
        movsd   xmm2, QWORD PTR .LC0[rip]
        divsd   xmm1, xmm2
        cvttsd2si       eax, xmm1
        cvtsi2sd        xmm1, eax
        subsd   xmm0, xmm1
        pxor    xmm1, xmm1
        comisd  xmm0, xmm1
        jbe     .L11
        cvtsi2sd        xmm0, DWORD PTR [rbp-36]
        movsd   xmm1, QWORD PTR .LC0[rip]
        divsd   xmm0, xmm1
        movapd  xmm1, xmm0
        movsd   xmm0, QWORD PTR .LC2[rip]
        addsd   xmm0, xmm1
        cvttsd2si       eax, xmm0
        jmp     .L6
.L11:
        cvtsi2sd        xmm0, DWORD PTR [rbp-36]
        movsd   xmm1, QWORD PTR .LC0[rip]
        divsd   xmm0, xmm1
        cvttsd2si       eax, xmm0
.L6:
        mov     DWORD PTR [rbp-12], eax
        mov     DWORD PTR [rbp-8], 0
        mov     DWORD PTR [rbp-4], 0
.L8:
        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-12]
        jge     .L7
        mov     eax, DWORD PTR [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rdx
        movzx   ecx, BYTE PTR [rax]
        mov     eax, DWORD PTR [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD PTR [rbp-32]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        xor     eax, ecx
        not     eax
        movzx   eax, al
        mov     edi, eax
        call    popcnt8(unsigned char)
        add     DWORD PTR [rbp-8], eax
        add     DWORD PTR [rbp-4], 1
        jmp     .L8
.L7:
        mov     eax, DWORD PTR [rbp-8]
        add     eax, eax
        sub     eax, DWORD PTR [rbp-36]
        mov     DWORD PTR [rbp-8], eax
        mov     eax, DWORD PTR [rbp-8]
        leave
        ret
.LC0:
        .long   0
        .long   1075838976
.LC2:
        .long   0
        .long   1072693248
```
## Related Work
- The AlexNet Moment for Homomorphic Encryption: HCNN,
the First Homomorphic CNN on Encrypted Data with GPUs
- CryptoNets: Applying Neural Networks to Encrypted Data
with High Throughput and Accuracy
