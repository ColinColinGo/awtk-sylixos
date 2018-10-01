/*********************************************************************************************************
**
**                                    �й�������Դ��֯
**
**                                   Ƕ��ʽʵʱ����ϵͳ
**
**                                SylixOS(TM)  LW : long wing
**
**                               Copyright All Rights Reserved
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**
** ��   ��   ��: cpu_cfg_x86.h
**
** ��   ��   ��: Han.Hui (����)
**
** �ļ���������: 2015 �� 11 �� 20 ��
**
** ��        ��: x86 CPU �����빦������.
*********************************************************************************************************/

#ifndef __CPU_CFG_X86_H
#define __CPU_CFG_X86_H

/*********************************************************************************************************
  CPU ��ϵ�ṹ
*********************************************************************************************************/

#define LW_CFG_CPU_ARCH_X86             1                               /*  CPU �ܹ�                    */
#if defined(__x86_64__)
#define LW_CFG_CPU_ARCH_FAMILY          "x86-64(R)"                     /*  x64 family                  */
#else
#define LW_CFG_CPU_ARCH_FAMILY          "x86(R)"                        /*  x86 family                  */
#endif

/*********************************************************************************************************
  SMT ͬ�����̵߳����Ż�
*********************************************************************************************************/

#define LW_CFG_CPU_ARCH_SMT             1                               /*  ͬ�����߳��Ż�              */

/*********************************************************************************************************
  CACHE LINE ����
*********************************************************************************************************/

#define LW_CFG_CPU_ARCH_CACHE_LINE      128                             /*  cache ����ж�������        */

/*********************************************************************************************************
  CPU ��ϵ�ṹ����
*********************************************************************************************************/

#define LW_CFG_CPU_X86_NO_BARRIER       0                               /*  ��֧���ڴ�����ָ��          */
                                                                        /*  ��ʽ���ڴ����� (1, 2, 3, 4) */
#define LW_CFG_CPU_X86_NO_PAUSE         0                               /*  ��֧�� PAUSE ָ��           */
#define LW_CFG_CPU_X86_NO_HLT           0                               /*  ��֧�� HLT ָ��             */

/*********************************************************************************************************
  CPU �ֳ������ʹ�С�˶���
*********************************************************************************************************/

#define LW_CFG_CPU_ENDIAN               0                               /*  0: С��  1: ���            */
#if defined(__x86_64__)
#define LW_CFG_CPU_WORD_LENGHT          64                              /*  CPU �ֳ�                    */
#define LW_CFG_CPU_PHYS_ADDR_64BIT      1                               /*  ������ַ 64bit ����         */

#else
#define LW_CFG_CPU_WORD_LENGHT          32                              /*  CPU �ֳ�                    */
#define LW_CFG_CPU_PHYS_ADDR_64BIT      0                               /*  ������ַ 64bit ����         */
#endif

/*********************************************************************************************************
  �������㵥Ԫ
*********************************************************************************************************/

#define LW_CFG_CPU_FPU_EN               1                               /*  CPU �Ƿ�ӵ�� FPU            */
#define LW_CFG_CPU_FPU_XSAVE_SIZE       1200                            /*  XSAVE & XRSTOR �����Ĵ�С   */

/*********************************************************************************************************
  DSP �����źŴ�����
*********************************************************************************************************/

#define LW_CFG_CPU_DSP_EN               0                               /*  CPU �Ƿ�ӵ�� DSP            */

/*********************************************************************************************************
  ATOMIC
*********************************************************************************************************/

#define LW_CFG_CPU_ATOMIC_EN            1

#endif                                                                  /*  __CPU_CFG_X86_H             */
/*********************************************************************************************************
  END
*********************************************************************************************************/