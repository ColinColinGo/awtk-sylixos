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
** ��   ��   ��: armCacheV4.h
**
** ��   ��   ��: Han.Hui (����)
**
** �ļ���������: 2013 �� 12 �� 09 ��
**
** ��        ��: ARMv4 ��ϵ���� CACHE ����.
*********************************************************************************************************/

#ifndef __ARMCACHEV4_H
#define __ARMCACHEV4_H

VOID  armCacheV4Init(LW_CACHE_OP *pcacheop, 
                     CACHE_MODE   uiInstruction, 
                     CACHE_MODE   uiData, 
                     CPCHAR       pcMachineName);
                      
VOID  armCacheV4Reset(CPCHAR  pcMachineName);

#endif                                                                  /*  __ARMCACHEV4_H              */
/*********************************************************************************************************
  END
*********************************************************************************************************/