;/*********************************************************************************************************
;**
;**                                    �й�������Դ��֯
;**
;**                                   Ƕ��ʽʵʱ����ϵͳ
;**
;**                                       SylixOS(TM)
;**
;**                               Copyright  All Rights Reserved
;**
;**--------------�ļ���Ϣ--------------------------------------------------------------------------------
;**
;** ��   ��   ��: mips32MmuAsm.S
;**
;** ��   ��   ��: Jiao.JinXing (������)
;**
;** �ļ���������: 2016 �� 06 �� 15 ��
;**
;** ��        ��: MIPS32 ��ϵ���� MMU TLB �����.
;*********************************************************************************************************/

#ifndef ASSEMBLY
#define ASSEMBLY 1
#endif

#include <arch/assembler.h>
#include <config/kernel/vmm_cfg.h>
#include <config/kernel/memory_cfg.h>

#if LW_CFG_VMM_EN > 0
#if LW_CFG_CPU_WORD_LENGHT == 32

#include "arch/mips/arch_mmu.h"

;/*********************************************************************************************************
;  PTE BASE ��ض���
;*********************************************************************************************************/

#define MIPS32_PTE_BASE_OFFSET          23
#define MIPS32_PTE_BASE_SIZE            9

;/*********************************************************************************************************
;  BADVPN2 ��ض���
;*********************************************************************************************************/

#if   LW_CFG_VMM_PAGE_SIZE == (4  * LW_CFG_KB_SIZE)
#define MIPS32_BADVPN2_SHIFT            0
#elif LW_CFG_VMM_PAGE_SIZE == (16 * LW_CFG_KB_SIZE)
#define MIPS32_BADVPN2_SHIFT            2
#elif LW_CFG_VMM_PAGE_SIZE == (64 * LW_CFG_KB_SIZE)
#define MIPS32_BADVPN2_SHIFT            4
#else
#error  LW_CFG_VMM_PAGE_SIZE must be (4K, 16K, 64K)!
#endif

    EXPORT_LABEL(mipsMmuTlbRefillEntry)

    FILE_BEGIN()

;/*********************************************************************************************************
;  TLB ����
;*********************************************************************************************************/

FUNC_DEF(mipsMmuTlbRefillEntry)
    .set    push
    .set    noat
    ;/*
    ; * K1 = CP0_CONTEXT
    ; * K0 = K1
    ; */
    MFC0    K1 , CP0_CONTEXT                                            ;/*  K1 ���� Context �Ĵ���      */
    EHB
    MOVE    K0 , K1                                                     ;/*  K0 ���� Context �Ĵ���      */

    ;/*
    ; * K1 <<= MIPS32_PTE_BASE_SIZE
    ; * K1 >>= MIPS32_PTE_BASE_SIZE
    ; * K1 >>= 4
    ; * K1 >>= MIPS32_BADVPN2_SHIFT
    ; * K1 <<= 3
    ; */
    SLL     K1 , MIPS32_PTE_BASE_SIZE
    SRL     K1 , (MIPS32_PTE_BASE_SIZE + 4 + MIPS32_BADVPN2_SHIFT)      ;/*  K1 Ϊ BAD VPN2              */
    SLL     K1 , (4 - 1)

    ;/*
    ; * K0 >>= MIPS32_PTE_BASE_OFFSET
    ; * K0 <<= MIPS32_PTE_BASE_OFFSET
    ; */
    SRL     K0 , MIPS32_PTE_BASE_OFFSET
    SLL     K0 , MIPS32_PTE_BASE_OFFSET                                 ;/*  K0 Ϊ PTE BASE              */

    ;/*
    ; * K1 = K1 | K0
    ; */
    OR      K1 , K1 , K0                                                ;/*  �ϳ�                        */

    ;/*
    ; * K0 = *K1
    ; * K1 = *(K1 + 4)
    ; */
    LW      K0 , 0(K1)
    LW      K1 , 4(K1)

    ;/*
    ; * CP0_ENTRYLO0 = K0
    ; * CP0_ENTRYLO1 = K1
    ; */
    MTC0    K0 , CP0_ENTRYLO0                                           ;/*  EntryLo0                    */
    MTC0    K1 , CP0_ENTRYLO1                                           ;/*  EntryLo1                    */
    EHB

    TLBWR                                                               ;/*  TLB ����滻                */

    ERET                                                                ;/*  �쳣����                    */
    NOP
    .set    pop
    FUNC_END(mipsMmuTlbRefillEntry)

    FILE_END()

#endif
#endif
;/*********************************************************************************************************
;  END
;*********************************************************************************************************/