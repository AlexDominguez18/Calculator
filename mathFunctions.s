BITS 64
section .data
oneNegative     dq -1.0
degreeConstant  dq 57.29578

section .bss
data 	resq 2

section .text

global seno:
seno:
    push rbp
    mov rbp, rsp

    movsd qword[rel data], xmm0
    fld qword[rel data]
    fsin

    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret


global arcoseno:
arcoseno:
    push rbp
    mov rbp, rsp

    movsd qword[rel data], xmm0
    fld qword[rel data]
    fld1
    fpatan
    fstp qword[rel data]
    movsd xmm0, [rel data]
    
    mov rsp, rbp
	pop rbp
	ret


global coseno:
coseno:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fcos
    
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret


global arcocoseno:
arcocoseno:
    push rbp
    mov rbp, rsp
    
    movsd qword[rel data], xmm0
    fld qword[rel data]
    fld1
    fpatan
    fstp qword[rel data]
    movsd xmm0, [rel data]

    mov rsp, rbp
	pop rbp
	ret


global tangente:
tangente:
    push rbp
    mov rbp, rsp
    
    movsd qword[rel data], xmm0
    fld qword[rel data]
    fsin
    fld qword[rel data]
    fcos
    fdiv
    fstp qword[rel data]
    movsd xmm0, [rel data]

    mov rsp, rbp
	pop rbp
	ret


global arcotangente:
arcotangente:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fld1
    fpatan
    fstp qword[rel data]
    movsd xmm0, [rel data]
    
    mov rsp, rbp
	pop rbp
	ret

global raizCuadrada:
raizCuadrada:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fsqrt
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret

global potenciaCuadrada:
potenciaCuadrada:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fld qword[rel data]
    fmul
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret


global logaritmo:
logaritmo:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld1
    fld qword[rel data]
    fyl2x
    fldl2t
    fdiv
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret


global antiLogaritmo:
antiLogaritmo:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fldlg2
    fdiv
    fst qword[rel data]
    fld qword[rel data]
    frndint
    fst qword[rel data]
    fsub
    fld qword[rel data]
    fxch
    f2xm1
    fld1
    fadd
    fscale
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret

global suma:
suma:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    movsd qword[rel data],xmm1
    fld qword[rel data]
    fadd
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret

global resta:
resta:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    movsd qword[rel data],xmm1
    fld qword[rel data]
    fsub
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret


global multiplicacion:
multiplicacion:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    movsd qword[rel data],xmm1
    fld qword[rel data]
    fmul
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret

global division:
division:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    movsd qword[rel data],xmm1
    fld qword[rel data]
    fdiv
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret

global cambiarSigno:
cambiarSigno:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fld qword[rel oneNegative]
    fmul
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret

global aGrados:
aGrados:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel data]
    fld qword[rel degreeConstant]
    fmul
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret


global aRadianes:
aRadianes:
    push rbp
    mov rbp, rsp

    movsd qword[rel data],xmm0
    fld qword[rel degreeConstant]
    fld qword[rel data]
    fdiv
    fstp qword[rel data]
    movsd xmm0,[rel data]

    mov rsp, rbp
	pop rbp
	ret
