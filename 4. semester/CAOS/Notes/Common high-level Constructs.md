### `if (eax == ebx)`


`cmp eax, ebx       ; compare eax and ebx jne skip_if        ; jump if not equal  ; --- then block --- ; code to run if eax == ebx  skip_if:`

### `if (eax == ebx) else`



`cmp eax, ebx jne else_block     ; if not equal, go to else  ; --- then block --- ; code to run if eax == ebx jmp end_if  else_block: ; --- else block --- ; code to run if eax ≠ ebx  end_if:`

### `while (eax != ebx)`



`loop_start: cmp eax, ebx je loop_end        ; exit if equal  ; --- loop body --- ; code to repeat  jmp loop_start loop_end:`

### `do { ... } while (eax != ebx)`


`loop_start: ; --- loop body --- ; code to run at least once  cmp eax, ebx jne loop_start     ; repeat if not equal`

### `for (ecx = 0; ecx < edx; ecx++)`



`mov ecx, 0  loop_start: cmp ecx, edx jge loop_end       ; exit if ecx ≥ edx  ; --- loop body --- ; your code here  inc ecx jmp loop_start  loop_end:`

### `break` (inside a loop)


`jmp loop_end       ; jump to the end of the loop`

###  `continue` (inside a loop)

`jmp loop_check     ; skip to condition or increment`

---

###  `switch (eax)` using compare chain

```
cmp eax, 1
je case_1

cmp eax, 2
je case_2

jmp default_case

case_1:
; code for case 1
jmp end_switch

case_2:
; code for case 2
jmp end_switch

default_case:
; default case code

end_switch:

```

---

### `call` and `ret` (function structure)

```
call my_function   ; call the function

; later in code...
my_function:
push ebp           ; standard function prologue
mov ebp, esp
; ... function body ...
mov esp, ebp       ; function epilogue
pop ebp
ret

```

