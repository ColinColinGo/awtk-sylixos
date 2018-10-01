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
** ��   ��   ��: pciStorageAta.h
**
** ��   ��   ��: Gong.YuJian (�����)
**
** �ļ���������: 2018 �� 09 �� 04 ��
**
** ��        ��: ATA/IDE ����.
*********************************************************************************************************/

#ifndef __PCISTORAGEATA_H
#define __PCISTORAGEATA_H

/*********************************************************************************************************
  ��������
*********************************************************************************************************/
#define ATA_PCI_DRV_NAME                    "ata_pci"                   /* PCI ����                     */
#define ATA_PCI_DRV_VER_NUM                 0x02000000                  /* �����汾��ֵ                 */

/*********************************************************************************************************
  ��������
*********************************************************************************************************/
INT  pciStorageAtaInit(VOID);

#endif                                                                  /*  __PCISTORAGEATA_H           */
/*********************************************************************************************************
  END
*********************************************************************************************************/