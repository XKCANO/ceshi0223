 ;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000800

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp    


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000800

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     WDT_IRQHandler            ; 0:  IWDT &  WWDT
                DCD     SVD_IRQHandler            ; 1:  SVD     
                DCD     RTC_IRQHandler            ; 2:  RTC     
                DCD     FLASH_IRQHandler          ; 3:  FLASH    
                DCD     FDET_IRQHandler           ; 4:  FDET    
                DCD     ADC_IRQHandler            ; 5:  ADC    
                DCD     RAMP_IRQHandler           ; 6:  RAMP
                DCD     SPI0_IRQHandler           ; 7:  SPI0     
                DCD     SPI1_IRQHandler           ; 8:  SPI1
                DCD     DAC_IRQHandler            ; 9:  DAC    
                DCD     UART0_IRQHandler          ; 10:  UART0    
                DCD     UART1_IRQHandler          ; 11:  UART1        
                DCD     UART2_IRQHandler          ; 12:  UART2    
                DCD     UART3_IRQHandler          ; 13:  UART3    
                DCD     UART4_IRQHandler          ; 14:  UART4        
                DCD     FSCAN_IRQHandler          ; 15:  FSCAN    
                DCD     LPUARTx_IRQHandler        ; 16:  LPUART    
                DCD     I2CSMBx_IRQHandler        ; 17:  I2Cx    
                DCD     CLM_PGL_IRQHandler        ; 18:  CLM_PGL    
                DCD     AES_IRQHandler            ; 19:  AES    
                DCD     LPTIM16_IRQHandler        ; 20:  LPTIM16    
                DCD     DMA_IRQHandler            ; 21:  DMA    
                DCD     WKUPx_IRQHandler          ; 22:  WKUP    
                DCD     SENTx_IRQHandler          ; 23:  SENT    
                DCD     BSTIM16_IRQHandler        ; 24:  BSTIM16
                DCD     COMPx_IRQHandler          ; 25:  COMPx
                DCD     GPTIM0_IRQHandler         ; 26:  GPTIM0    
                DCD     GPTIM1_IRQHandler         ; 27:  GPTIM1    
                DCD     ATIM_IRQHandler           ; 28:  ATIM    
                DCD     TAU0_IRQHandler           ; 29:  TAU0    
                DCD     GPIO_IRQHandler           ; 30:  GPIO
                DCD     LED_LCD_IRQHandler        ; 31:  LED_LCD
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                ;IMPORT  SystemInit
                IMPORT  __main
                ;LDR     R0, =SystemInit
                ;BLX     R0        
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  LED_LCD_IRQHandler        [WEAK]
                EXPORT  GPIO_IRQHandler           [WEAK]
                EXPORT  TAU0_IRQHandler           [WEAK]
                EXPORT  ATIM_IRQHandler           [WEAK]
                EXPORT  GPTIM1_IRQHandler         [WEAK]
                EXPORT  GPTIM0_IRQHandler         [WEAK]
                EXPORT  COMPx_IRQHandler          [WEAK]
                EXPORT  BSTIM16_IRQHandler          [WEAK]
                EXPORT  SENTx_IRQHandler          [WEAK]    
                EXPORT  WKUPx_IRQHandler           [WEAK]
                EXPORT  DMA_IRQHandler            [WEAK]
                EXPORT  LPTIM16_IRQHandler          [WEAK]
                EXPORT  AES_IRQHandler            [WEAK]
                EXPORT  CLM_PGL_IRQHandler        [WEAK]
                EXPORT  I2CSMBx_IRQHandler           [WEAK]
                EXPORT  LPUARTx_IRQHandler        [WEAK]    
                EXPORT  FSCAN_IRQHandler          [WEAK]
                EXPORT  UART4_IRQHandler          [WEAK]    
                EXPORT  UART3_IRQHandler          [WEAK]
                EXPORT  UART2_IRQHandler          [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  DAC_IRQHandler            [WEAK]
                EXPORT  SPI1_IRQHandler           [WEAK]
                EXPORT  SPI0_IRQHandler           [WEAK]
                EXPORT  RAMP_IRQHandler           [WEAK]
                EXPORT  ADC_IRQHandler            [WEAK]
                EXPORT  FDET_IRQHandler          [WEAK]
                EXPORT  FLASH_IRQHandler          [WEAK]
                EXPORT  RTC_IRQHandler            [WEAK]
                EXPORT  SVD_IRQHandler            [WEAK]
                EXPORT  WDT_IRQHandler            [WEAK]

LED_LCD_IRQHandler                    
GPIO_IRQHandler
TAU0_IRQHandler
ATIM_IRQHandler
GPTIM1_IRQHandler
GPTIM0_IRQHandler
COMPx_IRQHandler
BSTIM16_IRQHandler
SENTx_IRQHandler
WKUPx_IRQHandler
DMA_IRQHandler
LPTIM16_IRQHandler
AES_IRQHandler
CLM_PGL_IRQHandler
I2CSMBx_IRQHandler
LPUARTx_IRQHandler
FSCAN_IRQHandler
UART4_IRQHandler
UART3_IRQHandler
UART2_IRQHandler
UART1_IRQHandler
UART0_IRQHandler
DAC_IRQHandler
SPI1_IRQHandler
SPI0_IRQHandler
RAMP_IRQHandler
ADC_IRQHandler
FDET_IRQHandler
FLASH_IRQHandler
RTC_IRQHandler
SVD_IRQHandler
WDT_IRQHandler

                B       .
                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                ALIGN

                ENDIF


                END
                    
 *****END OF FILE*****