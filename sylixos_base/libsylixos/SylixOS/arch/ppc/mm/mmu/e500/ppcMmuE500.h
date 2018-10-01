/*********************************************************************************************************
**
**                                    �й�������Դ��֯
**
**                                   Ƕ��ʽʵʱ����ϵͳ
**
**                                       SylixOS(TM)
**
**                               Copyright  All Rights Reserved
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**
** ��   ��   ��: ppcMmuE500.h
**
** ��   ��   ��: Jiao.JinXing (������)
**
** �ļ���������: 2016 �� 05 �� 05 ��
**
** ��        ��: PowerPC E500 ��ϵ���� MMU ����.
*********************************************************************************************************/

#ifndef __ARCH_PPCMMUE500_H
#define __ARCH_PPCMMUE500_H

VOID   ppcE500MmuInit(LW_MMU_OP  *pmmuop, CPCHAR  pcMachineName);
ULONG  ppcE500MmuDataStorageAbortType(addr_t  ulAbortAddr, BOOL  bIsWrite);
ULONG  ppcE500MmuInstStorageAbortType(addr_t  ulAbortAddr);

#endif                                                                  /*  __ARCH_PPCMMUE500_H         */
/*********************************************************************************************************
  END
*********************************************************************************************************/